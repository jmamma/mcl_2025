#include "Wav.h"
#include "MidiSDS.h"
bool Wav::close(bool write) {
  DEBUG_PRINT_FN();
  bool ret;
  if (write) {
    ret = write_header();
    if (!ret) {
      DEBUG_PRINTLN(F("could not write header"));
      return false;
    }
  }
  headerRead = false;
  return file.close();
}

bool Wav::open(const char *file_name, bool write, uint16_t numChannels,
               uint32_t sampleRate, uint8_t bitRate, bool loop) {
  DEBUG_PRINT_FN();
  DEBUG_PRINTLN(filename);
  uint16_t file_mode = write ? (O_RDWR | O_CREAT) : O_RDWR;
  strncpy(filename, file_name, 16);
  headerRead = false;

  if (file.isOpen()) {
    DEBUG_PRINTLN(F("file already open"));
    goto failed;
  }

  if (!file.open(file_name, file_mode)) {
    DEBUG_PRINTLN(F("could not open wave file"));
    goto failed;
  }

  DEBUG_PRINTLN((uint32_t)file.fileSize());
  if (write) {
    DEBUG_PRINTLN(F("truncating"));
    if (!file.truncate(0)) {
      DEBUG_PRINTLN(F("truncate failed"));
      goto failed;
    }

    if (loop) {
      header.init(numChannels, sampleRate, bitRate, SDS_LOOP_FORWARD, 0, 0);
    } else {
      header.init(numChannels, sampleRate, bitRate);
    }
    if (!write_header()) {
      DEBUG_PRINTLN(F("Write wave header failed"));
      goto failed;
    }

    headerRead = true;
    DEBUG_DUMP(data_offset);
    DEBUG_DUMP(file.fileSize());
  } else {
    if (!read_header()) {
      DEBUG_PRINTLN(F("Could not read header"));
      goto failed;
    }
    headerRead = true;
  }
  return true;
failed:
  file.close();
  return false;
}

bool Wav::rename(char *new_name) {
  if (file.isOpen()) {
    return false;
  }
  if (!SD.rename(filename, new_name)) {
    DEBUG_PRINTLN(F("rename failed"));
    return false;
  } else {
    strncpy(filename, new_name, 16);
    return true;
  }
}

/// write layout:
/// RIFF head
/// fmt
/// smpl (optional)
/// data
bool Wav::write_header() {
  DEBUG_PRINT_FN();
  uint32_t chunk_offset = 12;
  // write RIFF chunk header
  if (!write_data(&header, chunk_offset, 0)) {
    return false;
  }
  if (!write_data(&header.fmt, header.fmt.total_len(), chunk_offset)) {
    return false;
  }
  chunk_offset += header.fmt.total_len();
  DEBUG_DUMP(header.fmt.total_len());
  DEBUG_DUMP(chunk_offset);
  if (header.smpl.is_active()) {
    if (!write_data(&header.smpl, header.smpl.total_len(), chunk_offset)) {
      return false;
    }
    chunk_offset += header.smpl.total_len();
    DEBUG_DUMP(header.smpl.total_len());
    DEBUG_DUMP(chunk_offset);
  }
  if (!write_data(&header.data, sizeof(datachunk_t), chunk_offset)) {
    return false;
  }
  chunk_offset += sizeof(datachunk_t);

  data_offset = chunk_offset;
  DEBUG_DUMP(data_offset);
  return true;
}

bool Wav::read_header() {
  DEBUG_PRINT_FN();
  char header_buf[72];
  uint32_t file_size = file.fileSize();
  uint32_t chunk_offset = 12;
  chunk_t *pchunk = (chunk_t *)header_buf;

  if (!read_data(&header, chunk_offset, 0)) {
    return false;
  }
  // check if it is a wav file
  if (!header.check(file_size)) {
    return false;
  }
  // deactivate all chunks
  header.init();

  // parse the subchunks
  while (chunk_offset < file_size) {
    uint32_t read_size = min(sizeof(header_buf), file_size - chunk_offset);
    if (!read_data(&header_buf, read_size, chunk_offset)) {
      return false;
    }
    if (pchunk->is<fmtchunk_t>()) {
      header.fmt = *(fmtchunk_t *)pchunk;
      DEBUG_PRINTLN("parse fmt");
      DEBUG_DUMP(header.fmt.audioFormat);
      DEBUG_DUMP(header.fmt.sampleRate);
      DEBUG_DUMP(header.fmt.bitRate);
      DEBUG_DUMP(header.fmt.numChannels);
    } else if (pchunk->is<datachunk_t>()) {
      header.data = *(datachunk_t *)pchunk;
      data_offset = chunk_offset + sizeof(datachunk_t);
      DEBUG_PRINTLN("parse data");
      DEBUG_DUMP(data_offset);
    } else if (pchunk->is<smplchunk_t>()) {
      header.smpl = *(smplchunk_t *)pchunk;
      smpl_offset = chunk_offset + sizeof(smplchunk_t) - sizeof(loop_t);
      DEBUG_PRINTLN("parse smpl");
      DEBUG_DUMP(smpl_offset);
    } else {
    //break;
    }
    chunk_offset += pchunk->total_len();
  }

  // required subchunks
  if (!header.fmt.is_active() || !header.data.is_active()) {
    return false;
  }

  if ((header.fmt.bitRate > 28) || (header.fmt.bitRate < 8)) {
    DEBUG_PRINTLN(F("header bitRate is not valid:"));
    DEBUG_PRINTLN(header.fmt.bitRate);
    return false;
  }
  return true;
}

bool Wav::write_data(void *data, uint32_t size, uint32_t position) {
  //  DEBUG_PRINTLN(size);
  //  DEBUG_PRINTLN(position);
  //  DEBUG_PRINTLN(file.fileSize());
  bool ret = false;

  ret = file.seekSet(position);

  if (!ret) {
    DEBUG_PRINTLN(F("could not seek"));
    DEBUG_PRINTLN(position);
    DEBUG_PRINTLN((uint32_t)file.fileSize());
    return false;
  }

  ret = mcl_sd.write_data(data, size, &file);
  return ret;
}

bool Wav::read_data(void *data, uint32_t size, uint32_t position) {
  // DEBUG_PRINT_FN();

  // DEBUG_PRINTLN(size);
  // DEBUG_PRINTLN(position);
  bool ret;

  ret = file.seekSet(position);
  if (!ret) {
    DEBUG_PRINTLN(F("could not seek"));
    DEBUG_PRINTLN(position);
    DEBUG_PRINTLN((uint32_t)file.fileSize());
    return false;
  }
  if (!file.isOpen()) {
    DEBUG_PRINTLN(F("file not open"));
    return false;
  }
  ret = mcl_sd.read_data(data, size, &file);
  return ret;
}

bool Wav::write_samples(void *data, uint32_t num_samples,
                        uint32_t sample_offset, uint8_t channel,
                        bool writeheader) {
  //  DEBUG_PRINTLN(channel);
  uint32_t position =
      channel * (header.data.chunk_size / header.fmt.numChannels) +
      sample_offset * (header.fmt.bitRate / 8);

  uint32_t size = num_samples * (header.fmt.bitRate / 8);
  // DEBUG_PRINTLN(num_samples);
  //  DEBUG_PRINTLN(header.bitRate);

  // DEBUG_PRINTLN(position);
  // DEBUG_PRINTLN(file.fileSize());
  bool ret = write_data(data, size, position + data_offset);

  if (!ret) {
    DEBUG_PRINTLN(F("write failed"));
    return false;
  }
  uint32_t new_subchunk2Size = (position + size) * header.fmt.numChannels;
  // DEBUG_PRINT_FN();
  // DEBUG_PRINTLN(position);
  // DEBUG_PRINTLN(num_samples);
  // DEBUG_PRINTLN(sample_offset);
  /*Sample chunk exceeds size of original data chunk, we must extend*/

  if (new_subchunk2Size > header.data.chunk_size) {
    header.data.chunk_size = new_subchunk2Size;
    header.chunk_size = header.total_len() - sizeof(chunk_t);
  }
  if (writeheader) {
    ret = write_header();
  }
  if (!ret) {
    DEBUG_PRINTLN(F("write header failed"));
    return false;
  }
  return ret;
}

bool Wav::read_samples(void *data, uint32_t num_samples, uint32_t sample_index,
                       uint8_t channel) {
  uint8_t sample_size = header.fmt.bitRate / 8;
  if (header.fmt.bitRate % 8 > 0) {
    sample_size++;
  }

  uint8_t nch_sample_size = sample_size * header.fmt.numChannels;
  uint32_t position = sample_index * nch_sample_size;

  uint32_t read_size = num_samples * sample_size;
  uint32_t nch_read_size = read_size * header.fmt.numChannels;
  uint32_t new_subchunk2Size = position + nch_read_size;
  // DEBUG_PRINTLN(size);
  // DEBUG_PRINTLN(header.bitRate);
  // DEBUG_PRINTLN(num_samples);
  // DEBUG_PRINTLN(header.subchunk2Size);

  // If requested read size extends past channel size, then truncate read
  if (new_subchunk2Size > header.data.chunk_size) {
    DEBUG_PRINTLN(F("read size is greater than file size, adjusting"));
    read_size = (header.data.chunk_size - position) / header.fmt.numChannels;
    nch_read_size = read_size * header.fmt.numChannels;
  }

  if (header.fmt.numChannels == 1) {
    return read_data(data, read_size, position + data_offset);
  }
  // Read all channels, if channel exceeds number of channels
  if (channel >= header.fmt.numChannels) {
    return read_data(data, nch_read_size, position + data_offset);
  }
  // DEBUG_PRINTLN(file.fileSize());
  // DEBUG_PRINTLN(header.bitRate);
  // DEBUG_PRINTLN(position);
  // DEBUG_PRINTLN(size);
  // DEBUG_PRINTLN(data_offset);

  // Sample data is interleaved.
  // 2-channel interleaved data:
  // [L R] [L R] [L R] ... [L R]    [L R] ... [L R]
  // s0    s1    s2        s{n/2-1} s{n/2}    s{n-1}
  char tmp_buf[80];
  position += data_offset;
  // 16-bit stereo full run = 20(L+R) = 80 bytes
  // 24-bit stereo full run = 13(L+R) = 78 bytes
  uint32_t full_run =
      ((sizeof(tmp_buf) / header.fmt.numChannels) / sample_size) * sample_size *
      header.fmt.numChannels;
  while (read_size > 0) {
    uint32_t current_run = min(full_run, read_size * header.fmt.numChannels);
    bool ret = read_data(tmp_buf, current_run, position);
    if (!ret)
      return false;
    position += current_run;
    read_size -= current_run / header.fmt.numChannels;
    for (uint32_t p = channel * sample_size; p < current_run;
         p += nch_sample_size) {
      memcpy(data, tmp_buf + p, sample_size);
      data = (char *)data + sample_size;
    }
  }
  return true;
}

__int24 Wav::find_peak(uint8_t channel, uint32_t num_samples,
                       uint32_t sample_index) {

  wav_sample_t c0_min_sample;
  wav_sample_t c0_max_sample;
  wav_sample_t c1_min_sample;
  wav_sample_t c1_max_sample;

  find_peaks(num_samples, sample_index, &c0_max_sample, &c0_min_sample,
             &c1_max_sample, &c1_min_sample);
  if (channel == 0) {

    if (abs(c0_min_sample.val) > c0_max_sample.val) {
      return abs(c0_min_sample.val);
    }
    return c0_max_sample.val;
  }

  if (abs(c1_min_sample.val) > c1_max_sample.val) {
    return abs(c1_min_sample.val);
  }
  return c1_max_sample.val;
}
void Wav::find_peaks(uint32_t num_samples, uint32_t sample_index,
                     wav_sample_t *c0_max_sample, wav_sample_t *c0_min_sample,
                     wav_sample_t *c1_max_sample, wav_sample_t *c1_min_sample) {
  DEBUG_PRINT_FN();
  // Stereo
  bool is_stereo = (header.fmt.numChannels == 2);
  bool ignore_second_chan = false;

  if ((c1_max_sample == NULL) || (c1_min_sample == NULL) || (!is_stereo)) {
    ignore_second_chan = true;
  }

  c0_max_sample->val = 0;
  c0_min_sample->val = 0;

  int16_t c0_min_sample16;
  int16_t c0_max_sample16;

  if (!ignore_second_chan) {
    c1_max_sample->val = 0;
    c1_min_sample->val = 0;
  }
  int16_t c1_min_sample16;
  int16_t c1_max_sample16;

  __int24 sample_val24 = 0;
  int16_t sample_val16 = 0;

  uint8_t sample_size = header.fmt.bitRate / 8;
  if (header.fmt.bitRate % 8 > 0) {
    sample_size++;
  }
  uint32_t num_of_samples;

  if (num_samples > 0) {
    num_of_samples = num_samples;
  }

  else {
    uint32_t num_of_samples =
        (header.data.chunk_size / header.fmt.numChannels) / sample_size;
  }

  int16_t buffer_size = 512;

  uint8_t buffer[buffer_size];

  int16_t read_size = buffer_size / (sample_size * header.fmt.numChannels);

  int32_t sample_max = (pow(2, header.fmt.bitRate) / 2);

  uint8_t word_offset = 4 - sample_size;

  DEBUG_DUMP(sample_size);
  DEBUG_DUMP(header.fmt.bitRate);
  DEBUG_DUMP(header.fmt.numChannels);
  DEBUG_PRINTLN(read_size);

  for (uint32_t n = sample_index; n < sample_index + num_of_samples;
       n += read_size) {
    // Adjust read size if too large
    if (n + read_size > sample_index + num_of_samples) {
      read_size = sample_index + num_of_samples - n;
    }
    // Read read_size samples.
    if (!read_samples(buffer, read_size, n, header.fmt.numChannels)) {
      DEBUG_PRINTLN("could not read");
      return;
    }
    // Itterate through samples in buffer
    uint16_t buf_index = 0;

    for (uint16_t sample = 0; sample < read_size; sample += 1) {
      switch (sample_size) {
      // 16bit - fast mode.
      case 2:

        sample_val16 = ((int16_t *)&buffer)[buf_index++];

        if (sample_val16 < c0_min_sample16) {
          c0_min_sample16 = sample_val16;
          c0_min_sample->pos = sample + sample_index;
        }

        if (sample_val16 > c0_max_sample16) {
          c0_max_sample16 = sample_val16;
          c0_max_sample->pos = sample + sample_index;
        }
        if (!ignore_second_chan) {
          sample_val16 = ((int16_t *)&buffer)[buf_index++];
          if (sample_val16 < c1_min_sample16) {
            c1_min_sample16 = sample_val16;
            c1_min_sample->pos = sample + sample_index;
          }

          if (sample_val16 > c1_max_sample16) {
            c1_max_sample16 = sample_val16;
            c1_max_sample->pos = sample + sample_index;
          }
        } else if (is_stereo) {
          buf_index++;
        }
        break;

      case 3:
        // 24bit

        sample_val24 = ((__int24 *)&buffer)[buf_index++];

        if (sample_val24 < c0_min_sample->val) {
          c0_min_sample->val = sample_val24;
          c0_min_sample->pos = sample + sample_index;
        }

        if (sample_val24 > c0_max_sample->val) {
          c0_max_sample->val = sample_val24;
          c0_max_sample->pos = sample + sample_index;
        }
        if (!ignore_second_chan) {
          sample_val24 = ((__int24 *)&buffer)[buf_index++];
          if (sample_val24 < c1_min_sample->val) {
            c1_min_sample->val = sample_val24;
            c1_min_sample->pos = sample + sample_index;
          }

          if (sample_val24 > c1_max_sample->val) {
            c1_max_sample->val = sample_val24;
            c1_max_sample->pos = sample + sample_index;
          }
        } else if (is_stereo) {
          buf_index++;
        }
      }
    }
  }

  if (sample_size == 2) {
    c0_min_sample->val = (__int24)c0_min_sample16;
    c0_max_sample->val = (__int24)c0_max_sample16;
    if (!ignore_second_chan) {
      c1_min_sample->val = (__int24)c1_min_sample16;
      c1_max_sample->val = (__int24)c1_max_sample16;
    }
  }
}

bool Wav::apply_gain(float gain, uint8_t channel, uint32_t num_samples,
                     uint32_t sample_index) {
  DEBUG_PRINT_FN();

  uint8_t sample_size = header.fmt.bitRate / 8;
  if (header.fmt.bitRate % 8 > 0) {
    sample_size++;
  }

  bool is_stereo = (header.fmt.numChannels == 2);

  uint32_t num_of_samples;

  if (num_samples > 0) {
    num_of_samples = num_samples;
  }

  else {
    num_of_samples =
        (header.data.chunk_size / header.fmt.numChannels) / sample_size;
  }

  int16_t buffer_size = 512;

  uint8_t buffer[buffer_size];

  int16_t read_size = buffer_size / (sample_size * header.fmt.numChannels);

  uint16_t sample_val16 = 0;
  __int24 sample_val24 = 0;

  uint32_t sample_max = (pow(2, header.fmt.bitRate) / 2);
  bool write_header = false;
  DEBUG_PRINTLN(F("read_size"));
  DEBUG_PRINTLN(read_size);
  DEBUG_PRINTLN(num_of_samples);
  DEBUG_PRINTLN(sample_size);
  DEBUG_PRINTLN(buffer_size);
  DEBUG_PRINTLN(gain);

  bool is_signed;

  for (int32_t n = 0; n < sample_index + num_of_samples; n += read_size) {
    // Adjust read size if too large
    if (n + read_size > sample_index + num_of_samples) {
      read_size = sample_index + num_of_samples - n;
    }
    // Read read_size samples.

    if (!read_samples(buffer, read_size, n, header.fmt.numChannels)) {
      DEBUG_PRINTLN("could not read");
      return false;
    }
    // Itterate through samples in buffer
    uint8_t current_channel = 0;
    uint8_t buf_index = 0;
    for (uint16_t sample = 0; sample < read_size; sample += 1) {

      if ((channel == current_channel) || (channel >= header.fmt.numChannels) ||
          (!is_stereo)) {
        switch (sample_size) {
        case 2:
          //16bit
          sample_val16 = ((int16_t *)&buffer)[buf_index];
          sample_val16 = (uint16_t)((float)sample_val16 * (float)gain);
          is_signed = (sample_val16 < 0);
          if (abs(sample_val16) > sample_max) {
            sample_val16 = sample_max;
            if (is_signed) {
              sample_val16 *= -1;
              sample_val16 -= 1;
            }
          }

          ((int16_t *)&buffer)[buf_index] = sample_val16;
          break;
        case 3:
          //24bit
          sample_val24 = ((__int24 *)&buffer)[buf_index];
          sample_val24 = (__int24)((float)sample_val24 * (float)gain);
          is_signed = ((int32_t)sample_val24 < 0);
          if (abs(sample_val24) > sample_max) {
            sample_val24 = sample_max;
            if (is_signed) {
              sample_val24 *= -1;
              sample_val24 -= 1;
            }
          }
          ((__int24 *)&buffer)[buf_index] = sample_val24;
          break;
        }
      }
      buf_index++;
      current_channel++;
      if (current_channel == header.fmt.numChannels) {
        current_channel = 0;
      }
    }
    // Write back the adjusted samples
    if (!write_samples(buffer, read_size, n, header.fmt.numChannels,
                       write_header)) {
      DEBUG_PRINTLN("could not write");
      return false;
    }
    // loop

  }

    return true;
}


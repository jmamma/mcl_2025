#pragma once

#include "ElektronModelTypes.h"
#include "MCLGif.h"
#include "MCLMemory.h"
#include "MCLMenuDefines.h"
#include "MenuTypes.h"
#include "PageIndex.h"
#include "SeqDefines.h"

extern const unsigned char __R_icons_knob[] PROGMEM;
struct __T_icons_knob {
  union {
    unsigned char encoder_small_0[0];
    char zz__encoder_small_0[24];
  };
  static constexpr size_t countof_encoder_small_0 = 24 / sizeof(unsigned char);
  static constexpr size_t sizeofof_encoder_small_0 = 24;

  union {
    unsigned char encoder_small_1[0];
    char zz__encoder_small_1[24];
  };
  static constexpr size_t countof_encoder_small_1 = 24 / sizeof(unsigned char);
  static constexpr size_t sizeofof_encoder_small_1 = 24;

  union {
    unsigned char encoder_small_2[0];
    char zz__encoder_small_2[24];
  };
  static constexpr size_t countof_encoder_small_2 = 24 / sizeof(unsigned char);
  static constexpr size_t sizeofof_encoder_small_2 = 24;

  union {
    unsigned char encoder_small_3[0];
    char zz__encoder_small_3[24];
  };
  static constexpr size_t countof_encoder_small_3 = 24 / sizeof(unsigned char);
  static constexpr size_t sizeofof_encoder_small_3 = 24;

  union {
    unsigned char encoder_small_4[0];
    char zz__encoder_small_4[24];
  };
  static constexpr size_t countof_encoder_small_4 = 24 / sizeof(unsigned char);
  static constexpr size_t sizeofof_encoder_small_4 = 24;

  union {
    unsigned char encoder_small_5[0];
    char zz__encoder_small_5[24];
  };
  static constexpr size_t countof_encoder_small_5 = 24 / sizeof(unsigned char);
  static constexpr size_t sizeofof_encoder_small_5 = 24;

  union {
    unsigned char encoder_small_6[0];
    char zz__encoder_small_6[24];
  };
  static constexpr size_t countof_encoder_small_6 = 24 / sizeof(unsigned char);
  static constexpr size_t sizeofof_encoder_small_6 = 24;

  union {
    unsigned char wheel_top[0];
    char zz__wheel_top[60];
  };
  static constexpr size_t countof_wheel_top = 60 / sizeof(unsigned char);
  static constexpr size_t sizeofof_wheel_top = 60;

  union {
    unsigned char wheel_angle[0];
    char zz__wheel_angle[60];
  };
  static constexpr size_t countof_wheel_angle = 60 / sizeof(unsigned char);
  static constexpr size_t sizeofof_wheel_angle = 60;

  union {
    unsigned char wheel_side[0];
    char zz__wheel_side[60];
  };
  static constexpr size_t countof_wheel_side = 60 / sizeof(unsigned char);
  static constexpr size_t sizeofof_wheel_side = 60;

  static constexpr size_t __total_size = 348;
};

extern const unsigned char __R_icons_device[] PROGMEM;
struct __T_icons_device {
  union {
    unsigned char icon_md[0];
    char zz__icon_md[120];
  };
  static constexpr size_t countof_icon_md = 120 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_md = 120;

  union {
    unsigned char icon_a4[0];
    char zz__icon_a4[120];
  };
  static constexpr size_t countof_icon_a4 = 120 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_a4 = 120;

  union {
    unsigned char icon_mnm[0];
    char zz__icon_mnm[120];
  };
  static constexpr size_t countof_icon_mnm = 120 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_mnm = 120;

  union {
    unsigned char icon_turbo[0];
    char zz__icon_turbo[120];
  };
  static constexpr size_t countof_icon_turbo = 120 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_turbo = 120;

  static constexpr size_t __total_size = 480;
};

extern const unsigned char __R_machine_param_names[] PROGMEM;
struct __T_machine_param_names {
  union {
    model_param_name_t md_model_param_names[0];
    char zz__md_model_param_names[3092];
  };
  static constexpr size_t countof_md_model_param_names = 3092 / sizeof(model_param_name_t);
  static constexpr size_t sizeofof_md_model_param_names = 3092;

  union {
    model_param_name_t mnm_model_param_names[0];
    char zz__mnm_model_param_names[956];
  };
  static constexpr size_t countof_mnm_model_param_names = 956 / sizeof(model_param_name_t);
  static constexpr size_t sizeofof_mnm_model_param_names = 956;

  static constexpr size_t __total_size = 4048;
};

extern const unsigned char __R_machine_names_short[] PROGMEM;
struct __T_machine_names_short {
  union {
    short_machine_name_t md_machine_names_short[0];
    char zz__md_machine_names_short[996];
  };
  static constexpr size_t countof_md_machine_names_short = 996 / sizeof(short_machine_name_t);
  static constexpr size_t sizeofof_md_machine_names_short = 996;

  union {
    short_machine_name_t mnm_machine_names_short[0];
    char zz__mnm_machine_names_short[140];
  };
  static constexpr size_t countof_mnm_machine_names_short = 140 / sizeof(short_machine_name_t);
  static constexpr size_t sizeofof_mnm_machine_names_short = 140;

  static constexpr size_t __total_size = 1136;
};

extern const unsigned char __R_page_entries[] PROGMEM;
struct __T_page_entries {
  union {
    PageSelectEntry Entries[0];
    char zz__Entries[392];
  };
  static constexpr size_t countof_Entries = 392 / sizeof(PageSelectEntry);
  static constexpr size_t sizeofof_Entries = 392;

  static constexpr size_t __total_size = 392;
};

extern const unsigned char __R_icons_page[] PROGMEM;
struct __T_icons_page {
  union {
    unsigned char icon_grid[0];
    char zz__icon_grid[48];
  };
  static constexpr size_t countof_icon_grid = 48 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_grid = 48;

  union {
    unsigned char icon_lfo[0];
    char zz__icon_lfo[72];
  };
  static constexpr size_t countof_icon_lfo = 72 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_lfo = 72;

  union {
    unsigned char icon_wavd[0];
    char zz__icon_wavd[60];
  };
  static constexpr size_t countof_icon_wavd = 60 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_wavd = 60;

  union {
    unsigned char icon_step[0];
    char zz__icon_step[64];
  };
  static constexpr size_t countof_icon_step = 64 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_step = 64;

  union {
    unsigned char icon_mixer[0];
    char zz__icon_mixer[48];
  };
  static constexpr size_t countof_icon_mixer = 48 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_mixer = 48;

  union {
    unsigned char icon_gatebox[0];
    char zz__icon_gatebox[76];
  };
  static constexpr size_t countof_icon_gatebox = 76 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_gatebox = 76;

  union {
    unsigned char icon_rhytmecho[0];
    char zz__icon_rhytmecho[76];
  };
  static constexpr size_t countof_icon_rhytmecho = 76 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_rhytmecho = 76;

  union {
    unsigned char icon_route[0];
    char zz__icon_route[44];
  };
  static constexpr size_t countof_icon_route = 44 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_route = 44;

  union {
    unsigned char icon_sample[0];
    char zz__icon_sample[76];
  };
  static constexpr size_t countof_icon_sample = 76 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_sample = 76;

  union {
    unsigned char icon_ram2[0];
    char zz__icon_ram2[76];
  };
  static constexpr size_t countof_icon_ram2 = 76 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_ram2 = 76;

  union {
    unsigned char icon_ram1[0];
    char zz__icon_ram1[76];
  };
  static constexpr size_t countof_icon_ram1 = 76 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_ram1 = 76;

  union {
    unsigned char icon_pianoroll[0];
    char zz__icon_pianoroll[76];
  };
  static constexpr size_t countof_icon_pianoroll = 76 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_pianoroll = 76;

  union {
    unsigned char icon_chroma[0];
    char zz__icon_chroma[76];
  };
  static constexpr size_t countof_icon_chroma = 76 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_chroma = 76;

  union {
    unsigned char icon_perf[0];
    char zz__icon_perf[56];
  };
  static constexpr size_t countof_icon_perf = 56 / sizeof(unsigned char);
  static constexpr size_t sizeofof_icon_perf = 56;

  static constexpr size_t __total_size = 924;
};

extern const unsigned char __R_icons_boot[] PROGMEM;
struct __T_icons_boot {
  union {
    unsigned char mcl_logo_bitmap[0];
    char zz__mcl_logo_bitmap[152];
  };
  static constexpr size_t countof_mcl_logo_bitmap = 152 / sizeof(unsigned char);
  static constexpr size_t sizeofof_mcl_logo_bitmap = 152;

  union {
    unsigned char evilknievel_bitmap[0];
    char zz__evilknievel_bitmap[156];
  };
  static constexpr size_t countof_evilknievel_bitmap = 156 / sizeof(unsigned char);
  static constexpr size_t sizeofof_evilknievel_bitmap = 156;

  static constexpr size_t __total_size = 308;
};

extern const unsigned char __R_machine_names_long[] PROGMEM;
struct __T_machine_names_long {
  union {
    md_machine_name_t machine_names[0];
    char zz__machine_names[1136];
  };
  static constexpr size_t countof_machine_names = 1136 / sizeof(md_machine_name_t);
  static constexpr size_t sizeofof_machine_names = 1136;

  union {
    mnm_machine_name_t mnm_machine_names[0];
    char zz__mnm_machine_names[240];
  };
  static constexpr size_t countof_mnm_machine_names = 240 / sizeof(mnm_machine_name_t);
  static constexpr size_t sizeofof_mnm_machine_names = 240;

  static constexpr size_t __total_size = 1376;
};

extern const unsigned char __R_menu_options[] PROGMEM;
struct __T_menu_options {
  union {
    menu_option_t MENU_OPTIONS[0];
    char zz__MENU_OPTIONS[1136];
  };
  static constexpr size_t countof_MENU_OPTIONS = 1136 / sizeof(menu_option_t);
  static constexpr size_t sizeofof_MENU_OPTIONS = 1136;

  static constexpr size_t __total_size = 1136;
};

extern const unsigned char __R_menu_layouts[] PROGMEM;
struct __T_menu_layouts {
  union {
    menu_t<boot_menu_page_N> boot_menu_layout[0];
    char zz__boot_menu_layout[96];
  };
  static constexpr size_t countof_boot_menu_layout = 96 / sizeof(menu_t<boot_menu_page_N>);
  static constexpr size_t sizeofof_boot_menu_layout = 96;

  union {
    menu_t<start_menu_page_N> start_menu_layout[0];
    char zz__start_menu_layout[56];
  };
  static constexpr size_t countof_start_menu_layout = 56 / sizeof(menu_t<start_menu_page_N>);
  static constexpr size_t sizeofof_start_menu_layout = 56;

  union {
    menu_t<system_menu_page_N> system_menu_layout[0];
    char zz__system_menu_layout[140];
  };
  static constexpr size_t countof_system_menu_layout = 140 / sizeof(menu_t<system_menu_page_N>);
  static constexpr size_t sizeofof_system_menu_layout = 140;

  union {
    menu_t<aux_config_page_N> auxconfig_menu_layout[0];
    char zz__auxconfig_menu_layout[56];
  };
  static constexpr size_t countof_auxconfig_menu_layout = 56 / sizeof(menu_t<aux_config_page_N>);
  static constexpr size_t sizeofof_auxconfig_menu_layout = 56;

  union {
    menu_t<midi_config_page_N> midiconfig_menu_layout[0];
    char zz__midiconfig_menu_layout[140];
  };
  static constexpr size_t countof_midiconfig_menu_layout = 140 / sizeof(menu_t<midi_config_page_N>);
  static constexpr size_t sizeofof_midiconfig_menu_layout = 140;

  union {
    menu_t<midiport_menu_page_N> midiport_menu_layout[0];
    char zz__midiport_menu_layout[140];
  };
  static constexpr size_t countof_midiport_menu_layout = 140 / sizeof(menu_t<midiport_menu_page_N>);
  static constexpr size_t sizeofof_midiport_menu_layout = 140;

  union {
    menu_t<midiprogram_menu_page_N> midiprogram_menu_layout[0];
    char zz__midiprogram_menu_layout[76];
  };
  static constexpr size_t countof_midiprogram_menu_layout = 76 / sizeof(menu_t<midiprogram_menu_page_N>);
  static constexpr size_t sizeofof_midiprogram_menu_layout = 76;

  union {
    menu_t<midiclock_menu_page_N> midiclock_menu_layout[0];
    char zz__midiclock_menu_layout[96];
  };
  static constexpr size_t countof_midiclock_menu_layout = 96 / sizeof(menu_t<midiclock_menu_page_N>);
  static constexpr size_t sizeofof_midiclock_menu_layout = 96;

  union {
    menu_t<midiroute_menu_page_N> midiroute_menu_layout[0];
    char zz__midiroute_menu_layout[96];
  };
  static constexpr size_t countof_midiroute_menu_layout = 96 / sizeof(menu_t<midiroute_menu_page_N>);
  static constexpr size_t sizeofof_midiroute_menu_layout = 96;

  union {
    menu_t<midimachinedrum_menu_page_N> midimachinedrum_menu_layout[0];
    char zz__midimachinedrum_menu_layout[76];
  };
  static constexpr size_t countof_midimachinedrum_menu_layout = 76 / sizeof(menu_t<midimachinedrum_menu_page_N>);
  static constexpr size_t sizeofof_midimachinedrum_menu_layout = 76;

  union {
    menu_t<midigeneric_menu_page_N> midigeneric_menu_layout[0];
    char zz__midigeneric_menu_layout[32];
  };
  static constexpr size_t countof_midigeneric_menu_layout = 32 / sizeof(menu_t<midigeneric_menu_page_N>);
  static constexpr size_t sizeofof_midigeneric_menu_layout = 32;

  union {
    menu_t<md_config_page_N> mdconfig_menu_layout[0];
    char zz__mdconfig_menu_layout[56];
  };
  static constexpr size_t countof_mdconfig_menu_layout = 56 / sizeof(menu_t<md_config_page_N>);
  static constexpr size_t sizeofof_mdconfig_menu_layout = 56;

  union {
    menu_t<md_import_page_N> mdimport_menu_layout[0];
    char zz__mdimport_menu_layout[96];
  };
  static constexpr size_t countof_mdimport_menu_layout = 96 / sizeof(menu_t<md_import_page_N>);
  static constexpr size_t sizeofof_mdimport_menu_layout = 96;

  union {
    menu_t<mcl_config_page_N> mclconfig_menu_layout[0];
    char zz__mclconfig_menu_layout[32];
  };
  static constexpr size_t countof_mclconfig_menu_layout = 32 / sizeof(menu_t<mcl_config_page_N>);
  static constexpr size_t sizeofof_mclconfig_menu_layout = 32;

  union {
    menu_t<file_menu_page_N> file_menu_layout[0];
    char zz__file_menu_layout[140];
  };
  static constexpr size_t countof_file_menu_layout = 140 / sizeof(menu_t<file_menu_page_N>);
  static constexpr size_t sizeofof_file_menu_layout = 140;

  union {
    menu_t<seq_menu_page_N> seq_menu_layout[0];
    char zz__seq_menu_layout[536];
  };
  static constexpr size_t countof_seq_menu_layout = 536 / sizeof(menu_t<seq_menu_page_N>);
  static constexpr size_t sizeofof_seq_menu_layout = 536;

  union {
    menu_t<grid_slot_page_N> slot_menu_layout[0];
    char zz__slot_menu_layout[200];
  };
  static constexpr size_t countof_slot_menu_layout = 200 / sizeof(menu_t<grid_slot_page_N>);
  static constexpr size_t sizeofof_slot_menu_layout = 200;

  union {
    menu_t<wavdesign_menu_page_N> wavdesign_menu_layout[0];
    char zz__wavdesign_menu_layout[76];
  };
  static constexpr size_t countof_wavdesign_menu_layout = 76 / sizeof(menu_t<wavdesign_menu_page_N>);
  static constexpr size_t sizeofof_wavdesign_menu_layout = 76;

  union {
    menu_t<perf_menu_page_N> perf_menu_layout[0];
    char zz__perf_menu_layout[56];
  };
  static constexpr size_t countof_perf_menu_layout = 56 / sizeof(menu_t<perf_menu_page_N>);
  static constexpr size_t sizeofof_perf_menu_layout = 56;

  static constexpr size_t __total_size = 2196;
};

extern const unsigned char __R_icons_logo[] PROGMEM;
struct __T_icons_logo {
  union {
    MCLGIF metronome_gif[0];
    char zz__metronome_gif[16];
  };
  static constexpr size_t countof_metronome_gif = 16 / sizeof(MCLGIF);
  static constexpr size_t sizeofof_metronome_gif = 16;

  union {
    MCLGIF perf_gif[0];
    char zz__perf_gif[16];
  };
  static constexpr size_t countof_perf_gif = 16 / sizeof(MCLGIF);
  static constexpr size_t sizeofof_perf_gif = 16;

  union {
    MCLGIF route_gif[0];
    char zz__route_gif[16];
  };
  static constexpr size_t countof_route_gif = 16 / sizeof(MCLGIF);
  static constexpr size_t sizeofof_route_gif = 16;

  union {
    MCLGIF analog_gif[0];
    char zz__analog_gif[16];
  };
  static constexpr size_t countof_analog_gif = 16 / sizeof(MCLGIF);
  static constexpr size_t sizeofof_analog_gif = 16;

  union {
    MCLGIF monomachine_gif[0];
    char zz__monomachine_gif[16];
  };
  static constexpr size_t countof_monomachine_gif = 16 / sizeof(MCLGIF);
  static constexpr size_t sizeofof_monomachine_gif = 16;

  union {
    MCLGIF machinedrum_gif[0];
    char zz__machinedrum_gif[16];
  };
  static constexpr size_t countof_machinedrum_gif = 16 / sizeof(MCLGIF);
  static constexpr size_t sizeofof_machinedrum_gif = 16;

  union {
    MCLGIF midi_gif[0];
    char zz__midi_gif[16];
  };
  static constexpr size_t countof_midi_gif = 16 / sizeof(MCLGIF);
  static constexpr size_t sizeofof_midi_gif = 16;

  union {
    unsigned char perf_gif_data[0];
    char zz__perf_gif_data[192];
  };
  static constexpr size_t countof_perf_gif_data = 192 / sizeof(unsigned char);
  static constexpr size_t sizeofof_perf_gif_data = 192;

  union {
    unsigned char route_gif_data[0];
    char zz__route_gif_data[100];
  };
  static constexpr size_t countof_route_gif_data = 100 / sizeof(unsigned char);
  static constexpr size_t sizeofof_route_gif_data = 100;

  union {
    unsigned char analog_gif_data[0];
    char zz__analog_gif_data[192];
  };
  static constexpr size_t countof_analog_gif_data = 192 / sizeof(unsigned char);
  static constexpr size_t sizeofof_analog_gif_data = 192;

  union {
    unsigned char machinedrum_gif_data[0];
    char zz__machinedrum_gif_data[216];
  };
  static constexpr size_t countof_machinedrum_gif_data = 216 / sizeof(unsigned char);
  static constexpr size_t sizeofof_machinedrum_gif_data = 216;

  union {
    unsigned char midi_gif_data[0];
    char zz__midi_gif_data[216];
  };
  static constexpr size_t countof_midi_gif_data = 216 / sizeof(unsigned char);
  static constexpr size_t sizeofof_midi_gif_data = 216;

  union {
    unsigned char monomachine_gif_data[0];
    char zz__monomachine_gif_data[272];
  };
  static constexpr size_t countof_monomachine_gif_data = 272 / sizeof(unsigned char);
  static constexpr size_t sizeofof_monomachine_gif_data = 272;

  union {
    unsigned char metronome_gif_data[0];
    char zz__metronome_gif_data[360];
  };
  static constexpr size_t countof_metronome_gif_data = 360 / sizeof(unsigned char);
  static constexpr size_t sizeofof_metronome_gif_data = 360;

  static constexpr size_t __total_size = 1660;
};


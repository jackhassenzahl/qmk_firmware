// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool is_gui_active = false;
uint16_t gui_timer = 0;

enum custom_keycodes {
    APP_RIGHT,
    APP_LEFT,
    DESK_RIGHT,
    DESK_LEFT,
    WIN1,
    WIN2,
    WIN3,
    WIN4,
    WIN5,
    WIN6,
    WIN7,
    WIN8,
    WIN9,
    WIN10
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        LT(2, KC_MPLY), KC_MUTE, KC_VOLD, KC_VOLU, MO(1),
        WIN1, WIN2, WIN3, WIN4, WIN5,
        WIN6, WIN7, WIN8, WIN9, WIN10,
        RALT(KC_SPC), RGUI(KC_TAB), RALT(KC_F4), KC_HOME, KC_END
    ),

    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT(
        KC_TRNS, RCTL(KC_X), RCTL(KC_C), RCTL(KC_V), QK_BOOT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] = { ENCODER_CCW_CW(APP_LEFT, APP_RIGHT) },
    [1] = { ENCODER_CCW_CW(DESK_LEFT, DESK_RIGHT) },
    [2] = { ENCODER_CCW_CW(KC_NO, KC_NO) },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case APP_RIGHT:
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code(KC_TAB);
                return false;
            case APP_LEFT:
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_RSFT);
                tap_code(KC_TAB);
                unregister_code(KC_RSFT);
                return false;
            case DESK_RIGHT:
                tap_code16(G(C(KC_RGHT)));
                return false;
            case DESK_LEFT:
                tap_code16(G(C(KC_LEFT)));
                return false;
            case WIN1:
                if (!is_gui_active) {
                    is_gui_active = true;
                    register_code(KC_LGUI);
                }
                gui_timer = timer_read();
                tap_code(KC_1);
                return false;
            case WIN2:
                if (!is_gui_active) {
                    is_gui_active = true;
                    register_code(KC_LGUI);
                }
                gui_timer = timer_read();
                tap_code(KC_2);
                return false;
            case WIN3:
                if (!is_gui_active) {
                    is_gui_active = true;
                    register_code(KC_LGUI);
                }
                gui_timer = timer_read();
                tap_code(KC_3);
                return false;
            case WIN4:
                if (!is_gui_active) {
                    is_gui_active = true;
                    register_code(KC_LGUI);
                }
                gui_timer = timer_read();
                tap_code(KC_4);
                return false;
            case WIN5:
                if (!is_gui_active) {
                    is_gui_active = true;
                    register_code(KC_LGUI);
                }
                gui_timer = timer_read();
                tap_code(KC_5);
                return false;
            case WIN6:
                if (!is_gui_active) {
                    is_gui_active = true;
                    register_code(KC_LGUI);
                }
                gui_timer = timer_read();
                tap_code(KC_6);
                return false;
            case WIN7:
                if (!is_gui_active) {
                    is_gui_active = true;
                    register_code(KC_LGUI);
                }
                gui_timer = timer_read();
                tap_code(KC_7);
                return false;
            case WIN8:
                if (!is_gui_active) {
                    is_gui_active = true;
                    register_code(KC_LGUI);
                }
                gui_timer = timer_read();
                tap_code(KC_8);
                return false;
            case WIN9:
                if (!is_gui_active) {
                    is_gui_active = true;
                    register_code(KC_LGUI);
                }
                gui_timer = timer_read();
                tap_code(KC_9);
                return false;
            case WIN10:
                if (!is_gui_active) {
                    is_gui_active = true;
                    register_code(KC_LGUI);
                }
                gui_timer = timer_read();
                tap_code(KC_0);
                return false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 750) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
  if (is_gui_active) {
    if (timer_elapsed(gui_timer) > 500) {
      unregister_code(KC_LGUI);
      is_gui_active = false;
    }
  }
}

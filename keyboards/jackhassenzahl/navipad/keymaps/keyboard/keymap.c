// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_S,    KC_D,    KC_L,    KC_C,    MO(1),
        KC_H,    KC_E,    KC_T,    KC_A,    KC_O,
        KC_W,    KC_U,    KC_N,    KC_M,    KC_I,
        MO(2),   TG(3),   KC_SPC,  KC_DOT,  SC_SENT
    ),

    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT(
        KC_K,    KC_P,    KC_B,    KC_V,    KC_CAPS,
        KC_Y,    KC_R,    KC_F,    KC_G,    KC_ESC,
        KC_J,    KC_X,    KC_Q,    KC_Z,    KC_QUOT,
        KC_TRNS, TG(4),   KC_BSPC, KC_COMM, KC_TRNS
    ),

    [3] = LAYOUT(
        KC_PEQL, KC_7,    KC_8,    KC_9,    MO(1),
        KC_DOT,  KC_4,    KC_5,    KC_6,    KC_PSLS,
        SC_SENT, KC_1,    KC_2,    KC_3,    KC_PAST,
        KC_NO,   TG(3),   KC_0,    KC_PPLS, KC_PMNS
    ),

    [4] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   MO(1),
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   TG(4),   KC_NO,   KC_NO,   KC_NO
    ),

};

const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [1] = { ENCODER_CCW_CW(KC_DOWN, KC_UP) },
    [2] = { ENCODER_CCW_CW(KC_NO,   KC_NO) },
    [3] = { ENCODER_CCW_CW(KC_NO,   KC_NO) },
    [4] = { ENCODER_CCW_CW(KC_NO,   KC_NO) }
};

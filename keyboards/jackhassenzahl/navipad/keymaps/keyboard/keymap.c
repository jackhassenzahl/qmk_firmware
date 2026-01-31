// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_E,    KC_T,    KC_A,    KC_O,    MO(1),
        KC_I,    KC_N,    KC_R,    KC_S,    KC_L,
        KC_H,    KC_D,    KC_U,    KC_C,    KC_M,
        MO(2),   KC_SPC,  KC_LSFT, KC_DOT,  KC_COMM
    ),

    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT(
        KC_B,    KC_F,    KC_G,    KC_J,    KC_NO,
        KC_K,    KC_P,    KC_W,    KC_V,    KC_X,
        KC_Q,    KC_Y,    KC_Z,    KC_SCLN, KC_COLN,
        KC_TRNS, KC_BSPC, KC_ENT,  KC_EXLM, KC_QUES
    ),

};

const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [1] = { ENCODER_CCW_CW(KC_UP,   KC_DOWN) },
    [2] = { ENCODER_CCW_CW(KC_NO,   KC_NO) },
};

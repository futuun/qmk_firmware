/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK_DH = 0,
    _NAV,
    _SYM,
    _FUNCTION,
    _MOUSE,
};


// Aliases for readability
#define DH       TO(_COLEMAK_DH)
#define NAV      TO(_NAV)
#define SYM      OSL(_SYM)
#define FKEYS    TO(_FUNCTION)
#define MOUSE    TO(_MOUSE)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT(
     KC_LGUI, KC_Q, KC_W,  KC_F  ,   KC_P ,   KC_B ,                                           KC_J,   KC_L ,  KC_U ,   KC_Y, KC_SCLN, KC_RGUI,
     KC_LSFT, KC_A, KC_R,  KC_S  ,   KC_T ,   KC_G ,                                           KC_M,   KC_N ,  KC_E ,   KC_I,   KC_O , KC_RSFT,
     KC_LALT, KC_Z, KC_X,  KC_C  ,   KC_D ,   KC_V ,   FKEYS, KC_SLEP, /**/ KC_LCTL,   FKEYS,  KC_K,   KC_H ,KC_COMM, KC_DOT, KC_SLSH, KC_RALT,
                          KC_LEFT,  KC_ENT,    SYM ,  KC_SPC,  KC_TAB, /**/  KC_DEL, KC_BSPC,   SYM, KC_ESC, KC_RGHT
    ),
    // [_SYM] = LAYOUT(
    //  KC_AMPR,   KC_AT, KC_HASH, KC_PERC, KC_BSLS, KC_EXLM,                                          KC_ASTR,   KC_7,   KC_8,   KC_9, KC_PLUS, KC_CIRC,
    //  KC_PIPE, KC_QUOT, KC_LPRN, KC_LCBR, KC_LBRC,  KC_GRV,                                           KC_EQL,   KC_4,   KC_5,   KC_6,    KC_0,  KC_DLR,
    //       DH, KC_DQUO, KC_RPRN, KC_RCBR, KC_RBRC, KC_TILD,      DH,      DH, /**/      DH,      DH, KC_UNDS,   KC_1,   KC_2,   KC_3, KC_MINS,      DH,
    //                                  DH,      DH,      DH,  KC_SPC,  KC_TAB, /**/  KC_DEL, KC_BSPC,      DH,       DH,      DH
    // ),
    [_SYM] = LAYOUT(
     KC_PIPE,    KC_7,    KC_5,    KC_3,    KC_1,    KC_9,                                             KC_8,    KC_0,    KC_2,    KC_4,    KC_6, KC_BSLS,
     KC_PLUS,  KC_EQL, KC_TILD, KC_LPRN, KC_LCBR, KC_LBRC,                                          KC_RBRC, KC_RCBR, KC_RPRN, KC_DQUO,  KC_GRV, KC_QUOT,
          DH, KC_AMPR, KC_PERC, KC_HASH, KC_EXLM, KC_UNDS,      DH,      DH, /**/      DH,      DH, KC_ASTR, KC_MINS,   KC_AT,  KC_DLR, KC_CIRC,      DH,
                                     DH,      DH,      DH,  KC_SPC,  KC_TAB, /**/  KC_DEL, KC_BSPC,      DH,      DH,      DH
    ),
    [_FUNCTION] = LAYOUT(
      RGB_MOD, KC_F9 ,  KC_F10,  KC_F11,  KC_F12,      DH,                                          KC_VOLU,      DH,   KC_UP,      DH,  KC_F20, RGB_SPI,
      RGB_TOG, KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_ESC,                                          KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT,      DH,      DH,
     RGB_RMOD, KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,      DH,      DH,      DH, /**/      DH,      DH, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT,  KC_F19, RGB_SPD,
                                     DH,      DH,      DH,  KC_SPC,  KC_TAB, /**/  KC_DEL, KC_BSPC,      DH,      DH,      DH
   ),
    [_NAV] = LAYOUT(
    _______, RGB_SPI, RGB_SPD, _______, _______, _______,                                           KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, _______,
    _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                           KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, _______,
    _______, RGB_M_P, RGB_SAD, RGB_HUD, RGB_VAD,RGB_RMOD,      DH,      DH, /**/      DH,      DH, KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, _______,
                                    DH,      DH,      DH,  KC_SPC,  KC_TAB, /**/  KC_DEL, KC_BSPC,       DH,      DH,      DH
    ),
    [_MOUSE] = LAYOUT(
      _______, _______, _______, KC_ACL2, KC_ACL1, KC_ACL0,                                     _______, _______, KC_MS_U, _______, _______, _______,
      _______,  KC_A  , _______,  KC_S  , KC_BTN1, KC_BTN2,                                     KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
      _______,  KC_Z  ,   KC_X ,  KC_C  ,   KC_D ,    KC_V, _______, _______, _______, _______, KC_WH_D, KC_WH_L, KC_WH_R, _______, _______, _______,
                                      DH, KC_RGUI, KC_LALT, KC_RCTL, _______, _______, _______,     SYM, KC_RSFT,      DH
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        // case _COLEMAK_DH:
        //     SEND_STRING(SS_TAP(X_F13));
        //     break;
        case _MOUSE:
            SEND_STRING(SS_TAP(X_F15));
            break;
        case _SYM:
            SEND_STRING(SS_TAP(X_F16));
            break;
        case _NAV:
            SEND_STRING(SS_TAP(X_F17));
            break;
        case _FUNCTION:
            SEND_STRING(SS_TAP(X_F18));
            break;
        default:
            SEND_STRING(SS_TAP(X_F13));
            break;
    }
    return state;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
  [_COLEMAK_DH]  = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_MOUSE]  = { ENCODER_CCW_CW(KC_MS_U, KC_MS_D), ENCODER_CCW_CW(KC_MS_L, KC_MS_R) },
  [_FUNCTION]  = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_SYM] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
  [_NAV] = { ENCODER_CCW_CW(C(KC_LEFT), C(KC_RGHT)), ENCODER_CCW_CW(C(S(KC_TAB)), C(KC_TAB)) }
};
#endif

// void toggle_raise_layer(void);

// // f13 = "DH",
// // f16 = "SYM",
// // f17 = "NAV",
// // f18 = "FKEYS",

// void toggle_raise_layer() {
//   if (IS_LAYER_ON(_RAISE)) {
//     // turn off the layer
//     layer_off(_RAISE);

//     // send f18
//     SEND_STRING(SS_TAP(X_F18));
//   } else {
//     // turn layer on
//     layer_on(_RAISE);

//     // send f17
//     SEND_STRING(SS_TAP(X_F17));
//   }
// }

// enum custom_keycodes {
//   TOGGLE_RAISE = SAFE_RANGE
// };

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case TOGGLE_RAISE:
//       if (record->event.pressed) toggle_raise_layer();

//       return false;

//     default:
//       // pass all other keypresses through
//       return true;
//   }
// }

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */

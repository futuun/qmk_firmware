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
};


// Aliases for readability
#define DH       TO(_COLEMAK_DH)
#define NAV      TO(_NAV)
#define SYM      TO(_SYM)
#define FKEYS    TO(_FUNCTION)

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
     _______, KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                         KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, _______,
     _______, KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                         KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , _______,
     _______, KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , _______, _______, _______, _______,     KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, _______,
                               _______, KC_RGUI, ALT_ENT, KC_SPC ,  KC_TAB,  KC_DEL, KC_BSPC,      SYM, KC_RSFT, _______
    ),
    [_SYM] = LAYOUT(
     _______,   KC_AT, KC_HASH, KC_PERC, KC_BSLS, KC_EXLM,                                     KC_ASTR,   KC_7,   KC_8,   KC_9, KC_PLUS, _______,
     _______, KC_QUOT, KC_LPRN, KC_LCBR, KC_LBRC,  KC_GRV,                                      KC_EQL,   KC_4,   KC_5,   KC_6,    KC_0, _______,
     _______, KC_DQUO, KC_RPRN, KC_RCBR, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_SLSH,   KC_1,   KC_2,   KC_3, KC_MINS, _______,
                                _______, KC_UNDS, KC_PIPE, CTL_ESC,     NAV,   FKEYS, _______,      DH, KC_DLR, _______
    ),
    [_FUNCTION] = LAYOUT(
     _______, KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     RGB_SPI, RGB_SPD, _______, _______, _______, _______,
     _______, KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______,
     _______, KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, RGB_M_P, RGB_SAD, RGB_HUD, RGB_VAD,RGB_RMOD, _______,
                               _______,      DH,     SYM,     NAV, _______, _______,     NAV,     SYM,      DH, _______
   ),
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, _______,
                                 _______,      DH,     SYM,   FKEYS, _______, _______,   FKEYS,     SYM,      DH, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        // case _COLEMAK_DH:
        //     SEND_STRING(SS_TAP(X_F13));
        //     break;
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

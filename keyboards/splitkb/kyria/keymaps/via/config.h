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

#pragma once

#undef MATRIX_ROW_PINS
#undef MATRIX_ROW_PINS_RIGHT
#undef MATRIX_COL_PINS
#undef MATRIX_COL_PINS_RIGHT
#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B
#undef ENCODERS_PAD_A_RIGHT
#undef ENCODERS_PAD_B_RIGHT
#undef SOFT_SERIAL_PIN
#undef RGB_DI_PIN
#undef SPLIT_HAND_MATRIX_GRID
#define MATRIX_ROW_PINS {GP27, GP26, GP22, GP20}
#define MATRIX_ROW_PINS_RIGHT {GP4, GP5, GP6, GP7}
#define MATRIX_COL_PINS {GP23, GP21, GP9, GP8, GP7, GP6, GP5, GP4}
#define MATRIX_COL_PINS_RIGHT {GP8, GP9, GP21, GP23, GP20, GP22, GP26, GP27}
#define ENCODERS_PAD_A {GP29}
#define ENCODERS_PAD_B {GP28}
#define ENCODERS_PAD_A_RIGHT {GP28}
#define ENCODERS_PAD_B_RIGHT {GP29}
#define SERIAL_USART_TX_PIN GP1
#define RGB_DI_PIN GP0
#define SPLIT_HAND_MATRIX_GRID GP7, GP20
#define BATTERY_LEVEL_PIN GP13

#define LAYER_STATE_8BIT
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define IGNORE_MOD_TAP_INTERRUPT

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT

#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 150
#endif

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U // Specify a optional status led which

#define CIRQUE_PINNACLE_DIAMETER_MM 35
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE // Enable cursor glide
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define POINTING_DEVICE_ROTATION_270


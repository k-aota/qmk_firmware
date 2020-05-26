/* Copyright 2019 k-aota
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
   * ,--------fn_E--------||-fn_D-.              |----------------------fn_A----------------------||-fn_B-.
   * | SW0  | SW1  | SW2  || SW3  |              | SW4  | SW5  | SW6  | SW7  | SW8  | SW9  |SW010 ||SW011 |
   * |------+------+------||------+              |------+------+------+------+------+------+------||------|
   * | SW0  | SW1  | SW2  || SW3  |              | SW4  | SW5  | SW6  | SW7  | SW8  | SW9  |SW010 ||SW011 |
   * |------+------+------||------+              |------+------+------+------+------+------+------||------|
   * | SW0  | SW1  | SW2  || SW3  |              | SW4  | SW5  | SW6  | SW7  | SW8  | SW9  |SW010 ||SW011 |
   * |------+------+------||======+-fn_C-+------||------+------+------+------+------+------+------||------|
   * | SW0  | SW1  | SW2  || SW3                || SW4  | SW5  | SW6  | SW7  | SW8  | SW9  |SW010 ||SW011 |
   * `------+------+------||------+------+------||------+------+------+------+------+------+------||------'
   */
  [0] = LAYOUT( \
    KC_0,  KC_1,  KC_2,    KC_3,                KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,    KC_1,\
    KC_0,  KC_1,  KC_2,    KC_3,                KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,    KC_1,\
    KC_0,  KC_1,  KC_2,    KC_3,                KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,    KC_1,\
    KC_0,  KC_1,  KC_2,    KC_3,                KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,    KC_1\
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-------------------------------------------------------.
   * |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  Del |
   * |------+------+------+------+------+------+------+------|
   * |   6  |   7  |   8  |   9  |   0  |   -  |   =  |  Bc  |
   * |------+------+------+------+------+------+------+------|
   * |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |   \  |
   * |------+------+------+------+------+------+------+------'
   * |   H  |   J  |   K  |   L  |   ;  |   '  |  Ent |
   * |------+------+------+------+------+------+------+------.
   * |   B  |   N  |   M  |   ,  |   .  |   /  |   ↑  | Shft |
   * |------+------+------+------+------+------+------+------'
   * |Space |  []  | Alt  | Ctrl | 　←  |　　↓ |　　→　|
   * `------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
      KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL, \
      KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, \
      KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, \
      KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,   KC_ESC,\
      KC_B,     KC_N,     KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_UP,    KC_RSFT, \
      KC_SPC,   KC_APP,   KC_RALT, KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_ESC\
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

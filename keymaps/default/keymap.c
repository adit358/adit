/* Copyright 2020 bt66tech
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

// Defines names for use in layer keycodes and the keymap

enum layer_names {
    _BASE,
    _FN,
    _FN1
};
enum custom_keycodes {
    END_I = SAFE_RANGE,
    END_II,
    END_III,
    BREAK,
    TRANSPOSE_UP,
    TRANSPOSE_DO,
    TEMPO_UP,
    TEMPO_DO,  
    
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case END_I:
        if (record->event.pressed) {
            // when keycode END_I is pressed
	   SEND_STRING(SS_LCTL("F10"));
        } else {
            // when keycode END_I is released
        }
        break;
        
        case END_II:
        if (record->event.pressed) {
            // when keycode END_II is pressed
	   SEND_STRING(SS_LCTL("F11"));
        } else {
            // when keycode END_II is released
        }
        break;
    }
    return true;
    
    case END_III:
        if (record->event.pressed) {
            // when keycode END_III is pressed
	   SEND_STRING(SS_LCTL("F12"));
        } else {
            // when keycode END_III is released
        }
        break;
    }
    return true;
    
    case BREAK:
        if (record->event.pressed) {
            // when keycode BREAK is pressed
	   SEND_STRING(SS_LCTL("F9"));
        } else {
            // when keycode BREAK is released
        }
        break;
    }
    return true;
    
    case TRANSPOSE_UP:
        if (record->event.pressed) {
            // when keycode TRANSPOSE_UP is pressed
	   SEND_STRING(SS_LCTL("+"));
        } else {
            // when keycode TRANSPOSE_UP is released
        }
        break;
    }
    return true;
    
    case TRANSPOSE_DO:
        if (record->event.pressed) {
            // when keycode TRANSPOSE_DO is pressed
	   SEND_STRING(SS_LCTL("-"));
        } else {
            // when keycode TRANSPOSE_DO is released
        }
        break;
    }
    return true;
    
    case TEMPO_UP:
        if (record->event.pressed) {
            // when keycode TEMPO_UP is pressed
	   SEND_STRING(SS_LSFT("+"));
        } else {
            // when keycode BREAK is released
        }
        break;
    }
    return true;
    
    case TEMPO_DO:
        if (record->event.pressed) {
            // when keycode TEMPO_DO is pressed
	   SEND_STRING(SS_LSFT("-"));
        } else {
            // when keycode TEMPO_DO is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
[_BASE] = LAYOUT_60_ansi(
    END_I, END_II,    END_III,    BREAK,    TRANSPOSE_UP,    TRANSPOSE_DO,    TEMPO_UP,                 TEMPO_DO,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC, 
    KC_TAB,  KC_SPC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   		KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10, KC_F11,  KC_F12, 
    KC_PLUS, KC_MINS,    KC_BSPC,    KC_HOME,    KC_VOLU,    KC_VOLD,    KC_DEL,                 KC_P0,    KC_P1,    KC_P3,    KC_P4, KC_P5,           KC_P6,  
    KC_P7, KC_P8,    KC_P9,    _______,    _______,    _______,    _______,                 	 _______,    _______, _______,  _______,           _______, 
    KC_LALT, _______, _______,                            KC_LEFT,                                          KC_DOWN, KC_UP, KC_RGHT,  MO(_FN)
  ),

  [_FN] = LAYOUT_60_ansi(
    	  KC_GRV,      KC_F1,       KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,    KC_F7,   KC_F8,    KC_F9,     KC_F10,  KC_F11,  KC_F12, 	KC_DEL, 
    KC_MS_ACCEL0, KC_MS_BTN1,    KC_MS_UP, KC_MS_BTN2, 	 _______,    _______, 	 _______,  _______, _______,  _______, KC_PSCREEN, _______, _______, _______, 
    KC_MS_ACCEL1, KC_MS_LEFT,  KC_MS_DOWN,KC_MS_RIGHT, 	 _______,    _______,	 _______,  _______, _______,  _______,    _______, _______,          _______, 
    KC_MS_ACCEL2,    _______,     _______,    _______,    _______,    _______,    _______,  _______, _______,  _______,              KC_UP,          MO(_FN1), 
    	 _______,    _______,     _______,                                       _______,                                 KC_LEFT, KC_DOWN, KC_RGHT, _______
  ),

[_FN1] = LAYOUT_60_ansi(
    BL_TOGG, BL_STEP,   BL_ON,   BL_OFF,   BL_INC,   BL_DEC,   BL_BRTG,   _______,   _______,   _______,   _______,  BL_DEC,  BL_INC,   _______, 
     _______, _______,  _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, 
     _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______, _______,          _______, 
     _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, 
    _______,  _______, _______,                            _______,                            _______,  _______, _______, _______
  )

};


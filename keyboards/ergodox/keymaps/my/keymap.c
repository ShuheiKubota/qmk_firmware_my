#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |  `~  |           |  ^~  |   6  |   7  |   8  |   9  |   0  |   -=   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  `~  |   Y  |   U  |   I  |   O  |   P  |   @`   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Caps  |   A  |   S  |   D  | F/L1 |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Tab  |           | BSpc |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl|  '"  |AltShf| LGUI | RAlt |                                       |   [  |   ]  |  \|  |  \_  | \/ _ |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | App  | Home |       | PgUp | Reset |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 | Space| Space| End  |       | PgDw |       |      |
 *                                 | /LSft| /L1  |------|       |------| RCtrl | Enter|
 *                                 |      |      | Enter|       | Alt  |       |      |
 *                                 `--------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,    KC_1,         KC_2,     KC_3,     KC_4,           KC_5,  KC_GRAVE,
        KC_TAB,    KC_Q,         KC_W,     KC_E,     KC_R,           KC_T,  TG(SYMB),
        KC_CAPS,   KC_A,         KC_S,     KC_D,     LT(SYMB,KC_F),  KC_G,
        KC_LSFT,   CTL_T(KC_Z),  KC_X,     KC_C,     KC_V,           KC_B,  KC_TAB,
         KC_LCTL,  KC_TRNS,      KC_TRNS,  KC_LGUI,  KC_RALT,

                                                               ALT_T(KC_APP),    KC_HOME,
                                                                                 KC_END,
                                               SFT_T(KC_SPC),  LT(SYMB,KC_SPC),  KC_ENTER,

        // right hand
             KC_EQL,    KC_6,  KC_7,     KC_8,     KC_9,    KC_0,              KC_MINS,
             KC_GRAVE,  KC_Y,  KC_U,     KC_I,     KC_O,    KC_P,              KC_LBRC,
                        KC_H,  KC_J,     KC_K,     KC_L,    LT(MDIA,KC_SCLN),  GUI_T(KC_QUOT),
             KC_BSPC,   KC_N,  KC_M,     KC_COMM,  KC_DOT,  CTL_T(KC_SLSH),    KC_RSFT,
                               KC_RBRC,  KC_BSLS,  KC_NUBS, KC_RO,             KC_RO,

             KC_PGUP,    RESET,
             KC_PGDOWN,
             KC_RALT,    KC_RCTL, KC_ENTER
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |C-Rgt | End  |      |      |  L2  |           |      |      |      |      |      |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | LCtl | LSft | ΦL1 |      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           | Del  |------+------+------+------+------+--------|
 * |        |      |      |      |      |C-Lft |      |           |      | Home | PgDw | PgUp | End  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Alt~ |      |------|       |------|      | Del  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       M(0),   KC_F1,    KC_F2,           KC_F3,    KC_F4,    KC_F5,          KC_NO,
       KC_NO,  KC_NO,    RCTL(KC_RIGHT),  KC_END,   KC_NO,    KC_NO,          TG(MDIA),
       KC_NO,  KC_HOME,  KC_LCTL,         KC_LSFT,  KC_TRNS,  KC_TRNS,
       KC_NO,  KC_NO,    KC_NO,           KC_NO,    KC_NO,    RCTL(KC_LEFT),  KC_TRNS,
       KC_NO,  KC_NO,    KC_NO,           KC_NO,    KC_NO,

                                              KC_TRNS,  KC_TRNS,
                                                        KC_TRNS,
                             LALT(KC_GRAVE),  KC_TRNS,  KC_TRNS,

       // right hand
       KC_TRNS,  KC_F6,    KC_F7,      KC_F8,    KC_F9,     KC_F10,  KC_F11,
       KC_TRNS,  KC_NO,    KC_NO,      KC_NO,    KC_NO,     KC_NO,   KC_F12,
                 KC_LEFT,  KC_DOWN,    KC_UP,    KC_RIGHT,  KC_NO,   KC_TRNS,
       KC_DEL,   KC_HOME,  KC_PGDOWN,  KC_PGUP,  KC_END,    KC_NO,   KC_TRNS,
                           KC_NO,      KC_NO,    KC_NO,     KC_NO,   KC_TRNS,

       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_TRNS,   KC_DEL
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |  L0  |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|      |
 *                                 | Lclk | Rclk |------|       |------| Back |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MS_U,  KC_TRNS,  KC_TRNS,  TG(BASE),
       KC_TRNS,  KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BTN1,  KC_BTN2,
                                            KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,
                                  KC_BTN1,  KC_BTN2,  KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPLY,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MNXT,  KC_TRNS,  KC_TRNS,
                           KC_VOLU,  KC_VOLD,  KC_MUTE,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_WBAK,  KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}
// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

void light_led_on_pressed(void) {

    ergodox_right_led_3_off();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
      for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        if (matrix_is_on(row, col)) {

          action_t action = layer_switch_get_action((keypos_t){ .row = row, .col = col });

          if(IS_MOD(action.code)) {
            ergodox_right_led_3_on();
            break;
          }
        }
      }
    }
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case MDIA:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

    light_led_on_pressed();
}

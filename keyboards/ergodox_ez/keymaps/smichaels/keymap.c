#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers
#define NAVI 3 // navigation

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD
};

// Notes:
// - Would like double-tap shift to be caps lock
// - Need a way to permanently activate the numpad (separate number layer?)
// - Minus/underscore gets typed a lot. Current key position should be more comfortable.
// - OSM doesn't work on top of OSL
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(
  // left fingers
  KC_TRANSPARENT,     KC_1,       KC_2,     KC_3,      KC_4,    KC_5, KC_TRANSPARENT,
  KC_TAB,             KC_QUOTE,   KC_COMMA, KC_DOT,    KC_P,    KC_Y, OSM(MOD_LCTL),
  OSM(MOD_LSFT),      KC_A,       KC_O,     KC_E,      KC_U,    KC_I,
  KC_ESCAPE,          KC_SCOLON,  KC_Q,     KC_J,      KC_K,    KC_X, OSM(MOD_LALT),
  TG(NUMB),           KC_END,     KC_HOME,  KC_PGDOWN, KC_PGUP,

                                            // left thumb cluster
                                                      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                      KC_TRANSPARENT,
                                            KC_SPACE, KC_BSPACE,      KC_TRANSPARENT,

  // right fingers
  KC_TRANSPARENT, KC_6,     KC_7,     KC_8,   KC_9,     KC_0,   KC_TRANSPARENT,
  OSM(MOD_RGUI),  KC_F,     KC_G,     KC_C,   KC_R,     KC_L,   OSL(SYMB),
                  KC_D,     KC_H,     KC_T,   KC_N,     KC_S,   OSM(MOD_RSFT),
  OSM(MOD_HYPR),  KC_B,     KC_M,     KC_W,   KC_V,     KC_Z,   KC_MINUS,
                  KC_LEFT,  KC_DOWN,  KC_UP,  KC_RIGHT, TG(NAVI),

  // right thumb cluster
  KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT,
  KC_TRANSPARENT, KC_DELETE,      KC_ENTER
),
[SYMB] = LAYOUT_ergodox(
  // left fingers
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_BSLASH,      KC_SLASH,       KC_QUES,        KC_EXLM,        KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_LPRN,        KC_RPRN,        KC_PIPE,
  KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

                                                                  // left thumb cluster
                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT,
                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

  // right fingers
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_EQUAL,       KC_UNDS,        KC_KP_ASTERISK, KC_CIRC,        KC_TRANSPARENT,
  KC_TILD,        KC_KP_PLUS,     KC_MINUS,       KC_AMPR,        KC_PERC,        KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_GRAVE,       KC_DLR,         KC_HASH,        KC_AT,          KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

  // right thumb cluster
  KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),
[NUMB] = LAYOUT_ergodox(
  // left hand
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

                                                                  // left thumb cluster
                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT,
                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

  // right fingers
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT,
  KC_0,           KC_4,           KC_5,           KC_6,           KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

  // right thumb cluster
  KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),
[NAVI] = LAYOUT_ergodox(
  // left hand
  RESET,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PWR,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PGDOWN,      KC_PGUP,        KC_TRANSPARENT, KC_TRANSPARENT,
                  KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_END,         KC_HOME,        KC_TRANSPARENT, KC_TRANSPARENT,
                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

                                                                                        // left thumb cluster
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,
                                                                                        KC_ENTER,       KC_MENU,        KC_TRANSPARENT,
  // right fingers
  KC_SLEP,              KC_TRANSPARENT,   KC_TRANSPARENT,         KC_TRANSPARENT,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT,       KC_MS_BTN4,       KC_MS_ACCEL0,           KC_MS_ACCEL1,         KC_MS_ACCEL2,   KC_MS_BTN5,     KC_TRANSPARENT,
  KC_MS_BTN3,           KC_MS_LEFT,       KC_MS_DOWN,             KC_MS_UP,             KC_MS_RIGHT,    KC_TRANSPARENT,
  KC_TRANSPARENT,       KC_MEDIA_STOP,    KC_MS_WH_LEFT,          KC_MS_WH_DOWN,        KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT,
  KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_REWIND,  KC_MEDIA_FAST_FORWARD,  KC_MEDIA_PREV_TRACK,  KC_TRANSPARENT,

  // right thumb cluster
  KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT,
  KC_TRANSPARENT, KC_MS_BTN2, KC_MS_BTN1
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

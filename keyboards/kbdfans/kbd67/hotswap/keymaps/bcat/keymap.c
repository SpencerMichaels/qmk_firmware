#include QMK_KEYBOARD_H

enum layer {
    LAYER_DEFAULT,
    LAYER_FUNCTION,
};

/* Switch to function layer when held. */
#define LY_FUNC MO(LAYER_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default layer: http://www.keyboard-layout-editor.com/#/gists/dd675b40cc4df2c7bb78847ac29f5988 */
    [LAYER_DEFAULT] = LAYOUT(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_GRV,   KC_HOME,  \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,  KC_PGUP,            \
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGDN,                      \
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,                       \
        KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,   KC_RALT,  LY_FUNC,  KC_LEFT,  KC_DOWN,  KC_RGHT                                                                         \
    ),

    /* Function layer: http://www.keyboard-layout-editor.com/#/gists/f29128427f674c43777f045e363d1b44 */
    [LAYER_FUNCTION] = LAYOUT(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,   _______,  \
        _______,  KC_MPLY,  KC_VOLU,  KC_MSTP,  _______,  _______,  EEP_RST,  _______,  KC_PSCR,  KC_SLCK,  KC_PAUS,  _______,  _______,  _______,  _______,            \
        KC_CAPS,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      \
        _______,  _______,  KC_MUTE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      \
        _______,  _______,  _______,  _______,  KC_APP,   _______,  _______,  _______,  _______                                                                         \
    ),
};

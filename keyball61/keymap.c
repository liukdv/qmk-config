#include QMK_KEYBOARD_H

enum layer_number {
    _COLEMAK = 0,
    _QWERTY,
    _GAMING,
    _EXTEND,
    _EXTEND_QW,
    _EXTEND_GM,
    _MOUSE,
    _NUMPAD,
};

enum custom_keycodes {
    MOUSE_OFF = SAFE_RANGE,
};

// The first three keys on the bottom row are additional Keyball61 keys:
// unused, menu, and layout selection.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_right_ball(
        KC_ESC,  KC_1,      KC_2,         KC_3,    KC_4,        KC_5,                                        KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL,
        KC_TAB,  KC_Q,      KC_W,         KC_F,    KC_P,        KC_G,                                        KC_J,     KC_L,    KC_U,    KC_Y,    KC_SCLN,   KC_MINS,
        KC_LSFT, KC_A,      KC_R,         KC_S,    KC_T,        KC_D,                                        KC_H,     KC_N,    KC_E,    KC_I,    KC_O,      KC_RSFT,
        KC_LCTL, KC_Z,      KC_X,         KC_C,    KC_V,        KC_B,           KC_RALT,            KC_LBRC, KC_K,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RCTL,
        KC_LALT, KC_APP,    DF(_QWERTY),  KC_LGUI, MO(_NUMPAD), MO(_EXTEND),    KC_SPC,             KC_BSPC, KC_ENT,                              KC_BSLS,   KC_QUOT
    ),

    [_QWERTY] = LAYOUT_right_ball(
        KC_ESC,  KC_1,      KC_2,         KC_3,    KC_4,        KC_5,                                        KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL,
        KC_TAB,  KC_Q,      KC_W,         KC_E,    KC_R,        KC_T,                                        KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,      KC_MINS,
        KC_LSFT, KC_A,      KC_S,         KC_D,    KC_F,        KC_G,                                        KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_RSFT,
        KC_LCTL, KC_Z,      KC_X,         KC_C,    KC_V,        KC_B,           KC_RALT,            KC_LBRC, KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RCTL,
        KC_LALT, KC_APP,    DF(_COLEMAK), KC_LGUI, MO(_NUMPAD), MO(_EXTEND_QW), KC_SPC,             KC_BSPC, KC_ENT,                              KC_BSLS,   KC_QUOT
    ),

    [_GAMING] = LAYOUT_right_ball(
        KC_GRV,  KC_1,      KC_2,         KC_3,    KC_4,        KC_5,                                        KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL,
        KC_ESC,  KC_Q,      KC_W,         KC_E,    KC_R,        KC_T,                                        KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,      KC_MINS,
        KC_TAB,  KC_A,      KC_S,         KC_D,    KC_F,        KC_G,                                        KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_RSFT,
        KC_LSFT, KC_Z,      KC_X,         KC_C,    KC_V,        KC_B,           KC_RALT,            KC_LBRC, KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RCTL,
        KC_LCTL, KC_APP,    DF(_QWERTY),  KC_LALT, KC_ENT,      KC_SPC,         MO(_EXTEND_GM),     KC_BSPC, KC_ENT,                              KC_BSLS,   KC_QUOT
    ),

    [_EXTEND] = LAYOUT_right_ball(
        KC_F12,  KC_F1,     KC_F2,        KC_F3,   KC_F4,       KC_F5,                                       KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,
        _______, KC_ESC,    C(S(KC_Z)),   KC_WBAK, KC_WFWD,     S(KC_TAB),                                   KC_PGUP,  KC_HOME, KC_UP,   KC_END,  KC_BSPC,   KC_PSCR,
        _______, KC_LALT,   KC_LCTL,      KC_LSFT, KC_RGUI,     KC_TAB,                                      KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,    _______,
        _______, C(KC_Z),   KC_BSPC,      KC_ESC,  KC_DEL,      KC_ENT,         _______,            KC_RBRC, KC_GRV ,  KC_VOLD, KC_MPLY, KC_VOLU, KC_QUOT,   _______,
        _______, _______,   _______,      _______, _______,     _______,        _______,            _______, _______,                             KC_MUTE,   KC_TILDE
    ),

    [_EXTEND_QW] = LAYOUT_right_ball(
        KC_F12,  KC_F1,     KC_F2,        KC_F3,   KC_F4,       KC_F5,                                       KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,
        _______, KC_ESC,    C(S(KC_Z)),   KC_WBAK, KC_WFWD,     S(KC_TAB),                                   KC_PGUP,  KC_HOME, KC_UP,   KC_END,  KC_BSPC,   KC_PSCR,
        _______, KC_LALT,   KC_LCTL,      KC_LSFT, KC_RGUI,     KC_TAB,                                      KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,    _______,
        _______, C(KC_Z),   KC_BSPC,      KC_ESC,  KC_DEL,      KC_ENT,         _______,            KC_RBRC, KC_GRV ,  KC_VOLD, KC_MPLY, KC_VOLU, KC_QUOT,   _______,
        _______, _______,   DF(_GAMING),  _______, _______,     _______,        _______,            _______, _______,                             KC_MUTE,   KC_TILDE
    ),

    [_EXTEND_GM] = LAYOUT_right_ball(
        KC_F12,  KC_F1,     KC_F2,        KC_F3,   KC_F4,       KC_F5,                                       KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,
        _______, KC_ESC,    C(S(KC_Z)),   KC_WBAK, KC_WFWD,     S(KC_TAB),                                   KC_PGUP,  KC_HOME, KC_UP,   KC_END,  KC_BSPC,   KC_PSCR,
        _______, KC_LALT,   KC_LCTL,      KC_LSFT, KC_RGUI,     KC_TAB,                                      KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,    _______,
        _______, C(KC_Z),   KC_BSPC,      KC_ESC,  KC_DEL,      KC_ENT,         _______,            KC_RBRC, KC_GRV ,  KC_VOLD, KC_MPLY, KC_VOLU, KC_QUOT,   _______,
        _______, _______,   DF(_QWERTY),  _______, _______,     _______,        _______,            _______, _______,                             KC_MUTE,   KC_TILDE
    ),

    [_MOUSE] = LAYOUT_right_ball(
        _______, _______,   _______,      _______, _______,     _______,                                     _______,  _______, _______, _______, _______,   _______,
        _______, _______,   _______,      KC_WBAK, KC_WFWD,     _______,                                     _______,  KC_WFWD, KC_WBAK, _______, _______,   _______,
        _______, MOUSE_OFF, KC_ESC ,      MS_BTN2, MS_BTN1,     _______,                                     _______,  MS_BTN1, MS_BTN2, KC_ESC,  MOUSE_OFF, _______,
        _______, _______,   _______,      MS_BTN3, SCRL_MO,     _______,        _______,            _______, _______,  SCRL_MO, MS_BTN3, _______, _______,   _______,
        _______, _______,   _______,      _______, _______,     _______,        _______,            _______, _______,                             _______,   _______
    ),

    [_NUMPAD] = LAYOUT_right_ball(
        _______, _______,   _______,      _______, _______,     _______,                                     _______,  _______, _______, _______, _______,   _______,
        _______, C(KC_Q),   C(KC_W),      _______, _______,     UG_NEXT,                                     KC_0,     KC_1,    KC_2,    KC_3,    KC_ASTR,   KC_ESC ,
        _______, C(KC_A),   _______,      _______, _______,     UG_PREV,                                     KC_DOT,   KC_4,    KC_5,    KC_6,    KC_MINS,   _______,
        _______, C(KC_Z),   C(KC_X),      C(KC_C), C(KC_V),     UG_TOGG,        _______,            KC_EQL,  KC_PLUS,  KC_7,    KC_8,    KC_9,    KC_SLSH,   _______,
        _______, _______,   _______,      _______, _______,     _______,        _______,            _______, _______,                             _______,   _______
    ),

};

#ifdef OLED_ENABLE

#    include <stdio.h>
#    include "lib/oledkit/oledkit.h"

static uint32_t press_count;
static char     keylogs[21];
static uint8_t  keylogs_index;

static const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '
};

static void add_keylog(uint16_t keycode) {
    char name = keycode < 60 ? code_to_name[keycode] : ' ';

    if (keylogs_index == sizeof(keylogs) - 1) {
        keylogs_index = 0;
        memset(keylogs, ' ', sizeof(keylogs) - 1);
    }

    keylogs[keylogs_index++] = name;
}

static void oled_print_layer(void) {
    uint8_t overlay = get_highest_layer(layer_state);
    uint8_t base    = get_highest_layer(default_layer_state);

    oled_write_P(PSTR("Layer: "), false);

    switch (overlay) {
        case _EXTEND:
            oled_write_ln_P(PSTR("(cmk) EXTEND"), false);
            return;
        case _EXTEND_QW:
            oled_write_ln_P(PSTR("(qw) EXTEND"), false);
            return;
        case _EXTEND_GM:
            oled_write_ln_P(PSTR("(gm) EXTEND"), false);
            return;
        case _MOUSE:
            oled_write_ln_P(PSTR("MOUSE"), false);
            return;
        case _NUMPAD:
            oled_write_ln_P(PSTR("NUMPAD"), false);
            return;
    }

    switch (base) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("COLEMAK"), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("GAMING"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UNDEF"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? rotation : OLED_ROTATION_180;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        char buffer[16];

        oled_write_ln(keylogs, false);

        snprintf(buffer, sizeof(buffer), "wpm: %3u", get_current_wpm());
        oled_write_ln(buffer, false);

        snprintf(buffer, sizeof(buffer), "count: %lu", (unsigned long)press_count);
        oled_write_ln(buffer, false);

        oled_print_layer();
    } else {
        oledkit_render_logo_user();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

void keyboard_post_init_user(void) {
    set_auto_mouse_enable(true);
    set_auto_mouse_timeout(AUTO_MOUSE_TIME);
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t *record) {
    (void)record;
    return keycode == KC_ESC && layer_state_is(_MOUSE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        press_count++;
        add_keylog(keycode);
    }
#endif
    if (keycode == MOUSE_OFF) {
        auto_mouse_reset_trigger(record->event.pressed);
        return false;
    }
    return true;
}

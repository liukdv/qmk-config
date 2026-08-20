#include QMK_KEYBOARD_H

enum layer_number {
    _COLEMAK = 0,
    _QWERTY,
    _EXTEND,
    _NUMPAD,
    _FN,
    _MOUSE,
};

enum custom_keycodes {
    MOUSE_OFF = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_right_ball(
        KC_ESC,  KC_1,      KC_2,         KC_3,    KC_4,        KC_5,                                 KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL,
        KC_TAB,  KC_Q,      KC_W,         KC_F,    KC_P,        KC_G,                                 KC_J,     KC_L,    KC_U,    KC_Y,    KC_SCLN,   KC_MINS,
        KC_LSFT, KC_A,      KC_R,         KC_S,    KC_T,        KC_D,                                 KC_H,     KC_N,    KC_E,    KC_I,    KC_O,      KC_RSFT,
        KC_LCTL, KC_Z,      KC_X,         KC_C,    KC_V,        KC_B,    KC_RALT,            KC_LBRC, KC_K,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RCTL,
        MO(_FN), KC_APP, DF(_QWERTY),  KC_LGUI, KC_LALT, MO(_EXTEND),    KC_SPC,             KC_BSPC, MO(_NUMPAD),                         KC_BSLS,   KC_QUOT
    ),

    [_QWERTY] = LAYOUT_right_ball(
        KC_ESC,  KC_1,      KC_2,         KC_3,    KC_4,        KC_5,                                 KC_6,     KC_7,    KC_8,    KC_9,    KC_0,      KC_EQL,
        KC_TAB,  KC_Q,      KC_W,         KC_E,    KC_R,        KC_T,                                 KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,      KC_MINS,
        KC_LSFT, KC_A,      KC_S,         KC_D,    KC_F,        KC_G,                                 KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_RSFT,
        KC_LCTL, KC_Z,      KC_X,         KC_C,    KC_V,        KC_B,    KC_RALT,            KC_LBRC, KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RCTL,
        MO(_FN), KC_APP, DF(_COLEMAK), KC_LGUI, KC_LALT, MO(_EXTEND),    KC_SPC,             KC_BSPC, MO(_NUMPAD),                         KC_BSLS,   KC_QUOT
    ),

    [_EXTEND] = LAYOUT_right_ball(
        KC_F12,  KC_F1,     KC_F2,        KC_F3,   KC_F4,       KC_F5,                                 KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,
        _______, KC_ESC,    C(S(KC_Z)),   KC_WBAK, KC_WFWD,     S(KC_TAB),                             KC_PGUP,  KC_HOME, KC_UP,   KC_END,  KC_DEL,    KC_PSCR,
        _______, KC_LALT,   KC_LCTL,      KC_LSFT, KC_RGUI,     KC_TAB,                                KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,   _______,
        _______, C(KC_Z),   KC_BSPC,      KC_ESC,  KC_DEL,      KC_ENT,   _______,            KC_RBRC, KC_QUOT,  KC_VOLD, KC_MPLY, KC_VOLU, KC_BSLS,   _______,
        _______, _______,   _______,      _______, _______,     _______,  _______,            KC_SPC,  KC_ENT,                             KC_MUTE,   KC_TILDE
    ),

    [_NUMPAD] = LAYOUT_right_ball(
        _______, _______,   _______,      _______, _______,     _______,                                _______,  _______, _______, _______, _______,   _______,
        _______, C(KC_Q),   C(KC_W),      _______,A(KC_F4),     _______,                                KC_ASTR,  KC_7,    KC_8,    KC_9,    KC_PLUS,   KC_ESC ,
        _______, C(KC_A),   _______,      _______, _______,     _______,                                KC_0,     KC_4,    KC_5,    KC_6,    KC_MINS,   _______,
        _______, C(KC_Z),   C(KC_X),      C(KC_C), C(KC_V),     _______,   _______,            KC_EQL,  KC_DOT,   KC_1,    KC_2,    KC_3,    KC_SLSH,   _______,
        _______, _______,   _______,      _______, _______,     _______,   _______,            _______, _______,                             _______,   _______
    ),

    [_FN] = LAYOUT_right_ball(
        KC_F12,  KC_F1,     KC_F2,        KC_F3,   KC_F4,       KC_F5,                                  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,
        _______, CPI_D1K,   CPI_D100,    CPI_I100, CPI_I1K,     _______,                                KC_F11,   KC_F7,   KC_F8,   KC_F9,   KC_F12,    _______,
        _______, UG_TOGG,   UG_PREV,      UG_NEXT, _______,     _______,                                KC_F10,   KC_F4,   KC_F5,   KC_F6,   _______,   _______,
        _______, _______,   _______,      _______, _______,     _______,   _______,            _______, _______,  KC_F1,   KC_F2,   KC_F3,   _______,   _______,
        _______, _______,   _______,      _______, _______,     _______,   _______,            _______, _______,                             _______,   _______
    ),

    [_MOUSE] = LAYOUT_right_ball(
        _______, _______,   _______,      _______, _______,     _______,                                _______,  _______, _______, _______, _______,   _______,
        _______, _______,   _______,      MS_BTN4, MS_BTN5,     _______,                                _______,  MS_BTN5, MS_BTN4, _______, _______,   _______,
        _______, MOUSE_OFF, MS_BTN3,      MS_BTN2, MS_BTN1,     _______,                                _______,  MS_BTN1, MS_BTN2, MS_BTN3, MOUSE_OFF, _______,
        _______, _______,   _______,      KC_ESC,  SCRL_MO,     SCRL_TO,   _______,            _______, SCRL_TO,  SCRL_MO, KC_ESC,  _______, _______,   _______,
        _______, _______,   _______,      _______, _______,     _______,   _______,            _______, _______,                             _______,   _______
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
            oled_write_ln_P(PSTR("EXTEND"), false);
            return;
        case _MOUSE:
            oled_write_ln_P(PSTR("MOUSE"), false);
            return;
        case _NUMPAD:
            oled_write_ln_P(PSTR("NUMPAD"), false);
            return;
        case _FN:
            oled_write_ln_P(PSTR("FN"), false);
            return;
    }

    switch (base) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("COLEMAK"), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
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

void keyboard_post_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
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

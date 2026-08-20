// Strict Miryoku-style 3x5+3 experiment for the Keyball61.
#include QMK_KEYBOARD_H

enum layer_number {
    _COLEMAK = 0,
    _QWERTY,
    _BUTTON,
    _NAV,
    _MEDIA,
    _MOUSE, // Keep layer 5 in sync with AUTO_MOUSE_DEFAULT_LAYER in config.h.
    _NUM,
    _SYM,
    _FUN,
};

#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_right_ball(
        KC_NO, KC_NO,              KC_NO,         KC_NO,         KC_NO,         KC_NO,                                        KC_NO,         KC_NO,         KC_NO,         KC_NO,         KC_NO,              KC_NO,
        KC_NO, KC_Q,               KC_W,          KC_F,          KC_P,          KC_G,                                         KC_J,          KC_L,          KC_U,          KC_Y,          KC_SCLN,            KC_NO,
        KC_NO, LALT_T(KC_A),       LCTL_T(KC_R),  LSFT_T(KC_S),  LGUI_T(KC_T),  KC_D,                                         KC_H,          RGUI_T(KC_N),  RSFT_T(KC_E),  RCTL_T(KC_I),  RALT_T(KC_O),       KC_NO,
        KC_NO, LT(_BUTTON, KC_Z),  KC_X,          KC_C,          KC_V,          KC_B,          KC_NO,                KC_NO,    KC_K,          KC_M,          KC_COMM,       KC_DOT,         LT(_BUTTON, KC_SLSH), KC_NO,
        KC_NO, KC_NO,              DF(_QWERTY),   KC_NO,         LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB),    LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC),       LT(_FUN, KC_DEL),                        KC_NO
    ),

    [_QWERTY] = LAYOUT_right_ball(
        KC_NO, KC_NO,              KC_NO,         KC_NO,         KC_NO,         KC_NO,                                        KC_NO,         KC_NO,         KC_NO,         KC_NO,         KC_NO,              KC_NO,
        KC_NO, KC_Q,               KC_W,          KC_E,          KC_R,          KC_T,                                         KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,               KC_NO,
        KC_NO, LALT_T(KC_A),       LCTL_T(KC_S),  LSFT_T(KC_D),  LGUI_T(KC_F),  KC_G,                                         KC_H,          RGUI_T(KC_J),  RSFT_T(KC_K),  RCTL_T(KC_L),  RALT_T(KC_QUOT),    KC_NO,
        KC_NO, LT(_BUTTON, KC_Z),  KC_X,          KC_C,          KC_V,          KC_B,          KC_NO,                KC_NO,    KC_N,          KC_M,          KC_COMM,       KC_DOT,         LT(_BUTTON, KC_SLSH), KC_NO,
        KC_NO, KC_NO,              DF(_COLEMAK),  KC_NO,         LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB),    LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC),       LT(_FUN, KC_DEL),                        KC_NO
    ),

    [_BUTTON] = LAYOUT_right_ball(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,                      U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   _______,
        _______, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_NO,                      KC_NO,   KC_RGUI, KC_RSFT, KC_RCTL, KC_RALT, _______,
        _______, U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,   _______,  _______, U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   _______,
        _______, _______, _______, _______, MS_BTN3, MS_BTN1, MS_BTN2,  MS_BTN2, MS_BTN1, MS_BTN3, _______
    ),

    [_NAV] = LAYOUT_right_ball(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   _______,
        _______, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_NO,                      KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,  _______, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
        _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,    KC_ENT,  KC_BSPC, KC_DEL,  _______
    ),

    [_MEDIA] = LAYOUT_right_ball(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      UG_TOGG, UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, _______,
        _______, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_NO,                      KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
        _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,    KC_MSTP, KC_MPLY, KC_MUTE, _______
    ),

    [_NUM] = LAYOUT_right_ball(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
        _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                     KC_NO,   KC_RGUI, KC_RSFT, KC_RCTL, KC_RALT, _______,
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
        _______, _______, _______, _______, KC_DOT,  KC_0,    KC_MINS,  KC_NO,   KC_NO,   KC_NO,   _______
    ),

    [_MOUSE] = LAYOUT_right_ball(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   _______,
        _______, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_NO,                      KC_NO,   MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______,
        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,  _______, KC_NO,   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______,
        _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,    MS_BTN2, MS_BTN1, MS_BTN3, _______
    ),

    [_SYM] = LAYOUT_right_ball(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
        _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                    KC_NO,   KC_RGUI, KC_RSFT, KC_RCTL, KC_RALT, _______,
        _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______,  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
        _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_UNDS,  KC_NO,   KC_NO,   KC_NO,   _______
    ),

    [_FUN] = LAYOUT_right_ball(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
        _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                    KC_NO,   KC_RGUI, KC_RSFT, KC_RCTL, KC_RALT, _______,
        _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______,  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
        _______, _______, _______, _______, KC_APP,  KC_SPC,  KC_TAB,   KC_NO,   KC_NO,   KC_NO,   _______
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
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BUTTON:
            oled_write_ln_P(PSTR("BUTTON"), false);
            return;
        case _NAV:
            oled_write_ln_P(PSTR("NAV"), false);
            return;
        case _MEDIA:
            oled_write_ln_P(PSTR("MEDIA"), false);
            return;
        case _NUM:
            oled_write_ln_P(PSTR("NUM"), false);
            return;
        case _MOUSE:
            oled_write_ln_P(PSTR("MOUSE"), false);
            return;
        case _SYM:
            oled_write_ln_P(PSTR("SYM"), false);
            return;
        case _FUN:
            oled_write_ln_P(PSTR("FUN"), false);
            return;
    }

    switch (get_highest_layer(default_layer_state)) {
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        press_count++;
        add_keylog(keycode);
    }
#endif
    return true;
}

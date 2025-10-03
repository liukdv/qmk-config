#include QMK_KEYBOARD_H

// Layer definitions
enum layer_number {
  _COLEMAK = 0,   // Base Colemak layer
  _QWERTY,
  _EXTEND,        // Dreymar-style Extend layer
  _EXTEND_QW
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK */
[_COLEMAK] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
  KC_LSFT,  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                     KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, DF(_QWERTY),KC_LBRC,KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_RALT, KC_DEL, KC_SPC, MO(_EXTEND), KC_LGUI,     KC_BSPC, KC_ENT, KC_LALT
),

/* QWERTY */
[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                        KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_EQL,
  KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                        KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_MINS,
  KC_LSFT,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, DF(_COLEMAK), KC_LBRC, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                KC_RALT, KC_DEL, KC_SPC,          MO(_EXTEND_QW), KC_LGUI,     KC_BSPC, KC_ENT, KC_LALT

),

/* EXTEND (Navigation, editing, function keys, symbols) */
[_EXTEND] = LAYOUT(
  KC_F12, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TAB,  KC_ESC, C(S(KC_Z)), KC_WBAK, KC_WFWD, _______ ,                 KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  KC_PSCR,
  KC_LSFT,  KC_LALT, _______, KC_LSFT, KC_LCTL, _______,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_GRV,
  KC_LCTL,  C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______, KC_RBRC, KC_MPRV, KC_VOLD, KC_MPLY, KC_VOLU, KC_MNXT, KC_BSLS,
                        KC_RALT, KC_DEL, KC_SPC,          _______, KC_LGUI,     KC_BSPC, KC_ENT, KC_LALT
),

[_EXTEND_QW] = LAYOUT(
  KC_F12, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TAB,  KC_ESC, C(S(KC_Z)), KC_WBAK, KC_WFWD, _______,                  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  KC_PSCR,
  KC_LSFT,  KC_LALT, _______, KC_LSFT, KC_LCTL, _______,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_GRV,
  KC_LCTL,  C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______, KC_RBRC, KC_MPRV, KC_VOLD, KC_MPLY, KC_VOLU, KC_MNXT, KC_BSLS,
                       KC_RALT, KC_DEL, KC_SPC,          _______, KC_LGUI,     KC_BSPC, KC_ENT, KC_LALT
),
};

// ─── OLED: Left = keylogs + Default + Layer + WPM + keys | Right = Lily58 logo ──
#ifdef OLED_ENABLE
#include <stdio.h>  // snprintf

// from lib/keylogger.c and lib/logo_reader.c
const char *read_keylog(void);
const char *read_keylogs(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_logo(void);

static uint32_t press_count = 0;

// rotate offhand for readability
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? rotation : OLED_ROTATION_180;
}

// show *current* layer: prefer overlays; fall back to default base
static void oled_print_layer(void) {
    uint8_t overlay = get_highest_layer(layer_state);          // momentary/toggled
    uint8_t base    = get_highest_layer(default_layer_state);  // persistent default

    oled_write_P(PSTR("Layer: "), false);

    // If an overlay is active, show it first
    switch (overlay) {
        case _EXTEND:
            oled_write_ln_P(PSTR("(cmk) EXTEND"), false);
            return;
        case _EXTEND_QW:
            oled_write_ln_P(PSTR("(qw) EXTEND"), false);
            return;
        default:
            break; // no overlay → show base below
    }

    // No overlay: show the current base layout
    oled_write_ln_P(base == _QWERTY ? PSTR("QWERTY") : PSTR("COLEMAK"), false);
}



// show stored default (what DF() wrote)
// static void oled_print_default_layer(void) {
//     uint32_t dl = default_layer_state;
//     oled_write_P(PSTR("Default: "), false);
//     if (dl & (1UL << _QWERTY))      oled_write_ln_P(PSTR("QWERTY"),  false);
//     else if (dl & (1UL << _COLEMAK)) oled_write_ln_P(PSTR("COLEMAK"), false);
//     else                             oled_write_ln_P(PSTR("?"),       false);
// }


// static inline void oled_print_wpm_and_count(void) {
//   char buf[22];                              // ~21 chars per line on 128×32
//   uint8_t w = get_current_wpm();
//   unsigned long c = press_count;
//   snprintf(buf, sizeof(buf), "wpm:%3u  count:%lu", w, c);
//   oled_write_ln(buf, false);
// }


bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // 1) Normal history (no label to maximize space)
    oled_write_ln(read_keylogs(), false);

    // 2) WPM on its own line
    oled_write_P(PSTR("wpm: "), false);
    char wbuf[8];
    snprintf(wbuf, sizeof(wbuf), "%3u", get_current_wpm());
    oled_write_ln(wbuf, false);

    // 3) count on its own line
    oled_write_P(PSTR("count: "), false);
    char cbuf[16];
    snprintf(cbuf, sizeof(cbuf), "%lu", (unsigned long)press_count);
    oled_write_ln(cbuf, false);

    // 4) Layer
    oled_print_layer();
    // oled_print_default_layer();

  } else {
    oled_write(read_logo(), false); // Offhand: logo only
  }
  return false;
}

#endif // OLED_ENABLE

// keep hook available
layer_state_t layer_state_set_user(layer_state_t state) { return state; }

// increment keystroke counter + feed keylogger
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        press_count++;
        set_keylog(keycode, record);
    }
#else
        if (record->event.pressed) {press_count++;}
#endif
    return true;
}

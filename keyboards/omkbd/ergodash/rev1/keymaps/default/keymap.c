#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ADJUST1,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  ADJUST1,
};

enum combos {
  R_T_LBRC,
  F_G_LPRN,
  V_B_LCBR,
  Y_U_RBRC,
  H_J_RPRN,
  N_M_RCBR,
  E_R_MINUS,
  U_I_EQL,

};

const uint16_t PROGMEM r_t_lbrc[] = { KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM f_g_lprn[] = { KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM v_b_lcbr[] = { KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM y_u_rbrc[] = { KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM h_j_rprn[] = { KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM n_m_rcbr[] = { KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM e_r_minus[] = { KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM u_i_eql[] = { KC_U, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [R_T_LBRC] = COMBO(r_t_lbrc, KC_LBRC),
  [F_G_LPRN] = COMBO(f_g_lprn, KC_LPRN),
  [V_B_LCBR] = COMBO(v_b_lcbr, KC_LCBR),
  [Y_U_RBRC] = COMBO(y_u_rbrc, KC_RBRC),
  [H_J_RPRN] = COMBO(h_j_rprn, KC_RPRN),
  [N_M_RCBR] = COMBO(n_m_rcbr, KC_RCBR),
  [E_R_MINUS] = COMBO(e_r_minus, KC_MINUS),
  [U_I_EQL] = COMBO(u_i_eql, KC_EQL),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    _______,               _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______,
    MT(MOD_LALT, KC_ESC),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,                         _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    LOWER,                 KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______ ,                        _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    MT(MOD_LCTL, KC_ENT),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______ ,                        _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    _______, _______, _______, LT(_ADJUST, KC_TAB),   LT(_LOWER, KC_BSPC), LT(_RAISE, KC_DEL),  _______, _______, KC_ENT , RAISE,   KC_LEFT, _______, _______, _______
  ),

  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL ,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, KC_DQT ,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_ESC,             LOWER,   KC_SPC ,KC_DEL,         KC_BSPC,KC_ENT , RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  [_RAISE] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL ,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, KC_DQT ,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_ESC,             LOWER,   KC_SPC ,KC_DEL,         KC_BSPC,KC_ENT , RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, QK_BOOT  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______,
    _______, _______, BL_TOGG, BL_BRTG, BL_UP  , BL_DOWN,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______
  ),

  [_ADJUST1] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, QK_BOOT  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______,
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

// #include "features/achordion.h"

// ------------------------------------------------------------------------------------------------------ //

//   [_SYM2] = LAYOUT(
//                     KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6 ,  KC_F7 ,  KC_F8  , KC_F9  , KC_F10 ,     XXXXXXX, KC_F11 ,
//     _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TR_RPRN, TR_RCBR, TR_RBRC, TR_RABK, TR_BSLS,     XXXXXXX, KC_F12 ,
//     _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TR_GRV , XXXXXXX, TR_DQUO, TR_SCLN, TR_EXLM,     XXXXXXX, XXXXXXX ,
//     _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, TR_TILD, TR_HASH, TR_PERC, TR_CIRC,     XXXXXXX, XXXXXXX ,
//     _______                , _______, _______, _______, _______,     _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
//   ),

// ------------------------------------------------------------------------------------------------------ //

// bool     is_alt_tab_active  = false; // ADD this near the beginning of keymap.c
// bool     is_ctrl_tab_active = false; // ADD this near the beginning of keymap.c
// uint16_t alt_tab_timer      = 0;     // we will be using them soon.
// uint16_t ctrl_tab_timer     = 0;

// ------------------------------------------------------------------------------------------------------ //

// case MY_AT:
//     if (record->event.pressed) {
//         my_at_timer = timer_read();
//         register_code(KC_LGUI); // Change the key to be held here
//     } else {
//         unregister_code(KC_LGUI); // Change the key that was held here, too!
//         if (timer_elapsed(my_at_timer) < TAPPING_TERM) {
//             register_code(KC_LALT);
//             tap_code(TR_Q);
//             unregister_code(KC_LALT);
//         }
//     }
//     return false;
// case ALT_TAB:
//     if (record->event.pressed) {
//         if (!is_alt_tab_active) {
//             is_alt_tab_active = true;
//             register_code(KC_LALT);
//         }
//         alt_tab_timer = timer_read();
//         register_code(KC_TAB);
//     } else {
//         unregister_code(KC_TAB);
//     }
//     break;
// case CTL_TAB:
//     if (record->event.pressed) {
//         if (!is_ctrl_tab_active) {
//             is_ctrl_tab_active = true;
//             register_code(KC_LCTL);
//         }
//         ctrl_tab_timer = timer_read();
//         register_code(KC_TAB);
//     } else {
//         unregister_code(KC_TAB);
//     }
//     break;

// ------------------------------------------------------------------------------------------------------ //

// The very important timer.
// void matrix_scan_user(void) {
//     // achordion_task();
//     if (is_alt_tab_active && timer_elapsed(alt_tab_timer) > 500) {
//             unregister_code(KC_LALT);
//             is_alt_tab_active = false;
//     }
//     if (is_ctrl_tab_active && timer_elapsed(ctrl_tab_timer) > 500) {
//             unregister_code(KC_LCTL);
//             is_ctrl_tab_active = false;
//     }
// }

// ------------------------------------------------------------------------------------------------------ //

// const key_override_t SHIFTED_LPRN = ko_make_basic(MOD_MASK_ALT, TR_LPRN, TR_RPRN);
// const key_override_t SHIFTED_LCBR = ko_make_basic(MOD_MASK_ALT, TR_LCBR, TR_RCBR);
// const key_override_t SHIFTED_LBRC = ko_make_basic(MOD_MASK_ALT, TR_LBRC, TR_RBRC);
// const key_override_t SHIFTED_LABK = ko_make_basic(MOD_MASK_ALT, TR_LABK, TR_RABK);
// const key_override_t SHIFTED_SLSH = ko_make_basic(MOD_MASK_ALT, TR_SLSH, TR_BSLS);

// const key_override_t SHIFTED_COMM = ko_make_basic(MOD_MASK_ALT, TR_COMM, TR_GRV );
// const key_override_t SHIFTED_QUOT = ko_make_basic(MOD_MASK_ALT, TR_QUOT, TR_DQUO);
// const key_override_t SHIFTED_COLN = ko_make_basic(MOD_MASK_ALT, TR_COLN, TR_SCLN);
// const key_override_t SHIFTED_QUES = ko_make_basic(MOD_MASK_ALT, TR_EXLM, TR_QUES);

// const key_override_t SHIFTED_MINS = ko_make_basic(MOD_MASK_ALT, TR_MINS, TR_TILD);
// const key_override_t SHIFTED_EQL  = ko_make_basic(MOD_MASK_ALT, TR_EQL , TR_HASH);
// const key_override_t SHIFTED_PLUS = ko_make_basic(MOD_MASK_ALT, TR_PLUS, TR_PERC);
// const key_override_t SHIFTED_ASTR = ko_make_basic(MOD_MASK_ALT, TR_ASTR, TR_CIRC);




// const key_override_t mac_like_left  = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_LEFT, LGUI(KC_LEFT),~0,MOD_MASK_CTRL);
// const key_override_t mac_like_right = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_RGHT, LGUI(KC_RGHT),~0,MOD_MASK_CTRL);
// const key_override_t mac_like_up    = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_UP  , LGUI(KC_UP),  ~0,MOD_MASK_CTRL);
// const key_override_t mac_like_down  = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_DOWN, LGUI(KC_DOWN),~0,MOD_MASK_CTRL);

// const key_override_t MY_GRV  = ko_make_basic(MOD_MASK_CA , TR_H   , TR_GRV );
// const key_override_t MY_DQUO = ko_make_basic(MOD_MASK_CA , TR_K   , TR_DQUO);
// const key_override_t MY_SCLN = ko_make_basic(MOD_MASK_CA , TR_L   , TR_SCLN);
// const key_override_t MY_EXLM = ko_make_basic(MOD_MASK_CA , TR_AT  , TR_EXLM);
// const key_override_t MY_TILD = ko_make_basic(MOD_MASK_CA , TR_M   , TR_TILD);
// const key_override_t MY_HASH = ko_make_basic(MOD_MASK_CA , TR_CCED, TR_HASH);
// const key_override_t MY_PERC = ko_make_basic(MOD_MASK_CA , TR_GBRV, TR_PERC);
// const key_override_t MY_CIRC = ko_make_basic(MOD_MASK_CA , TR_SCED, TR_CIRC);
// const key_override_t MY_RPRN = ko_make_basic(MOD_MASK_ALT, TR_6   , TR_RPRN);
// const key_override_t MY_RCBR = ko_make_basic(MOD_MASK_ALT, TR_7   , TR_RCBR);
// const key_override_t MY_RBRC = ko_make_basic(MOD_MASK_ALT, TR_8   , TR_RBRC);
// const key_override_t MY_RABK = ko_make_basic(MOD_MASK_ALT, TR_9   , TR_RABK);
// const key_override_t MY_BSLS = ko_make_basic(MOD_MASK_ALT, TR_0   , TR_BSLS);
// const key_override_t MY_LPRN = ko_make_basic(MOD_MASK_ALT, TR_Y   , TR_LPRN);
// const key_override_t MY_LCBR = ko_make_basic(MOD_MASK_ALT, TR_U   , TR_LCBR);
// const key_override_t MY_LBRC = ko_make_basic(MOD_MASK_ALT, TR_IDOT, TR_LBRC);
// const key_override_t MY_LABK = ko_make_basic(MOD_MASK_ALT, TR_O   , TR_LABK);
// const key_override_t MY_SLSH = ko_make_basic(MOD_MASK_ALT, TR_P   , TR_SLSH);
// const key_override_t MY_COMM = ko_make_basic(MOD_MASK_ALT, TR_H   , TR_COMM);
// const key_override_t MY_DOT  = ko_make_basic(MOD_MASK_ALT, TR_J   , TR_DOT );
// const key_override_t MY_QUOT = ko_make_basic(MOD_MASK_ALT, TR_K   , TR_QUOT);
// const key_override_t MY_COLN = ko_make_basic(MOD_MASK_ALT, TR_L   , TR_COLN);
// const key_override_t MY_QUES = ko_make_basic(MOD_MASK_ALT, TR_AT  , TR_QUES);
// const key_override_t MY_UNDS = ko_make_basic(MOD_MASK_ALT, TR_N   , TR_UNDS);
// const key_override_t MY_MINS = ko_make_basic(MOD_MASK_ALT, TR_M   , TR_MINS);
// const key_override_t MY_EQL  = ko_make_basic(MOD_MASK_ALT, TR_CCED, TR_EQL );
// const key_override_t MY_PLUS = ko_make_basic(MOD_MASK_ALT, TR_GBRV, TR_PLUS);
// const key_override_t MY_ASTR = ko_make_basic(MOD_MASK_ALT, TR_SCED, TR_ASTR);
// const key_override_t MY_PIPE = ko_make_basic(MOD_MASK_ALT, TR_I   , TR_PIPE);
// const key_override_t MY_AMPR = ko_make_basic(MOD_MASK_ALT, TR_ODIA, TR_AMPR);
// const key_override_t MY_DLR  = ko_make_basic(MOD_MASK_ALT, TR_UDIA, TR_DLR );
// const key_override_t MY_Q = ko_make_basic(MOD_MASK_ALT, TR_Q, LGUI(TR_Q));
// const key_override_t MY_W = ko_make_basic(MOD_MASK_ALT, TR_W, LGUI(TR_W));
// const key_override_t MY_E = ko_make_basic(MOD_MASK_ALT, TR_E, LGUI(TR_E));
// const key_override_t MY_R = ko_make_basic(MOD_MASK_ALT, TR_R, LGUI(TR_R));
// const key_override_t MY_T = ko_make_basic(MOD_MASK_ALT, TR_T, LGUI(TR_T));
// const key_override_t MY_A = ko_make_basic(MOD_MASK_ALT, TR_A, LGUI(TR_A));
// const key_override_t MY_S = ko_make_basic(MOD_MASK_ALT, TR_S, LGUI(TR_S));
// const key_override_t MY_D = ko_make_basic(MOD_MASK_ALT, TR_D, LGUI(TR_D));
// const key_override_t MY_F = ko_make_basic(MOD_MASK_ALT, TR_F, LGUI(TR_F));
// const key_override_t MY_G = ko_make_basic(MOD_MASK_ALT, TR_G, LGUI(TR_G));
// const key_override_t MY_Z = ko_make_basic(MOD_MASK_ALT, TR_Z, LGUI(TR_Z));
// const key_override_t MY_X = ko_make_basic(MOD_MASK_ALT, TR_X, LGUI(TR_X));
// const key_override_t MY_C = ko_make_basic(MOD_MASK_ALT, TR_C, LGUI(TR_C));
// const key_override_t MY_V = ko_make_basic(MOD_MASK_ALT, TR_V, LGUI(TR_V));
// const key_override_t MY_B = ko_make_basic(MOD_MASK_ALT, TR_B, LGUI(TR_B));

// ------------------------------------------------------------------------------------------------------ //

// &mac_like_left,
// &mac_like_right,
// &mac_like_up,
// &mac_like_down,

// &MY_GRV,
// &MY_DQUO,
// &MY_SCLN,
// &MY_EXLM,
// &MY_TILD,
// &MY_HASH,
// &MY_PERC,
// &MY_CIRC,
// &MY_RPRN,
// &MY_RCBR,
// &MY_RBRC,
// &MY_RABK,
// &MY_BSLS,
// &MY_LPRN,
// &MY_LCBR,
// &MY_LBRC,
// &MY_LABK,
// &MY_SLSH,
// &MY_COMM,
// &MY_DOT,
// &MY_QUOT,
// &MY_COLN,
// &MY_QUES,
// &MY_UNDS,
// &MY_MINS,
// &MY_EQL,
// &MY_PLUS,
// &MY_ASTR,
// &MY_PIPE,
// &MY_AMPR,
// &MY_DLR,
// &MY_Q,
// &MY_W,
// &MY_E,
// &MY_R,
// &MY_T,
// &MY_A,
// &MY_S,
// &MY_D,
// &MY_F,
// &MY_G,
// &MY_Z,
// &MY_X,
// &MY_C,
// &MY_V,
// &MY_B,

// &SHIFTED_LPRN,
// &SHIFTED_LCBR,
// &SHIFTED_LBRC,
// &SHIFTED_LABK,
// &SHIFTED_SLSH,

// &SHIFTED_COMM,
// &SHIFTED_QUOT,
// &SHIFTED_COLN,
// &SHIFTED_QUES,

// &SHIFTED_MINS,
// &SHIFTED_EQL,
// &SHIFTED_PLUS,
// &SHIFTED_ASTR,

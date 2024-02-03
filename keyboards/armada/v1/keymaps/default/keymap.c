#include QMK_KEYBOARD_H
#include "keymap_turkish_q.h"
#include "emoji.c"

// ------------------------------------------------------------------------------------------------------ //

enum layer {
    _BASE,
    _SYMB,
    _NAV,
    _EMOJI,
};

enum custom_keycodes {
    EMOJI,
    RPC
};

// ------------------------------------------------------------------------------------------------------ //

#define SPR_CPS     LSFT_T(KC_CAPS)   // tap to caps-lock, hold to shift
#define EMOJIPOPUP  LGUI(LCTL(KC_SPC))
#define SWITCHINPUT LCTL(LALT(KC_SPC))

// ------------------------------------------------------------------------------------------------------ //

// #define MY_6    LT(0, TR_6)
// #define MY_7    LT(0, TR_7)
// #define MY_8    LT(0, TR_8)
// #define MY_9    LT(0, TR_9)
// #define MY_0    LT(0, TR_0)

// #define MY_Y    LT(0, TR_Y)
// #define MY_U    LT(0, TR_U)
// #define MY_IDOT LT(0, TR_IDOT)
// #define MY_O    LT(0, TR_O)
// #define MY_P    LT(0, TR_P)

// #define MY_H    LT(0, TR_H)
// #define MY_J    LT(0, TR_J)
// #define MY_K    LT(0, TR_K)
// #define MY_L    LT(0, TR_L)

// #define MY_N    LT(0, TR_N)
// #define MY_M    LT(0, TR_M)
// #define MY_CCED LT(0, TR_CCED)
// #define MY_GBRV LT(0, TR_GBRV)
// #define MY_SCED LT(0, TR_SCED)

// #define MY_I    LT(0, TR_I)
// #define MY_ODIA LT(0, TR_ODIA)
// #define MY_UDIA LT(0, TR_UDIA)

// #define MY_Q    LT(0, TR_Q)
// #define MY_W    LT(0, TR_W)
// #define MY_E    LT(0, TR_E)
// #define MY_R    LT(0, TR_R)
// #define MY_T    LT(0, TR_T)

// #define MY_A    LT(0, TR_A)
// #define MY_S    LT(0, TR_S)
// #define MY_D    LT(0, TR_D)
// #define MY_F    LT(0, TR_F)
// #define MY_G    LT(0, TR_G)

// #define MY_Z    LT(0, TR_Z)
// #define MY_X    LT(0, TR_X)
// #define MY_C    LT(0, TR_C)
// #define MY_V    LT(0, TR_V)
// #define MY_B    LT(0, TR_B)

// ------------------------------------------------------------------------------------------------------ //

// Helper for implementing tap vs. long-press keys. Given a tap-hold key event, replaces the hold function with `long_press_keycode`.
// static bool process_tap_or_long_press_key(keyrecord_t *record, uint16_t long_press_keycode) {
//     if (record->tap.count == 0) { // Key is being held.
//         if (record->event.pressed) {
//             tap_code16(long_press_keycode);
//         }
//         return false; // Skip default handling.
//     }
//     return true; // Continue default handling.
// }

// ------------------------------------------------------------------------------------------------------ //

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static uint16_t my_at_timer;

    switch (keycode) {
        // case MY_6   : return process_tap_or_long_press_key(record, TR_RPRN);
        // case MY_7   : return process_tap_or_long_press_key(record, TR_RCBR);
        // case MY_8   : return process_tap_or_long_press_key(record, TR_RBRC);
        // case MY_9   : return process_tap_or_long_press_key(record, TR_RABK);
        // case MY_0   : return process_tap_or_long_press_key(record, TR_BSLS);

        // case MY_Y   : return process_tap_or_long_press_key(record, TR_LPRN);
        // case MY_U   : return process_tap_or_long_press_key(record, TR_LCBR);
        // case MY_IDOT: return process_tap_or_long_press_key(record, TR_LBRC);
        // case MY_O   : return process_tap_or_long_press_key(record, TR_LABK);
        // case MY_P   : return process_tap_or_long_press_key(record, TR_SLSH);

        // case MY_H   : return process_tap_or_long_press_key(record, TR_COMM);
        // case MY_J   : return process_tap_or_long_press_key(record, TR_DOT);
        // case MY_K   : return process_tap_or_long_press_key(record, TR_QUOT);
        // case MY_L   : return process_tap_or_long_press_key(record, TR_COLN);

        // case MY_N   : return process_tap_or_long_press_key(record, TR_UNDS);
        // case MY_M   : return process_tap_or_long_press_key(record, TR_MINS);
        // case MY_CCED: return process_tap_or_long_press_key(record, TR_PIPE );
        // case MY_GBRV: return process_tap_or_long_press_key(record, TR_AMPR);
        // case MY_SCED: return process_tap_or_long_press_key(record, TR_DLR);

        // case MY_I   : return process_tap_or_long_press_key(record, TR_EQL);
        // case MY_ODIA: return process_tap_or_long_press_key(record, TR_PLUS);
        // case MY_UDIA: return process_tap_or_long_press_key(record, TR_ASTR );

        // case MY_Q   : return process_tap_or_long_press_key(record, TR_BSLS);
        // case MY_W   : return process_tap_or_long_press_key(record, TR_RABK);
        // case MY_E   : return process_tap_or_long_press_key(record, TR_RBRC);
        // case MY_R   : return process_tap_or_long_press_key(record, TR_RCBR);
        // case MY_T   : return process_tap_or_long_press_key(record, TR_RPRN);

        // case MY_A   : return process_tap_or_long_press_key(record, TR_TILD);
        // case MY_S   : return process_tap_or_long_press_key(record, TR_SCLN);
        // case MY_D   : return process_tap_or_long_press_key(record, TR_DQUO);
        // case MY_F   : return process_tap_or_long_press_key(record, TR_DOT );
        // case MY_G   : return process_tap_or_long_press_key(record, TR_GRV );

        // case MY_Z   : return process_tap_or_long_press_key(record, TR_CIRC);
        // case MY_X   : return process_tap_or_long_press_key(record, TR_PERC);
        // case MY_C   : return process_tap_or_long_press_key(record, TR_HASH);
        // case MY_V   : return process_tap_or_long_press_key(record, TR_EXLM);
        // case MY_B   : return process_tap_or_long_press_key(record, TR_QUES);

        case EMOJI:
            if (record->event.pressed) {
                // my_at_timer = timer_read();
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_SPC);
                layer_on(_EMOJI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_SPC);
            } else {
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_SPC);
                layer_off(_EMOJI);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_SPC);
                // if (timer_elapsed(my_at_timer) < TAPPING_TERM) {
                //     tap_code(TR_G);
                // }
            }
            return false;

        // swap cmd+tab with ctrl+tab and vice versa
        case KC_TAB:
            if(get_mods() & MOD_MASK_GUI){
                uint8_t mods = get_mods(); // trick is here
                set_mods(MOD_MASK_CTRL);
                if (record->event.pressed) {
                    tap_code16(KC_TAB);
                }
                set_mods(mods);
            }
            else if(get_mods() & MOD_MASK_CTRL){
                uint8_t mods = get_mods(); // trick is here
                set_mods(MOD_MASK_GUI);
                if (record->event.pressed) {
                    tap_code16(KC_TAB);
                }
                set_mods(mods);
            }
            else{
                if (record->event.pressed) {
                    tap_code16(KC_TAB);
                }
            }
            return false;
    }
    return true;
};

// ------------------------------------------------------------------------------------------------------ //

#define TOP1 KC_TAB
#define BTM1 MO(_SYMB)
#define LFT1 KC_SPC
#define RGT1 KC_SPC

// ------------------------------------------------------------------------------------------------------ //

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
                    TR_1, TR_2   , TR_3   , TR_4, TR_5,          TR_6, TR_7, TR_8   , TR_9   , TR_0   ,     KC_BSPC      , LAG(KC_I) ,
    KC_ESC    ,     TR_Q, TR_W   , TR_E   , TR_R, TR_T,          TR_Y, TR_U, TR_IDOT, TR_O   , TR_P   ,     KC_ENT       , SGUI(KC_X),
    KC_CAPS   ,     TR_A, TR_S   , TR_D   , TR_F, TR_G,          TR_H, TR_J, TR_K   , TR_L   , TR_AT  ,     LGUI(KC_RGHT), KC_RGHT   ,
    KC_LSFT   ,     TR_Z, TR_X   , TR_C   , TR_V, TR_B,          TR_N, TR_M, TR_I   , TR_ODIA, TR_UDIA,     LGUI(KC_LEFT), KC_UP     ,
    KC_LGUI   ,           KC_LCTL, KC_LALT, LFT1, TOP1,          RGT1, BTM1, TR_CCED, TR_GBRV, TR_SCED,     KC_LEFT      , KC_DOWN
  ),

  [_SYMB] = LAYOUT(
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_MUTE, KC_VOLU,
    _______   ,     TR_BSLS, TR_RABK, TR_RBRC, TR_RCBR, TR_RPRN,     TR_LPRN, TR_LCBR, TR_LBRC, TR_LABK, TR_SLSH,     KC_MPLY, KC_VOLD,
    _______   ,     TR_TILD, TR_SCLN, TR_DQUO, TR_DOT , TR_GRV ,     TR_COMM, TR_DOT , TR_QUOT, TR_COLN, TR_AT  ,     _______, _______,
    _______   ,     TR_CIRC, TR_PERC, TR_HASH, TR_EXLM, TR_QUES,     TR_UNDS, TR_MINS, TR_EQL , TR_PLUS, TR_ASTR,     _______, _______,
    _______   ,              _______, _______, _______, QK_BOOT,     _______, _______, TR_PIPE, TR_AMPR, TR_DLR ,     _______, _______
  ),

  [_NAV] = LAYOUT(
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX ,
    _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_UP  , XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX ,
    _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,     XXXXXXX, XXXXXXX ,
    _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX ,
    _______   ,              _______, _______, _______, _______,     _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
  ),

  [_EMOJI] = LAYOUT(
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     X(SHRG) , X(CONFU), X(FROWN), X(UNAMU), X(DISAP),     SWITCHINPUT, XXXXXXX ,
    _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     X(ROCKT), X(THMUP), X(HDSUP), X(CLAP) , X(SALT) ,     EMOJIPOPUP , XXXXXXX ,
    _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     X(SMILE), X(GRIN1), X(GRIN2), X(JOY)  , X(SWSML),     XXXXXXX    , XXXXXXX ,
    _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     X(SNAKE), X(FIRE) , X(SUNG) , X(NERD) , X(MONO) ,     XXXXXXX    , XXXXXXX ,
    _______   ,              _______, _______, _______, QK_BOOT,      _______, _______ , X(SCRM) , X(EXPLD), X(EYOP) ,     XXXXXXX    , XXXXXXX
  )
};

// ------------------------------------------------------------------------------------------------------ //

const key_override_t win_like_left  = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KC_LEFT, LALT(KC_LEFT),~0,MOD_MASK_CTRL);
const key_override_t win_like_right = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KC_RGHT, LALT(KC_RGHT),~0,MOD_MASK_CTRL);
const key_override_t win_like_up    = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KC_UP  , LALT(KC_UP),  ~0,MOD_MASK_CTRL);
const key_override_t win_like_down  = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KC_DOWN, LALT(KC_DOWN),~0,MOD_MASK_CTRL);

const key_override_t mac_like_left  = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_LEFT, LGUI(KC_LEFT),~0,MOD_MASK_CTRL);
const key_override_t mac_like_right = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_RGHT, LGUI(KC_RGHT),~0,MOD_MASK_CTRL);
const key_override_t mac_like_up    = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_UP  , LGUI(KC_UP),  ~0,MOD_MASK_CTRL);
const key_override_t mac_like_down  = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_DOWN, LGUI(KC_DOWN),~0,MOD_MASK_CTRL);

const key_override_t win_like_del   = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC      , KC_DEL            );
const key_override_t word_del       = ko_make_basic(MOD_MASK_GUI  , KC_BSPC      , LALT(KC_BSPC)     );
const key_override_t line_del       = ko_make_basic(MOD_MASK_ALT  , KC_BSPC      , LGUI(KC_BSPC)     );

const key_override_t alt_tab        = ko_make_basic(MOD_MASK_ALT  , LGUI(KC_RGHT), LALT(KC_TAB)      );
const key_override_t alt_shift_tab  = ko_make_basic(MOD_MASK_ALT  , LGUI(KC_LEFT), LALT(LSFT(KC_TAB)));

const key_override_t ctrl_tab       = ko_make_basic(MOD_MASK_CTRL , LGUI(KC_RGHT), LCTL(KC_TAB)      );
const key_override_t ctrl_shift_tab = ko_make_basic(MOD_MASK_CTRL , LGUI(KC_LEFT), LCTL(LSFT(KC_TAB)));

const key_override_t sft_i          = ko_make_basic(MOD_MASK_SHIFT, TR_I         , LSFT(TR_IDOT)     );
const key_override_t sft_idot       = ko_make_basic(MOD_MASK_SHIFT, TR_IDOT      , LSFT(TR_I)        );

// ------------------------------------------------------------------------------------------------------ //

const key_override_t **key_overrides = (const key_override_t *[]){
    &win_like_left,
    &win_like_right,
    &win_like_up,
    &win_like_down,

    &mac_like_left,
    &mac_like_right,
    &mac_like_up,
    &mac_like_down,

    &win_like_del,
    &word_del,
    &line_del,

    &alt_tab,
    &alt_shift_tab,

    &ctrl_tab,
    &ctrl_shift_tab,

    &sft_i,
    &sft_idot,

    NULL
};

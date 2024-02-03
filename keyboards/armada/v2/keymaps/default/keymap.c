#include QMK_KEYBOARD_H
#include "keymap_turkish_q.h"
#include "emoji.c"

// ------------------------------------------------------------------------------------------------------ //

enum layer {
    _BASE,
    _SYM1,
    _SYM2,
    _EMOJI,
};

enum custom_keycodes {
    EMOJI,
};

// ------------------------------------------------------------------------------------------------------ //

#define SPR_CPS     LSFT_T(KC_CAPS)   // tap to caps-lock, hold to shift
#define EMOJIPOPUP  LGUI(LCTL(KC_SPC))
#define SWITCHINPUT LCTL(LALT(KC_SPC))

// ------------------------------------------------------------------------------------------------------ //

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static uint16_t my_at_timer;

    switch (keycode) {

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

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYM1, _SYM2, _EMOJI);
    return state;
}

// ------------------------------------------------------------------------------------------------------ //

#define LFT1 KC_LGUI
#define LFT2 KC_LALT
#define LFT3 MO(_SYM2)
#define LFT4 MO(_SYM1)
#define LFT5 MO(_SYM1)
#define LFT6 MO(_SYM2)

// ------------------------------------------------------------------------------------------------------ //

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_ESC , TR_1   , TR_2   , TR_3   , TR_4   , TR_5   ,     TR_6   , TR_7   , TR_8   , TR_9   , TR_0   ,     KC_BSPC, KC_DEL ,
    KC_TAB , TR_Q   , TR_W   , TR_E   , TR_R   , TR_T   ,     TR_Y   , TR_U   , TR_IDOT, TR_O   , TR_P   ,     KC_ENT , KC_CAPS,
    KC_LCTL, TR_A   , TR_S   , TR_D   , TR_F   , TR_G   ,     TR_H   , TR_J   , TR_K   , TR_L   , TR_AT  ,     KC_UP  , KC_RGHT,
    KC_LSFT, TR_Z   , TR_X   , TR_C   , TR_V   , TR_B   ,     TR_M   , TR_N   , TR_DOT , TR_COMM, TR_QUOT,     KC_LEFT, KC_DOWN,
    LFT1   , LFT2   , LFT3   , LFT4   , LFT5   , LFT6   ,     TR_CCED, TR_GBRV, TR_SCED, TR_I   , TR_ODIA,     TR_UDIA, KC_SPC
  ),

  [_SYM1] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_MUTE, KC_VOLU,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TR_LPRN, TR_LCBR, TR_LBRC, TR_LABK, TR_SLSH,     KC_MPLY, KC_VOLD,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TR_EQL,  TR_MINS, TR_PLUS, TR_ASTR, TR_DLR ,     _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TR_QUES, TR_AMPR, TR_COLN, TR_SCLN, TR_GRV ,     _______, _______,
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,     _______, _______
  ),
  [_SYM2] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_MUTE, KC_VOLU,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TR_RPRN, TR_RCBR, TR_RBRC, TR_RABK, TR_BSLS,     KC_MPLY, KC_VOLD,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TR_HASH, TR_UNDS, TR_PERC, TR_CIRC, TR_TILD,     _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TR_EXLM, TR_PIPE, XXXXXXX, XXXXXXX, TR_DQUO,     _______, _______,
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,     _______, _______
  ),

  [_EMOJI] = LAYOUT(
    _______, X(SNAKE), X(FIRE), X(SUNG), X(NERD), X(MONO),     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     SWITCHINPUT, XXXXXXX ,
    _______, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     X(SHRG) , X(CONFU), X(FROWN), X(UNAMU), X(DISAP),     EMOJIPOPUP , XXXXXXX ,
    _______, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     X(ROCKT), X(THMUP), X(HDSUP), X(CLAP) , X(SALT) ,     XXXXXXX    , XXXXXXX ,
    _______, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     X(SMILE), X(GRIN1), X(GRIN2), X(JOY)  , X(SWSML),     XXXXXXX    , XXXXXXX ,
    _______, _______ , _______, _______, _______, _______,     _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX    , XXXXXXX
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
    // &win_like_left,
    // &win_like_right,
    // &win_like_up,
    // &win_like_down,

    // &mac_like_left,
    // &mac_like_right,
    // &mac_like_up,
    // &mac_like_down,

    // &win_like_del,
    // &word_del,
    // &line_del,

    // &alt_shift_tab,
    // &alt_tab,

    // &ctrl_tab,
    // &ctrl_shift_tab,

    &sft_i,
    &sft_idot,

    NULL
};

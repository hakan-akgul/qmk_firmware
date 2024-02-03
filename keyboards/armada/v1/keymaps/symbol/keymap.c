#include QMK_KEYBOARD_H
#include "keymap_turkish_q.h"
#include "../default/emoji.c"

// ------------------------------------------------------------------------------------------------------ //

enum layer {
    _BASE,
    _SYMB,
    _EMOJI,
};

enum custom_keycodes {
    EMOJI,
};

// ------------------------------------------------------------------------------------------------------ //

#define SPR_CPS     LSFT_T(KC_CAPS)
#define EMOJIPOPUP  LGUI(LCTL(KC_SPC))
#define SWITCHINPUT LCTL(LALT(KC_SPC))

// ------------------------------------------------------------------------------------------------------ //

#define MY_C    LT(0, TR_C)
#define MY_G    LT(0, TR_G)
#define MY_S    LT(0, TR_S)

#define MY_IDOT LT(0, TR_IDOT)
#define MY_O    LT(0, TR_O)
#define MY_U    LT(0, TR_U)

#define MY_LGUI LT(0, KC_LGUI)

// ------------------------------------------------------------------------------------------------------ //

// Helper for implementing tap vs. long-press keys. Given a tap-hold key event, replaces the hold function with `long_press_keycode`.
static bool process_tap_or_long_press_key(keyrecord_t *record, uint16_t long_press_keycode) {
    if (record->tap.count == 0) { // Key is being held.
        if (record->event.pressed) {
            tap_code16(long_press_keycode);
        }
        return false; // Skip default handling.
    }
    return true; // Continue default handling.
}

static bool process_gui_lock(keyrecord_t *record) {
    if (record->tap.count == 0) { // Key is being held.
        if (record->event.pressed) {
            tap_code16(KC_LGUI);
        }
        return false; // Skip default handling.
    }
    else if (record->tap.count == 2) { // Key is being held.
        if (record->event.pressed) {
            register_code16(QK_LOCK);
            tap_code16(KC_LGUI);
            unregister_code16(QK_LOCK);
        }
        return false; // Skip default handling.
    }
    return true; // Continue default handling.
}

// ------------------------------------------------------------------------------------------------------ //


enum {
  MY_LSFT
};

tap_dance_action_t tap_dance_actions[] = {
    // [MY_LGUI] = ACTION_TAP_DANCE_FN(set_gui_lock),
    [MY_LSFT] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

// ------------------------------------------------------------------------------------------------------ //

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// const uint8_t mods = get_mods();
	// uint8_t shifted = mods & MOD_MASK_SHIFT;

    switch (keycode) {
        case MY_C   : return process_tap_or_long_press_key(record, TR_CCED);
        case MY_G   : return process_tap_or_long_press_key(record, TR_GBRV);
        case MY_S   : return process_tap_or_long_press_key(record, TR_SCED);

        case MY_O   : return process_tap_or_long_press_key(record, TR_ODIA);
        case MY_U   : return process_tap_or_long_press_key(record, TR_UDIA);

        case MY_LGUI: return process_gui_lock(record);

        case MY_IDOT: return process_tap_or_long_press_key(record, TR_I);

        case EMOJI:
            if (record->event.pressed) {
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
            }
            return false;

    }
    return true;
};


// ------------------------------------------------------------------------------------------------------ //

#define TOP1 KC_TAB
#define BTM1 KC_LALT
#define LFT1 KC_SPC
#define RGT1 KC_SPC

// ------------------------------------------------------------------------------------------------------ //

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
             TR_1, TR_2   , TR_3     , TR_4, TR_5,          TR_6, TR_7, TR_8   , TR_9   , TR_0   ,     KC_BSPC      , KC_DEL    ,
    KC_ESC , TR_Q, TR_W   , TR_E     , TR_R, TR_T,          TR_Y, MY_U, MY_IDOT, MY_O   , TR_P   ,     KC_ENT       , KC_CAPS   ,
    EMOJI  , TR_A, MY_S   , TR_D     , TR_F, MY_G,          TR_H, TR_J, TR_K   , TR_L   , TR_AT  ,     LGUI(KC_RGHT), KC_RGHT   ,
    KC_LSFT, TR_Z, TR_X   , MY_C     , TR_V, TR_B,          TR_N, TR_M, TR_DOT , TR_COMM, TR_QUOT,     LGUI(KC_LEFT), KC_UP     ,
    KC_LGUI,       KC_LCTL, QK_LOCK  , LFT1, TOP1,          RGT1, BTM1, TR_QUES, TR_AMPR, TR_GRV ,     KC_LEFT      , KC_DOWN
  ),

  [_SYMB] = LAYOUT(
                    XXXXXXX, TR_CIRC, TR_HASH, TR_DLR , TR_PERC,     TR_RPRN, TR_RCBR, TR_RBRC, TR_RABK, TR_BSLS,     KC_MUTE, KC_VOLU,
    _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TR_LPRN, TR_LCBR, TR_LBRC, TR_LABK, TR_SLSH,     KC_MPLY, KC_VOLD,
    _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     TR_UNDS, TR_MINS, TR_EQL , TR_PLUS, TR_ASTR,     _______, _______,
    _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     _______, _______,
    _______   ,              _______, _______, _______, _______,     _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,     _______, _______
  ),

  [_EMOJI] = LAYOUT(
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     X(SHRG) , X(CONFU), X(FROWN), X(UNAMU), X(DISAP),     SWITCHINPUT, XXXXXXX ,
    QK_BOOT   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     X(ROCKT), X(THMUP), X(HDSUP), X(CLAP) , X(SALT) ,     EMOJIPOPUP , XXXXXXX ,
    _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     X(SMILE), X(GRIN1), X(GRIN2), X(JOY)  , X(SWSML),     XXXXXXX    , XXXXXXX ,
    _______   ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     X(SNAKE), X(FIRE) , X(SUNG) , X(NERD) , X(MONO) ,     XXXXXXX    , XXXXXXX ,
    _______   ,              _______, _______, _______, _______,      _______, _______ , X(SCRM) , X(EXPLD), X(EYOP) ,     XXXXXXX    , XXXXXXX
  )

};


// ------------------------------------------------------------------------------------------------------ //

const key_override_t WIN_LIKE_LEFT  = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KC_LEFT, LALT(KC_LEFT),~0,MOD_MASK_CTRL);
const key_override_t WIN_LIKE_RIGHT = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KC_RGHT, LALT(KC_RGHT),~0,MOD_MASK_CTRL);
const key_override_t WIN_LIKE_UP    = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KC_UP  , LALT(KC_UP),  ~0,MOD_MASK_CTRL);
const key_override_t WIN_LIKE_DOWN  = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KC_DOWN, LALT(KC_DOWN),~0,MOD_MASK_CTRL);

const key_override_t WIN_LIKE_DEL   = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC      , KC_DEL        );
const key_override_t WORD_DEL       = ko_make_basic(MOD_MASK_GUI  , KC_BSPC      , LALT(KC_BSPC) );
const key_override_t LINE_DEL       = ko_make_basic(MOD_MASK_ALT  , KC_BSPC      , LGUI(KC_BSPC) );

const key_override_t CTRL_TAB       = ko_make_basic(MOD_MASK_ALT  , KC_TAB       , LCTL(KC_TAB)  );
const key_override_t ALT_TAB        = ko_make_basic(MOD_MASK_CTRL , KC_TAB       , LALT(KC_TAB)  );

const key_override_t DEV_TOOLS      = ko_make_basic(MOD_MASK_ALT  , KC_DEL       , LAG(KC_I)     );
const key_override_t SCREENSHOT     = ko_make_basic(MOD_MASK_ALT  , KC_CAPS      , SGUI(KC_X)    );

const key_override_t MO_6           = ko_make_basic(MOD_MASK_ALT  , TR_6         , TR_RPRN       );
const key_override_t MO_7           = ko_make_basic(MOD_MASK_ALT  , TR_7         , TR_RCBR       );
const key_override_t MO_8           = ko_make_basic(MOD_MASK_ALT  , TR_8         , TR_RBRC       );
const key_override_t MO_9           = ko_make_basic(MOD_MASK_ALT  , TR_9         , TR_RABK       );
const key_override_t MO_0           = ko_make_basic(MOD_MASK_ALT  , TR_0         , TR_BSLS       );

const key_override_t MO_Y           = ko_make_basic(MOD_MASK_ALT  , TR_Y         , TR_LPRN       );
const key_override_t MO_U           = ko_make_basic(MOD_MASK_ALT  , MY_U         , TR_LCBR       );
const key_override_t MO_IDOT        = ko_make_basic(MOD_MASK_ALT  , MY_IDOT      , TR_LBRC       );
const key_override_t MO_O           = ko_make_basic(MOD_MASK_ALT  , MY_O         , TR_LABK       );
const key_override_t MO_P           = ko_make_basic(MOD_MASK_ALT  , TR_P         , TR_SLSH       );

const key_override_t MO_H           = ko_make_basic(MOD_MASK_ALT  , TR_H         , TR_UNDS       );
const key_override_t MO_J           = ko_make_basic(MOD_MASK_ALT  , TR_J         , TR_MINS       );
const key_override_t MO_K           = ko_make_basic(MOD_MASK_ALT  , TR_K         , TR_EQL        );
const key_override_t MO_L           = ko_make_basic(MOD_MASK_ALT  , TR_L         , TR_PLUS       );
const key_override_t MO_AT          = ko_make_basic(MOD_MASK_ALT  , TR_AT        , TR_ASTR       );

const key_override_t MO_2           = ko_make_basic(MOD_MASK_ALT  , TR_2         , TR_CIRC       );

const key_override_t MO_DOT         = ko_make_basic(MOD_MASK_ALT  , TR_DOT       , TR_COLN       );
const key_override_t MO_COMM        = ko_make_basic(MOD_MASK_ALT  , TR_COMM      , TR_SCLN       );
const key_override_t MO_QUOT        = ko_make_basic(MOD_MASK_ALT  , TR_QUOT      , TR_DQUO       );

const key_override_t MO_QUES        = ko_make_basic(MOD_MASK_ALT  , TR_QUES      , TR_EXLM       );
const key_override_t MO_GRV         = ko_make_basic(MOD_MASK_ALT  , TR_GRV       , TR_TILD       );
const key_override_t MO_AMPR        = ko_make_basic(MOD_MASK_ALT  , TR_AMPR      , TR_PIPE       );

// ------------------------------------------------------------------------------------------------------ //

const key_override_t **key_overrides = (const key_override_t *[]){
    &WIN_LIKE_LEFT,
    &WIN_LIKE_RIGHT,
    &WIN_LIKE_UP,
    &WIN_LIKE_DOWN,

    &WIN_LIKE_DEL,
    &WORD_DEL,
    &LINE_DEL,

    // &CTRL_TAB,
    // &ALT_TAB,

    &DEV_TOOLS,
    &SCREENSHOT,

    &MO_6   ,
    &MO_7   ,
    &MO_8   ,
    &MO_9   ,
    &MO_0   ,

    &MO_Y   ,
    &MO_U   ,
    &MO_IDOT,
    &MO_O   ,
    &MO_P   ,

    &MO_H   ,
    &MO_J   ,
    &MO_K   ,
    &MO_L   ,
    &MO_AT  ,

    &MO_2   ,

    &MO_DOT ,
    &MO_COMM,
    &MO_QUOT,

    &MO_QUES,
    &MO_GRV ,
    &MO_AMPR,

    NULL
};

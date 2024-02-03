// ------------------------------------------------------------------------------------------------------ //
// ------------------------------------------------ emoji ----------------------------------------------- //
// ------------------------------------------------------------------------------------------------------ //

enum unicode_names {
    SHRG,  // 🤷🏻‍♂️
    CONFU, // 😕
    FROWN, // 🙁
    UNAMU, // 😒
    DISAP, // 😞

    ROCKT, // 🚀
    HDSUP, // 🙌
    THMUP, // 👍
    CLAP,  // 👏
    SALT,  // 🫡

    GRIN1, // 😄
    GRIN2, // 😀
    SMILE, // 😊
    JOY,   // 😂
    SWSML, // 😅

    FIRE,  // 🔥
    SNAKE, // 🐍

    SUNG,  // 😎
    NERD,  // 🤓
    MONO,  // 🧐

    SCRM,  // 😱
    EXPLD, // 🤯
    EYOP,  // 😳

    PHEW,  // 😌
    PENSV, // 😔
};

const uint32_t PROGMEM unicode_map[] = {
    [SHRG]  = 0x1F937,
    [CONFU] = 0x1F615,
    [FROWN] = 0x1F641,
    [UNAMU] = 0x1F612,
    [DISAP] = 0x1F61E,

    [ROCKT] = 0x1F680,
    [HDSUP]  = 0x1F64C,
    [THMUP] = 0x1F44D,
    [CLAP]  = 0x1F44F,
    [SALT]  = 0x1FAE1,

    [GRIN1]  = 0x1F604,
    [GRIN2]  = 0x1F600,
    [SMILE] = 0x1F60A,
    [JOY]   = 0X1F602,
    [SWSML] = 0x1F605,

    [FIRE] = 0X1F525,
    [SNAKE] = 0x1F40D,

    [SUNG]  = 0x1F60E,
    [NERD]  = 0x1F913,
    [MONO]  = 0x1F9D0,

    [SCRM]  = 0x1F631,
    [EXPLD]  = 0x1F92F,
    [EYOP]  = 0x1F633,

    [PHEW]  = 0x1F60C,
    [PENSV] = 0x1F614,
};

void matrix_init_user(void) {
    set_unicode_input_mode(UNICODE_MODE_MACOS);
}

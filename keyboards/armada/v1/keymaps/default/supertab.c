
bool     is_alt_tab_active  = false; // ADD this near the begining of keymap.c
bool     is_ctrl_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer      = 0;     // we will be using them soon.
uint16_t ctrl_tab_timer     = 0;     // we will be using them soon.

// key processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) { // This will do most of the grunt work with the keycodes.
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case CTL_TAB:
            if (record->event.pressed) {
                if (!is_ctrl_tab_active) {
                    is_ctrl_tab_active = true;
                    register_code(KC_LCTL);
                }
                ctrl_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
    }

    return true;
}

// The very important timer.
void matrix_scan_user(void) {
    if (is_alt_tab_active && timer_elapsed(alt_tab_timer) > 500) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
    if (is_ctrl_tab_active && timer_elapsed(ctrl_tab_timer) > 500) {
        unregister_code(KC_LCTL);
        is_ctrl_tab_active = false;
    }
}

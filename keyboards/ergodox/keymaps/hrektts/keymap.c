#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "sendchar.h"
#include "virtser.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Base layer
     * ,--------------------------------------------------.      ,--------------------------------------------------.
     * |   +=   |  !1  |  @2  |  #3  |  $4  |  %5  | Mute |      | PrtSc|  ^6  |  &7  |  *8  |  (9  |  )0  |   _-   |
     * |--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
     * |  Tab   |  Qq  |  Ww  |  Ee  |  Rr  |  Tt  | VolUp|      |  L1  |  Yy  |  Uu  |  Ii  |  Oo  |  Pp  |   |\   |
     * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
     * | LCtrl  |  Aa  |  Ss  |  Dd  |  Ff  |  Gg  |------|      |------|  Hh  |  Jj  |  Kk  |  Ll  |  :;  |   "'   |
     * |--------+------+------+------+------+------| VolDn|      |  Heh |------+------+------+------+------+--------|
     * | LShift |  Zz  |  Xx  |  Cc  |  Vv  |  Bb  |      |      |      |  Nn  |  Mm  |  <,  |  >.  |  ?/  | RShift |
     * `--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
     *   | L2/`~|  '"  | LAlt | Left | Right|                                  |  Up  | Down |  {[  |  }]  | RGui   |
     *   `----------------------------------'                                  `------------------------------------'
     *                                      ,---------------.  ,---------------.
     *                                      |   App  | LGui |  | RAlt |Ctrl/Esc|
     *                               ,------|--------|------|  |------+--------+------.
     *                               |      |        | Home |  | Pgup |        |      |
     *                               | Space|  Back  |------|  |------|  Del   |Enter |
     *                               |      |  space | End  |  | Pgdw |        |      |
     *                               `----------------------'  `----------------------'
     */
    [BASE] = KEYMAP(
        // left hand
        KC_EQL,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MUTE,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_VOLU,
        KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_VOLD,
        LT(MDIA, KC_GRV), KC_QUOT, KC_LALT, KC_LEFT, KC_RGHT,
                                                     KC_APP,  KC_LGUI,
                                                              KC_HOME,
                                            KC_SPC,  KC_BSPC, KC_END,
        // right hand
        KC_PSCR,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_FN1,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        MEH_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, KC_RGUI,
        KC_RALT,      CTL_T(KC_ESC),
        KC_PGUP,
        KC_PGDN,      KC_DELT,  KC_ENT
    ),

    /* Layer 1: Symbol layer
     * ,--------------------------------------------------.      ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
     * |--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
     * |        |   !  |   @  |   {  |   }  |   |  |  L0  |      |  L2  |   Up |   7  |   8  |   9  |   *  |   F12  |
     * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
     * |        |   #  |   $  |   (  |   )  |   `  |------|      |------| Down |   4  |   5  |   6  |   +  |        |
     * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
     * |        |   %  |   ^  |   [  |   ]  |   ~  |      |      |      |   &  |   1  |   2  |   3  |   \  |        |
     * `--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                  |      |    . |   0  |   =  |      |
     *   `----------------------------------'                                  `----------------------------------'
     *                                        ,-------------.  ,-------------.
     *                                        |      |      |  |      |      |
     *                                 ,------|------|------|  |------+------+------.
     *                                 |      |      |      |  |      |      |      |
     *                                 |      |      |------|  |------|      |      |
     *                                 |      |      |      |  |      |      |      |
     *                                 `--------------------'  `--------------------'
     *
     */
    [SYMB] = KEYMAP(
        // left hand
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
        KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_FN0,
        KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
        KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_FN2,  KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
                 KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
        KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                          KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* Layer 2: Media and mouse keys
     *
     * ,--------------------------------------------------.      ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |      |      |      |      | MsUp |      |      |        |
     * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|      |------|      |MsLeft|MsDown|MsRght|      |  Play  |
     * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |      |      |      |      | Prev | Next |      |        |
     * `--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
     *   |      |      |      | Lclk | Rclk |                                  |VolUp |VolDn | Mute |      |      |
     *   `----------------------------------'                                  `----------------------------------'
     *                                        ,-------------.  ,-------------.
     *                                        |      |      |  |      |      |
     *                                 ,------|------|------|  |------+------+------.
     *                                 |      |      |      |  |      |      |Brwser|
     *                                 |      |      |------|  |------|      |Back  |
     *                                 |      |      |      |  |      |      |      |
     *                                 `--------------------'  `--------------------'
     */
    [MDIA] = KEYMAP(
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_MPLY,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_WBAK
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_SET_CLEAR(BASE),    // FN0 - Clear All Layers Set 0 (Base)
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),   // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(MDIA)    // FN2 - Momentary Layer 2 (Media)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};

#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "vim.h"

#define VERSION_STRING QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
#define X_____X KC_TRNS
#define TO_NORM  TT(NORM)
#define TO_BASE  TO(BASE)
#define TO_MDIA  TT(MDIA)
#define TO_REACH TT(REACH)

/* key combos */
/* https://github.com/qmk/qmk_firmware/pull/960 */
/* const uint16_t PROGMEM test_combo[] = { KC_9, KC_0, COMBO_END }; */
/* combo_t key_combos[COMBO_COUNT] = { COMBO(test_combo, KC_PWR) }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Insert mode
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |    `   |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |  CAPS  |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |   ⇥    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |  ⌃/⎋   |⇧ /A  | ⌃/S  | ⌥ /D | ⌘ /F |HYP/G |------|           |------|HYP/H | ⌘ /J | ⌥ /K |⌃ / L | ⇧ /; |   '    |
  * |--------+------+------+------+------+------|   -  |           |   =  |------+------+------+------+------+--------|
  * |  ⇧ /(  |   Z  |   X  |   C  |   V  |  B   |      |           |      |   N  |   M  |   ,  |   .  |   /  | R⇧ /)  |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      | MDIA | NORM |                                       |REACH |  ←   |  ↓   |  ↑   |  →   |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 | BSPC |      |      |       |      |      |      |
  *                                 |      |DELETE|------|       |------| ENTER| SPC  |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [BASE] = LAYOUT_ergodox(
    // Left Hand
    KC_GRAVE       , KC_1         , KC_2         , KC_3         , KC_4         , KC_5            , X_____X ,
    KC_TAB         , KC_Q         , KC_W         , KC_E         , KC_R         , KC_T            , KC_LBRC ,
    LCTL_T(KC_ESC) , LSFT_T(KC_A) , LCTL_T(KC_S) , LALT_T(KC_D) , LGUI_T(KC_F) , ALL_T(KC_G)     ,
    KC_LSPO        , KC_Z         , KC_X         , KC_C         , KC_V         , KC_B            , KC_MINS ,
    X_____X        , X_____X      , X_____X      , TO_MDIA      , TO_NORM      ,

              X_____X , X_____X ,
                        X_____X ,
    KC_BSPC , KC_DEL  , X_____X ,

    // Right Hand
    X_____X        , KC_6         , KC_7         , KC_8         , KC_9         , KC_0            , KC_CAPS         ,
    KC_RBRC        , KC_Y         , KC_U         , KC_I         , KC_O         , KC_P            , KC_BSLS         ,
                     ALL_T(KC_H)  , RGUI_T(KC_J) , RALT_T(KC_K) , RCTL_T(KC_L) , RSFT_T(KC_SCLN) , RCTL_T(KC_QUOT) ,
    KC_EQL         , KC_N         , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH         , KC_RSPC         ,
                                    TO_REACH     , KC_LEFT      , KC_DOWN      , KC_UP           , KC_RIGHT        ,

    X_____X , X_____X ,
    X_____X ,
    X_____X , KC_ENT  , KC_SPC
  ),

  /* Normal (vim) mode 
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |  TAB   |      | WORD |  END |      |      |      |           |      | YANK | UNDO |      | OPEN |  PUT |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |    ⎋   |      |      |  DEL |      |      |------|           |------|  ←   |  ↓   |  ↑   |  →   |      |    ⎋   |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * | SHIFT  |      |      | CHNG | VISL | BACK |      |           |      | NEXT | PREV |      |      |      | SHIFT  |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      | MDIA | BASE |                                       |REACH |      |      |      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 | BSPC |DELETE|------|       |------|ENTER |SPACE |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [NORM] = LAYOUT_ergodox(
    // Left Hand
    X_____X , X_____X , X_____X , X_____X , X_____X , X_____X , X_____X ,
    X_____X , X_____X , VIM_W   , VIM_E   , X_____X , X_____X , X_____X ,
    X_____X , VIM_A   , VIM_S   , VIM_D   , X_____X , X_____X ,
    KC_LSFT , X_____X , VIM_X   , VIM_C   , VIM_V   , VIM_B   , X_____X ,
    X_____X , X_____X , X_____X , TO_MDIA , TO_BASE ,

             X_____X, X_____X,
                      X_____X,
    KC_BSPC, KC_DEL , X_____X,

    // Right Hand
    X_____X , X_____X , X_____X , X_____X , X_____X , X_____X  , X_____X ,
    X_____X , VIM_Y   , VIM_U   , VIM_I   , VIM_O   , VIM_P    , X_____X ,
              VIM_H   , VIM_J   , VIM_K   , VIM_L   , X_____X  , X_____X ,
    X_____X , VIM_N   , X_____X , X_____X , X_____X , VIM_SLSH , KC_RSFT ,
                        TO_REACH , X_____X , X_____X , X_____X  , X_____X ,

    X_____X, X_____X,
    X_____X,
    X_____X, KC_ENT , KC_SPC
  ),


  [MDIA] = LAYOUT_ergodox(
    // Left Hand
    RESET   , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , X_____X ,
    X_____X , X_____X , X_____X , X_____X , X_____X , X_____X , X_____X ,
    X_____X , X_____X , X_____X , X_____X , X_____X , X_____X ,
    X_____X , X_____X , X_____X , X_____X , X_____X , X_____X , X_____X ,
    X_____X , X_____X , X_____X , TO_BASE , TO_NORM ,

              KC_F14  , KC_F15  ,
                        X_____X ,
    KC_MFFD , KC_MPRV , X_____X ,

    // Right Hand
    X_____X , KC_F6         , KC_F7   , KC_F8   , KC_F9   , KC_F10        , KC_PWR  ,
    X_____X , SGUI(KC_LBRC) , KC_BTN1 , KC_MS_U , KC_BTN2 , SGUI(KC_RBRC) , X_____X ,
              LGUI(KC_LBRC) , KC_MS_L , KC_MS_D , KC_MS_R , LGUI(KC_RBRC) , X_____X ,
    X_____X , X_____X       , X_____X , X_____X , X_____X , X_____X       , X_____X ,
                              TO_REACH, KC_LEFT , KC_DOWN , KC_UP         , KC_RGHT ,

    KC_VOLD , KC_VOLU,
    KC_MUTE ,
    X_____X , KC_MSTP , KC_MPLY
  ),

  /* Reachability™ mode
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |   ⎋    |      |      |      |      |      |      |           |      |      |      |      |      |      |  CAPS  |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |   ⇥    |   !  |   @  |   #  |   $  |   %  |  [   |           |   ]  |   ^  |   &  |   *  |   [  |   ]  |   \    |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |    `   |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |   '    |
  * |--------+------+------+------+------+------|   -  |           |   =  |------+------+------+------+------+--------|
  * |  ⇧ /(  |      |      |      |      |      |      |           |      |   -  |   =  |   ,  |   .  |   /  | R⇧ /)  |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      | MDIA | NORM |                                       | BASE |  ←   |  ↓   |  ↑   |  →   |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 | BSPC |DELETE|------|       |------| ENTER| SPC  |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [REACH] = LAYOUT_ergodox(
    // Left Hand
    KC_ESC   , X_____X , X_____X , X_____X  , X_____X  , X_____X  , X_____X  ,
    KC_TAB   , KC_EXLM , KC_AT   , KC_HASH  , KC_DLR   , KC_PERC  , KC_LBRC  ,
    KC_GRAVE , KC_1    , KC_2    , KC_3     , KC_4     , KC_5     ,
    KC_LSPO  , X_____X , X_____X , X_____X  , X_____X  , X_____X  , KC_MINS  ,
    X_____X  , X_____X , X_____X , TO_MDIA  , TO_NORM  ,

               X_____X , X_____X ,
                         X_____X ,
    KC_BSPC  , KC_DEL  , X_____X ,

    // Right Hand
    X_____X   , X_____X , X_____X   , X_____X , X_____X  , X_____X  , KC_CAPS  ,
    KC_RBRC   , KC_CIRC , KC_AMPR   , KC_ASTR , KC_LBRC  , KC_RBRC  , KC_BSLS  ,
                KC_6    , KC_7      , KC_8    , KC_9     , KC_0     , KC_QUOT  ,
    KC_EQL    , KC_MINS , KC_EQL    , KC_COMM , KC_DOT   , KC_SLSH  , KC_RSPC  ,
                          TO_REACH  , KC_LEFT , KC_DOWN  , KC_UP    , KC_RIGHT ,

    X_____X   , X_____X ,
    X_____X   ,
    X_____X   , KC_ENT  , KC_SPC
  ),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case 0:
        if (record->event.pressed) { SEND_STRING (VERSION_STRING); }
        break;
  }
return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* if (!process_record_dynamic_macro(keycode, record)) { */
  /*   return false; */
  /* } */

  bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) |
                 (keyboard_report->mods & MOD_BIT(KC_RSFT));

  switch (keycode) {

    case VIM_A:
      if (record->event.pressed) { SHIFTED ? VIM_APPEND_LINE() : VIM_APPEND(); }
      return false;

    case VIM_B:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: VIM_BACK(); break;
          case VIM_C: VIM_CHANGE_BACK(); break;
          case VIM_D: VIM_DELETE_BACK(); break;
          case VIM_V: VIM_VISUAL_BACK(); break;
        }
      }
      return false;

    case VIM_C:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_CHANGE_LINE() : VIM_LEADER(VIM_C); break;
          case VIM_C: VIM_CHANGE_WHOLE_LINE(); break;
        }
      }
      return false;

    case VIM_D:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_DELETE_LINE() : VIM_LEADER(VIM_D); break;
          case VIM_D: VIM_DELETE_WHOLE_LINE(); break;
        }
      }
      return false;

    case VIM_E:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_END(); break;
          case VIM_C: VIM_CHANGE_END(); break;
          case VIM_D: VIM_DELETE_END(); break;
          case VIM_V: VIM_VISUAL_END(); break;
        }
      }
      return false;

    case VIM_H:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_LEFT(); break;
          case VIM_C: VIM_CHANGE_LEFT(); break;
          case VIM_D: VIM_DELETE_LEFT(); break;
          case VIM_V: VIM_VISUAL_LEFT(); break;
        }
      }
      return false;

    case VIM_I:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: layer_on(BASE); break;
          case VIM_C: VIM_LEADER(VIM_CI); break;
          case VIM_D: VIM_LEADER(VIM_DI); break;
          case VIM_V: VIM_LEADER(VIM_VI); break;
        }
      }
      return false;

    case VIM_J:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_JOIN() : VIM_DOWN(); break;
          case VIM_C: VIM_CHANGE_DOWN(); break;
          case VIM_D: VIM_DELETE_DOWN(); break;
          case VIM_V: VIM_VISUAL_DOWN(); break;
        }
      }
      return false;

    case VIM_K:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_UP(); break;
          case VIM_C: VIM_CHANGE_UP(); break;
          case VIM_D: VIM_DELETE_UP(); break;
          case VIM_V: VIM_VISUAL_UP(); break;
        }
      }
      return false;

    case VIM_L:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_RIGHT(); break;
          case VIM_C: VIM_CHANGE_RIGHT(); break;
          case VIM_D: VIM_DELETE_RIGHT(); break;
          case VIM_V: VIM_VISUAL_RIGHT(); break;
        }
      }
      return false;

    case VIM_N:
      if (record->event.pressed) { SHIFTED ? VIM_FIND_PREV() : VIM_FIND_NEXT(); }
      return false;

    case VIM_O:
      if (record->event.pressed) { SHIFTED ? VIM_OPEN_ABOVE() : VIM_OPEN(); }
      return false;

    case VIM_P:
      if (record->event.pressed) { SHIFTED ? VIM_PUT_BEFORE() : VIM_PUT(); }
      return false;

    case VIM_S:
      if (record->event.pressed) { SHIFTED ? VIM_CHANGE_WHOLE_LINE() : VIM_SUBSTITUTE(); }
      return false;

    case VIM_U:
      if (record->event.pressed) { VIM_UNDO(); }
      return false;

    case VIM_V:
      if (record->event.pressed) { VIM_LEADER(VIM_V); }
      return false;

    case VIM_W:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_WORD(); break;
          case VIM_C: VIM_CHANGE_WORD(); break;
          case VIM_CI: VIM_CHANGE_INNER_WORD(); break;
          case VIM_D: VIM_DELETE_WORD(); break;
          case VIM_DI: VIM_DELETE_INNER_WORD(); break;
          case VIM_V: VIM_VISUAL_WORD(); break;
          case VIM_VI: VIM_VISUAL_INNER_WORD(); break;
        }
      }
      return false;

    case VIM_X:
      if (record->event.pressed) { VIM_CUT(); }
      return false;

    case VIM_Y:
      if (record->event.pressed) { SHIFTED ? VIM_YANK_LINE() : VIM_YANK(); }
      return false;

    case VIM_SLSH:
      if (record->event.pressed) { VIM_FIND(); }
      return false;

    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) { eeconfig_init(); }
      return false;
    case VRSN:
      if (record->event.pressed) { SEND_STRING(VERSION_STRING); }
      return false;
    case RGB_SLD:
      if (record->event.pressed) { rgblight_mode(1); }
      return false;
  }

  // End by clearing the queue unless keycode is a
  // if ((record->event.pressed) &&
  //     (keycode != VIM_I ||
  //     keycode != VIM_C ||
  //     keycode != VIM_D ||
  //     keycode != VIM_V)) {
  //   VIM_LEADER(KC_NO);
  // }

  return true;
};

void matrix_init_user(void) {
  debug_enable = true;
  VIM_LEADER(KC_NO);
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};

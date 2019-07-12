#include QMK_KEYBOARD_H

 /*       Left Hand                                   Right Hand
      --+-+-+-+-+--                                  --+-+-+-+-+--
      |~|1|2|3|4|5| <-------                 ------> |<|7|8|9|0|-|
    --+-+-+-+-+-+-+        ¦                ¦        +-+-+-+-+-+-+--
    |e|@|Q|W|E|R|T| <----- ¦                ¦ -----> |Y|U|I|O|P|[|p|
    +-+-+-+-+-+-+-+      ¦ ¦                ¦ ¦      +-+-+-+-+-+-+-+
    |t|<|A|S|D|F|G| <--- ¦ ¦                ¦ ¦ ---> |H|J|K|L|;|e|p|
    --+-+-+-+-+-+-+    ¦ ¦ ¦                ¦ ¦ ¦    +-+-+-+-+-+-+--
      |l|Z|X|C|V|B| <- ¦ ¦ ¦                ¦ ¦ ¦ -> |N|M|,|.|/|r|
     ^--+-+-+-+-+-+- ¦ ¦ ¦ ¦                ¦ ¦ ¦ ¦ -+-+-+-+-+-+--^
     |------------|m|¦ ¦ ¦ ¦                ¦ ¦ ¦ ¦|a|------------|
                  --+- ¦ ¦ ¦                ¦ ¦ ¦ -+--
                    |c|¦ ¦ ¦                ¦ ¦ ¦¦s|
                    --+- ¦ ¦                ¦ ¦ -+--
                      |s|¦ ¦                ¦ ¦| |
                      --+- ¦                ¦ -+--
                        |f|¦                ¦|f|
                        --+--              --+--
                          |w|              |f|
                          ---              ---                       */

/*
                                                  раскладки старой клавиатуры!!!
#define _MAIN 0
#define _RAISE 1
#define _LOWER 2

// Readability keycodes
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


 MAIN
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | Backsp | Delete |   7    |   8    |   9    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ESC    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      |  PgUp  |   4    |   5    |   6    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SHIFT  | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | ENTER  |  PgDn  |   1    |   2    |   3    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LCTRL  |  PAUS  | GUI    | ALT    | Lower  | Space  |  Space | Raise  | Left   | Down   | Up     | Right  |  Shift |   0    |   .    |  ENTER |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'

  [_MAIN] = LAYOUT_ortho_4x16(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL, KC_KP_7, KC_KP_8, KC_KP_9,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_PGUP, KC_KP_4, KC_KP_5, KC_KP_6,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  KC_PGDN, KC_KP_1, KC_KP_2, KC_KP_3,
  KC_LCTL, KC_PAUS, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RSFT, KC_KP_0, KC_KP_DOT, KC_PENT
  ),

RAISE
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * |    `   |  1     |  2     |  3     |  4     |  5     |  6     |  7     |  8     |  9     |  0     |        | Insert |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        | -      | =      | [      | ]      |   \    |  Home  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |  ISO # |  ISO / |        |        |  PScr  |  End   |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |                 |        |  Next  |  Vol-  |  Vol+  |  Play  |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'

  [_RAISE] = LAYOUT_ortho_4x16(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_INS, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_NUBS, _______, _______, KC_PSCR, KC_END, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, _______, _______
  ),

// LOWER
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * |    ~   |    !   |    @   |    #   |    $   |    %   |    ^   |    &   |    *   |    (   |    )   |        |        |        |        | Reset  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |    _   |    +   |    {   |    }   |   |    |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   | ISO ~  | ISO |  |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |                 |        |        |        |        |  Mute  |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'

  [_LOWER] = LAYOUT_ortho_4x16(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,  _______, _______, _______, RESET,
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS,  KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______, _______,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS), _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______
  ),

};                                         конец старых раскладов
*/       

    /* Macro definition */
    enum macro_id {
        ONCAPS,
        OFFCAPS,
        NUMOFFP5ON,
    };

    const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
    {
        keyevent_t event = record->event;
        //uint8_t tap_count = record->tap_count;

        switch (id) {
    case ONCAPS:
      return (event.pressed ?
        MACRO( D(LCAP), D(LNUM), END ) :
        MACRO( END ) );
    case OFFCAPS:
      return (event.pressed ?
        MACRO( U(LCAP), D(LNUM), END ) :
        MACRO( END ) );
//    case ONNUM:
//      return (event.pressed ?
//        MACRO( D(LNUM), END ) :
//        MACRO( END ) );
    case NUMOFFP5ON:
      return (event.pressed ?
        MACRO( U(LNUM), W(10), T(P5), W(10), D(LNUM), END ) :
        MACRO( END ) );
      
        }
        return MACRO_NONE;
    }

#define _MAIN 0           // 0: Normal keys letters and punctuation
#define _ARROWS 1         // 1: On the two hand — arrows keys
#define _NUMBERS 2        // 2: On the two hand — digits
#define _LARROW 3         // 3: On the left hand — arrow keys, on the right hand — digits
#define _RARROW 4         // 4: On the right hand — arrow keys, on the left hand — digits
#define _PURESHIFTFUNC 5  // 5: «Pure» and with Shift Fx keys
#define _ALTCTRLFUNC 6    // 6: Fx keys with Alt and Ctrl
#define _SPECIALCHARS 7   // 7: Special Characters

// Readability keycodes
#define K_MAIN   ACTION_DEFAULT_LAYER_SET(_MAIN)
#define ARROWS   ACTION_DEFAULT_LAYER_SET(_ARROWS)
#define NUMBRS   ACTION_DEFAULT_LAYER_SET(_NUMBERS)
#define LARROW   ACTION_LAYER_MOMENTARY(_LARROW)
#define RARROW   ACTION_LAYER_MOMENTARY(_RARROW)
#define FUNCSH   ACTION_LAYER_MOMENTARY(_PURESHIFTFUNC)
#define FUNCAC   ACTION_LAYER_MOMENTARY(_ALTCTRLFUNC)
#define SPECCH   ACTION_LAYER_TAP_KEY(_SPECIALCHARS, KC_APP)

const uint16_t PROGMEM fn_actions[] = {
  [4] = ACTION_MACRO(ONCAPS),      //vkluchaem CapsLock — tam u nas russkie bukvy
  [5] = ACTION_MACRO(OFFCAPS),     //otkluchaem CapsLock — perehodim na latinicu
  [7] = ACTION_MACRO(NUMOFFP5ON),  //otkluchaet NumLock, vvodit 5 na cyfrovoj klave, vkluchaet Num — dlq FARa
  [8] = ACTION_MODS_KEY(MOD_LCTL|MOD_LSFT, KC_ESC), // TaskManager (Control,Shift+Esc)
};

/*const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(3), // to LFn overlay
//  [0] = ACTION_LAYER_ON_OFF(3), // to LFn overlay
  [1] = ACTION_LAYER_MOMENTARY(4), // to RFn overlay
//  [1] = ACTION_LAYER_ON_OFF(4), // to RFn overlay
  [2] = ACTION_LAYER_MOMENTARY(5), // to CFx overlay - «Pure» and with Shift Fx keys
//  [2] = ACTION_LAYER_ON_OFF(5), // to CFx overlay - «Pure» and with Shift Fx keys
  [3] = ACTION_LAYER_TAP_KEY(_SPECIALCHARS, KC_APP), // to special symbols width APP key

  [6] = ACTION_MACRO(ONNUM),       //vkluchaet NumLock, chtoby cyfry vvodit

  [9] = ACTION_LAYER_MOMENTARY(6), // to CACFx overlay - Fx keys with Alt and Ctrl
  [10] = ACTION_DEFAULT_LAYER_SET(0),    // switch to layer Default Letters
  [11] = ACTION_DEFAULT_LAYER_SET(1),    // switch to layer Arrows
  [12] = ACTION_DEFAULT_LAYER_SET(2),    // switch to layer Numbers
  [13] = ACTION_MACRO(FN0M),  

//ACTION_LAYER_CLEAR(ON_RELEASE)

// Akcii rabotaut!!!

  [10] = ACTION_MOUSEKEY(KC_WH_U), // wheel
  [11] = ACTION_MOUSEKEY(KC_MS_U), // mouse movement

//  Primery akcij iz drugih klaviatur
    [3] = ACTION_DEFAULT_LAYER_SET(0)
    [3] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_APP),
    [0] = ACTION_LAYER_MODS(1, MOD_LSFT),
    [0] = ACTION_DEFAULT_LAYER_SET(0),                // Default layer(not used)
    [1] = ACTION_LAYER_TAP_TOGGLE(1),                 // HHKB layer(toggle with 5 taps)
    [2] = ACTION_LAYER_TAP_KEY(2, KC_SLASH),          // Cursor layer with Slash*
    [3] = ACTION_LAYER_TAP_KEY(3, KC_SCLN),           // Mousekey layer with Semicolon*
    [4] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),      // RControl with tap Enter*
    [5] = ACTION_MODS_ONESHOT(MOD_LSFT),              // Oneshot Shift*
    [6] = ACTION_LAYER_TAP_KEY(5, KC_SPC),            // Mousekey layer with Space
    [7] = ACTION_LAYER_TOGGLE(3),                     // Mousekey layer(toggle)
    [8] = ACTION_MODS_KEY(MOD_LCTL, KC_W),            // Close Tab
    [9] = ACTION_MODS_KEY(MOD_LSFT, KC_4),            // Shift stuck test

  [8] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_BSPC),       // LControl with tap Backspace
  [9] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_ESC),        // LControl with tap Esc
  [11] = ACTION_FUNCTION_TAP(LSHIFT_LPAREN),         // Function: LShift with tap '('
  [12] = ACTION_FUNCTION_TAP(RSHIFT_RPAREN),         // Function: RShift with tap ')'
  [13] = ACTION_MACRO_TAP(LSHIFT_PAREN),             // Macro: LShift with tap '('
  [14] = ACTION_MACRO_TAP(RSHIFT_PAREN),             // Macro: RShift with tap ')'
  [15] = ACTION_MACRO(HELLO),                        // Macro: say hello
  [9] = ACTION_MACRO(VOLUP),                         // Macro: media key
  [3] = ACTION_FUNCTION(BOOTLOADER), // ToDo — BootLoader
  [4] = ACTION_LAYER_TAP_KEY(4, KC_VOLU), // perekluchenie na russkij
  [5] = ACTION_LAYER_TAP_KEY(0, KC_VOLD) // perekluchenie na anglijskij
  [6] = ACTION_MODS_KEY(MOD_RCTL|MOD_RSFT, KC_ESC), // Task(RControl,RShift+Esc)
  [7] = ACTION_LAYER_TAP_KEY(0, ALT(KC_P0), ALT(KC_P1), ALT(KC_P7), ALT(KC_P1)) // Task(RAlt+0171)
  
  MACRO( D(LALT), T(H), T(D), U(LALT), END ) eto budet zazhatie levogo alta, nazhatie H zatem nazhatie D i otpuskanie alta


  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER), // reset for uploading new code
  [4] = ACTION_LAYER_ON(3, 1),  // switch to layer 2
  [5] = ACTION_LAYER_OFF(3, 1),  // switch back to layer 0

  [6] = ACTION_MOUSEKEY(KC_MS_U), // mouse movement
  [7] = ACTION_MOUSEKEY(KC_MS_D),
  [8] = ACTION_MOUSEKEY(KC_MS_L),
  [9] = ACTION_MOUSEKEY(KC_MS_R),
  [10] = ACTION_MOUSEKEY(KC_WH_U), // wheel
  [11] = ACTION_MOUSEKEY(KC_WH_D),
  [12] = ACTION_MOUSEKEY(KC_WH_L),
  [13] = ACTION_MOUSEKEY(KC_WH_R),
  [14] = ACTION_MOUSEKEY(KC_BTN1), // clicks
  [15] = ACTION_MOUSEKEY(KC_BTN2),
  [16] = ACTION_MOUSEKEY(KC_BTN3),
  [17] = ACTION_MOUSEKEY(KC_BTN4),
  [18] = ACTION_MOUSEKEY(KC_BTN5),
  [19] = ACTION_MOUSEKEY(KC_ACL0), // acceleration settings
  [20] = ACTION_MOUSEKEY(KC_ACL1),
  [21] = ACTION_MOUSEKEY(KC_ACL2),
*/

/* The default kKeyb layout. Layer is normal keys and punctuation */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦      ;      ¦      (      ¦       "     ¦      «      ¦      !      ¦      +      ¦    Win      ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     ESC      ¦      @      ¦      J      ¦       C     ¦      U      ¦      K      ¦      Y      ¦   LARROW    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦ LeftArrows  ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     TAB      ¦  BackSpace  ¦      Q      ¦       E     ¦      V      ¦      A      ¦      P      ¦  LeftShift  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     APP      ¦     FN5     ¦      F      ¦      <      ¦      S      ¦      M      ¦      I      ¦ LeftControl ¦
        ¦Special Chars ¦     LAT     ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦    FUNCSH    ¦  BackSpace  ¦      -      ¦      »      ¦      :      ¦      )      ¦      /      ¦     none
        ¦Function Keys ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦    RARROW    ¦      N      ¦      G      ¦      W      ¦      H      ¦      Z      ¦     #       ¦ PrintScreen ¦
        ¦ RightArrows  ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   Space      ¦      R      ¦      O      ¦      L      ¦      D      ¦      \      ¦   Enter     ¦   Pause     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  RightShift  ¦      T      ¦      X      ¦      B      ¦      >      ¦      ,      ¦     FN4     ¦   Left Alt  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦     RUS     ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
//First four lines — the left hand, next four lines — the right hand
[_MAIN] = LAYOUT_ortho_4x16(
         KC_NO,         KC_GRV,         KC_1,           KC_2,           KC_3,          KC_4,           KC_5,      KC_LGUI,
        KC_ESC,        KC_QUOT,         KC_J,           KC_C,           KC_U,          KC_K,           KC_Y,      LARROW,
        KC_TAB,        KC_BSPC,         KC_Q,           KC_E,           KC_V,          KC_A,           KC_P,      KC_LSFT,
        SPECCH,         KC_FN5,         KC_F,        KC_COMM,           KC_S,          KC_M,           KC_I,      KC_LCTL,

        FUNCSH,        KC_BSPC,         KC_7,           KC_8,           KC_9,          KC_0,        KC_MINS,        KC_NO,
        RARROW,           KC_N,         KC_G,           KC_W,           KC_H,          KC_Z,        KC_LBRC,      KC_PSCR,
        KC_SPC,           KC_R,         KC_O,           KC_L,           KC_D,       KC_SCLN,         KC_ENT,      KC_PAUS,
       KC_RSFT,           KC_T,         KC_X,           KC_B,         KC_DOT,       KC_SLSH,         KC_FN4,      KC_LALT),

/* 1: FN_ARROWS_LAYER On the left and right hands — arrows keys */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦      +      ¦       -     ¦      *      ¦      /      ¦     none    ¦    Win      ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     PgUp    ¦     End     ¦   Empty(5)  ¦     Home    ¦     none    ¦   LARROW    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦ LeftArrows  ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Tab      ¦   BackSpace ¦     PgDn    ¦     Left    ¦      Up     ¦     Right   ¦    Enter    ¦  LeftShift  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Arrows   ¦    Normal   ¦     none    ¦    Delete   ¦     Down    ¦      Ins    ¦     none    ¦     none    ¦
        ¦      Lock    ¦     Lock    ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand 
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦  BackSpace  ¦      /      ¦      *      ¦      -      ¦      +      ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     RARROW   ¦     none    ¦     Home    ¦   Empty(5)  ¦      End    ¦     PgUp    ¦     none    ¦     none    ¦
        ¦  RightArrows ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  Left Shift  ¦     Enter   ¦     Left    ¦      Up     ¦     Right   ¦     PgDn    ¦   NumEnter  ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦ Left Control ¦     none    ¦      Ins    ¦     Down    ¦     Delete  ¦     none    ¦    Normal   ¦    Arrows   ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦     Lock    ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------                                                                                                
*/

//First four lines — the left hand, next four lines — the right hand
[_ARROWS] = LAYOUT_ortho_4x16(
         KC_NO,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,      KC_LGUI,
         KC_NO,          KC_NO,      KC_PGUP,         KC_END,         KC_FN7,       KC_HOME,          KC_NO,      LARROW,
        KC_TAB,        KC_BSPC,      KC_PGDN,        KC_LEFT,          KC_UP,       KC_RGHT,         KC_ENT,      KC_LSFT,
        ARROWS,         K_MAIN,        KC_NO,      KC_DELETE,        KC_DOWN,        KC_INS,          KC_NO,        KC_NO,

         KC_NO,        KC_BSPC,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,        KC_NO,
        RARROW,          KC_NO,      KC_HOME,         KC_FN7,         KC_END,       KC_PGUP,          KC_NO,        KC_NO,
       KC_LSFT,         KC_ENT,      KC_LEFT,          KC_UP,        KC_RGHT,       KC_PGDN,        KC_PENT,        KC_NO,
       KC_LCTL,          KC_NO,       KC_INS,        KC_DOWN,      KC_DELETE,         KC_NO,         K_MAIN,       ARROWS),

/* 2: FN_NUMBERS_LAYER On the left and right hands — digits */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦      +      ¦       -     ¦      *      ¦      /      ¦     none    ¦    Win      ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦      1      ¦      2      ¦      3      ¦     none    ¦    LARROW   ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦  LeftArrows ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Tab      ¦  BackSpace  ¦     none    ¦      4      ¦      5      ¦      6      ¦     Enter   ¦      0      ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦    Normal   ¦      ,      ¦      7      ¦      8      ¦      9      ¦      .      ¦     Num     ¦
        ¦              ¦     Lock    ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦    FUNCSH    ¦  BackSpace  ¦      /      ¦      *      ¦      -      ¦      +      ¦     none    ¦     none
        ¦Function Keys ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦    RARROW    ¦     none    ¦      7      ¦      8      ¦      9      ¦     none    ¦     none    ¦     none    ¦
        ¦ RightArrows  ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦      0       ¦     Enter   ¦      4      ¦      5      ¦      6      ¦     none    ¦   NumEnter  ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Num      ¦      .      ¦      1      ¦      2      ¦      3      ¦      ,      ¦    Normal   ¦     none    ¦
        ¦     Lock     ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
[_NUMBERS] = LAYOUT_ortho_4x16(
         KC_NO,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,      KC_LGUI,
         KC_NO,          KC_NO,        KC_NO,          KC_P1,          KC_P2,         KC_P3,          KC_NO,       LARROW,
        KC_TAB,        KC_BSPC,        KC_NO,          KC_P4,          KC_P5,         KC_P6,         KC_ENT,        KC_P0,
         KC_NO,         K_MAIN,      KC_SLSH,          KC_P7,          KC_P8,         KC_P9,     S(KC_SLSH),       NUMBRS,

        FUNCSH,        KC_BSPC,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,        KC_NO,
        RARROW,          KC_NO,        KC_P7,          KC_P8,          KC_P9,         KC_NO,          KC_NO,        KC_NO,
         KC_P0,         KC_ENT,        KC_P4,          KC_P5,          KC_P6,         KC_NO,        KC_PENT,        KC_NO,
        NUMBRS,     S(KC_SLSH),        KC_P1,          KC_P2,          KC_P3,       KC_SLSH,         K_MAIN,        KC_NO),

/* 3: FN_LARROW_LAYER On the left hand — arrows keys, on the right hand — digits */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦      +      ¦       -     ¦      *      ¦      /      ¦     none    ¦     none    ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     PgUp    ¦     End     ¦    Empty    ¦     Home    ¦     none    ¦   LARROW    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦ LeftArrows  ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   Alt+Tab    ¦   BackSpace ¦     PgDn    ¦     Left    ¦      Up     ¦     Right   ¦    Enter    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Arrows   ¦    Normal   ¦     none    ¦    Delete   ¦     Down    ¦      Ins    ¦     none    ¦     Num     ¦
        ¦      Lock    ¦     Lock    ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦  BackSpace  ¦      /      ¦      *      ¦      -      ¦      +      ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  Ctrl+Shift  ¦     none    ¦      7      ¦      8      ¦      9      ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦      0       ¦     none    ¦      4      ¦      5      ¦      6      ¦     none    ¦   NumEnter  ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  RightShift  ¦      .      ¦      1      ¦      2      ¦      3      ¦      ,      ¦    Normal   ¦   LeftCtrl  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
[_LARROW] = LAYOUT_ortho_4x16(
         KC_NO,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,        KC_NO,
         KC_NO,          KC_NO,      KC_PGUP,         KC_END,         KC_FN7,       KC_HOME,          KC_NO,       LARROW,
     A(KC_TAB),        KC_BSPC,      KC_PGDN,        KC_LEFT,          KC_UP,       KC_RGHT,         KC_ENT,        KC_NO,
        ARROWS,         K_MAIN,        KC_NO,      KC_DELETE,        KC_DOWN,        KC_INS,          KC_NO,       NUMBRS,

         KC_NO,        KC_BSPC,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,        KC_NO,
    S(KC_LCTL),          KC_NO,        KC_P7,          KC_P8,          KC_P9,         KC_NO,          KC_NO,        KC_NO,
         KC_P0,          KC_NO,        KC_P4,          KC_P5,          KC_P6,         KC_NO,        KC_PENT,        KC_NO,
       KC_RSFT,     S(KC_SLSH),        KC_P1,          KC_P2,          KC_P3,       KC_SLSH,         K_MAIN,      KC_LCTL),

/* 4: FN_RARROW_LAYER On the left hand — digits, on the right hand — arrows keys */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦      +      ¦       -     ¦      *      ¦      /      ¦     none    ¦    Win      ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦      1      ¦      2      ¦      3      ¦     none    ¦  LeftShift  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦  BackSpace  ¦     none    ¦      4      ¦      5      ¦      6      ¦     none    ¦      0      ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦    Normal   ¦      ,      ¦      7      ¦      8      ¦      9      ¦      .      ¦ LeftControl ¦
        ¦              ¦     Lock    ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦      /      ¦      *      ¦      -      ¦      +      ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦    RARROW    ¦     none    ¦     Home    ¦   Empty(5)  ¦      End    ¦     PgUp    ¦     none    ¦     none    ¦
        ¦  RightArrows ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     Enter   ¦     Left    ¦      Up     ¦     Right   ¦     PgDn    ¦   NumEnter  ¦   Alt+Tab   ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Num      ¦     none    ¦      Ins    ¦     Down    ¦     Delete  ¦     none    ¦    Normal   ¦    Arrows   ¦
        ¦     Lock     ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦     Lock    ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
[_RARROW] = LAYOUT_ortho_4x16(
         KC_NO,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,      KC_LGUI,
         KC_NO,          KC_NO,        KC_NO,          KC_P1,          KC_P2,         KC_P3,          KC_NO,      KC_LSFT,
         KC_NO,        KC_BSPC,        KC_NO,          KC_P4,          KC_P5,         KC_P6,          KC_NO,        KC_P0,
         KC_NO,         K_MAIN,      KC_SLSH,          KC_P7,          KC_P8,         KC_P9,     S(KC_SLSH),      KC_LCTL,

         KC_NO,          KC_NO,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,        KC_NO,
        RARROW,          KC_NO,      KC_HOME,         KC_FN7,         KC_END,       KC_PGUP,          KC_NO,        KC_NO,
         KC_NO,         KC_ENT,      KC_LEFT,          KC_UP,        KC_RGHT,       KC_PGDN,        KC_PENT,    A(KC_TAB),
        NUMBRS,          KC_NO,       KC_INS,        KC_DOWN,      KC_DELETE,         KC_NO,         K_MAIN,       ARROWS),

/* 5: FN_PURESHIFTFUNC_LAYER «Pure» and with Shift Fx keys */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦     none    ¦     F11     ¦     F12     ¦     none    ¦     none    ¦   FUNCAC    ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦     F1      ¦     F2      ¦     F3      ¦     none    ¦    none     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦     F4      ¦     F5      ¦     F6      ¦     none    ¦     F10     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   LeftAlt    ¦     none    ¦     none    ¦     F7      ¦     F8      ¦     F9      ¦     none    ¦ LeftControl ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦    FUNCSH    ¦     none    ¦     none    ¦   SHIFT+F11 ¦   SHIFT+F12 ¦     none    ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦   SHIFT+F7  ¦   SHIFT+F8  ¦   SHIFT+F9  ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   SHIFT+F10  ¦     none    ¦   SHIFT+F4  ¦   SHIFT+F5  ¦   SHIFT+F6  ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  RightShift  ¦     none    ¦   SHIFT+F1  ¦   SHIFT+F2  ¦   SHIFT+F3  ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
[_PURESHIFTFUNC] = LAYOUT_ortho_4x16(
         KC_NO,          KC_NO,        KC_NO,         KC_F11,         KC_F12,         KC_NO,          KC_NO,       FUNCAC,
         KC_NO,          KC_NO,        KC_NO,          KC_F1,          KC_F2,         KC_F3,          KC_NO,        KC_NO,
         KC_NO,          KC_NO,        KC_NO,          KC_F4,          KC_F5,         KC_F6,          KC_NO,       KC_F10,
       KC_LALT,          KC_NO,        KC_NO,          KC_F7,          KC_F8,         KC_F9,          KC_NO,      KC_LCTL,

        FUNCSH,          KC_NO,        KC_NO,      S(KC_F11),      S(KC_F12),         KC_NO,          KC_NO,        KC_NO,
         KC_NO,          KC_NO,     S(KC_F7),       S(KC_F8),       S(KC_F9),         KC_NO,          KC_NO,        KC_NO,
     S(KC_F10),          KC_NO,     S(KC_F4),       S(KC_F5),       S(KC_F6),         KC_NO,          KC_NO,        KC_NO,
       KC_RSFT,          KC_NO,     S(KC_F1),       S(KC_F2),       S(KC_F3),         KC_NO,          KC_NO,      KC_RSFT),

/* 6: FN_ALTCTRLFUNC_LAYER Fx keys with Alt and Ctrl */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦     none    ¦   ALT+F11   ¦   ALT+F12   ¦     none    ¦     none    ¦    FUNCAC   ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦   ALT+F1    ¦   ALT+F2    ¦   ALT+F3    ¦     none    ¦    none     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦   ALT+F4    ¦   ALT+F5    ¦   ALT+F6    ¦     none    ¦   ALT+F10   ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   LeftAlt    ¦     none    ¦     none    ¦   ALT+F7    ¦   ALT+F8    ¦   ALT+F9    ¦     none    ¦ LeftControl ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦    FUNCSH    ¦     none    ¦     none    ¦    CTRL+F11 ¦    CTRL+F12 ¦     none    ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦    CTRL+F7  ¦    CTRL+F8  ¦    CTRL+F9  ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦    CTRL+F10  ¦     none    ¦    CTRL+F4  ¦    CTRL+F5  ¦    CTRL+F6  ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  RightShift  ¦     none    ¦    CTRL+F1  ¦    CTRL+F2  ¦    CTRL+F3  ¦     none    ¦     none    ¦   Left Alt  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
[_ALTCTRLFUNC] = LAYOUT_ortho_4x16(
         KC_NO,          KC_NO,        KC_NO,      A(KC_F11),      A(KC_F12),         KC_NO,          KC_NO,       FUNCAC,
         KC_NO,          KC_NO,        KC_NO,       A(KC_F1),       A(KC_F2),      A(KC_F3),          KC_NO,        KC_NO,
         KC_NO,          KC_NO,        KC_NO,       A(KC_F4),       A(KC_F5),      A(KC_F6),          KC_NO,    A(KC_F10),
       KC_LALT,          KC_NO,        KC_NO,       A(KC_F7),       A(KC_F8),      A(KC_F9),          KC_NO,      KC_LCTL,

        FUNCSH,          KC_NO,        KC_NO,      C(KC_F11),      C(KC_F12),         KC_NO,          KC_NO,        KC_NO,
         KC_NO,          KC_NO,     C(KC_F7),       C(KC_F8),       C(KC_F9),         KC_NO,          KC_NO,        KC_NO,
     C(KC_F10),          KC_NO,     C(KC_F4),       C(KC_F5),       C(KC_F6),         KC_NO,          KC_NO,        KC_NO,
       KC_RSFT,          KC_NO,     C(KC_F1),       C(KC_F2),       C(KC_F3),         KC_NO,          KC_NO,      KC_LALT),

/* 7: FN_SPECIALCHARS_LAYER Special Characters */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦      `      ¦      ~      ¦       '     ¦     none    ¦     none    ¦      ±      ¦    none     ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦Ctrl+Shift+Esc¦     none    ¦     none    ¦       1     ¦       2     ¦       3     ¦     none    ¦    none     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦  BackSpace  ¦       .     ¦       4     ¦       5     ¦       6     ¦     Enter   ¦    none     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦      APP     ¦     none    ¦       ,     ¦       7     ¦       8     ¦       9     ¦       0     ¦    none     ¦
        ¦Special Chars ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦    Accent   ¦      –      ¦      —      ¦ Multiplicat ¦   Division  ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Space    ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  RightShift  ¦     none    ¦     none    ¦     none    ¦     none    ¦      …      ¦     none    ¦  NumLock On ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
[_SPECIALCHARS] = LAYOUT_ortho_4x16(
         KC_NO,       S(KC_6),         KC_EQL,           KC_6,          KC_NO,          KC_NO,       KC_RBRC,        KC_NO,
        KC_FN8,         KC_NO,          KC_NO,          KC_P1,          KC_P2,          KC_P3,         KC_NO,        KC_NO,
         KC_NO,       KC_BSPC,     S(KC_SLSH),          KC_P4,          KC_P5,          KC_P6,        KC_ENT,        KC_NO,
        SPECCH,      KC_LCTRL,        KC_SLSH,          KC_P7,          KC_P8,          KC_P9,         KC_P0,        KC_NO,

         KC_NO,     S(KC_EQL),        KC_NUBS,     S(KC_NUBS),        KC_BSLS,     S(KC_BSLS),         KC_NO,        KC_NO,
         KC_NO,         KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,         KC_NO,        KC_NO,
        KC_SPC,         KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,         KC_NO,        KC_NO,
       KC_RSFT,         KC_NO,          KC_NO,          KC_NO,          KC_NO,     S(KC_RBRC),         KC_NO,       KC_FN6),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

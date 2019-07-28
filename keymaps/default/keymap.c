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
#define _RARROW 4         // 4: On the left hand — digits, on the right hand — arrow keys
#define _PSFUNC 5         // 5: «Pure» and with Shift Fx keys
#define _ACFUNC 6         // 6: Fx keys with Alt and Ctrl
#define _SCHARS 7         // 7: Special Characters

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_MACRO(ONCAPS),      //vkluchaem CapsLock — tam u nas russkie bukvy
  [1] = ACTION_MACRO(OFFCAPS),     //otkluchaem CapsLock — perehodim na latinicu
  [2] = ACTION_MACRO(NUMOFFP5ON),  //otkluchaet NumLock, vvodit 5 na cyfrovoj klave, vkluchaet Num — dlq FARa
  [3] = ACTION_MODS_KEY(MOD_LCTL|MOD_LSFT, KC_ESC), // TaskManager (Control,Shift+Esc)
};

/* The default kKeyb layout. Layer is normal keys and punctuation */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦      ;      ¦      (      ¦       "     ¦      «      ¦      !      ¦      +      ¦    App      ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦Special Chars¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     ESC      ¦      @      ¦      J      ¦       C     ¦      U      ¦      K      ¦      Y      ¦   LARROW    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦ LeftArrows  ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     TAB      ¦  BackSpace  ¦      Q      ¦       E     ¦      V      ¦      A      ¦      P      ¦  LeftShift  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Win      ¦     FN1     ¦      F      ¦      <      ¦      S      ¦      M      ¦      I      ¦ LeftControl ¦
        ¦              ¦     LAT     ¦             ¦             ¦             ¦             ¦             ¦             ¦
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
        ¦  RightShift  ¦      T      ¦      X      ¦      B      ¦      >      ¦      ,      ¦     FN0     ¦   Left Alt  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦     RUS     ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
//First four lines — the left hand, next four lines — the right hand
[_MAIN] = LAYOUT_ortho_8x8(
         KC_NO,         KC_GRV,         KC_1,           KC_2,           KC_3,          KC_4,           KC_5, LT(_SCHARS, KC_APP),
        KC_ESC,        KC_QUOT,         KC_J,           KC_C,           KC_U,          KC_K,           KC_Y,  MO(_LARROW),
        KC_TAB,        KC_BSPC,         KC_Q,           KC_E,           KC_V,          KC_A,           KC_P,      KC_LSFT,
       KC_LGUI,         KC_FN1,         KC_F,        KC_COMM,           KC_S,          KC_M,           KC_I,      KC_LCTL,

   MO(_PSFUNC),        KC_BSPC,         KC_7,           KC_8,           KC_9,          KC_0,        KC_MINS,        KC_NO,
   MO(_RARROW),           KC_N,         KC_G,           KC_W,           KC_H,          KC_Z,        KC_LBRC,      KC_PSCR,
        KC_SPC,           KC_R,         KC_O,           KC_L,           KC_D,       KC_SCLN,         KC_ENT,      KC_PAUS,
       KC_RSFT,           KC_T,         KC_X,           KC_B,         KC_DOT,       KC_SLSH,         KC_FN0,      KC_LALT),

/* 1: FN_ARROWS_LAYER On the left and right hands — arrows keys */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦      +      ¦       -     ¦      *      ¦      /      ¦     none    ¦     App     ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦Special Chars¦
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
[_ARROWS] = LAYOUT_ortho_8x8(
       KC_TRNS,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,       KC_APP,
       KC_TRNS,          KC_NO,      KC_PGUP,         KC_END,         KC_FN2,       KC_HOME,          KC_NO,        KC_NO,
       KC_TRNS,        KC_BSPC,      KC_PGDN,        KC_LEFT,          KC_UP,       KC_RGHT,         KC_ENT,      KC_LSFT,
         KC_NO,      TO(_MAIN),        KC_NO,      KC_DELETE,        KC_DOWN,        KC_INS,          KC_NO,      KC_LCTL,

         KC_NO,        KC_BSPC,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,      KC_TRNS,
         KC_NO,          KC_NO,      KC_HOME,         KC_FN2,         KC_END,       KC_PGUP,          KC_NO,       KC_ESC,
       KC_LSFT,         KC_ENT,      KC_LEFT,          KC_UP,        KC_RGHT,       KC_PGDN,        KC_PENT,       KC_TAB,
       KC_LCTL,          KC_NO,       KC_INS,        KC_DOWN,      KC_DELETE,         KC_NO,      TO(_MAIN),        KC_NO),

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
        ¦     none     ¦    Normal   ¦       ,     ¦      7      ¦      8      ¦      9      ¦      ,      ¦     Num     ¦
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
[_NUMBERS] = LAYOUT_ortho_8x8(
       KC_TRNS,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,       KC_APP,
       KC_TRNS,          KC_NO,        KC_NO,          KC_P1,          KC_P2,         KC_P3,          KC_NO,  MO(_LARROW),
        KC_TAB,        KC_BSPC,        KC_NO,          KC_P4,          KC_P5,         KC_P6,         KC_ENT,        KC_P0,
       KC_LGUI,      TO(_MAIN),      KC_SLSH,          KC_P7,          KC_P8,         KC_P9,        KC_SLSH,        KC_NO,

   MO(_PSFUNC),        KC_BSPC,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,      KC_TRNS,
   MO(_RARROW),          KC_NO,        KC_P7,          KC_P8,          KC_P9,         KC_NO,          KC_NO,        KC_NO,
         KC_P0,         KC_ENT,        KC_P4,          KC_P5,          KC_P6,         KC_NO,        KC_PENT,        KC_NO,
         KC_NO,     S(KC_SLSH),        KC_P1,          KC_P2,          KC_P3,       KC_SLSH,      TO(_MAIN),        KC_NO),

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
[_LARROW] = LAYOUT_ortho_8x8(
       KC_TRNS,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,        KC_NO,
        KC_ESC,          KC_NO,      KC_PGUP,         KC_END,         KC_FN2,       KC_HOME,          KC_NO,      KC_TRNS,
     A(KC_TAB),        KC_BSPC,      KC_PGDN,        KC_LEFT,          KC_UP,       KC_RGHT,         KC_ENT,        KC_NO,
   TO(_ARROWS),          KC_NO,        KC_NO,      KC_DELETE,        KC_DOWN,        KC_INS,          KC_NO, TO(_NUMBERS),

         KC_NO,        KC_BSPC,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,      KC_TRNS,
    S(KC_LCTL),          KC_NO,        KC_P7,          KC_P8,          KC_P9,         KC_NO,          KC_NO,        KC_NO,
         KC_P0,          KC_NO,        KC_P4,          KC_P5,          KC_P6,         KC_NO,        KC_PENT,        KC_NO,
       KC_RSFT,     S(KC_SLSH),        KC_P1,          KC_P2,          KC_P3,       KC_SLSH,          KC_NO,      KC_LCTL),

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
[_RARROW] = LAYOUT_ortho_8x8(
       KC_TRNS,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,      KC_LGUI,
         KC_NO,          KC_NO,        KC_NO,          KC_P1,          KC_P2,         KC_P3,          KC_NO,      KC_LSFT,
         KC_NO,        KC_BSPC,        KC_NO,          KC_P4,          KC_P5,         KC_P6,          KC_NO,        KC_P0,
         KC_NO,          KC_NO,      KC_SLSH,          KC_P7,          KC_P8,         KC_P9,     S(KC_SLSH),      KC_LCTL,

         KC_NO,          KC_NO,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,      KC_TRNS,
       KC_TRNS,          KC_NO,      KC_HOME,         KC_FN2,         KC_END,       KC_PGUP,          KC_NO,        KC_NO,
         KC_NO,         KC_ENT,      KC_LEFT,          KC_UP,        KC_RGHT,       KC_PGDN,        KC_PENT,    A(KC_TAB),
  TO(_NUMBERS),          KC_NO,       KC_INS,        KC_DOWN,      KC_DELETE,         KC_NO,          KC_NO,  TO(_ARROWS)),

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
[_PSFUNC] = LAYOUT_ortho_8x8(
       KC_TRNS,          KC_NO,        KC_NO,         KC_F11,         KC_F12,         KC_NO,          KC_NO,  MO(_ACFUNC),
         KC_NO,          KC_NO,        KC_NO,          KC_F1,          KC_F2,         KC_F3,          KC_NO,        KC_NO,
         KC_NO,          KC_NO,        KC_NO,          KC_F4,          KC_F5,         KC_F6,          KC_NO,       KC_F10,
       KC_LALT,          KC_NO,        KC_NO,          KC_F7,          KC_F8,         KC_F9,          KC_NO,      KC_TRNS,

       KC_TRNS,          KC_NO,        KC_NO,      S(KC_F11),      S(KC_F12),         KC_NO,          KC_NO,      KC_TRNS,
         KC_NO,          KC_NO,     S(KC_F7),       S(KC_F8),       S(KC_F9),         KC_NO,          KC_NO,        KC_NO,
     S(KC_F10),          KC_NO,     S(KC_F4),       S(KC_F5),       S(KC_F6),         KC_NO,          KC_NO,        KC_NO,
         KC_NO,          KC_NO,     S(KC_F1),       S(KC_F2),       S(KC_F3),         KC_NO,     C(KC_BSLS),        KC_NO),

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
[_ACFUNC] = LAYOUT_ortho_8x8(
       KC_TRNS,          KC_NO,        KC_NO,      A(KC_F11),      A(KC_F12),         KC_NO,          KC_NO,      KC_TRNS,
         KC_NO,          KC_NO,        KC_NO,       A(KC_F1),       A(KC_F2),      A(KC_F3),          KC_NO,        KC_NO,
         KC_NO,          KC_NO,        KC_NO,       A(KC_F4),       A(KC_F5),      A(KC_F6),          KC_NO,    A(KC_F10),
       KC_LALT,          KC_NO,        KC_NO,       A(KC_F7),       A(KC_F8),      A(KC_F9),          KC_NO,      KC_LSFT,

         KC_NO,          KC_NO,        KC_NO,      C(KC_F11),      C(KC_F12),         KC_NO,          KC_NO,      KC_TRNS,
         KC_NO,          KC_NO,     C(KC_F7),       C(KC_F8),       C(KC_F9),         KC_NO,          KC_NO,        KC_NO,
     C(KC_F10),          KC_NO,     C(KC_F4),       C(KC_F5),       C(KC_F6),         KC_NO,          KC_NO,        KC_NO,
         KC_NO,          KC_NO,     C(KC_F1),       C(KC_F2),       C(KC_F3),         KC_NO,          KC_NO,        KC_NO),

/* 7: FN_SPECIALCHARS_LAYER Special Characters */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦      `      ¦      ~      ¦       '     ¦       “     ¦    n-Dash   ¦      ±      ¦Special Chars¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦Ctrl+Shift+Esc¦     none    ¦     none    ¦             ¦             ¦             ¦     none    ¦    none     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦  BackSpace  ¦             ¦             ¦             ¦             ¦ Shift+Enter ¦    Space    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦             ¦             ¦             ¦             ¦             ¦    none     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦    Accent   ¦    m-Dash   ¦      ”      ¦       ×     ¦       ÷     ¦       ‰     ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Enter    ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦NonBreackable ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦     Enter   ¦     none    ¦
        ¦    Space     ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  RightShift  ¦     none    ¦     none    ¦     none    ¦     none    ¦      …      ¦     none    ¦  NumLock On ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
[_SCHARS] = LAYOUT_ortho_8x8(
       KC_TRNS,       S(KC_6),        KC_NUBS,           KC_6,        KC_RBRC,         KC_EQL,  ALGR(KC_EQL),      KC_TRNS,
        KC_FN3,    S(KC_RBRC),          KC_NO,          KC_NO,          KC_NO,          KC_NO,         KC_NO,        KC_NO,
  A(S(KC_TAB)),       KC_BSPC,          KC_NO,  ALGR(KC_RBRC),          KC_NO,          KC_NO,        KC_ENT,       KC_SPC,
         KC_NO,    C(KC_BSLS),          KC_NO,          KC_NO,          KC_NO,          KC_NO,         KC_NO,        KC_NO,

       KC_LSFT,    S(KC_NUBS),      S(KC_EQL),        KC_BSLS,  ALGR(KC_NUBS), ALGR(S(KC_NUBS)), ALGR(S(KC_EQL)),  KC_TRNS,
         KC_NO,         KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,    S(KC_BSLS),        KC_NO,
  ALGR(KC_SPC),         KC_NO,  ALGR(KC_RBRC),          KC_NO,          KC_NO,          KC_NO,     S(KC_ENT),        KC_NO,
       KC_RSFT,         KC_NO,  ALGR(KC_BSLS),          KC_NO,          KC_NO,  ALGR(KC_PDOT),         KC_NO,      KC_RSFT),
};

void matrix_init_user(void) {
//  setPinOutput(B0);
//  setPinOutput(D5);
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

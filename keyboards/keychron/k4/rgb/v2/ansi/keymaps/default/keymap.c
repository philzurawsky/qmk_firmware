/*
Copyright 2021 Dimitris Mantzouranis

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include <cli_abbv.c>

enum my_keycodes {
  S_MU = SAFE_RANGE,  // Inline Medicare Unsigned 
  S_ML,               // Inline Medicare Signed
  S_PO,               // Parent of

  S_M1,               // Change Medicare Number to 1
  S_M2,               // Change Medicare Number to 2
  S_M3,               // Change Medicare Number to 3
  S_M4,               // Change Medicare Number to 4
  S_M5,               // Change Medicare Number to 5
  S_M6,               // Change Medicare Number to 6
  S_M7,               // Change Medicare Number to 7
  S_M8,               // Change Medicare Number to 8
  S_M9,               // Change Medicare Number to 9

  S_NFL,              // Not fully legible
  S_PSOR,             // ??
  S_NH,               // No history

  S_MIDDLENAME,       // Move cursor to add middle name
  S_MNTOFN,           // Move middle name to name field (USE WITH CAUTION)

  S_PEN,              // Add Pension in Field 20
  S_PENEXP,           // Change Expiry
  S_CLR12,            // Clear field 12


  S_D_CTIME,          // Collection time to 0000
  S_Y,                // Yesterday

  S_DHP,              // DHP-
  S_DON,              // /DON



  E_EORDD,            // EOR/DD
  E_EOR,              // EOR/
  E_ML,               // EOR Make Medicare Signed
  E_M,                // EOR Make Medicare Unsigned
  E_NH,               // No History

  CL_AD,              // adenocarcinoma
  CL_ANA,             // Anaemia
  
  CL_COV,             // Covid

  CL_D,               // Diarrhoea
  CL_DYS,             // Dysuria


  CL_HOT,             // Hypothyroidism
  CL_HYPT,            // Hyperthyroidism

  CL_ST              // Sore Thorat

};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE = 0,
    _FL,
    _CLI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*				+--------------------------------------------------------------------------+-------------------+
				| ESC | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|DEL|HOME| END|PGUP|PGDN| RGB|
				+--------------------------------------------------------------------------+----|----|----|----+				
 				|  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP |NLCK|  / |  * |  - |
 				+--------------------------------------------------------------------------+----|----|----|----+
 				|  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  |  7 |  8 |  9 |    |
 				+--------------------------------------------------------------------------+----|----|----|  + +
 				| CAPSLCK |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |  RETURN |  4 |  5 |  6 |    |
 				+--------------------------------------------------------------------------+----|----|----|----+
 				| LSHIFT   |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / | RSHIFT | UP |  1 |  2 |  3 |    |
 				+--------------------------------------------------------------------------+----|----|----| ENT+
 				|LCTRL| LGUI|  LALT|            SPACE            | RALT| FN|RCTRL| LFT| DWN| RGT|  0 |  . |    |
 				+--------------------------------------------------------------------------+-------------------+
*/ 				
    /*  Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15         16         17         18     */
    [_BASE] = { {   KC_ESC,    KC_F1,     KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_DEL,    KC_HOME,   KC_END,    KC_PGUP,   KC_PGDN,   RGB_MOD },
                {   KC_GRV,    KC_1,      KC_2,      KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,   KC_NO,     KC_NUM,   KC_PSLS,   KC_PAST,   KC_PMNS },
                {   KC_TAB,    KC_Q,      KC_W,      KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,   KC_NO,     KC_P7,     KC_P8,     KC_P9,     KC_PPLS },
                {   KC_CAPS,   KC_A,      KC_S,      KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,   KC_NO,     KC_ENT,    KC_NO,     KC_P4,     KC_P5,     KC_P6,     KC_NO   },
                {   KC_LSFT,   KC_NO,     KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,   KC_NO,     KC_RSFT,   KC_UP,     KC_P1,     KC_P2,     KC_P3,     KC_PENT },
                {   KC_LCTL,   KC_LGUI,   KC_LALT,   KC_NO,   KC_NO,   KC_NO,   LT(_FL, KC_SPC),   KC_NO,   KC_NO,   KC_NO,     KC_RALT,   MO(_CLI),   KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_P0,     KC_PDOT,   KC_NO   }
              },

/*				+--------------------------------------------------------------------------+-------------------+
				|     |SLCK|PAUS|    |BRLR|BRIN|MPRV| PLY|MNXT|MUTE|VLDN|VLUP|    |   |PSCR|    |    | SLP| TOG|
				+--------------------------------------------------------------------------+----|----|----|----+				
 				|     |    |    |    |    |    |    |    |    |    |    |    |    |        |    |    |    | HUE|
 				+--------------------------------------------------------------------------+----|----|----|----+
 				|       |    |    |    |    |    |    |    |    |    |    |    |    |      |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----| SPD+
 				|         |    |    |    |    |    |    |    |    |    |    |    |         |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----|----+
 				|          |    |    |    |    |    |    |    |    |    |    |        |    |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----| SAT+
 				|     | LALT|  LGUI|                             |     |   |     |    |    |    |    |    |    |
 				+--------------------------------------------------------------------------+-------------------+
*/ 				
    /*  Row:        0         1         2          3        4         5         6         7         8         9          10         11         12         13       14        15        16        17        18     */
    [_FL] =   { {   S_MIDDLENAME,  KC_SLCT,  KC_PAUS,   KC_APP,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_INS,  KC_PSCR,  _______,  _______,  KC_SLEP,  RGB_TOG },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,   _______,  _______,    KC_NO,  _______,  KC_SLSH,  S(KC_8),  KC_MINS },
                {   S_DON,  _______,  _______,  E_EORDD,  _______,  S_Y,  _______,  _______,  _______,  _______,   S_PO,   _______,   _______,  _______,    KC_NO,  S_M7,  S_M8,  S_M9,  S(KC_EQL) },
                {   E_EOR,  _______,  S_PENEXP,  S_DHP,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,     KC_NO,  _______,    KC_NO,  S_M4,  S_M5,  S_M6,    KC_NO },
                {   _______,    KC_NO,  _______,  _______,  _______,  E_ML,  E_M,  E_NH,  S_MU,  S_ML,   _______,   _______,     KC_NO,  _______,  _______,  S_M1,  S_M2,  S_M3,  KC_MS_BTN3 },
                {   _______,  KC_LALT,  KC_LGUI,    KC_NO,    KC_NO,    KC_NO,  _______,    KC_NO,    KC_NO,    KC_NO,   _______,   _______,   _______,  _______,  _______,  _______,  _______,  S_D_CTIME,    KC_NO }
              },

    [_CLI] =   { {   S_NFL,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______ },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,   _______,  _______,    KC_NO,  _______,  _______,  _______,  _______ },
                {   _______,  _______,  _______,  _______,  _______,  _______,  CL_HYPT,  _______,  _______,  _______,   S_PO,   _______,   _______,  _______,    KC_NO,  _______,  _______,  _______,  _______ },
                {   _______,  CL_ANA,  CL_ST,  CL_D,  CL_DYS,  _______,  CL_HOT,  _______,  _______,  _______,   _______,   _______,     KC_NO,  _______,    KC_NO,  _______,  _______,  _______,    KC_NO },
                {   _______,    KC_NO,  _______,  _______,  CL_COV,  _______,  _______,  S_NH,  _______,  _______,   _______,   S_PSOR,     KC_NO,  _______,  _______,  _______,  _______,  _______,  _______ },
                {   _______,  KC_LALT,  KC_LGUI,    KC_NO,    KC_NO,    KC_NO,  _______,    KC_NO,    KC_NO,    KC_NO,   _______,   MO(_CLI),   _______,  _______,  _______,  _______,  _______,  _______,    KC_NO }
              }  

};
bool dip_switch_update_user(uint8_t index, bool active){
  switch(index){
    case 0:
      if(active){ //BT mode
// do stuff
      }
      else{ //Cable mode
// do stuff
      }
      break;
    case 1:
      if(active){ // Win/Android mode
// do stuff
      }
      else{ // Mac/iOS mode
// do stuff
      }
      break;
  }
  return true;
}
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}


void leader_end_user(void) {
  if (leader_sequence_one_key(...)) {
    ...
  }

  if (leader_sequence_two_keys(KC_A, KC_D)) {
    SEND_STRING(CL_AD);
  }

  if (leader_sequence_two_keys(KC_A, KC_L)) {
    SEND_STRING(CL_AL);
  }
  if (leader_sequence_two_keys(KC_A, KC_M)) {
    SEND_STRING(CL_AM);
  }
  if (leader_sequence_two_keys(KC_A, KC_O)) {
    SEND_STRING(CL_AO);
  }

  if (leader_sequence_two_keys(KC_A, KC_Q)) {
    SEND_STRING(CL_AQ);
  }

  if (leader_sequence_two_keys(KC_A, KC_R)) {
    SEND_STRING(CL_AR);
  }

  if (leader_sequence_two_keys(KC_A, KC_N)) {
    SEND_STRING(CL_AN);
  }

  if (leader_sequence_two_keys(KC_A, KC_F)) {
    SEND_STRING(CL_AF);
  }

  if (leader_sequence_three_keys(KC_A, KC_N, KC_A)) {
    SEND_STRING(CL_ANA);
  }

  if (leader_sequence_three_keys(KC_A, KC_R, KC_R)) {
    SEND_STRING(CL_ARR);
  }

  if (leader_sequence_three_keys(KC_A, KC_S, KC_Y)) {
    SEND_STRING(CL_ASY);
  }
  
  if (leader_sequence_three_keys(KC_A, KC_C, KC_P)) {
    SEND_STRING(CL_ACP);
  }


  if (leader_sequence_one_key(KC_B)) {
    SEND_STRING(CL_B);
  }

  if (leader_sequence_two_keys(KC_B, KC_C)) {
    SEND_STRING(CL_BC);
  }

  if (leader_sequence_two_keys(KC_B, KC_A)) {
    SEND_STRING(CL_BA);
  }

  if (leader_sequence_two_keys(KC_B, KC_I)) {
    SEND_STRING(CL_BI);
  }

  if (leader_sequence_two_keys(KC_B, KC_R)) {
    SEND_STRING(CL_BR);
  }

  if (leader_sequence_three_keys(KC_B, KC_R, KC_A)) {
    SEND_STRING(CL_BRA);
  }


  if (leader_sequence_one_key(KC_)) {
    SEND_STRING(CL_);
  }

  if (leader_sequence_two_keys(KC_, KC_)) {
    SEND_STRING(CL_);
  }

  if (leader_sequence_three_keys(KC_, KC_, KC_)) {
    SEND_STRING(CL_);
  }

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case S_MU:
      if (record->event.pressed) {
          SEND_STRING("m"SS_TAP(X_ENT)"y"SS_TAP(X_ENT)SS_TAP(X_ENT)"y"SS_TAP(X_ENT)SS_TAP(X_ENT));
      }
      return false;
    case S_ML:
      if (record->event.pressed) {
          SEND_STRING("m"SS_TAP(X_ENT)"y"SS_TAP(X_ENT)"l"SS_TAP(X_ENT)SS_TAP(X_ENT));
      }
      return false;

    case S_PO:
      if (record->event.pressed) {
          SEND_STRING("parent of "); //Add ability to move the cursor to the name field and click it
      }
      return false;

    case S_M1:
      if (record->event.pressed) {
          SEND_STRING("19"SS_TAP(X_ENT)SS_TAP(X_END)SS_TAP(X_BSPC)"1"SS_TAP(X_ENT));
      }
      return false;
    case S_M2:
      if (record->event.pressed) {
          SEND_STRING("19"SS_TAP(X_ENT)SS_TAP(X_END)SS_TAP(X_BSPC)"2"SS_TAP(X_ENT));
      }
      return false;
    case S_M3:
      if (record->event.pressed) {
          SEND_STRING("19"SS_TAP(X_ENT)SS_TAP(X_END)SS_TAP(X_BSPC)"3"SS_TAP(X_ENT));
      }
      return false;
    case S_M4:
      if (record->event.pressed) {
          SEND_STRING("19"SS_TAP(X_ENT)SS_TAP(X_END)SS_TAP(X_BSPC)"4"SS_TAP(X_ENT));
      }
      return false;
    case S_M5:
      if (record->event.pressed) {
          SEND_STRING("19"SS_TAP(X_ENT)SS_TAP(X_END)SS_TAP(X_BSPC)"5"SS_TAP(X_ENT));
      }
      return false;
    case S_M6:
      if (record->event.pressed) {
          SEND_STRING("19"SS_TAP(X_ENT)SS_TAP(X_END)SS_TAP(X_BSPC)"6"SS_TAP(X_ENT));
      }
      return false;
    case S_M7:
      if (record->event.pressed) {
          SEND_STRING("19"SS_TAP(X_ENT)SS_TAP(X_END)SS_TAP(X_BSPC)"7"SS_TAP(X_ENT));
      }
      return false;
    case S_M8:
      if (record->event.pressed) {
          SEND_STRING("19"SS_TAP(X_ENT)SS_TAP(X_END)SS_TAP(X_BSPC)"8"SS_TAP(X_ENT));
      }
      return false;
    case S_M9:
      if (record->event.pressed) {
          SEND_STRING("19"SS_TAP(X_ENT)SS_TAP(X_END)SS_TAP(X_BSPC)"9"SS_TAP(X_ENT));
      }
      return false;

    case S_NFL:
      if (record->event.pressed) {
        SEND_STRING("not fully legible");
      }
      return false;
    
    case S_PSOR:
      if (record->event.pressed) {
        SEND_STRING("??"SS_TAP(X_ENT)SS_TAP(X_ENT));
      }
      return false;

    case S_NH:
      if (record->event.pressed) {
        SEND_STRING("nh"SS_TAP(X_ENT)SS_TAP(X_ENT));
      }
      return false;

    case S_MIDDLENAME:
      if (record->event.pressed) {
        SEND_STRING("3"SS_TAP(X_ENT)SS_TAP(X_END)" ");
      }
      return false;

    case S_MNTOFN: // Placeholder, will copy name from field 21, clear 21 and paste name into 3
      if (record->event.pressed) {
        SEND_STRING("3"SS_TAP(X_ENT)SS_TAP(X_END)" ");
      }
      return false;

    case S_PEN:
      if (record->event.pressed) {
        SEND_STRING("20"SS_TAP(X_ENT)"pen");
      }
      return false;

    case S_PENEXP:
      if (record->event.pressed) {
        SEND_STRING("12"SS_TAP(X_F6)SS_LCTL("x")"exp ");
      }
      return false;

    case S_CLR12:
      if (record->event.pressed) {
        SEND_STRING("12"SS_TAP(X_F6)SS_LCTL("x")SS_TAP(X_ENT));
      }
      return false;

    case S_D_CTIME:
      if (record->event.pressed) {
        SEND_STRING("4"SS_TAP(X_ENT)"0000"SS_TAP(X_ENT));
      }
      return false;

    case S_Y:
      if (record->event.pressed) {
        SEND_STRING("-1"SS_TAP(X_ENT));
      }
      return false;
    
    case S_DHP:
      if (record->event.pressed) {
        SEND_STRING("dhp-");
      }
      return false;

    case S_DON:
      if (record->event.pressed) {
        SEND_STRING("/don"SS_TAP(X_ENT));
      }
      return false;
    
    case E_EORDD:
      if (record->event.pressed) {
        SEND_STRING("16"SS_TAP(X_ENT)SS_TAP(X_F6)SS_LCTL("x")"eor/dd"SS_TAP(X_ENT));
      }
      return false;

    case E_EOR:
      if (record->event.pressed) {
         SEND_STRING("16"SS_TAP(X_ENT)SS_TAP(X_F6)SS_LCTL("x")"eor/");
      }
      return false;

    case E_ML:
      if (record->event.pressed) {
        SEND_STRING("17"SS_TAP(X_ENT)"p"SS_TAP(X_ENT)SS_TAP(X_BSPC)"m"SS_TAP(X_ENT)"y"SS_TAP(X_ENT)"l"SS_TAP(X_ENT)SS_TAP(X_ENT));
      }
      return false;

    case E_M:
      if (record->event.pressed) {
        SEND_STRING("17"SS_TAP(X_ENT)"p"SS_TAP(X_ENT)SS_TAP(X_BSPC)"m"SS_TAP(X_ENT)"y"SS_TAP(X_ENT)SS_TAP(X_DEL)"y"SS_TAP(X_ENT)SS_TAP(X_ENT));
      }
      return false;

    case E_NH:
      if (record->event.pressed) {
        SEND_STRING("10"SS_TAP(X_ENT)"nh"SS_TAP(X_ENT)SS_TAP(X_ENT));
      }
      return false;

    case CL_ANA:
      if (record->event.pressed) {
        SEND_STRING("anaemia ");
      }
      return false;

    case CL_COV:
      if (record->event.pressed) {
        SEND_STRING("covid ");
      }
      return false;

    case CL_D:
      if (record->event.pressed) {
        SEND_STRING("diarrhoea ");
      }
      return false;

    case CL_DYS:
      if (record->event.pressed) {
        SEND_STRING("dysuria ");
      }
      return false;
    
    case CL_HOT:
      if (record->event.pressed) {
        SEND_STRING("hypothyroidism ");
      }
      return false;

    case CL_HYPT:
      if (record->event.pressed) {
        SEND_STRING("hyperthyroidism ");
      }
      return false;

    case CL_ST:
      if (record->event.pressed) {
        SEND_STRING("sore throat ");
      }
      return false;

    default:
     return true;
  }
}
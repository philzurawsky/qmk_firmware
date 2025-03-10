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
#include <quantum_keycodes.h>

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
  MO_LEFT,
  MO_DOWN
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
                {   QK_LEAD,   KC_A,      KC_S,      KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,   KC_NO,     KC_ENT,    KC_NO,     KC_P4,     KC_P5,     KC_P6,     KC_NO   },
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
    [_FL] =   { {   S_MNTOFN,  KC_SLCT,  KC_PAUS,   KC_APP,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_INS,  KC_PSCR,  _______,  _______,  KC_SLEP,  RGB_TOG },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,   _______,  _______,    KC_NO,  _______,  KC_SLSH,  S(KC_8),  KC_MINS },
                {   S_DON,  _______,  _______,  E_EORDD,  _______,  S_Y,  _______,  _______,  _______,  _______,   S_PO,   _______,   _______,  _______,    KC_NO,  S_M7,  S_M8,  S_M9,  S(KC_EQL) },
                {   E_EOR,  _______,  S_PENEXP,  S_DHP,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,     KC_NO,  _______,    KC_NO,  S_M4,  S_M5,  S_M6,    KC_NO },
                {   _______,    KC_NO,  _______,  _______,  _______,  E_ML,  E_M,  E_NH,  S_MU,  S_ML,   _______,   _______,     KC_NO,  _______,  _______,  S_M1,  S_M2,  S_M3,  KC_MS_BTN3 },
                {   _______,  KC_LALT,  KC_LGUI,    KC_NO,    KC_NO,    KC_NO,  _______,    KC_NO,    KC_NO,    KC_NO,   _______,   _______,   _______,  _______,  _______,  _______,  _______,  S_D_CTIME,    KC_NO }
              },

    [_CLI] =   { {   S_NFL,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______ },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,   _______,  _______,    KC_NO,  _______,  _______,  _______,  _______ },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   S_PO,   _______,   _______,  _______,    KC_NO,  _______,  _______,  _______,  _______ },
                {   KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,     KC_NO,  _______,    KC_NO,  _______,  _______,  _______,    KC_NO },
                {   _______,    KC_NO,  _______,  _______,  _______,  _______,  _______,  S_NH,  _______,  _______,   _______,   S_PSOR,     KC_NO,  _______,  _______,  _______,  _______,  _______,  _______ },
                {   _______,  KC_LALT,  KC_LGUI,    KC_NO,    KC_NO,    KC_NO,  _______,    KC_NO,    KC_NO,    KC_NO,   _______,   MO(_CLI),   _______,  MO_LEFT,  MO_DOWN,  _______,  _______,  _______,    KC_NO }
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


// void leader_end_user(void) {
//   // if (leader_sequence_one_key(...)) {
//   //   ...
//   // }
// if (leader_sequence_two_keys(KC_A, KC_M)) {
//     SEND_STRING(CL_AM);
// }
// else if (leader_sequence_two_keys(KC_A, KC_O)) {
//     SEND_STRING(CL_AO);
// }
// else if (leader_sequence_four_keys(KC_T, KC_2, KC_D, KC_M)) {
//     SEND_STRING(CL_T2DM);
// }
// else if (leader_sequence_two_keys(KC_V, KC_D)) {
//     SEND_STRING(CL_VD);
// }
// else if (leader_sequence_three_keys(KC_V, KC_A, KC_G)) {
//     SEND_STRING(CL_VAG);
// }
// else if (leader_sequence_one_key(KC_C)) {
//     SEND_STRING(CL_C);
// }
// }

void leader_end_user(void) {
    if(leader_sequence_two_keys(KC_C, KC_X)) {
        SEND_STRING(CL_CX);
    }
    else if(leader_sequence_four_keys(KC_N, KC_A, KC_S, KC_O)) {
        SEND_STRING(CL_NASO);
    }
    else if(leader_sequence_two_keys(KC_A, KC_M)) {
        SEND_STRING(CL_AM);
    }
    else if(leader_sequence_two_keys(KC_A, KC_R)) {
        SEND_STRING(CL_AR);
    }
    else if(leader_sequence_two_keys(KC_A, KC_A)) {
        SEND_STRING(CL_AA);
    }
    else if(leader_sequence_two_keys(KC_A, KC_N)) {
        SEND_STRING(CL_AN);
    }
    else if(leader_sequence_three_keys(KC_A, KC_R, KC_R)) {
        SEND_STRING(CL_ARR);
    }
    else if(leader_sequence_three_keys(KC_A, KC_S, KC_Y)) {
        SEND_STRING(CL_ASY);
    }
    else if(leader_sequence_two_keys(KC_A, KC_F)) {
        SEND_STRING(CL_AF);
    }
    else if(leader_sequence_two_keys(KC_C, KC_U)) {
        SEND_STRING(CL_CU);
    }
    else if(leader_sequence_two_keys(KC_C, KC_T)) {
        SEND_STRING(CL_CT);
    }
    else if(leader_sequence_two_keys(KC_C, KC_H)) {
        SEND_STRING(CL_CH);
    }
    else if(leader_sequence_three_keys(KC_C, KC_H, KC_C)) {
        SEND_STRING(CL_CHC);
    }
    else if(leader_sequence_two_keys(KC_C, KC_D)) {
        SEND_STRING(CL_CD);
    }
    else if(leader_sequence_three_keys(KC_C, KC_O, KC_D)) {
        SEND_STRING(CL_COD);
    }
    else if(leader_sequence_three_keys(KC_C, KC_O, KC_N)) {
        SEND_STRING(CL_CON);
    }
    else if(leader_sequence_two_keys(KC_D, KC_E)) {
        SEND_STRING(CL_DE);
    }
    else if(leader_sequence_two_keys(KC_D, KC_B)) {
        SEND_STRING(CL_DB);
    }
    else if(leader_sequence_one_key(KC_D)) {
        SEND_STRING(CL_D);
    }
    else if(leader_sequence_two_keys(KC_D, KC_V)) {
        SEND_STRING(CL_DV);
    }
    else if(leader_sequence_three_keys(KC_D, KC_I, KC_S)) {
        SEND_STRING(CL_DIS);
    }
    else if(leader_sequence_three_keys(KC_D, KC_Y, KC_M)) {
        SEND_STRING(CL_DYM);
    }
    else if(leader_sequence_two_keys(KC_D, KC_U)) {
        SEND_STRING(CL_DU);
    }
    else if(leader_sequence_two_keys(KC_E, KC_C)) {
        SEND_STRING(CL_EC);
    }
    else if(leader_sequence_two_keys(KC_E, KC_P)) {
        SEND_STRING(CL_EP);
    }
    else if(leader_sequence_two_keys(KC_F, KC_D)) {
        SEND_STRING(CL_FD);
    }
    else if(leader_sequence_two_keys(KC_F, KC_U)) {
        SEND_STRING(CL_FU);
    }
    else if(leader_sequence_two_keys(KC_G, KC_E)) {
        SEND_STRING(CL_GE);
    }
    else if(leader_sequence_three_keys(KC_G, KC_C, KC_U)) {
        SEND_STRING(CL_GCU);
    }
    else if(leader_sequence_two_keys(KC_G, KC_O)) {
        SEND_STRING(CL_GO);
    }
    else if(leader_sequence_two_keys(KC_G, KC_D)) {
        SEND_STRING(CL_GD);
    }
    else if(leader_sequence_two_keys(KC_H, KC_U)) {
        SEND_STRING(CL_HU);
    }
    else if(leader_sequence_two_keys(KC_H, KC_C)) {
        SEND_STRING(CL_HC);
    }
    else if(leader_sequence_four_keys(KC_H, KC_E, KC_C, KC_H)) {
        SEND_STRING(CL_HECH);
    }
    else if(leader_sequence_three_keys(KC_H, KC_P, KC_Y)) {
        SEND_STRING(CL_HPY);
    }
    else if(leader_sequence_three_keys(KC_H, KC_I, KC_C)) {
        SEND_STRING(CL_HIC);
    }
    else if(leader_sequence_two_keys(KC_Y, KC_C)) {
        SEND_STRING(CL_YC);
    }
    else if(leader_sequence_two_keys(KC_Y, KC_G)) {
        SEND_STRING(CL_YG);
    }
    else if(leader_sequence_two_keys(KC_Y, KC_K)) {
        SEND_STRING(CL_YK);
    }
    else if(leader_sequence_two_keys(KC_Y, KC_L)) {
        SEND_STRING(CL_YL);
    }
    else if(leader_sequence_two_keys(KC_Y, KC_N)) {
        SEND_STRING(CL_YN);
    }
    else if(leader_sequence_two_keys(KC_H, KC_T)) {
        SEND_STRING(CL_HT);
    }
    else if(leader_sequence_two_keys(KC_Y, KC_T)) {
        SEND_STRING(CL_YT);
    }
    else if(leader_sequence_two_keys(KC_O, KC_K)) {
        SEND_STRING(CL_OK);
    }
    else if(leader_sequence_two_keys(KC_O, KC_L)) {
        SEND_STRING(CL_OL);
    }
    else if(leader_sequence_two_keys(KC_O, KC_N)) {
        SEND_STRING(CL_ON);
    }
    else if(leader_sequence_two_keys(KC_O, KC_T)) {
        SEND_STRING(CL_OT);
    }
    else if(leader_sequence_two_keys(KC_H, KC_Y)) {
        SEND_STRING(CL_HY);
    }
    else if(leader_sequence_two_keys(KC_I, KC_C)) {
        SEND_STRING(CL_IC);
    }
    else if(leader_sequence_three_keys(KC_I, KC_B, KC_D)) {
        SEND_STRING(CL_IBD);
    }
    else if(leader_sequence_three_keys(KC_I, KC_B, KC_S)) {
        SEND_STRING(CL_IBS);
    }
    else if(leader_sequence_three_keys(KC_I, KC_D, KC_A)) {
        SEND_STRING(CL_IDA);
    }
    else if(leader_sequence_two_keys(KC_I, KC_P)) {
        SEND_STRING(CL_IP);
    }
    else if(leader_sequence_two_keys(KC_J, KC_P)) {
        SEND_STRING(CL_JP);
    }
    else if(leader_sequence_one_key(KC_L)) {
        SEND_STRING(CL_L);
    }
    else if(leader_sequence_three_keys(KC_M, KC_C, KC_A)) {
        SEND_STRING(CL_MCA);
    }
    else if(leader_sequence_one_key(KC_M)) {
        SEND_STRING(CL_M);
    }
    else if(leader_sequence_two_keys(KC_M, KC_P)) {
        SEND_STRING(CL_MP);
    }
    else if(leader_sequence_three_keys(KC_M, KC_T, KC_H)) {
        SEND_STRING(CL_MTH);
    }
    else if(leader_sequence_two_keys(KC_M, KC_H)) {
        SEND_STRING(CL_MH);
    }
    else if(leader_sequence_two_keys(KC_M, KC_O)) {
        SEND_STRING(CL_MO);
    }
    else if(leader_sequence_two_keys(KC_M, KC_Y)) {
        SEND_STRING(CL_MY);
    }
    else if(leader_sequence_three_keys(KC_O, KC_C, KC_H)) {
        SEND_STRING(CL_OCH);
    }
    else if(leader_sequence_three_keys(KC_O, KC_L, KC_I)) {
        SEND_STRING(CL_OLI);
    }
    else if(leader_sequence_two_keys(KC_O, KC_O)) {
        SEND_STRING(CL_OO);
    }
    else if(leader_sequence_two_keys(KC_O, KC_R)) {
        SEND_STRING(CL_OR);
    }
    else if(leader_sequence_two_keys(KC_O, KC_S)) {
        SEND_STRING(CL_OS);
    }
    else if(leader_sequence_three_keys(KC_O, KC_T, KC_H)) {
        SEND_STRING(CL_OTH);
    }
    else if(leader_sequence_two_keys(KC_O, KC_W)) {
        SEND_STRING(CL_OW);
    }
    else if(leader_sequence_three_keys(KC_O, KC_N, KC_Y)) {
        SEND_STRING(CL_ONY);
    }
    else if(leader_sequence_three_keys(KC_O, KC_S, KC_A)) {
        SEND_STRING(CL_OSA);
    }
    else if(leader_sequence_three_keys(KC_O, KC_S, KC_T)) {
        SEND_STRING(CL_OST);
    }
    else if(leader_sequence_two_keys(KC_O, KC_E)) {
        SEND_STRING(CL_OE);
    }
    else if(leader_sequence_four_keys(KC_P, KC_E, KC_R, KC_I)) {
        SEND_STRING(CL_PERI);
    }
    else if(leader_sequence_two_keys(KC_P, KC_C)) {
        SEND_STRING(CL_PC);
    }
    else if(leader_sequence_two_keys(KC_P, KC_D)) {
        SEND_STRING(CL_PD);
    }
    else if(leader_sequence_three_keys(KC_I, KC_M, KC_B)) {
        SEND_STRING(CL_IMB);
    }
    else if(leader_sequence_two_keys(KC_P, KC_M)) {
        SEND_STRING(CL_PM);
    }
    else if(leader_sequence_two_keys(KC_P, KC_N)) {
        SEND_STRING(CL_PN);
    }
    else if(leader_sequence_two_keys(KC_Q, KC_A)) {
        SEND_STRING(CL_QA);
    }
    else if(leader_sequence_two_keys(KC_Q, KC_C)) {
        SEND_STRING(CL_QC);
    }
    else if(leader_sequence_two_keys(KC_Q, KC_D)) {
        SEND_STRING(CL_QD);
    }
    else if(leader_sequence_two_keys(KC_Q, KC_U)) {
        SEND_STRING(CL_QU);
    }
    else if(leader_sequence_two_keys(KC_Q, KC_T)) {
        SEND_STRING(CL_QT);
    }
    else if(leader_sequence_two_keys(KC_S, KC_C)) {
        SEND_STRING(CL_SC);
    }
    else if(leader_sequence_two_keys(KC_S, KC_V)) {
        SEND_STRING(CL_SV);
    }
    else if(leader_sequence_three_keys(KC_S, KC_C, KC_B)) {
        SEND_STRING(CL_SCB);
    }
    else if(leader_sequence_three_keys(KC_C, KC_L, KC_B)) {
        SEND_STRING(CL_CLB);
    }
    else if(leader_sequence_two_keys(KC_S, KC_T)) {
        SEND_STRING(CL_ST);
    }
    else if(leader_sequence_two_keys(KC_Q, KC_S)) {
        SEND_STRING(CL_QS);
    }
    else if(leader_sequence_three_keys(KC_S, KC_C, KC_H)) {
        SEND_STRING(CL_SCH);
    }
    else if(leader_sequence_three_keys(KC_S, KC_T, KC_S)) {
        SEND_STRING(CL_STS);
    }
    else if(leader_sequence_three_keys(KC_S, KC_I, KC_S)) {
        SEND_STRING(CL_SIS);
    }
    else if(leader_sequence_two_keys(KC_T, KC_1)) {
        SEND_STRING(CL_T1);
    }
    else if(leader_sequence_three_keys(KC_T, KC_1, KC_D)) {
        SEND_STRING(CL_T1D);
    }
    else if(leader_sequence_two_keys(KC_T, KC_2)) {
        SEND_STRING(CL_T2);
    }
    else if(leader_sequence_three_keys(KC_T, KC_2, KC_D)) {
        SEND_STRING(CL_T2D);
    }
    else if(leader_sequence_one_key(KC_C)) {
        SEND_STRING(CL_C);
    }
    else if(leader_sequence_two_keys(KC_C, KC_O)) {
        SEND_STRING(CL_CO);
    }
    else if(leader_sequence_three_keys(KC_C, KC_L, KC_C)) {
        SEND_STRING(CL_CLC);
    }
    else if(leader_sequence_three_keys(KC_C, KC_K, KC_D)) {
        SEND_STRING(CL_CKD);
    }
    else if(leader_sequence_three_keys(KC_A, KC_C, KC_F)) {
        SEND_STRING(CL_ACF);
    }
    else if(leader_sequence_three_keys(KC_N, KC_F, KC_L)) {
        SEND_STRING(CL_NFL);
    }
}

#define resetCursor for (int i = 0; i < 50; i++) {\
    mousekey_on(KC_MS_RIGHT);\
        mousekey_on(KC_MS_UP);\
        mousekey_send();\
        mousekey_off(KC_MS_RIGHT);\
        mousekey_off(KC_MS_UP);\
        mousekey_send();\
    }

#define copyMiddleName  mousekey_on(KC_ACL0); \
    mousekey_send();\
    for (int i = 0; i < 5; i++) { \
        mousekey_on(KC_MS_LEFT);\
        mousekey_on(KC_MS_DOWN);\
        mousekey_send();\
        mousekey_off(KC_MS_LEFT);\
         mousekey_off(KC_MS_DOWN);\
        mousekey_send();\
    }\
        mousekey_on(KC_MS_BTN1);\
        mousekey_send();\
        mousekey_off(KC_MS_BTN1);\
        mousekey_send();\

#define mousePaste mousekey_on(KC_MS_BTN2);\
        mousekey_send();\
        mousekey_off(KC_MS_BTN2);\
        mousekey_send();

// void copyMiddleName() {
//     resetCursor
//     for (int i = 0; i < 10; i++) { // Adjust loop count as needed to achieve desired movement
//         mousekey_on(KC_MS_RIGHT);
//         mousekey_on(KC_MS_UP);
//         mousekey_send();
//         mousekey_off(KC_MS_RIGHT);
//         mousekey_off(KC_MS_UP);
//         mousekey_send();
//     }
//     for (int i = 0; i < 2; i++) { // Adjust loop count as needed to achieve desired movement
//         mousekey_on(KC_MS_LEFT);
//         mousekey_send();
//         mousekey_off(KC_MS_LEFT);
//         mousekey_send();
//     }
//     for (int i = 0; i < 2; i++) { // Adjust loop count as needed to achieve desired movement
//         mousekey_on(KC_MS_DOWN);
//         mousekey_send();
//         mousekey_off(KC_MS_DOWN);
//         mousekey_send();
//     }
//         mousekey_on(KC_MS_BTN1);
//         mousekey_send();
//         mousekey_off(KC_MS_BTN1);
//         mousekey_send();
// }

// void mousePaste() {
//     mousekey_on(KC_MS_BTN3);
//         mousekey_send();
//         mousekey_off(KC_MS_BTN3);
//         mousekey_send();
// }


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MO_DOWN:
        if (record->event.pressed) {
            // mousekey_on(KC_ACL0);
            // mousekey_send();
            // mousekey_off(KC_ACL0);
            // mousekey_send();
            // mousekey_on(KC_MS_DOWN);
            // mousekey_send();
            // mousekey_off(KC_MS_DOWN);
            // mousekey_send();
            resetCursor
            copyMiddleName
        }
        return false;
    case MO_LEFT:
        if (record->event.pressed) {
            // mousekey_on(KC_ACL0);
            // mousekey_send();

            mousekey_on(KC_MS_LEFT);
            mousekey_send();
            mousekey_off(KC_MS_LEFT);
            mousekey_send();
            // mousekey_off(KC_ACL0);
            // mousekey_send();
        }
        return false;
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
            resetCursor
            copyMiddleName
            mousePaste
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

    default:
     return true;
  }
}

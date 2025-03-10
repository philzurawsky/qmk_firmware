// Copyright 2023 PythonDeployer (@PythonDeployer)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */


/* LED Status indicators */


#define DIP_SWITCH_PINS { D5, D6 }
#define RGB_MATRIX_LED_COUNT 100

/* RGB Matrix Animation modes. Explicitly enabled
 * For full list of effects, see:
 * https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
 */

#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#    define RGB_MATRIX_DEFAULT_SAT 0

#define SN32_RGB_MATRIX_ROW_PINS { C3, C1, C0, C6, C5, C4, C9, C8, C7, C12, C11, C10, B13, C14, C13, B14, B15, D3 }

#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended

// #define MK_3_SPEED
// #define MK_MOMENTARY_ACCEL

// #define MOUSEKEY_DELAY 1
// #define MOUSEKEY_INTERVAL 20
// #define MOUSEKEY_MOVE_DELTA 10
// #define MOUSEKEY_MAX_SPEED 1

#define LEADER_NO_TIMEOUT
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

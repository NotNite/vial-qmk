/* Copyright 2020 Naoki Katahira
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number { _QWERTY = 0, _LOWER, _RAISE, _ADJUST, _MO4, _MO5 };

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ~   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `-------------------''-------'           '------''--------------------'
     */

    [_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, LOWER, KC_LGUI, KC_LALT, KC_SPC, KC_ENT, KC_BSPC, KC_RGUI, RAISE),
    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   1  |   2  |   3  |   4  |   5  |-------.    ,-------|   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|   |  |   `  |   +  |   {  |   }  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `-------------------''-------'           '------''--------------------'
     */
    [_LOWER] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_GRAVE, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /* RAISE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down |  Up  |Right |      |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|   +  |   =  |   [  |   ]  |   \  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `-------------------''-------'           '------''--------------------'
     */

    [_RAISE] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, KC_PLUS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_ADJUST] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______),
    /* MO(4)
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_MO4] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______),
    /* MO(5)
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_MO5] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______)};

#define SPLIT_TRANSACTION_IDS_KB KEYBOARD_SYNC_A, KEYBOARD_SYNC_B
typedef struct _master_to_slave_t {
    int m2s_wpm;
} master_to_slave_t;

typedef struct _slave_to_master_t {
    int m2s_wpm;
} slave_to_master_t;

// #ifdef OLED_ENABLE

static const char PROGMEM zero[] = {
    0, 254, 254, 254, 254, 254, 254, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 254, 254, 254, 254, 254, 254, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 160, 64, 160, 64, 160, 64, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 2, 5, 2, 5, 2, 5, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 127, 127, 127, 127, 127, 127, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 0,
};
static const char PROGMEM one[] = {
    0, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 0, 0, 0, 0, 0, 0, 126, 126, 126, 126, 126, 126, 254, 254, 254, 254, 254, 254, 0, 0, 160, 64, 160, 64, 160, 64, 160, 64, 160, 64, 160, 64, 160, 64, 160, 64, 160, 64, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 2, 5, 2, 5, 2, 5, 2, 5, 2, 5, 2, 5, 2, 5, 2, 5, 2, 5, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 0, 0, 0, 0, 0, 0, 127, 127, 127, 127, 127, 127, 0,
};
static const char PROGMEM two[] = {
    0, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 254, 254, 254, 254, 254, 254, 0, 0, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 255, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 127, 127, 127, 127, 127, 127, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 0,
};
static const char PROGMEM three[] = {
    0, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 254, 254, 254, 254, 254, 254, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 255, 255, 255, 255, 255, 255, 0, 0, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 0,
};
static const char PROGMEM four[] = {
    0, 254, 254, 254, 254, 254, 254, 0, 0, 0, 0, 0, 0, 42, 84, 42, 84, 42, 84, 0, 0, 0, 0, 0, 0, 254, 254, 254, 254, 254, 254, 0, 0, 255, 255, 255, 255, 255, 255, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 255, 255, 255, 255, 255, 255, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 255, 255, 255, 255, 255, 255, 0, 0, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 42, 84, 0, 0, 0, 0, 0, 0, 127, 127, 127, 127, 127, 127, 0,
};
static const char PROGMEM five[] = {
    0, 254, 254, 254, 254, 254, 254, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 0, 0, 255, 255, 255, 255, 255, 255, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 255, 255, 255, 255, 255, 255, 0, 0, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 0,
};
static const char PROGMEM six[] = {
    0, 254, 254, 254, 254, 254, 254, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 0, 0, 255, 255, 255, 255, 255, 255, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 0, 0, 255, 255, 255, 255, 255, 255, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 255, 255, 255, 255, 255, 255, 0, 0, 127, 127, 127, 127, 127, 127, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 0,
};
static const char PROGMEM seven[] = {
    0, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 254, 254, 254, 254, 254, 254, 0, 0, 160, 64, 160, 64, 160, 64, 0, 0, 0, 0, 0, 0, 160, 64, 160, 64, 160, 64, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 170, 85, 170, 85, 170, 85, 0, 0, 0, 0, 0, 0, 170, 85, 170, 85, 170, 85, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 42, 85, 42, 85, 42, 85, 0, 0, 0, 0, 0, 0, 42, 85, 42, 85, 42, 85, 0, 0, 0, 0, 0, 0, 127, 127, 127, 127, 127, 127, 0,
};
static const char PROGMEM eight[] = {
    0, 254, 254, 254, 254, 254, 254, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 254, 254, 254, 254, 254, 254, 0, 0, 255, 255, 255, 255, 255, 255, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 255, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 255, 255, 255, 255, 255, 255, 0, 0, 127, 127, 127, 127, 127, 127, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 0,
};
static const char PROGMEM nine[] = {
    0, 254, 254, 254, 254, 254, 254, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 254, 254, 254, 254, 254, 254, 0, 0, 255, 255, 255, 255, 255, 255, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 255, 255, 255, 255, 255, 255, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 255, 255, 255, 255, 255, 255, 0, 0, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 0,
};

static const char PROGMEM layer_up_active[] = {
    0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 128, 254, 254, 254, 254, 254, 254, 128, 128, 128, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 224, 224, 224, 224, 224, 224, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 255, 255, 255, 255, 255, 255, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
static const char PROGMEM layer_up_inactive[] = {
    0, 0, 0, 0, 0, 0, 0, 128, 0, 128, 0, 128, 0, 170, 84, 170, 84, 170, 84, 128, 0, 128, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 160, 64, 160, 64, 160, 64, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 160, 64, 160, 64, 160, 64, 0, 0, 2, 5, 2, 5, 2, 5, 2, 5, 2, 5, 2, 5, 170, 85, 170, 85, 170, 85, 2, 5, 2, 5, 2, 5, 2, 5, 2, 5, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42, 85, 42, 85, 42, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
static const char PROGMEM layer_qwerty_active[] = {
    0, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0,
};
static const char PROGMEM layer_qwerty_inactive[] = {
    0, 170, 84, 170, 84, 170, 84, 170, 84, 170, 84, 170, 84, 170, 84, 170, 84, 170, 84, 170, 84, 170, 84, 170, 84, 170, 84, 170, 84, 170, 84, 0, 0, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 0, 0, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 0, 0, 42, 85, 42, 85, 42, 85, 42, 85, 42, 85, 42, 85, 42, 85, 42, 85, 42, 85, 42, 85, 42, 85, 42, 85, 42, 85, 42, 85, 42, 85, 0,
};
static const char PROGMEM layer_down_active[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 254, 254, 254, 254, 254, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 255, 255, 255, 255, 255, 255, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 0, 0, 7, 7, 7, 7, 7, 7, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 127, 127, 127, 127, 127, 127, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
};
static const char PROGMEM layer_down_inactive[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 170, 84, 170, 84, 170, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 160, 64, 160, 64, 160, 64, 160, 64, 160, 64, 160, 64, 170, 85, 170, 85, 170, 85, 160, 64, 160, 64, 160, 64, 160, 64, 160, 64, 160, 64, 0, 0, 2, 5, 2, 5, 2, 5, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 170, 85, 2, 5, 2, 5, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 42, 85, 42, 85, 42, 85, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
};

static const char PROGMEM logo_goober[] = {
    15, 121, 193, 1, 129, 193, 227, 186, 14, 6, 4, 4, 6, 2, 2, 2, 2, 2, 6, 4, 4, 4, 62, 226, 131, 1, 129, 193, 97, 57, 15, 1, 0, 128, 241, 31, 241, 0, 48, 49, 3, 66, 134, 132, 132, 68, 68, 132, 132, 132, 68, 68, 6, 50, 50, 3, 3, 255, 13, 56, 96, 192, 0, 0, 252, 135, 192, 112, 27, 14, 12, 152, 240, 48, 96, 64, 192, 128, 128, 128, 192, 96, 32, 48, 16, 248, 12, 30, 51, 33, 96, 64, 192, 255, 0, 0, 0, 0, 0, 0, 0, 0, 252, 39, 33, 33, 35, 38, 60, 48, 0, 0, 112, 76, 70, 67, 97, 51, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
static const char PROGMEM logo_notnet[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 254, 254, 254, 254, 254, 254, 254, 1, 1, 1, 1, 1, 1, 1, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 254, 254, 254, 254, 0, 0, 0, 0, 127, 127, 127, 127, 127, 127, 127, 255, 255, 255, 255, 255, 255, 255, 128, 128, 128, 128, 128, 128, 128, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    // return rotation;
    return OLED_ROTATION_270;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

void number(void* buf, uint8_t num) {
    switch (num) {
        case 1:
            memcpy(buf, one, 128);
            break;
        case 2:
            memcpy(buf, two, 128);
            break;
        case 3:
            memcpy(buf, three, 128);
            break;
        case 4:
            memcpy(buf, four, 128);
            break;
        case 5:
            memcpy(buf, five, 128);
            break;
        case 6:
            memcpy(buf, six, 128);
            break;
        case 7:
            memcpy(buf, seven, 128);
            break;
        case 8:
            memcpy(buf, eight, 128);
            break;
        case 9:
            memcpy(buf, nine, 128);
            break;
        default:
            memcpy(buf, zero, 128);
            break;
    }
}

bool oled_task_user(void) {
    oled_clear();

    char display[512];

    if (is_keyboard_master()) {
        switch (get_highest_layer(layer_state)) {
            case _RAISE:
                memcpy(display, layer_up_active, 128);
                memcpy(&display[128], layer_qwerty_inactive, 128);
                memcpy(&display[256], layer_down_inactive, 128);
                break;

            case _LOWER:
                memcpy(display, layer_up_inactive, 128);
                memcpy(&display[128], layer_qwerty_inactive, 128);
                memcpy(&display[256], layer_down_active, 128);
                break;

            default:
                memcpy(display, layer_up_inactive, 128);
                memcpy(&display[128], layer_qwerty_active, 128);
                memcpy(&display[256], layer_down_inactive, 128);
                break;
        }

        memcpy(&display[384], logo_goober, 128);
    } else {
        char wpm_str[4];
        sprintf(wpm_str, "%03d", get_current_wpm());
        
        for (uint8_t i = 0; i < 3; i++) {
            number(&display[i * 128], wpm_str[i] - 48);
        }
        memcpy(&display[384], logo_notnet, 128);
    }

    oled_write_raw_P(display, 512);
    return false;
}

// #endif // OLED_ENABLE

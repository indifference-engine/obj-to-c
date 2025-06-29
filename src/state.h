#ifndef STATE_H

#define STATE_H

/**
 * The parser is currently at the start of a line.
 */
#define STATE_INITIAL 0

/**
 * The parser has found a line starting "u".
 */
#define STATE_U 1

/**
 * The parser has found a line starting "us".
 */
#define STATE_US 2

/**
 * The parser has found a line starting "use".
 */
#define STATE_USE 3

/**
 * The parser has found a line starting "usem".
 */
#define STATE_USEM 4

/**
 * The parser has found a line starting "usemt".
 */
#define STATE_USEMT 5

/**
 * The parser has found a line starting "usemtl".
 */
#define STATE_USEMTL 6

/**
 * The parser has found a line starting "usemtl", then at least one space.
 */
#define STATE_USEMTL_SPACE 7

/**
 * The parser has found a line starting "usemtl", then at least one space, then
 * a material name.
 */
#define STATE_USEMTL_NAME 8

/**
 * The parser has found a line starting "usemtl", then at least one space, then
 * a material name, then at least one space.
 */
#define STATE_USEMTL_NAME_SPACE 9

/**
 * The parser has found a line starting "m".
 */
#define STATE_M 10

/**
 * The parser has found a line starting "mt".
 */
#define STATE_MT 11

/**
 * The parser has found a line starting "mtl".
 */
#define STATE_MTL 12

/**
 * The parser has found a line starting "mtll".
 */
#define STATE_MTLL 13

/**
 * The parser has found a line starting "mtlli".
 */
#define STATE_MTLLI 14

/**
 * The parser has found a line starting "mtllib".
 */
#define STATE_MTLLIB 15

/**
 * The parser has found a line starting "mtllib", then at least one space.
 */
#define STATE_MTLLIB_SPACE 16

/**
 * The parser has found a line starting "usemtl", then at least one space, then
 * a file name.
 */
#define STATE_MTLLIB_NAME 17

/**
 * The parser has found a line starting "usemtl", then at least one space, then
 * a file name, then at least one space.
 */
#define STATE_MTLLIB_NAME_SPACE 18

/**
 * The parser has found a line starting "o".
 */
#define STATE_O 19

/**
 * The parser has found a line starting "o", then at least one space.
 */
#define STATE_O_SPACE 20

/**
 * The parser has found a line starting "o", then at least one space, then an
 * object name.
 */
#define STATE_O_NAME 21

/**
 * The parser has found a line starting "o", then at least one space, then an
 * object name, then at least one space.
 */
#define STATE_O_NAME_SPACE 22

/**
 * The parser has found a line starting "v".
 */
#define STATE_V 23

/**
 * The parser has found a line starting "v", then at least one space.
 */
#define STATE_V_SPACE 24

/**
 * The parser has found a line starting "v", then at least one space, then at
 * least part of a number.
 */
#define STATE_V_X 25

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space.
 */
#define STATE_V_X_SPACE 26

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then at least part of a number.
 */
#define STATE_V_Y 27

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then a number, then at least one space.
 */
#define STATE_V_Y_SPACE 28

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then a number, then at least one space, then
 * at least part of a number.
 */
#define STATE_V_Z 29

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then a number, then at least one space, then
 * a number, then at least one space.
 */
#define STATE_V_Z_SPACE 30

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then a number, then at least one space, then
 * a number, then at least one space, then at least part of a number.
 */
#define STATE_V_R 31

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then a number, then at least one space, then
 * a number, then at least one space, then a number, then at least one space.
 */
#define STATE_V_R_SPACE 32

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then a number, then at least one space, then
 * a number, then at least one space, then a number, then at least one space,
 * then at least part of a number.
 */
#define STATE_V_G 33

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then a number, then at least one space, then
 * a number, then at least one space, then a number, then at least one space,
 * then a number, then at least one space.
 */
#define STATE_V_G_SPACE 34

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then a number, then at least one space, then
 * a number, then at least one space, then a number, then at least one space,
 * then a number, then at least one space, then at least part of a number.
 */
#define STATE_V_B 35

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then a number, then at least one space, then
 * a number, then at least one space, then a number, then at least one space,
 * then a number, then at least one space, then a number, then at least one
 * space.
 */
#define STATE_V_B_SPACE 36

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then a number, then at least one space, then
 * a number, then at least one space, then a number, then at least one space,
 * then a number, then at least one space, then a number, then at least one
 * space, then at least part of a number.
 */
#define STATE_V_O 37

/**
 * The parser has found a line starting "v", then at least one space, then a
 * number, then at least one space, then a number, then at least one space, then
 * a number, then at least one space, then a number, then at least one space,
 * then a number, then at least one space, then a number, then at least one
 * space, then a number, then at least one space.
 */
#define STATE_V_O_SPACE 38

/**
 * The parser has found a line starting "vt".
 */
#define STATE_VT 39

/**
 * The parser has found a line starting "vt", then at least one space.
 */
#define STATE_VT_SPACE 40

/**
 * The parser has found a line starting "vt", then at least one space, then at
 * least part of a number.
 */
#define STATE_VT_U 41

/**
 * The parser has found a line starting "vt", then at least one space, then a
 * number, then at least one space.
 */
#define STATE_VT_U_SPACE 42

/**
 * The parser has found a line starting "vt", then at least one space, then a
 * number, then at least one space, then at least part of a number.
 */
#define STATE_VT_V 43

/**
 * The parser has found a line starting "vt", then at least one space, then a
 * number, then at least one space, then a number, then at least one space.
 */
#define STATE_VT_V_SPACE 44

/**
 * The parser has found a line starting "f".
 */
#define STATE_F 45

/**
 * The parser has found a line starting "f", then at least one space.
 */
#define STATE_F_SPACE 46

/**
 * The parser has found a line starting "f", then at least one space, then at
 * least part of a number.
 */
#define STATE_F_V 47

/**
 * The parser has found a line starting "f", then at least one space, then a
 * number, then a slash.
 */
#define STATE_F_V_SLASH 48

/**
 * The parser has found a line starting "f", then at least one space, then a
 * number, then a slash, then at least part of a number.
 */
#define STATE_F_VT 49

/**
 * The current state of the parser.
 */
extern int state;

#endif

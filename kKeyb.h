#ifndef kKeyb_H
#define kKeyb_H

/*                                          Matrix kKeyb
    K00, K01, K02, K03, K04, K05, K06, K07,             K32, K33, K34, K35, K36, K37, K38, K39,
    K08, K09, K10, K11, K12, K13, K14, K15,             K40, K41, K42, K43, K44, K45, K46, K47,
    K16, K17, K18, K19, K20, K21, K22, K23,             K48, K49, K50, K51, K52, K53, K54, K55,
    K24, K25, K26, K27, K28, K29, K30, K31,             K56, K57, K58, K59, K60, K61, K62, K63
*/

/*                                     Matrix kKeyb phisical
         K01, K02, K03, K04, K05, K06,                       K33, K34, K35, K36, K37, K38,
    K08, K09, K10, K11, K12, K13, K14,                       K41, K42, K43, K44, K45, K46, K47,
    K16, K17, K18, K19, K20, K21, K22,                       K49, K50, K51, K52, K53, K54, K55,
         K25, K26, K27, K28, K29, K30,                       K57, K58, K59, K60, K61, K62,
                            K24, K31,                         K56, K63
                                     K23,                 K48,
                                        K15,            K40,
                                         K07,          K32,
*/

#include "quantum.h"
#define ___ KC_NO

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
// Такая конверсия сделана из-за простоты монтажа, иначе одна половина получается зеркально

#define LAYOUT_ortho_8x8( \
    K00, K01, K02, K03, K04, K05, K06, K07, \
    K08, K09, K10, K11, K12, K13, K14, K15, \
    K16, K17, K18, K19, K20, K21, K22, K23, \
    K24, K25, K26, K27, K28, K29, K30, K31, \
    \
    K32, K33, K34, K35, K36, K37, K38, K39, \
    K40, K41, K42, K43, K44, K45, K46, K47, \
    K48, K49, K50, K51, K52, K53, K54, K55, \
    K56, K57, K58, K59, K60, K61, K62, K63 \
) \
{ \
    { K07, K06, K05, K04, K03, K02, K01, K00 }, \
    { K15, K14, K13, K12, K11, K10, K09, K08 }, \
    { K23, K22, K21, K20, K19, K18, K17, K16 }, \
    { K31, K30, K29, K28, K27, K26, K25, K24 }, \
    \
    { K32, K33, K34, K35, K36, K37, K38, K39 }, \
    { K40, K41, K42, K43, K44, K45, K46, K47 }, \
    { K48, K49, K50, K51, K52, K53, K54, K55 }, \
    { K56, K57, K58, K59, K60, K61, K62, K63 } \
}

#endif

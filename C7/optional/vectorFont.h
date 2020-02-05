/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *          View this license at http://creativecommons.org/about/licenses/
 */

#include <avr/pgmspace.h>

const int8_t hershey_vertices[] PROGMEM = {
    /*   */ 
    /* ! */  5,21, 5, 7,-1,-1, 5, 2, 4, 1, 5, 0, 6, 1, 5, 2,
    /* " */  4,21, 4,14,-1,-1,12,21,12,14,
    /* # */ 11,25, 4,-7,-1,-1,17,25,10,-7,-1,-1, 4,12,18,12,-1,-1, 3, 6,17, 6,
    /* $ */  8,25, 8,-4,-1,-1,12,25,12,-4,-1,-1,17,18,15,20,12,21, 8,21, 5,20, 3,18, 3,16, 4,14, 5,13, 7,12,13,10,15, 9,16, 8,17, 6,17, 3,15, 1,12, 0, 8, 0, 5, 1, 3, 3,
    /* % */ 21,21, 3, 0,-1,-1, 8,21,10,19,10,17, 9,15, 7,14, 5,14, 3,16, 3,18, 4,20, 6,21, 8,21,10,20,13,19,16,19,19,20,21,21,-1,-1,17, 7,15, 6,14, 4,14, 2,16, 0,18, 0,20, 1,21, 3,21, 5,19, 7,17, 7,
    /* & */ 23,12,23,13,22,14,21,14,20,13,19,11,17, 6,15, 3,13, 1,11, 0, 7, 0, 5, 1, 4, 2, 3, 4, 3, 6, 4, 8, 5, 9,12,13,13,14,14,16,14,18,13,20,11,21, 9,20, 8,18, 8,16, 9,13,11,10,16, 3,18, 1,20, 0,22, 0,23, 1,23, 2,
    /* ' */  5,19, 4,20, 5,21, 6,20, 6,18, 5,16, 4,15,
    /* ( */ 11,25, 9,23, 7,20, 5,16, 4,11, 4, 7, 5, 2, 7,-2, 9,-5,11,-7,
    /* ) */  3,25, 5,23, 7,20, 9,16,10,11,10, 7, 9, 2, 7,-2, 5,-5, 3,-7,
    /* * */  8,21, 8, 9,-1,-1, 3,18,13,12,-1,-1,13,18, 3,12,
    /* + */ 13,18,13, 0,-1,-1, 4, 9,22, 9,
    /* , */  6, 1, 5, 0, 4, 1, 5, 2, 6, 1, 6,-1, 5,-3, 4,-4,
    /* - */  4, 9,22, 9,
    /* . */  5, 2, 4, 1, 5, 0, 6, 1, 5, 2,
    /* / */ 20,25, 2,-7,
    /* 0 */  9,21, 6,20, 4,17, 3,12, 3, 9, 4, 4, 6, 1, 9, 0,11, 0,14, 1,16, 4,17, 9,17,12,16,17,14,20,11,21, 9,21,
    /* 1 */  6,17, 8,18,11,21,11, 0,
    /* 2 */  4,16, 4,17, 5,19, 6,20, 8,21,12,21,14,20,15,19,16,17,16,15,15,13,13,10, 3, 0,17, 0,
    /* 3 */  5,21,16,21,10,13,13,13,15,12,16,11,17, 8,17, 6,16, 3,14, 1,11, 0, 8, 0, 5, 1, 4, 2, 3, 4,
    /* 4 */ 13,21, 3, 7,18, 7,-1,-1,13,21,13, 0,
    /* 5 */ 15,21, 5,21, 4,12, 5,13, 8,14,11,14,14,13,16,11,17, 8,17, 6,16, 3,14, 1,11, 0, 8, 0, 5, 1, 4, 2, 3, 4,
    /* 6 */ 16,18,15,20,12,21,10,21, 7,20, 5,17, 4,12, 4, 7, 5, 3, 7, 1,10, 0,11, 0,14, 1,16, 3,17, 6,17, 7,16,10,14,12,11,13,10,13, 7,12, 5,10, 4, 7,
    /* 7 */ 17,21, 7, 0,-1,-1, 3,21,17,21,
    /* 8 */  8,21, 5,20, 4,18, 4,16, 5,14, 7,13,11,12,14,11,16, 9,17, 7,17, 4,16, 2,15, 1,12, 0, 8, 0, 5, 1, 4, 2, 3, 4, 3, 7, 4, 9, 6,11, 9,12,13,13,15,14,16,16,16,18,15,20,12,21, 8,21,
    /* 9 */ 16,14,15,11,13, 9,10, 8, 9, 8, 6, 9, 4,11, 3,14, 3,15, 4,18, 6,20, 9,21,10,21,13,20,15,18,16,14,16, 9,15, 4,13, 1,10, 0, 8, 0, 5, 1, 4, 3,
    /* : */  5,14, 4,13, 5,12, 6,13, 5,14,-1,-1, 5, 2, 4, 1, 5, 0, 6, 1, 5, 2,
    /* ; */  5,14, 4,13, 5,12, 6,13, 5,14,-1,-1, 6, 1, 5, 0, 4, 1, 5, 2, 6, 1, 6,-1, 5,-3, 4,-4,
    /* < */ 20,18, 4, 9,20, 0,
    /* = */  4,12,22,12,-1,-1, 4, 6,22, 6,
    /* > */  4,18,20, 9, 4, 0,
    /* ? */  3,16, 3,17, 4,19, 5,20, 7,21,11,21,13,20,14,19,15,17,15,15,14,13,13,12, 9,10, 9, 7,-1,-1, 9, 2, 8, 1, 9, 0,10, 1, 9, 2,
    /* @ */ 18,13,17,15,15,16,12,16,10,15, 9,14, 8,11, 8, 8, 9, 6,11, 5,14, 5,16, 6,17, 8,-1,-1,12,16,10,14, 9,11, 9, 8,10, 6,11, 5,-1,-1,18,16,17, 8,17, 6,19, 5,21, 5,23, 7,24,10,24,12,23,15,22,17,20,19,18,20,15,21,12,21, 9,20, 7,19, 5,17, 4,15, 3,12, 3, 9, 4, 6, 5, 4, 7, 2, 9, 1,12, 0,15, 0,18, 1,20, 2,21, 3,-1,-1,19,16,18, 8,18, 6,19, 5,
    /* A */  9,21, 1, 0,-1,-1, 9,21,17, 0,-1,-1, 4, 7,14, 7,
    /* B */  4,21, 4, 0,-1,-1, 4,21,13,21,16,20,17,19,18,17,18,15,17,13,16,12,13,11,-1,-1, 4,11,13,11,16,10,17, 9,18, 7,18, 4,17, 2,16, 1,13, 0, 4, 0,
    /* C */ 18,16,17,18,15,20,13,21, 9,21, 7,20, 5,18, 4,16, 3,13, 3, 8, 4, 5, 5, 3, 7, 1, 9, 0,13, 0,15, 1,17, 3,18, 5,
    /* D */  4,21, 4, 0,-1,-1, 4,21,11,21,14,20,16,18,17,16,18,13,18, 8,17, 5,16, 3,14, 1,11, 0, 4, 0,
    /* E */  4,21, 4, 0,-1,-1, 4,21,17,21,-1,-1, 4,11,12,11,-1,-1, 4, 0,17, 0,
    /* F */  4,21, 4, 0,-1,-1, 4,21,17,21,-1,-1, 4,11,12,11,
    /* G */ 18,16,17,18,15,20,13,21, 9,21, 7,20, 5,18, 4,16, 3,13, 3, 8, 4, 5, 5, 3, 7, 1, 9, 0,13, 0,15, 1,17, 3,18, 5,18, 8,-1,-1,13, 8,18, 8,
    /* H */  4,21, 4, 0,-1,-1,18,21,18, 0,-1,-1, 4,11,18,11,
    /* I */  4,21, 4, 0,
    /* J */ 12,21,12, 5,11, 2,10, 1, 8, 0, 6, 0, 4, 1, 3, 2, 2, 5, 2, 7,
    /* K */  4,21, 4, 0,-1,-1,18,21, 4, 7,-1,-1, 9,12,18, 0,
    /* L */  4,21, 4, 0,-1,-1, 4, 0,16, 0,
    /* M */  4,21, 4, 0,-1,-1, 4,21,12, 0,-1,-1,20,21,12, 0,-1,-1,20,21,20, 0,
    /* N */  4,21, 4, 0,-1,-1, 4,21,18, 0,-1,-1,18,21,18, 0,
    /* O */  9,21, 7,20, 5,18, 4,16, 3,13, 3, 8, 4, 5, 5, 3, 7, 1, 9, 0,13, 0,15, 1,17, 3,18, 5,19, 8,19,13,18,16,17,18,15,20,13,21, 9,21,
    /* P */  4,21, 4, 0,-1,-1, 4,21,13,21,16,20,17,19,18,17,18,14,17,12,16,11,13,10, 4,10,
    /* Q */  9,21, 7,20, 5,18, 4,16, 3,13, 3, 8, 4, 5, 5, 3, 7, 1, 9, 0,13, 0,15, 1,17, 3,18, 5,19, 8,19,13,18,16,17,18,15,20,13,21, 9,21,-1,-1,12, 4,18,-2,
    /* R */  4,21, 4, 0,-1,-1, 4,21,13,21,16,20,17,19,18,17,18,15,17,13,16,12,13,11, 4,11,-1,-1,11,11,18, 0,
    /* S */ 17,18,15,20,12,21, 8,21, 5,20, 3,18, 3,16, 4,14, 5,13, 7,12,13,10,15, 9,16, 8,17, 6,17, 3,15, 1,12, 0, 8, 0, 5, 1, 3, 3,
    /* T */  8,21, 8, 0,-1,-1, 1,21,15,21,
    /* U */  4,21, 4, 6, 5, 3, 7, 1,10, 0,12, 0,15, 1,17, 3,18, 6,18,21,
    /* V */  1,21, 9, 0,-1,-1,17,21, 9, 0,
    /* W */  2,21, 7, 0,-1,-1,12,21, 7, 0,-1,-1,12,21,17, 0,-1,-1,22,21,17, 0,
    /* X */  3,21,17, 0,-1,-1,17,21, 3, 0,
    /* Y */  1,21, 9,11, 9, 0,-1,-1,17,21, 9,11,
    /* Z */ 17,21, 3, 0,-1,-1, 3,21,17,21,-1,-1, 3, 0,17, 0,
    /* [ */  4,25, 4,-7,-1,-1, 5,25, 5,-7,-1,-1, 4,25,11,25,-1,-1, 4,-7,11,-7,
    /* \ */  0,21,14,-3,
    /* ] */  9,25, 9,-7,-1,-1,10,25,10,-7,-1,-1, 3,25,10,25,-1,-1, 3,-7,10,-7,
    /* ^ */  6,15, 8,18,10,15,-1,-1, 3,12, 8,17,13,12,-1,-1, 8,17, 8, 0,
    /* _ */  0,-2,16,-2,
    /* ` */  6,21, 5,20, 4,18, 4,16, 5,15, 6,16, 5,17,
    /* a */ 15,14,15, 0,-1,-1,15,11,13,13,11,14, 8,14, 6,13, 4,11, 3, 8, 3, 6, 4, 3, 6, 1, 8, 0,11, 0,13, 1,15, 3,
    /* b */  4,21, 4, 0,-1,-1, 4,11, 6,13, 8,14,11,14,13,13,15,11,16, 8,16, 6,15, 3,13, 1,11, 0, 8, 0, 6, 1, 4, 3,
    /* c */ 15,11,13,13,11,14, 8,14, 6,13, 4,11, 3, 8, 3, 6, 4, 3, 6, 1, 8, 0,11, 0,13, 1,15, 3,
    /* d */ 15,21,15, 0,-1,-1,15,11,13,13,11,14, 8,14, 6,13, 4,11, 3, 8, 3, 6, 4, 3, 6, 1, 8, 0,11, 0,13, 1,15, 3,
    /* e */  3, 8,15, 8,15,10,14,12,13,13,11,14, 8,14, 6,13, 4,11, 3, 8, 3, 6, 4, 3, 6, 1, 8, 0,11, 0,13, 1,15, 3,
    /* f */ 10,21, 8,21, 6,20, 5,17, 5, 0,-1,-1, 2,14, 9,14,
    /* g */ 15,14,15,-2,14,-5,13,-6,11,-7, 8,-7, 6,-6,-1,-1,15,11,13,13,11,14, 8,14, 6,13, 4,11, 3, 8, 3, 6, 4, 3, 6, 1, 8, 0,11, 0,13, 1,15, 3,
    /* h */  4,21, 4, 0,-1,-1, 4,10, 7,13, 9,14,12,14,14,13,15,10,15, 0,
    /* i */  3,21, 4,20, 5,21, 4,22, 3,21,-1,-1, 4,14, 4, 0,
    /* j */  5,21, 6,20, 7,21, 6,22, 5,21,-1,-1, 6,14, 6,-3, 5,-6, 3,-7, 1,-7,
    /* k */  4,21, 4, 0,-1,-1,14,14, 4, 4,-1,-1, 8, 8,15, 0,
    /* l */  4,21, 4, 0,
    /* m */  4,14, 4, 0,-1,-1, 4,10, 7,13, 9,14,12,14,14,13,15,10,15, 0,-1,-1,15,10,18,13,20,14,23,14,25,13,26,10,26, 0,
    /* n */  4,14, 4, 0,-1,-1, 4,10, 7,13, 9,14,12,14,14,13,15,10,15, 0,
    /* o */  8,14, 6,13, 4,11, 3, 8, 3, 6, 4, 3, 6, 1, 8, 0,11, 0,13, 1,15, 3,16, 6,16, 8,15,11,13,13,11,14, 8,14,
    /* p */  4,14, 4,-7,-1,-1, 4,11, 6,13, 8,14,11,14,13,13,15,11,16, 8,16, 6,15, 3,13, 1,11, 0, 8, 0, 6, 1, 4, 3,
    /* q */ 15,14,15,-7,-1,-1,15,11,13,13,11,14, 8,14, 6,13, 4,11, 3, 8, 3, 6, 4, 3, 6, 1, 8, 0,11, 0,13, 1,15, 3,
    /* r */  4,14, 4, 0,-1,-1, 4, 8, 5,11, 7,13, 9,14,12,14,
    /* s */ 14,11,13,13,10,14, 7,14, 4,13, 3,11, 4, 9, 6, 8,11, 7,13, 6,14, 4,14, 3,13, 1,10, 0, 7, 0, 4, 1, 3, 3,
    /* t */  5,21, 5, 4, 6, 1, 8, 0,10, 0,-1,-1, 2,14, 9,14,
    /* u */  4,14, 4, 4, 5, 1, 7, 0,10, 0,12, 1,15, 4,-1,-1,15,14,15, 0,
    /* v */  2,14, 8, 0,-1,-1,14,14, 8, 0,
    /* w */  3,14, 7, 0,-1,-1,11,14, 7, 0,-1,-1,11,14,15, 0,-1,-1,19,14,15, 0,
    /* x */  3,14,14, 0,-1,-1,14,14, 3, 0,
    /* y */  2,14, 8, 0,-1,-1,14,14, 8, 0, 6,-4, 4,-6, 2,-7, 1,-7,
    /* z */ 14,14, 3, 0,-1,-1, 3,14,14,14,-1,-1, 3, 0,14, 0,
    /* { */  9,25, 7,24, 6,23, 5,21, 5,19, 6,17, 7,16, 8,14, 8,12, 6,10,-1,-1, 7,24, 6,22, 6,20, 7,18, 8,17, 9,15, 9,13, 8,11, 4, 9, 8, 7, 9, 5, 9, 3, 8, 1, 7, 0, 6,-2, 6,-4, 7,-6,-1,-1, 6, 8, 8, 6, 8, 4, 7, 2, 6, 1, 5,-1, 5,-3, 6,-5, 7,-6, 9,-7,
    /* | */  4,25, 4,-7,
    /* } */  5,25, 7,24, 8,23, 9,21, 9,19, 8,17, 7,16, 6,14, 6,12, 8,10,-1,-1, 7,24, 8,22, 8,20, 7,18, 6,17, 5,15, 5,13, 6,11,10, 9, 6, 7, 5, 5, 5, 3, 6, 1, 7, 0, 8,-2, 8,-4, 7,-6,-1,-1, 8, 8, 6, 6, 6, 4, 7, 2, 8, 1, 9,-1, 9,-3, 8,-5, 7,-6, 5,-7,
    /* ~ */  3, 6, 3, 8, 4,11, 6,12, 8,12,10,11,14, 8,16, 7,18, 7,20, 8,21,10,-1,-1, 3, 8, 4,10, 6,11, 8,11,10,10,14, 7,16, 6,18, 6,20, 7,21,10,21,12,
};

const uint16_t hershey_offset[] PROGMEM = {
 /* 0-31 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    /*   */ 0,
    /* ! */ 0,
    /* " */ 16,
    /* # */ 26,
    /* $ */ 48,
    /* % */ 100,
    /* & */ 162,
    /* ' */ 230,
    /* ( */ 244,
    /* ) */ 264,
    /* * */ 284,
    /* + */ 300,
    /* , */ 310,
    /* - */ 326,
    /* . */ 330,
    /* / */ 340,
    /* 0 */ 344,
    /* 1 */ 378,
    /* 2 */ 386,
    /* 3 */ 414,
    /* 4 */ 444,
    /* 5 */ 456,
    /* 6 */ 490,
    /* 7 */ 536,
    /* 8 */ 546,
    /* 9 */ 604,
    /* : */ 650,
    /* ; */ 672,
    /* < */ 700,
    /* = */ 706,
    /* > */ 716,
    /* ? */ 722,
    /* @ */ 762,
    /* A */ 872,
    /* B */ 888,
    /* C */ 934,
    /* D */ 970,
    /* E */ 1000,
    /* F */ 1022,
    /* G */ 1038,
    /* H */ 1082,
    /* I */ 1098,
    /* J */ 1102,
    /* K */ 1122,
    /* L */ 1138,
    /* M */ 1148,
    /* N */ 1170,
    /* O */ 1186,
    /* P */ 1228,
    /* Q */ 1254,
    /* R */ 1302,
    /* S */ 1334,
    /* T */ 1374,
    /* U */ 1384,
    /* V */ 1404,
    /* W */ 1414,
    /* X */ 1436,
    /* Y */ 1446,
    /* Z */ 1458,
    /* [ */ 1474,
    /* \ */ 1496,
    /* ] */ 1500,
    /* ^ */ 1522,
    /* _ */ 1542,
    /* ` */ 1546,
    /* a */ 1560,
    /* b */ 1594,
    /* c */ 1628,
    /* d */ 1656,
    /* e */ 1690,
    /* f */ 1724,
    /* g */ 1740,
    /* h */ 1784,
    /* i */ 1804,
    /* j */ 1820,
    /* k */ 1842,
    /* l */ 1858,
    /* m */ 1862,
    /* n */ 1898,
    /* o */ 1918,
    /* p */ 1952,
    /* q */ 1986,
    /* r */ 2020,
    /* s */ 2036,
    /* t */ 2070,
    /* u */ 2086,
    /* v */ 2106,
    /* w */ 2116,
    /* x */ 2138,
    /* y */ 2148,
    /* z */ 2166,
    /* { */ 2182,
    /* | */ 2260,
    /* } */ 2264,
    /* ~ */ 2342,
    /*  */ 2388,
};

const int8_t hershey_width[] PROGMEM = {
 /* 0-31 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    /*   */ 16,
    /* ! */ 10,
    /* " */ 16,
    /* # */ 21,
    /* $ */ 20,
    /* % */ 24,
    /* & */ 26,
    /* ' */ 10,
    /* ( */ 14,
    /* ) */ 14,
    /* * */ 16,
    /* + */ 26,
    /* , */ 10,
    /* - */ 26,
    /* . */ 10,
    /* / */ 22,
    /* 0 */ 20,
    /* 1 */ 20,
    /* 2 */ 20,
    /* 3 */ 20,
    /* 4 */ 20,
    /* 5 */ 20,
    /* 6 */ 20,
    /* 7 */ 20,
    /* 8 */ 20,
    /* 9 */ 20,
    /* : */ 10,
    /* ; */ 10,
    /* < */ 24,
    /* = */ 26,
    /* > */ 24,
    /* ? */ 18,
    /* @ */ 27,
    /* A */ 18,
    /* B */ 21,
    /* C */ 21,
    /* D */ 21,
    /* E */ 19,
    /* F */ 18,
    /* G */ 21,
    /* H */ 22,
    /* I */ 8,
    /* J */ 16,
    /* K */ 21,
    /* L */ 17,
    /* M */ 24,
    /* N */ 22,
    /* O */ 22,
    /* P */ 21,
    /* Q */ 22,
    /* R */ 21,
    /* S */ 20,
    /* T */ 16,
    /* U */ 22,
    /* V */ 18,
    /* W */ 24,
    /* X */ 20,
    /* Y */ 18,
    /* Z */ 20,
    /* [ */ 14,
    /* \ */ 14,
    /* ] */ 14,
    /* ^ */ 16,
    /* _ */ 16,
    /* ` */ 10,
    /* a */ 19,
    /* b */ 19,
    /* c */ 18,
    /* d */ 19,
    /* e */ 18,
    /* f */ 12,
    /* g */ 19,
    /* h */ 19,
    /* i */ 8,
    /* j */ 10,
    /* k */ 17,
    /* l */ 8,
    /* m */ 30,
    /* n */ 19,
    /* o */ 19,
    /* p */ 19,
    /* q */ 19,
    /* r */ 13,
    /* s */ 17,
    /* t */ 12,
    /* u */ 19,
    /* v */ 16,
    /* w */ 22,
    /* x */ 17,
    /* y */ 16,
    /* z */ 17,
    /* { */ 14,
    /* | */ 8,
    /* } */ 14,
    /* ~ */ 24,
};


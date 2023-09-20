/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Patterns for Pattern Generator
 */

#ifndef PATTERNS_H
#define PATTERNS_H

/**
 * @brief Put box patterns in pattern table starting at index n
 * @param n the pattern # to start copying to
 */
void patterns_box(unsigned char n);

/**
 * @brief Put the lives pattern at position specified by n
 */
void pattern_lives(unsigned char n);

/**
 * @brief External references so other parts of program can use targ patterns, e.g. bonus
 */
extern const unsigned char _targ_left_patterns[];
extern const unsigned char _targ_right_patterns[];
extern const unsigned char _targ_down_patterns[];
extern const unsigned char _targ_up_patterns[];

/**
 * @brief External references for the Wummel sprite patterns
 */
extern const unsigned char wummel_left_pattern[8];
extern const unsigned char wummel_right_pattern[8];
extern const unsigned char wummel_down_pattern[8];
extern const unsigned char wummel_up_pattern[8];
#endif /* PATTERNS_H */

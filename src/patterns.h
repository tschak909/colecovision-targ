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

extern const unsigned char _targ_left_patterns[];
extern const unsigned char _targ_right_patterns[];

#endif /* PATTERNS_H */

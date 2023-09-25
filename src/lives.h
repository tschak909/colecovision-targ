/**
 * @file lives.h
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Lives display
 */

#ifndef LIVES_H
#define LIVES_H

/**
 * @brief Update lives on display
 */
void lives(void);

/**
 * @brief set # of lives for player
 * @param p Pointer to lives counter to change (lives_1 or lives_2)
 * @param n the new lives value (0-5)
 */
void lives_set(unsigned char *p, unsigned char n);

extern unsigned char lives_1[5];
extern unsigned char lives_2[5];

#endif /* LIVES_H */

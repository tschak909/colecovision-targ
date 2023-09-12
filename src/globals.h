/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Globals and typedefs
 */

#ifndef GLOBALS_H
#define GLOBALS_H

typedef enum _player
  {
    PLAYER_1 = 0,
    PLAYER_2
  } Player;

extern unsigned char score_1[5];
extern unsigned char score_2[5];

#endif /* GLOBALS_H */

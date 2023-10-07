/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Velocity types/functions
 */

typedef enum _direction
  {
    LEFT,
    RIGHT,
    UP,
    DOWN
  } Direction;

typedef struct _velocity
{
  Direction d;  // see enum
  char dx;      // signed  (0-3)
  char dy;      // signed  (0-3)
  char i;       // signed  (0-15)
} Velocity;


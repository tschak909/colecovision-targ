/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Velocity type
 */

#ifndef VELOCITY_H
#define VELOCITY_H

#define UP 0x00
#define RIGHT 0x01
#define DOWN 0x02
#define LEFT 0x03

typedef struct _velocity
{
  Accum hv; // Horizontal velocity (signed)
  Accum vv; // Vertical velocity (signed)
} Velocity; 

#endif /* VELOCITY_H */

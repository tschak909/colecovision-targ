/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Targ rider object code/data
 */

#include <stdlib.h>
#include <stdbool.h>
#include <os7.h>
#include <arch/coleco.h>
#include <math/math_fix16.h>
#include "patterns.h"
#include "targ.h"
#include "velocity.h"

#define TARG_MAX 10

/**
 * @brief Holds current horizontal/vertical velocity for each targ
 */
Velocity targ_velocity[TARG_MAX];

/**
 * @brief holds whether each targ is alive (1) or dead (0)
 */
bool targ_alive[TARG_MAX];



/**
 * @brief the state objects for each targ
 */
static SprStatus targ_status[TARG_MAX];

/**
 * @brief the frame objects mapping sprite generators and colors to each frame
 */
static const SprFrame targ_frame[4] =
  {
    {
      DARK_RED,       // color to use for sprite
      0               // generator offset to use for frame
    },
    {
      DARK_RED,
      1
    },
    {
      DARK_RED,
      2
    },
    {
      DARK_RED,
      3
    }
  };

/**
 * @brief the graphics object mapping generators in our rom to their place in the sprite generator table
 */
static const SprGraphics targ_graphics =
  {
    SPRITE,            // Object type is SPRITE
    0x01,              // First sprite pattern generator used is 0x05
    targ_generators,   // pointer to targ generator patterns in our ROM
    4,                 // Number of generators to copy
    targ_frame         // pointer to previously defined targ frame table.
  };

/**
 * @brief the top level targ objects
 */
static const SprObj targ_obj[10] = 
  {
    {
      targ_graphics,   // ptr to graphics object
      &targ_status[0], // ptr to frame object
      1
    },
    {
      targ_graphics,   // ptr to graphics object
      &targ_status[1], // ptr to frame object
      2
    },
    {
      targ_graphics,   // ptr to graphics object
      &targ_status[2], // ptr to frame object
      3
    },
    {
      targ_graphics,   // ptr to graphics object
      &targ_status[3], // ptr to frame object
      4
    },
    {
      targ_graphics,   // ptr to graphics object
      &targ_status[4], // ptr to frame object
      5
    },
    {
      targ_graphics,   // ptr to graphics object
      &targ_status[5], // ptr to frame object
      6
    },
    {
      targ_graphics,   // ptr to graphics object
      &targ_status[6], // ptr to frame object
      7
    },
    {
      targ_graphics,   // ptr to graphics object
      &targ_status[7], // ptr to frame object
      8
    },
    {
      targ_graphics,   // ptr to graphics object
      &targ_status[8], // ptr to frame object
      9
    },
    {
      targ_graphics,   // ptr to graphics object
      &targ_status[9], // ptr to frame object
      10
    }
  };

/**
 * @brief Reset targs to their initial positions, and copy targ data into VRAM
 */
void targ_reset(void)
{
  // Initial X position table
  unsigned char rx[TARG_MAX] = {16,40,64,88,112,136,160,184,208,232};

  // Reset positions to start based on table above
  for (unsigned char i=0;i<TARG_MAX;i++)
    {
      // move generators from ROM into VRAM
      activate(targ_obj[i],true);

      targ_alive[i]=true;
      targ_status[i].frame=DOWN;
      targ_status[i].x = rx[i];
      targ_status[i].y = 40;
    }
}

/**
 * @brief Multiplex targ sprites
 */
void targ_mux_sprites(void)
{
  for (unsigned char i=0;i<15;i++)
    {
      os7_sprite_order_table[i+1] -= 0x04;
      os7_sprite_order_table[i+1] &= 0x0F;
    }
}

/**
 * @brief change velocity
 */
void targ_change_velocity(SprStatus *s, Velocity *v)
{
}

/**
 * @brief Check for collisions
 */
void targ_check_collisions(void)
{
  for (unsigned char i=0;i<TARG_MAX;i++)
    {
      unsigned char o = (targ_status[i].y >> 3) + (targ_status[i].x >> 3); // convert sprite to bg tile offset
      char t;

      // Determine adjacent tile to check for barrier (building or city wall)
      switch (targ_status[i].frame)
	{
	case UP:
	  o -= 32;
	  break;
	case RIGHT:
	  o++;
	  break;
	case DOWN:
	  o += 32;
	  break;
	case LEFT:
	  o--;
	  break;
	}

      // Read adjacent tile
      read_vram(&t,o,1);

      if (t!=0x20) // next tile is not empty space, change direction
	targ_change_velocity(&targ_status[i],&targ_velocity[i]);      
    }
}

/**
 * @brief update targ positions
 */
void targ(void)
{
  for (unsigned char i=0;i<TARG_MAX;i++)
    {
      if (!targ_alive[i])
	targ_status[i].x = targ_status[i].y = 0xFFFF; // put off screen, if dead.

      put_obj(targ_obj[i],0);
    }

  targ_mux_sprites();
}


/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Targ rider object code/data
 */

#include <stdlib.h>
#include <os7.h>
#include "patterns.h"

SMOFrame(2) TargFrame;
SMOOldScreen(2) TargOldScreen;
SMOGraphics(9,TargFrame) TargGraphics;

// Extents must be at least 1, 0 causes a pre-decrement wrap to 255
// The frame objects.
const TargFrame targFrame0 = {1,2,{0x60,0x61}};
const TargFrame targFrame1 = {1,2,{0x62,0x63}};
const TargFrame targFrame2 = {1,2,{0x64,0x65}};
const TargFrame targFrame3 = {1,2,{0x66,0x67}};
const TargFrame targFrame4 = {1,2,{0x68,0x69}};
const TargFrame targFrame5 = {1,2,{0x6a,0x6b}};
const TargFrame targFrame6 = {1,2,{0x6c,0x6d}};
const TargFrame targFrame7 = {1,2,{0x6e,0x6f}};
const TargFrame targFrame8 = {1,2,{0x70,0x71}};

// The Targ graphic object
const TargGraphics targGraphics=
  {
    0,
    0x60,
    18,
    _targ_down_patterns,
    {targFrame0,targFrame1,targFrame2,targFrame3,targFrame4,targFrame5,targFrame6,targFrame7,targFrame8}
  };

// The 10 targStatus objects (x, y, frame, etc.)
SMOStatus targStatus[10];

// The 10 targOldScreen objects (see above)
TargOldScreen targOldScreen[10];

// The 10 top level SEMI-MOBILE objects
const SMO targSMO[10];

/**
 * @brief since SMO is in RAM, we have to initialize it dynamically
 */
void targ_init(void)
{
  for (int i=0;i<10;i++)
    {
      targSMO[i].graphics_addr=&targGraphics;
      targSMO[i].status_addr=&targStatus[i];
      targSMO[i].old_screen_addr=&targOldScreen[i];
    }
}

/**
 * @brief plot 10 targs, and go down the screen
 */
void targ(void)
{
  targ_init();

  // Set initial positions
  for (int i=0;i<10;i++)
    {
      activate(&targSMO[i],false);
      targStatus[i].x=(i*24)+16;
      targStatus[i].y=40;
      targStatus[i].frame=0;
    }

  // The main loop here, update position
  while(true)
    {
      for (int i=0;i<10;i++)
	{
	  if (targStatus[i].frame==0x08)
	    {
	      targStatus[i].frame=0;
	      targStatus[i].y+=8;
	      if (targStatus[i].y>160)
		return;
	    }
	  else
	    targStatus[i].frame+=2;

	  put_obj(&targSMO[i],0);
	}

    }
}

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


struct _targGraphics
{
  unsigned char obj_type;
  unsigned char first_gen_name;
  unsigned char numgen;
  void *generators;
  Frame *frame[8];
};

struct _targFrame
{
  unsigned char x_extent;
  unsigned char y_extent;
  unsigned char generator_0;
  unsigned char generator_1;
};

// Extents must be at least 1, 0 causes a pre-decrement wrap to 255
const struct _targFrame targFrame0 = {2,1,0x60,0x61};
const struct _targFrame targFrame1 = {2,1,0x62,0x63};
const struct _targFrame targFrame2 = {2,1,0x64,0x65};
const struct _targFrame targFrame3 = {2,1,0x66,0x67};
const struct _targFrame targFrame4 = {2,1,0x68,0x69};
const struct _targFrame targFrame5 = {2,1,0x6A,0x6B};
const struct _targFrame targFrame6 = {2,1,0x6C,0x6D};
const struct _targFrame targFrame7 = {2,1,0x6E,0x6F};

const struct _targGraphics targGraphics={0,0x60,16,_targ_right_patterns,{targFrame0,targFrame1,targFrame2,targFrame3,targFrame4,targFrame5,targFrame6,targFrame7}};

Status targStatus;
unsigned char targOldScreen[2];
const SMO targSMO={targGraphics,targStatus,targOldScreen};

int i=0;

void targ(void)
{
  SignalNum wait;
  
  activate(&targSMO,false);
  
  for (i=0;i<256;i++)
    {
      targStatus.x++;
      targStatus.frame++;
      targStatus.frame &= 0x07;
      
      activate(&targSMO,true);
      put_obj(&targSMO);
    }
}

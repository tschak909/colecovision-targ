/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Initialization
 */

#include <interrupt.h>
#include <arch/z80.h>
#include <intrinsic.h>
#include <os7.h>
#include "init.h"

TimerTable tt[8];
TimerData td[2];
unsigned char queue[48];

static void vdp_nmi(void)
{
  M_PRESERVE_ALL;
  writer();
  time_mgr();
  M_RESTORE_ALL;
}

void init(void)
{
  init_timer(&tt,&td);
  init_writer(queue,16);
  add_raster_int(vdp_nmi);
}

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

TimerTable tt[2];
TimerData td[2];

static void vdp_nmi(void)
{
  M_PRESERVE_ALL;
  time_mgr();
  M_RESTORE_ALL;
}

void init(void)
{
  init_timer(&tt,&td);
  add_raster_int(vdp_nmi);
}

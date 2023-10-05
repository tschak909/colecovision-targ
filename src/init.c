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
#include <stdbool.h>
#include "init.h"

#define QUEUE_SIZE 16

TimerTable tt[8];
TimerData td[2];

unsigned char deferred_writer_queue[QUEUE_SIZE*WRITER_QUEUE_ENTRY_SIZE];

static void vdp_nmi(void)
{
  M_PRESERVE_ALL;
  time_mgr();
  writer();
  VDP_STATUS_BYTE = read_register();
  M_RESTORE_ALL;
}

void init(void)
{
  init_timer(&tt,&td);
  init_writer(&deferred_writer_queue,QUEUE_SIZE);
  add_raster_int(vdp_nmi);
}

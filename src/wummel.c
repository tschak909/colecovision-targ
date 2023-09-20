/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Wummel object code/data
 */

#include <os7.h>
#include "patterns.h"

SprStatus wummel_status;
const SprFrame wummel_frame = {LIGHT_GREEN,0x50};
const SprGraphics wummel_graphics = {SPRITE,0x50,wummel_left_pattern,1,wummel_frame};
const SprObj wummel_obj = {wummel_graphics,wummel_status,0};

void wummel(void)
{
  wummel_status.x=232;
  wummel_status.y=176;
  activate(wummel_obj,false);
  put_obj(wummel_obj,0);
}

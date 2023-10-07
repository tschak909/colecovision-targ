/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Wummel object code/data
 */

#include <os7.h>
#include "patterns.h"

/**
 * @brief The reset (starting position for the wummel
 */
#define WUMMEL_RESET_X 220
#define WUMMEL_RESET_Y 175

static SprStatus wummel_status;
static const SprFrame wummel_frame = {LIGHT_GREEN,0x00};
static const SprGraphics wummel_graphics_left = {SPRITE,0x00,wummel_left_pattern,1,wummel_frame};
static const SprGraphics wummel_graphics_right = {SPRITE,0x00,wummel_right_pattern,1,wummel_frame};
static const SprGraphics wummel_graphics_up = {SPRITE,0x00,wummel_up_pattern,1,wummel_frame};
static const SprGraphics wummel_graphics_down = {SPRITE,0x00,wummel_down_pattern,1,wummel_frame};
static const SprObj wummel_obj_left = {wummel_graphics_left,wummel_status,0};
static const SprObj wummel_obj_right = {wummel_graphics_right,wummel_status,0};
static const SprObj wummel_obj_up = {wummel_graphics_up,wummel_status,0};
static const SprObj wummel_obj_down = {wummel_graphics_down,wummel_status,0};

/**
 * @brief reset wummel position to home
 */
void wummel_reset(void)
{
  wummel_status.x=WUMMEL_RESET_X;
  wummel_status.y=WUMMEL_RESET_Y;
}

/**
 * @brief update wummel position/velocity
 */
void wummel(void)
{
  wummel_status.x=220;
  wummel_status.y=175;
  activate(wummel_obj_left,false);
  put_obj(wummel_obj_left,0);
}

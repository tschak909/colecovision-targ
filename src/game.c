/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Main game
 */

#include <os7.h>
#include "patterns.h"
#include "colors.h"
#include "nametables.h"
#include "lives.h"
#include "scores.h"
#include "player_headers.h"
#include "targ.h"
#include "wummel.h"

#define BOARD_POS 96

void game(void)
{
  mode_1();
  fill_vram(MODE1_PATTERN_NAME_TABLE,BOARD_POS,' ');
  load_ascii();
  set_colors();
  patterns_box(0);
  pattern_lives('@');
  player_headers();
  lives();
  scores();
  nametable_board(BOARD_POS);
  targ_reset();
  wummel_reset();
  blank(true);

  while(1)
    {
      SignalNum wait = request_signal(1,false);
      targ();
      wummel();
      while (!test_signal(wait));
    }
}

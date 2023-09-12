/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Show Get Ready, wait.
 */

#include <os7.h>
#include "colors.h"
#include "get_ready.h"

#define MSG_SIZE          9 // # of characters in each message
#define GET_READY_POS 0x12C // Screen pos of get ready relative to top of screen
#define PLAYER_POS    0x16C // screen pos of player # relative to top of screen
#define WAIT_TIME       128 // Wait time in 1/60th second (frames)

void get_ready(Player player_no)
{
  const char *get_ready="GET READY";
  const char *player_1 ="PLAYER  1";
  const char *player_2 ="PLAYER  2";
  SignalNum ready_wait;
  
  // Clear the VRAM
  fill_vram(0x0000,0x4000,0x00);

  // Set up for Graphics 1
  mode_1();

  // Load the ASCII Character set into the patterns
  load_ascii();

  // Set colors
  set_colors();

  // Place GET READY onto screen via nametable
  put_vram(PATTERN_NAME_TABLE,GET_READY_POS,get_ready,9);

  // Place player1/2 on screen
  put_vram(PATTERN_NAME_TABLE,PLAYER_POS,player_no ? player_2 : player_1,MSG_SIZE);

  // Turn on the display
  write_register(0x01,0xE0);

  // Set border/backdrop to dark blue
  write_register(0x07,4);

  // Request a pause timer, no repeat.
  ready_wait = request_signal(WAIT_TIME,false);

  // Sit here and spin waiting for timer to run out
  while (!test_signal(ready_wait));
}

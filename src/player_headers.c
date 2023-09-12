/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Player headers display
 */

#include <os7.h>

#define PL1_POS 2
#define PL2_POS 25

void player_headers(void)
{
  const char pl_1[5]={'P','L',' ','#','1'};
  const char pl_2[5]={'P','L',' ','#','2'};

  put_vram(PATTERN_NAME_TABLE,PL1_POS,pl_1,sizeof(pl_1));
  put_vram(PATTERN_NAME_TABLE,PL2_POS,pl_2,sizeof(pl_2));
}

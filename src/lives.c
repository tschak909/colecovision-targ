/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Lives display
 */

#include <os7.h>

#define LIVES1_POS 66
#define LIVES2_POS 89

static unsigned char lives_1[5]={'@','@','@','@','@'}; // @ = 0x40 = white car facing up
static unsigned char lives_2[5]={'@','@','@','@','@'}; // @ = 0x40 = white car facing up

void lives(void)
{
  put_vram(PATTERN_NAME_TABLE,LIVES1_POS,lives_1,sizeof(lives_1));
  put_vram(PATTERN_NAME_TABLE,LIVES2_POS,lives_2,sizeof(lives_2));
}

void lives_set(unsigned char *p, unsigned char n)
{
  for (unsigned char i=0;i<5;i++) // Clear the lives counter
    if (i<n)
      p[i]='@';
    else
      p[i]=' ';
}

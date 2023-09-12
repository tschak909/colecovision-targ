/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Score routines
 */

#include <os7.h>
#include <stdbool.h>
#include "scores.h"

/**
 * @brief nametable positions for score display
 */
#define SCORE1_POS 34
#define SCORE2_POS 57

/**
 * @brief We store the current score for each player here, digit by digit, in ascii form
 * @verbose so we can easily move it into the VDP nametable and display it.
 */
static unsigned char score_1[5]={'0','0','0','0','0'};
static unsigned char score_2[5]={'0','0','0','0','0'};

void scores(void)
{
  put_vram(PATTERN_NAME_TABLE,SCORE1_POS,score_1,sizeof(score_1));
  put_vram(PATTERN_NAME_TABLE,SCORE2_POS,score_2,sizeof(score_2));
}

void clear_scores(void)
{
  // This uses a multiple equals (transitive) assignment, to make more compact; faster code.
  for (unsigned char i=0;i<5;i++)
    score_1[i]=score_2[i]=0;
}

void add_points(char *s,const char *t)
{
  unsigned char i=4; // Start at end
  bool carry=false;
  
  while (i) // Loop from right (4) to left (0)
    {
      if (t[i] == ' ') // space, move forward, and ignore.
	{
	  i--;
	  continue;
	}

      s[i] += t[i] + carry; // add the source and new digits together + any carry
      
      if (s[i] > '9')          // did we roll over?
	{
	  carry=true;         // Yes, set carry for next digit to true.
	  s[i] = s[i] - '0';  // and subtract the remainder back into displayable ASCII
	}
      else
	carry=false;         // We did not roll over, so clear the carry.
    }
}

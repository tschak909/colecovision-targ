
/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Bonus Screen
 */

#include <os7.h>
#include <ctype.h> // for toascii()
#include "colors.h"
#include "bonus.h"
#include "patterns.h"

static const char *_extra_digit[10]=
  {
    // 0
    {
      "  // "
      " /  /"
      " /  /"
      " /  /"
      " /  /"
      "  // "
    },
    
    // 1
    {
      " //  "
      "  /  "
      "  /  "
      "  /  "
      "  /  "
      " /// "
    },

    // 2
    {
      " /// "
      " / / "
      "   / "
      " /// "
      " /   "
      " /// "
    },
    
    // 3
    {
      " /// "
      "   / "
      "  // "
      "   / "
      "   / "
      " /// "
    },
    
    // 4
    {
      "   / "
      " / / "
      " / / "
      " ////"
      "   / "
      "  ///"
    },

    // 5
    {
      " /// "
      " /   "
      " /// "
      "    /"
      "    /"
      " ////"
    },

    // 6
    {
      " /// "
      " /   "
      " /   "
      " ////"
      " /  /"
      " ////"
    },

    // 7
    {
      " ////"
      "    /"
      "   //"
      "  // "
      "  /  "
      "  /  "
    },

    // 8
    {
      "  ///"
      "  / /"
      " ////"
      " /  /"
      " /  /"
      " ////"
    },

    // 9
    {
      " ////"
      " /  /"
      " ////"
      "    /"
      "    /"
      "  ///"
    }    
  };

#define BONUS_FRAME_COUNT 180

#define EXTRA_POS_X 5
#define EXTRA_POS_Y 2
#define EXTRA_NUM_DIGITS 4
#define EXTRA_DIGIT_WIDTH 5
#define EXTRA_DIGIT_HEIGHT 6

#define EXTRA_POINTS_POS 362
#define BONUS_POS 525

#define POINTS_POS 650
#define POINTS_DIGIT_POS POINTS_POS + 2

#define SCREEN_WIDTH 32

static const char *_extra_points = "EXTRA POINTS";
static const char *_bonus = "BONUS";
static const char *_points[12]= "<  0 POINTS";

/**
 * @brief Show BONUS/EXTRA POINTS screen, with requested point values
 * @param extra_digit, large digit to show (0-9)
 * @param bonus_digit, bonus digit to show (0-9)
 */
void bonus(unsigned char extra_digit, unsigned char bonus_digit)
{
  SignalNum wait;
  unsigned char block_pattern[8] =
    {
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111
    };
  
  // clear vram
  fill_vram(0x0000,0x4000,0x00);

  // set up for graphics 1
  mode_1();

  // Load ASCII table into VRAM
  load_ascii();

  // Replace / with block char
  put_vram(PATTERN_GENERATOR_TABLE,'/',block_pattern,1);

  // Replace < with up-facing Targ rider
  put_vram(PATTERN_GENERATOR_TABLE,'<',_targ_up_patterns,1);
  
  // Set color palette
  set_colors();

  // Plot the extra digits i = digit, j = digit row
  for (int i=0;i<EXTRA_NUM_DIGITS;i++)
    {
      unsigned char *p = i==0 ? _extra_digit[extra_digit] : _extra_digit[0];
      
      for (int j=0;j<EXTRA_DIGIT_HEIGHT;j++)
	{
	  int pos = ((j+EXTRA_POS_Y)*SCREEN_WIDTH) + (i*EXTRA_DIGIT_WIDTH) + EXTRA_POS_X;
	  
	  put_vram(PATTERN_NAME_TABLE,pos,p,6);
	  p += EXTRA_DIGIT_WIDTH;
	}
    }

  // plot EXTRA POINTS
  put_vram(PATTERN_NAME_TABLE,EXTRA_POINTS_POS,_extra_points,12);

  // plot bonus
  put_vram(PATTERN_NAME_TABLE,BONUS_POS,_bonus,5);
  
  // plot bonus points
  put_vram(PATTERN_NAME_TABLE,POINTS_POS,_points,12);

  // plot bonus digit
  bonus_digit += '0'; // convert to ascii character
  put_vram(PATTERN_NAME_TABLE,POINTS_DIGIT_POS,&bonus_digit,1);
  
  // Turn on display
  write_register(0x01,0xE0);
  write_register(0x07,0x04);

  // RED
  wait = request_signal(30,false);
  
  while (!test_signal(wait))
    {
      unsigned char color = 0x64;

      put_vram(PATTERN_COLOR_TABLE,0x05,&color,1);
    }

  // RED/YELLOW FLASHING
  for (unsigned i=0;i<8;i++)
    {
      unsigned char color = i % 2 ? 0x64 : 0xB4;

      put_vram(PATTERN_COLOR_TABLE,0x05,&color,1);
      wait = request_signal(4,false);

      while (!test_signal(wait));
    }

  // Yellow static
  wait = request_signal(120,false);

  while (!test_signal(wait))
    {
      unsigned char color = 0xB4;
      
      for (unsigned char i=0;i<8;i++)
	block_pattern[i]=rand();

      put_vram(PATTERN_GENERATOR_TABLE,'/',block_pattern,1);
      put_vram(PATTERN_COLOR_TABLE,0x05,&color,1);
    }
  
  /* bonus_wait = request_signal(BONUS_FRAME_COUNT,false); */

  /* // Static the extra point tile */
  /* while (!test_signal(bonus_wait)) */
  /*   { */
  /*     unsigned char color = rand(); */
  /*     SignalNum frame_wait = request_signal(1,false); */
      
  /*     for (unsigned char i=0;i<8;i++) */
  /* 	block_pattern[i] = rand(); */
      
  /*     put_vram(PATTERN_GENERATOR_TABLE,'/',block_pattern,1); */
  /*     put_vram(PATTERN_COLOR_TABLE,0x05,&color,1); */
  /*     while (!test_signal(frame_wait)); */
  /*   } */
}

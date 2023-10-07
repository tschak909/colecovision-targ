/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Patterns for Pattern Generator
 */

#include <os7.h>

static const unsigned char _lives_pattern[]=
  {
    0b00111100,
    0b10100101,
    0b11111111,
    0b10111101,
    0b00111100,
    0b10111101,
    0b11111111,
    0b10111101
  };

void pattern_lives(unsigned char n)
{
  put_vram(PATTERN_GENERATOR_TABLE,n,_lives_pattern,1);
}

static const unsigned char _box_patterns[]=
  {
    // top 0x00
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11111111,

    // bottom 0x01
    0b11111111,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,

    // right 0x02
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,

    // left 0x03
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,

    // bldg top-left 0x04
    0b00000000,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01111111,
    
    // bldg top-right 0x05
    0b00000000,
    0b11111110,
    0b11111110,
    0b11111110,
    0b11111110,
    0b11111110,
    0b11111110,
    0b11111110,

    // bldg bottom-left 0x06
    0b01111111,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01111111,
    0b00000000,
    
    // bldg bottom-right 0x07
    0b11111110,
    0b11111110,
    0b11111110,
    0b11111110,
    0b11111110,
    0b11111110,
    0b11111110,
    0b00000000,    
  };

void patterns_box(unsigned char n)
{
  put_vram(PATTERN_GENERATOR_TABLE,n,_box_patterns,8);
}

const unsigned char targ_generators[32] =
  {
    0b00011000,
    0b00011000,
    0b00111100,
    0b00111100,
    0b01111110,
    0b01111110,
    0b11100111,
    0b11000011,

    0b11000000,
    0b11110000,
    0b01111100,
    0b00111111,
    0b00111111,
    0b01111100,
    0b11110000,
    0b11000000,

    0b11000011,
    0b11100111,
    0b01111110,
    0b01111110,
    0b00111100,
    0b00111100,
    0b00011000,
    0b00011000,

    0b00000011,
    0b00001111,
    0b00111110,
    0b11111100,
    0b11111100,
    0b00111110,
    0b00001111,
    0b00000011
  };

const unsigned char wummel_left_pattern[8] =
  {
    0b01110111,
    0b00100010,
    0b11111111,
    0b10111111,
    0b10111111,
    0b11111111,
    0b00100010,
    0b01110111,
  };

const unsigned char wummel_right_pattern[8] =
  {
    0b11101110,
    0b01000100,
    0b11111111,
    0b11111101,
    0b11111101,
    0b11111111,
    0b01000100,
    0b11101110
  };

const unsigned char wummel_up_pattern[8] =
  {
    0b00111100,
    0b10100101,
    0b11111111,
    0b10111101,
    0b00111100,
    0b10111101,
    0b11111111,
    0b10111101
  };

const unsigned char wummel_down_pattern[8] =
  {
    0b10111101,
    0b11111111,
    0b10111101,
    0b00111100,
    0b10111101,
    0b11111111,
    0b10100101,
    0b00111100
  };

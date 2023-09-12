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


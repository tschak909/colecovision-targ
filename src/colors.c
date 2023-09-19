/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Colors and color setting code
 */

#include <os7.h>

/**
 * @brief mode 1 color palette
 * @verbose defined as static const so it stays in ROM, and is only referenced in this file.
 */
static const unsigned char colors[32]=
  {
    0xB4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0x64, // 5 for bonus
    0x64,
    0x64,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4,
    0xF4
  };

void set_colors(void)
{
  put_vram(PATTERN_COLOR_TABLE,0,colors,sizeof(colors));
  write_register(0x07,0x04);
}

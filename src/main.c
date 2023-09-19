/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Main entrypoint
 */

#include <stdbool.h>
#include <os7.h>
#include "init.h"
#include "game.h"
#include "bonus.h"

void main(void)
{
  init();
  while(1)
    bonus(3,3);
}

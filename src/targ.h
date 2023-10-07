/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Targ rider object code/data
 */

#ifndef TARG_H
#define TARG_H

/**
 * @brief Reset targs to their initial positions, and copy targ data into VRAM
 */
void targ_reset(void);

/**
 * @brief update targ positions
 */
void targ(void);

#endif /* TARG_H */

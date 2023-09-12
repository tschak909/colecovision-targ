/**
 * @brief Targ example using os7lib
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE for details
 * @verbose Score routines
 */

#ifndef SCORES_H
#define SCORES_H

#include <stdbool.h>

/**
 * @brief update display with current scores.
 */
void scores(void);

/**
 * @brief clear both player scores
 */
void clear_scores(void);

/**
 * @brief Add points to a score, e.g.
 * @example add_points(score_1,"  100");
 */
void add_points(char *s,const char *t);

#endif /* SCORES_H */

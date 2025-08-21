#ifndef OVERLAP_H
# define OVERLAP_H

# include <math.h>

# include "t_frame.h"

# include "overlap.h"
# include "utils.h"
# include "mlx.h"

void	check_walls(t_frame *frame, int move_count);
void	check_collectibles(t_frame *frame);
void	check_exit(t_frame *frame);

#endif

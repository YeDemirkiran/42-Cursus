#ifndef EVENTS_H
# define EVENTS_H

# include "macro.h"
# include "e_keys.h"
# include "t_frame.h"

# include "mlx.h"
# include "ft_write.h"

// events.c
int	on_key_down(int keycode, t_frame *frame);
int	on_key_up(int keycode, t_frame *frame);

// events_extra.c
int	on_destroy_notify(void *mlx_addr);

#endif

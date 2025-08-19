#include "so_long.h"

void	init_player(t_frame *frame)
{
	frame->player.current_collect = 0;
	frame->player.target_collect = 0;
	frame->player.move_count = 0;
	frame->player.object.sprite = &(frame->sprites[S_PLAYER]);
	frame->player.object.position.x = frame->map->start_pos.x;
	frame->player.object.position.y = frame->map->start_pos.y;
	frame->player.object.velocity.x = 0;
	frame->player.object.velocity.y = 0;
}

void	init_exit(t_frame *frame)
{
	frame->exit.sprite = &(frame->sprites[S_EXIT]);
	frame->exit.position.x = frame->map->exit_pos.x;
	frame->exit.position.y = frame->map->exit_pos.y;
	frame->exit.velocity.x = 0;
	frame->exit.velocity.y = 0;
}

void	init_hooks(t_frame *frame)
{
	mlx_hook(frame->mlx_window, KeyPress, KeyPressMask, on_key_down, frame);
	mlx_hook(frame->mlx_window, KeyRelease, KeyReleaseMask, on_key_up, frame);
	mlx_hook(frame->mlx_window, DestroyNotify,
			0, on_destroy_notify, frame->mlx_addr);
	mlx_loop_hook(frame->mlx_addr, update_frame, frame);
}

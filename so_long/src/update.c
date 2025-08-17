#include "so_long.h"

void	update_player(t_player *player, t_frame *frame)
{
	t_vec_2	overlap;

	player->object.position.x += player->object.velocity.x;
	player->object.position.y += player->object.velocity.y;
	overlap = player_overlapping_wall(frame);
	if (overlap.x && overlap.y)
	{
		if (fabs(overlap.x) < fabs(overlap.y))
			player->object.position.x += overlap.x;
		else
			player->object.position.y += overlap.y;
	}
}

void	update_camera_offset(t_frame *frame)
{
	if (frame->player.object.position.x + frame->camera_offset.x >= RES_X)
		frame->camera_offset.x = frame->player.object.position.x * -1;
	else if ((frame->player.object.position.x + frame->player.object.sprite->size.x) + frame->camera_offset.x <= 0)
		frame->camera_offset.x = RES_X - (frame->player.object.position.x + frame->player.object.sprite->size.x);
	frame->camera_offset.y = 0;
}

int	update_frame(t_frame *frame)
{
	update_player(&(frame->player), frame);
	update_camera_offset(frame);
	render_frame(frame);
	return (0);
}

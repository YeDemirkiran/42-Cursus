#include "so_long.h"
#include "ft_write.h"

void	check_collectibles(t_frame *frame)
{
	int		i;
	t_vec_2	overlap;

	i = 0;
	while (frame->collectibles[i].sprite)
	{
		overlap = are_objects_overlapping(frame->player.object, frame->collectibles[i]);
		if (overlap.x && overlap.y)
		{
			frame->player.current_collect++;
			destroy_object(frame->collectibles, i);
		}
		i++;
	}
}
#include "stdio.h"
void	check_exit(t_frame *frame)
{
	t_vec_2	overlap;
	if (frame->player.current_collect != frame->map->target_collect)
		return ;
	overlap = are_objects_overlapping(frame->player.object, frame->exit);
	if (overlap.x && overlap.y)
		mlx_loop_end(frame->mlx_addr);
}

void	update_player(t_player *player, t_frame *frame)
{
	static int	count;
	t_vec_2		overlap;

	player->object.position.x += player->object.velocity.x;
	player->object.position.y += player->object.velocity.y;
	overlap = player_overlapping_wall(frame);
	if (overlap.x && overlap.y)
	{
		if (fabs(overlap.x) < fabs(overlap.y))
			player->object.position.x += overlap.x;
		else
			player->object.position.y += overlap.y;
		if (player->move_count != count)
			player->move_count = count;
	}
	check_collectibles(frame);
	check_exit(frame);
	if (player->move_count != count)
	{
		count = player->move_count;
		ft_putstr("PLAYER MOVE COUNT: ");
		ft_putnbr(player->move_count);
		ft_putstr("\n");
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

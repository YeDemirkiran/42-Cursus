#include "so_long.h"

void	add_sprite(char *path, t_sprite *sprites_buffer, void *mlx_addr)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (sprites_buffer[i].id >= 0)
		i++;
	sprites_buffer[i].id = i;
	x = 0;
	y = 0;
	sprites_buffer[i].image.img_addr = mlx_xpm_file_to_image(mlx_addr,
			path, &x, &y);
	sprites_buffer[i].size.x = (float)x;
	sprites_buffer[i].size.y = (float)y;
}

void	add_object(t_object *objects_buffer, t_sprite *sprite, t_vec_2 pos)
{
	int	i;

	i = 0;
	while (objects_buffer[i].sprite)
		i++;
	objects_buffer[i].sprite = sprite;
	objects_buffer[i].position.x = pos.x;
	objects_buffer[i].position.y = pos.y;
	objects_buffer[i].velocity.x = 0;
	objects_buffer[i].velocity.y = 0;
}

void	add_wall(t_frame *frame, t_vec_2 pos)
{
	add_object(frame->walls, &(frame->sprites[S_WALL]), pos);
}

void	add_collectible(t_frame *frame, t_vec_2 pos)
{
	add_object(frame->collectibles, &(frame->sprites[S_COLL]), pos);
}

t_map	init_map(void)
{
	t_map	map;

	map.map_valid = 0;
	map.map_width = 0;
	map.map_height = 0;
	map.target_collect = 0;
	map.start_pos.x = -999;
	map.start_pos.y = -999;
	map.exit_pos.x = -999;
	map.exit_pos.y = -999;
	return (map);
}

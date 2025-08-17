#include "so_long.h"

t_vec_2	are_objects_overlapping(t_object obj_1, t_object obj_2)
{
	t_vec_2	overlap;

	overlap.x = 0;
	if (obj_2.position.x >= obj_1.position.x && obj_2.position.x <= obj_1.position.x + obj_1.sprite->size.x)
		overlap.x = obj_2.position.x - (obj_1.position.x + obj_1.sprite->size.x);
	else if (obj_1.position.x >= obj_2.position.x && obj_1.position.x <= obj_2.position.x + obj_2.sprite->size.x)
		overlap.x = (obj_2.position.x + obj_2.sprite->size.x) - obj_1.position.x;
	overlap.y = 0;
	if (obj_2.position.y >= obj_1.position.y && obj_2.position.y <= obj_1.position.y + obj_1.sprite->size.y)
		overlap.y = obj_2.position.y - (obj_1.position.y + obj_1.sprite->size.y);
	else if (obj_1.position.y >= obj_2.position.y && obj_1.position.y <= obj_2.position.y + obj_2.sprite->size.y)
		overlap.y = (obj_2.position.y + obj_2.sprite->size.y) - obj_1.position.y;
	return (overlap);
}

t_vec_2	player_overlapping_wall(t_frame *frame)
{
	int		i;
	t_vec_2	overlap;
	t_vec_2	total;

	i = 0;
	total.x = 0;
	total.y = 0;
	while (frame->walls[i].sprite)
	{
		overlap = are_objects_overlapping(frame->player.object, frame->walls[i]);
		if (overlap.x && overlap.y)
			return (overlap);
		i++;
	}
	return (total);
}

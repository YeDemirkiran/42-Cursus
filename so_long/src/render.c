#include "so_long.h"

void	render_sprite(t_frame *frame, t_sprite *sprite,
			t_vec_2 pos, t_vec_2 *offset)
{
	t_vec_2	new_pos;

	new_pos.x = (int)(pos.x);
	new_pos.y = (int)(pos.y);
	if (offset)
	{
		new_pos.x += (int)(offset->x);
		new_pos.y += (int)(offset->y);
	}
	mlx_put_image_to_window(frame->mlx_addr, frame->mlx_window,
		sprite->image.img_addr, new_pos.x, new_pos.y);
}

void	render_background(t_frame *frame)
{
	t_vec_2	pos;
	t_vec_2	pos_2;
	t_vec_2	offset;

	pos.x = (int)(frame->background.sprite->size.x) / -4;
	pos.y = (int)(frame->background.sprite->size.y) / -4;
	pos_2.x = pos.x + frame->background.sprite->size.x;
	pos_2.y = pos.y;
	offset.x = frame->camera_offset.x * 0.1f;
	offset.y = frame->camera_offset.y * 0.1f;
	render_sprite(frame, frame->background.sprite, pos, &offset);
	render_sprite(frame, frame->background.sprite, pos_2, &offset);
}

void	render_object(t_frame *frame, t_object object, t_vec_2 *offset)
{
	render_sprite(frame, object.sprite, object.position, offset);
}

void	render_objects(t_object *objects, t_frame *frame)
{
	int	i;

	i = 0;
	while (objects[i].sprite)
	{
		render_object(frame, objects[i], &(frame->camera_offset));
		i++;
	}
}

void	render_frame(t_frame *frame)
{
	render_background(frame);
	render_object(frame, frame->exit, &(frame->camera_offset));
	render_object(frame, frame->player.object, &(frame->camera_offset));
	render_objects(frame->walls, frame);
	render_objects(frame->collectibles, frame);
}

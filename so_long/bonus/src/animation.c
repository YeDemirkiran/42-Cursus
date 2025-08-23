#include "animation.h"

static void	init_anim_sprites(t_animation *animation)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		animation->sprites[i] = NULL;
		i++;
	}
}

static void	init_animation(t_animation *animation, float frequency)
{
	animation->timer = 0;
	animation->current_index = 0;
	animation->sprite_length = 0;
	animation->frequency = frequency;
	init_anim_sprites(animation);
}

static void	add_sprite_to_anim(t_animation *animation, t_sprite *sprite)
{
	int	i;

	i = 0;
	while (animation->sprites[i])
		i++;
	animation->sprites[i] = sprite;
	animation->sprite_length++;
}

void	add_animation(t_frame *frame, float frequency, int sprite_indices[])
{
	int	i;
	int	j;

	i = 0;
	while (frame->animations[i].current_index >= 0)
		i++;
	init_animation(frame->animations + i, frequency);
	j = 0;
	while (sprite_indices[j] != -1)
	{
		add_sprite_to_anim(frame->animations + i,
			frame->sprites + sprite_indices[j]);
		j++;
	}
}

void	animation_loop(t_animation *animation)
{
	float	dt;

	dt = get_delta_time();
	animation->timer += dt;
	if (animation->timer > animation->frequency)
	{
		animation->timer = 0;
		animation->current_index++;
		if (animation->current_index >= animation->sprite_length)
			animation->current_index = 0;
	}
}

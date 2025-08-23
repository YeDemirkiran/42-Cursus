#include "animation.h"

static void	init_anim_sprites(t_animation *animation)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		animation->sprites[i] = NULL;
		i++;
	}
}
#include "stdio.h"
// static void	init_animation(t_animation *animation, float frequency)
// {
// 	animation->timer = -1;
// 	animation->current_index = 0;
// 	animation->sprite_length = 0;
// 	animation->frequency = frequency;
// 	init_anim_sprites(animation);
// }

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
	frame->animations[i].timer = 0;
	frame->animations[i].current_index = 0;
	frame->animations[i].sprite_length = 0;
	frame->animations[i].frequency = frequency;
	init_anim_sprites(&(frame->animations[i]));
	j = 0;
	while (sprite_indices[j] >= 0)
	{
		add_sprite_to_anim(frame->animations + i,
			frame->sprites + sprite_indices[j]);
		j++;
	}
}
#include "stdio.h"
void	animation_loop(t_animation *animation)
{
	float	dt;

	dt = get_delta_time();
	printf("DT: %f\n", dt);
	animation->timer += dt;
	printf("FREQUENCY: %f, TIMER: %f\n", animation->frequency, animation->timer);
	printf("SL: %i\n", animation->sprite_length);
	if (animation->timer >= (1 / animation->frequency))
	{
		animation->timer = 0;
		(animation->current_index)++;
		if (animation->current_index >= animation->sprite_length)
			animation->current_index = 0;
	}
}

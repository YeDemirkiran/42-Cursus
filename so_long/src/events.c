#include "so_long.h"
#include "stdio.h"

int	on_key_press(int keycode, t_frame *frame)
{
	unsigned char	key;

	key = keycode;
	on_esc_press(key, frame->mlx_addr);
	on_move(key, &(frame->player));
	return (0);
}

int	on_key_up(int keycode, t_frame *frame)
{
	unsigned char	key;

	key = keycode;
	on_stop_move(key, &(frame->player));
	return (0);
}

void	on_esc_press(unsigned char key, void *mlx_addr)
{
	if (key == K_ESC)
		mlx_loop_end(mlx_addr);
}

void	on_move(unsigned int key, t_player *player)
{
	int	input_x;
	int	input_y;

	input_x = ((key == K_D) || (key == K_RIGHT)) - ((key == K_A) || (key == K_LEFT));
	input_y = ((key == K_S) || (key == K_DOWN)) - ((key == K_W) || (key == K_UP));
	player->object.velocity.x = input_x * 1;
	player->object.velocity.y = input_y * 1;
	if (input_x || input_y)
	{
		player->move_count += input_x || input_y;
		printf("PLAYER MOVE COUNT: %i\n", player->move_count);
	}
}

void	on_stop_move(unsigned int key, t_player *player)
{
	if ((key == K_D) || (key == K_RIGHT) || (key == K_A) || (key == K_LEFT))
	{
		player->object.velocity.x = 0;
		//printf("Vel X is now 0\n");
	}
	if ((key == K_S) || (key == K_DOWN) || (key == K_W) || (key == K_UP))
	{
		player->object.velocity.y = 0;
		//printf("Vel Y is now 0\n");
	}
}

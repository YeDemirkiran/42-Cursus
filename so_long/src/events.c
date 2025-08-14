#include "so_long.h"
#include "stdio.h"

int	on_key_press(int keycode, t_frame *frame)
{
	unsigned char	key;

	key = keycode;
	//printf("Keycode: %i\n", key);
	on_esc_press(key, frame->mlx_addr);
	on_move(key, &(frame->player));
	return (0);
}

int	on_key_up(int keycode, t_frame *frame)
{
	unsigned char	key;

	key = keycode;
	//printf("Keycode: %i\n", key);
	on_move(key, &(frame->player));
	return (0);
}

void	on_esc_press(unsigned char key, void *mlx_addr)
{
	if (key == K_ESC)
		mlx_loop_end(mlx_addr);
}

// int	on_cross_press(int button_code)
// {
// //	printf("Button Code: %i\n", (unsigned char)button_code);
// 	return (0);
// }

void	on_move(unsigned int key, t_player *player)
{
	int	input_x;
	int	input_y;

	input_x = ((key == K_D) || (key == K_RIGHT)) - ((key == K_A) || (key == K_LEFT));
	input_y = ((key == K_S) || (key == K_DOWN)) - ((key == K_W) || (key == K_UP));
	//printf("OLD POS: x %i, y %i\n", current_pos->x, current_pos->y);
	player->object.velocity.x = input_x * 1;
	player->object.velocity.y = input_y * 1;
	//printf("NEW POS: x %i, y %i\n", player->object.position.x, player->object.position.y);
}

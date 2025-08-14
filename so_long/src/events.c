#include "so_long.h"
#include "stdio.h"

int	on_key_press(int keycode, t_vec_2 *current_pos)
{
	unsigned char	key;

	key = keycode;
	printf("Keycode: %i\n", key);
	on_esc_press(key);
	on_move(key, current_pos);
	return (0);
}

void	on_esc_press(unsigned char key)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
}

int	on_cross_press(int button_code)
{
	printf("Button Code: %i\n", (unsigned char)button_code);
	return (0);
}

void	on_move(unsigned int key, t_vec_2 *current_pos)
{
	printf("OLD POS: x %i, y %i\n", current_pos->x, current_pos->y);
	if (key == K_W)
		current_pos->y -= 10;
	if (key == K_S)
		current_pos->y += 10;
	if (key == K_A)
		current_pos->x -= 10;
	if (key == K_D)
		current_pos->x += 10;
	printf("NEW POS: x %i, y %i\n", current_pos->x, current_pos->y);
}

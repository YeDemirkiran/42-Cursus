#include "so_long.h"
#include "stdio.h"

int	on_esc_press(int keycode)
{
	unsigned char	key;

	key = keycode;
	printf("Keycode: %i\n", key);
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int	on_cross_press(int button_code)
{
	printf("Button Code: %i\n", (unsigned char)button_code);
	return (0);
}

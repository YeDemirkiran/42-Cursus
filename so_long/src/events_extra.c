#include "so_long.h"

int	on_destroy_notify(void *mlx_addr)
{
	mlx_loop_end(mlx_addr);
	return (0);
}

#include "delta_time.h"

float	get_delta_time(void)
{
	static float	time;
	float			current_time;
	float			delta_time;
	struct timespec	tp;

	delta_time = 0;
	clock_gettime(CLOCK_MONOTONIC, &tp);
	current_time = (float)(tp.tv_sec + (tp.tv_nsec / 1e9));
	if (current_time > time)
	{
		delta_time = current_time - time;
		time = current_time;
	}
	return (delta_time);
}

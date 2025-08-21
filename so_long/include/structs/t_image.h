#ifndef T_IMAGE_H
# define T_IMAGE_H

typedef struct s_image
{
	void	*img_addr;
	char	*mod_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

#endif

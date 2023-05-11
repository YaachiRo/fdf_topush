#include "fdf.h"

float	angle(float angle)
{
	if (angle > M_PI)
		angle = -1 * M_PI;
	else if (angle < -1 * M_PI)
		angle = -1 * M_PI;
	return (angle);
}

void	error(char *str, int x)
{
	int	i;

	i = write(2, str, ft_strlen(str));
	(void)i;
	exit(x);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;
	if ((y >= 0 && y < HEIGHT) && (x >= 0 && x < WIDTH))
	{
		dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void creat_image(t_fdf *fdf)
{
	if (fdf->image.image)
		mlx_destroy_image(fdf->mlx, fdf->image.image);
	fdf->image.image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->image.addr = mlx_get_data_addr(fdf->image.image, &fdf->image.bits_per_pixel, &fdf->image.line_length, &fdf->image.endian);
}

void put_and_draw(t_fdf *fdf)
{
	draw_menu_bg(fdf, fdf->flag);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image.image, 0, 0);
	menu(fdf, fdf->flag);
}

#include "fdf.h"

void	menu(t_fdf *fdf, int flag)
{
	int		x;
	void	*mlx;
	void	*win;

	if(flag == 0)
		return ;
	x = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 20, x += 60, 0x11e3cd, "CONTROL BUTTONS");
	mlx_string_put(mlx, win, 10, x += 30, 0xffd700, "ZOOM CONTROL");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "O To Zoom Out");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "I To Zoom In");
	mlx_string_put(mlx, win, 10, x += 30, 0xffd700, "Move :");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "Direction buttons");
	mlx_string_put(mlx, win, 10, x += 30, 0xffd700, "Rotatation:");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "X : A - D");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "Y : W - S");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "Z : Z - X");
	mlx_string_put(mlx, win, 10, x += 30, 0xffd700, "Projection");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "conic : NUM 0");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "parallel : NUM 1");
	mlx_string_put(mlx, win, 10, x += 30, 0xffd700, "CONTROL HEIGHT Z");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "M - N");
	mlx_string_put(mlx, win, 20, x += 45, 0x11e3cd, "HAVE FUN <3");
}

void draw_menu_bg(t_fdf *fdf, int flag)
{
	int i;
	int j;

	if (flag == 0)
		return;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH / 14)
		{
			my_mlx_pixel_put(&fdf->image, i, j, 0x151717);
			i++;
		}
		j++;
	}
}

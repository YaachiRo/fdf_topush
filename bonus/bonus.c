#include "../srcs/fdf.h"

void	supporter(int x, t_fdf *fdf)
{
	if (x == 65362)
		fdf->shifty -= 25;
	if (x == 65364)
		fdf->shifty += 25;
	if (x == 65363)
		fdf->shiftx += 25;
	if (x == 65361)
		fdf->shiftx -= 25;
	if (x == 119)
		fdf->angle += 0.1;
	if (x == 115)
		fdf->angle -= 0.1;
	if (x == 100)
		fdf->angle2 += 0.1;
	if (x == 97)
		fdf->angle2 -= 0.1;
	if (x == 122)
		fdf->angle3 += 0.05;
	if (x == 120)
		fdf->angle3 -= 0.05;
	if (x == 65307)
		exit(0);
}

void	supporter_two(int x, t_fdf *fdf)
{
	if (x == 98)
	{
		fdf->angle = angle(fdf->angle + 0.01);
		fdf->angle2 = angle(fdf->angle2 - 0.05);
		fdf->angle3 = angle(fdf->angle3 + 0.08);
	}
	if (x == 65438)
	{
		fdf->angle = 0;
		fdf->angle2 = 0;
		fdf->angle3 = 0;
	}
	if (x == 65436)
	{
		fdf->angle = 1.6;
		fdf->angle2 = -0.3;
		fdf->angle3 = 0.3;
	}
	if (x == 111)
		fdf->zoom -= 2;
	if (x == 105)
		fdf->zoom += 2;
}

int	key_hook(int x, t_fdf *fdf)
{
	supporter(x, fdf);
	supporter_two(x, fdf);
	if (x == 110)
	{
		fdf->sclr -= 0.1;
		if (!fdf->sclr)
			fdf->sclr -= 0.1;
	}
	if (x == 109)
	{
		fdf->sclr += 0.1;
		if (!fdf->sclr)
			fdf->sclr += 0.1;
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	return (0);
}

int	event(int keycode, t_fdf *fdf)
{
	(void)fdf;
	(void)keycode;
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (ac != 2)
		error("argumant are not valid\n", 1);
	read_fdf(av[1], fdf);
	fdf->image.image = NULL;
	fdf->zoom = 15;
	fdf->shiftx += (WIDTH / 3);
	fdf->shifty += (HEIGHT / 3);
	fdf->angle = 0.3;
    fdf->flag = 1;
	fdf->angle2 = 0.3;
	fdf->angle3 = 0.3;
	fdf->sclr = 1;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	draw_map(fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_hook(fdf->win, 17, 0l, event, fdf);
	mlx_loop(fdf->mlx);
}
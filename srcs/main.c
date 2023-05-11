/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:14:19 by idelfag           #+#    #+#             */
/*   Updated: 2023/04/18 00:50:11 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key(int x, t_fdf *fdf)
{
	(void)fdf;
	if (x == 65307)
		exit(0);
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
	fdf->zoom = 20;
	fdf->shiftx += (WIDTH / 3);
	fdf->shifty += (HEIGHT / 3);
	fdf->flag = 0;
	fdf->angle = 0.3;
	fdf->angle2 = 0.3;
	fdf->angle3 = 0.3;
	fdf->sclr = 1;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	draw_map(fdf);
	mlx_key_hook(fdf->win, key, fdf);
	mlx_hook(fdf->win, 17, 0l, event, fdf);
	mlx_loop(fdf->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:15:26 by idelfag           #+#    #+#             */
/*   Updated: 2023/04/18 00:38:26 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../gnl/get_next_line.h"
# include "../tools/tools.h"
# include <fcntl.h>
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include "../matrex/matrex.h"
# include <sys/types.h>
# include <sys/time.h>

# define THOUSAND 1000
# define ANGLERATE 0.01
# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_image
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fdf
{
	int		rows;
	int		**map;
	int		colums;
	int		fd;
	void	*win;
	void	*mlx;
	int		zoom;
	int		color;
	int		shiftx;
	int		shifty;
	float	angle;
	float	angle2;
	float	angle3;
	float	x;
	float	y;
	float	x_end;
	float	y_end;
	float	sclr;
	float	z;
	float	z_end;
	float	*array1;
	float	*array2;
	int		flag;
	t_image	image;

}	t_fdf;

typedef struct s_vars
{
	double	total_x;
	double	total_y;
	double	total_z;
	int		total_point;
	float	dx;
	float	dy;
	int		step;
}	t_vars;

typedef struct s_mat
{
	t_matrex	*y_rotation_mt;
	t_matrex	*x_rotation_mt;
	t_matrex	*z_rotation_mt;
	t_matrex	*rotated;
	t_matrex	*scaled;
	t_matrex	*scaller;
}	t_mat;


void		read_fdf(char *filename, t_fdf *fdf);
void		error(char *str, int x);
t_matrex	*creat_matrex(int r, int c);
t_matrex	*mt_multiplication(t_matrex *mt1, t_matrex *mt2);
void		projection(float *x, float *y, float *z, t_fdf fdf);
t_matrex	*rotation_mt(t_matrex *point, float x, float y, float z);
t_matrex	*projection_mt(t_matrex *point);
t_matrex	*avg(t_fdf *fdf);
t_matrex	*scaler(int zoom);
void		draw_map(t_fdf *fdf);
long		get_time(void);
int			animate(t_fdf *fdf);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
float		angle(float angle);
void		menu(t_fdf *fdf, int flag);
void	draw_menu_bg(t_fdf *fdf, int flag);
void	 put_and_draw(t_fdf *fdf);
void 	creat_image(t_fdf *fdf);

#endif

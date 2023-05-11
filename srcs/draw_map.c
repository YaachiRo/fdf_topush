#include "fdf.h"

int	which(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

float	gtfm(float *x, float *y, t_fdf *fdf)
{
	t_matrex	*center;
	float		z;
	float		old_z;

	center = avg(fdf);
	z = (fdf->map[(int)*y][(int)*x] * fdf->sclr);
	old_z = z;
	*x -= center->matrex[0][0];
	*y -= center->matrex[1][0];
	z -= center->matrex[2][0];
	projection(x, y, &z, *fdf);
	*x += center->matrex[0][0];
	*y += center->matrex[1][0];
	*x += fdf->shiftx;
	*y += fdf->shifty;
	free_mt(center);
	return (old_z);
}

int **end_lines(t_fdf *fdf)
{
	int i;
	int j;
	int k;
	int **end;

	end = malloc(sizeof(int *) * fdf->rows + 1);

	i = 0;
	k = 0;
	while(i < fdf->rows)
	{
		j = 0;
		while(j < fdf->colums)
		{
			end = malloc(sizeof(int) * fdf->colums + 1);
			end[i][k++] = i + 1;
			end[i][k++] = j + 1;
			j++;
		}
		i++;
	}
	return(end);
}

int **start_lines(t_fdf *fdf)
{
		int i;
	int j;
	int k;
	int **end;

	end = malloc(sizeof(int *) * fdf->rows + 1);

	i = 0;
	k = 0;
	while(i < fdf->rows)
	{
		j = 0;
		while(j < fdf->colums)
		{
			end = malloc(sizeof(int) * fdf->colums + 1);
			end[i][k++] = i;
			end[i][k++] = j;
			j++;
		}
		i++;
	}
	return(end);
}

void	dda(float *array, t_fdf *fdf)
{
	t_vars	vars;

	fdf->x = array[0];
	fdf->y = array[1];
	fdf->x_end = array[2];
	fdf->y_end = array[3];
	fdf->z = gtfm(&fdf->x, &fdf->y, fdf);
	fdf->z_end = gtfm(&fdf->x_end, &fdf->y_end, fdf);
	if (fdf->z || fdf->z_end)
		fdf->color = 0xffd700;
	else if (!fdf->z && !fdf->z_end)
		fdf->color = 0x863ca2;
	vars.dx = fdf->x_end - fdf->x;
	vars.dy = fdf->y_end - fdf->y;
	vars.step = which(fabs(vars.dx), fabs(vars.dy));
	vars.dx /= vars.step;
	vars.dy /= vars.step;
	while ((int)(fdf->x - fdf->x_end) || (int)(fdf->y - fdf->y_end))
	{
		my_mlx_pixel_put(&fdf->image, fdf->x, fdf->y, fdf->color);
		fdf->x += vars.dx;
		fdf->y += vars.dy;
	}
}

float	*array(float x, float y, float x_end, float y_end)
{
	float	*array;

	array = malloc(sizeof(float) * 4);
	array[0] = x;
	array[1] = y;
	array[2] = x_end;
	array[3] = y_end;
	return (array);
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;


	y = -1;
	creat_image(fdf);
	while (++y < fdf->rows)
	{
		x = -1;
		while (++x < fdf->colums)
		{
			if (x < fdf->colums - 1)
			{
				fdf->array1 = array(x, y,x + 1,y);
				dda(fdf->array1, fdf);
				free(fdf->array1);
			}
			if (y < fdf->rows - 1)
			{
				fdf->array2 = array(x, y, x, y + 1);
				dda(fdf->array2, fdf);
				free(fdf->array2);
			}
		}
	}
	put_and_draw(fdf);
}

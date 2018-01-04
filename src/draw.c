/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:30:47 by wnoth             #+#    #+#             */
/*   Updated: 2017/12/11 10:29:25 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Information sur la fractal
*/

void	draw_info(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 5, 10, 0xFFFFFF, "Fractol :");
	mlx_string_put(e->mlx, e->win, 100, 10, 0xFFFFFF, ft_itoa(e->fractale));
	mlx_string_put(e->mlx, e->win, 5, 25, 0xFFFFFF, "Ireration :");
	if (e->cam->maxit <= 2120332444.202914)
		mlx_string_put(e->mlx, e->win, 130, 25, 0xFFFFFF,
			ft_itoa(e->cam->maxit));
	else
		mlx_string_put(e->mlx, e->win, 130, 25, 0xFFFFFF, "> 2120334244");
	mlx_string_put(e->mlx, e->win, 5, 40, 0xFFFFFF, "Zoom :");
	if (e->cam->z * 10 <= 2120332444.202914)
		mlx_string_put(e->mlx, e->win, 80, 40, 0xFFFFFF,
			ft_itoa(e->cam->z * 10));
	else
		mlx_string_put(e->mlx, e->win, 80, 40, 0xFFFFFF, "> 2120332444");
	mlx_string_put(e->mlx, e->win, 5, 55, 0xFFFFFF, "Color :");
	mlx_string_put(e->mlx, e->win, 81, 55, 0xFFFFFF, ft_itoa(e->selectedcolor));
}

/*
** Dessin de la fractal selectionnee
*/

void	draw_fractal(t_env *e)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = get_selected_fractal(e, x, y);
			if (i < e->cam->maxit)
				draw_dot(e, x, y,
				hsv_to_rgb(((i + e->cam->color) % 256), 255, 255, e));
			else
				draw_dot(e, x, y, 0);
			x++;
		}
		y++;
	}
}

/*
** Dessing pixel actuel XY
*/

void	draw_dot(t_env *e, int x, int y, int color)
{
	char	b;
	char	g;
	char	r;
	int		i;

	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (e->size_line * y) + (x * (e->bpp / 8));
	e->imgpix[i] = b;
	e->imgpix[i + 1] = g;
	e->imgpix[i + 2] = r;
}

/*
** Draw de l'image generer par la fractal et infos utilisateur
*/

void	draw_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->imgpix = mlx_get_data_addr(
	e->img, &(e->bpp), &(e->size_line), &(e->endian));
	draw_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	draw_info(e);
	mlx_destroy_image(e->mlx, e->img);
}

/*
** help usage cmd
*/

void	help(void)
{
	ft_putendl("./fractol <fractal name> OR <fractal name> <color name>");
	ft_putendl("/-----NAME---------\\");
	ft_putendl("|  Mandelbrot      |");
	ft_putendl("|  Julia           |");
	ft_putendl("|  crackdisappear  |");
	ft_putendl("\\------------------/");
	ft_putchar('\n');
	ft_putendl("/-----COLOR-----\\");
	ft_putendl("| \e[40;38;5;27mdarkblue\x1b[0m      |");
	ft_putendl("| \e[40;38;5;38mhereticblue\x1b[0m   |");
	ft_putendl("| \e[40;38;5;107mhereticgreen\x1b[0m  |");
	ft_putendl("| \e[40;38;5;155mgreen\x1b[0m         |");
	ft_putendl("| \e[40;38;5;106mgreenmoche\x1b[0m    |");
	ft_putendl("| \e[40;38;5;208morange\x1b[0m        |");
	ft_putendl("\\---------------/");
	exit(EXIT_FAILURE);
}

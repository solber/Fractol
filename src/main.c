/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:30:47 by wnoth             #+#    #+#             */
/*   Updated: 2017/12/11 10:09:57 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(char **av)
{
	if (!av[2])
		return (6);
	if (!ft_strcmp(av[2], "darkblue"))
		return (1);
	else if (!ft_strcmp(av[2], "hereticblue"))
		return (6);
	else if (!ft_strcmp(av[2], "herecticbluegreen"))
		return (7);
	else if (!ft_strcmp(av[2], "green"))
		return (14);
	else if (!ft_strcmp(av[2], "greenmoche"))
		return (15);
	else if (!ft_strcmp(av[2], "orange"))
		return (16);
	help();
	return (EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	int c;

	if (ac != 2 && ac != 3)
		help();
	c = get_color(av);
	if (!ft_strcmp(av[1], "mandelbrot"))
	{
		setup(1, c);
		return (0);
	}
	if (!ft_strcmp(av[1], "julia"))
	{
		setup(2, c);
		return (0);
	}
	if (!ft_strcmp(av[1], "crackdisappear"))
	{
		setup(3, c);
		return (0);
	}
	if (!ft_strcmp(av[1], "commands"))
		keyhelp();
	else
		help();
	return (0);
}

int			get_selected_fractal(t_env *e, int x, int y)
{
	int	i;

	i = 0;
	if (e->fractale == 1)
		i = mandelbrot(e, x, y);
	else if (e->fractale == 2)
		i = julia(e, x, y);
	else if (e->fractale == 3)
		i = crackdisappear(e, x, y);
	return (i);
}

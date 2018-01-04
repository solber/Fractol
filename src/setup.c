/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:30:47 by wnoth             #+#    #+#             */
/*   Updated: 2017/12/11 10:14:25 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keyhelp(void)
{
	ft_putendl("COMMANDS :");
	ft_putendl("\e[40;38;5;27m< >\x1b[0m : Iterations");
	ft_putendl("\e[40;38;5;197m+ -\x1b[0m : Zoom");
	ft_putendl("\e[40;38;5;68m/ *\x1b[0m : Zoom * 10");
	ft_putendl("\e[40;38;5;82mArrow\x1b[0m : Translation");
	ft_putendl("\e[40;38;5;164mMouse Button Left\x1b[0m : Focus");
	ft_putendl("\e[40;38;5;221mF\x1b[0m : Unlock mouse movement");
}

/*
** init vals
*/

void	setup(int f, int c)
{
	t_env	e;

	e.selectedcolor = c;
	e.fractale = f;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Fractol");
	e.bpp = 0;
	e.size_line = 0;
	e.endian = 0;
	e.cam = cam();
	mlx_hook(e.win, 2, 1, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 6, 1, mouse_motion, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	keyhelp();
	mlx_loop(e.mlx);
}

/*
** Init val camera
*/

t_cam	*cam(void)
{
	t_cam *camera;

	camera = (t_cam*)malloc(sizeof(t_cam));
	camera->z = 1;
	camera->movex = 0;
	camera->movey = 0;
	camera->maxit = 30;
	camera->mousex = 0;
	camera->mousey = 0;
	camera->varx = 0;
	camera->vary = 0;
	camera->anim = 0;
	camera->color = 0;
	return (camera);
}

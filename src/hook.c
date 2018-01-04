/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:30:47 by wnoth             #+#    #+#             */
/*   Updated: 2017/12/11 09:49:55 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Redraw image after event
*/

int		expose_hook(t_env *e)
{
	draw_img(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	mouseto(e, button, x, y);
	draw_img(e);
	return (0);
}

int		mouse_motion(int x, int y, t_env *e)
{
	if (e->cam->anim)
	{
		mouseto(e, 0, x, y);
		draw_img(e);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	keyto(e, keycode);
	draw_img(e);
	return (0);
}

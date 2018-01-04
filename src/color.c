/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:30:47 by wnoth             #+#    #+#             */
/*   Updated: 2017/12/11 09:47:12 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	deplacement de X bit sur le R
*/

int	rgb_to_int(int r, int g, int b, t_env *e)
{
	int	color;

	color = 0;
	color = (r << e->selectedcolor) | (g << 8) | b;
	return (color);
}

/*
** Conversion couleurs // couleur en fonction de la region
*/

int	hsv_to_rgb(unsigned int h, unsigned int s, unsigned int v, t_env *e)
{
	unsigned char	region;
	unsigned char	fpart;
	unsigned char	p;
	unsigned char	q;
	unsigned char	t;

	if (h == 0)
		return (rgb_to_int(v, v, v, e));
	region = h / 43;
	fpart = (h - (region * 43)) * 6;
	p = (v * (255 - s)) >> 8;
	q = (v * (255 - ((s * fpart) >> 8))) >> 8;
	t = (v * (255 - ((s * (255 - fpart)) >> 8))) >> 8;
	if (region == 0)
		return (rgb_to_int(v, t, p, e));
	if (region == 1)
		return (rgb_to_int(q, v, p, e));
	if (region == 2)
		return (rgb_to_int(p, v, t, e));
	if (region == 3)
		return (rgb_to_int(p, q, v, e));
	if (region == 4)
		return (rgb_to_int(t, p, v, e));
	else
		return (rgb_to_int(v, p, q, e));
}

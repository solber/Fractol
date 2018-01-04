/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:52:51 by wnoth             #+#    #+#             */
/*   Updated: 2017/12/11 09:46:32 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** calc complex nbr
*/

t_complex	initcomplex(void)
{
	t_complex	nb;

	nb.r = 0;
	nb.i = 0;
	return (nb);
}

/*
** Addition complexe
*/

t_complex	addcomplex(t_complex d1, t_complex d2)
{
	t_complex	result;

	result.r = d1.r + d2.r;
	result.i = d1.i + d2.i;
	return (result);
}

/*
** sub complex
*/

t_complex	souscomplex(t_complex d1, t_complex d2)
{
	t_complex	result;

	result.r = d1.r - d2.r;
	result.i = d1.i - d2.i;
	return (result);
}

/*
** times complex
*/

t_complex	multcomplex(t_complex d1, t_complex d2)
{
	t_complex	result;

	result.r = d1.r * d2.r + ((-1) * d1.i * d2.i);
	result.i = (d1.r * d2.i) + (d1.i * d2.r);
	return (result);
}

/*
** polish
*/

t_complex	offsetcomplex(t_env *e, int x, int y)
{
	t_complex	p;

	p.r = 1.5 * (x - WIDTH / 2) / (0.5 * e->cam->z * WIDTH) + e->cam->movex;
	p.i = (y - HEIGHT / 2) / (0.5 * e->cam->z * HEIGHT) + e->cam->movey;
	return (p);
}

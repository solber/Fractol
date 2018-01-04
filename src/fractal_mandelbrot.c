/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:30:47 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/27 09:39:20 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Maths mandelbrot
*/

int		mandelbrot(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	p;
	int			i;

	p = offsetcomplex(e, x, y);
	new = initcomplex();
	new.r += e->cam->varx;
	new.i += e->cam->vary;
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxit && ((new.r * new.r + new.i * new.i) <= 4))
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + p.r;
		new.i = 2 * old.r * old.i + p.i;
		i++;
	}
	return (i);
}

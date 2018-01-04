/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:30:47 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/27 10:59:11 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Maths Julia
*/

#include "fractol.h"

int		julia(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	c;
	int			i;

	c.r = -0.7 + e->cam->varx;
	c.i = 0.27015 + e->cam->vary;
	new = offsetcomplex(e, x, y);
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxit && (new.r * new.r + new.i * new.i) <= 4)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + c.r;
		new.i = 2 * old.r * old.i + c.i;
		i++;
	}
	return (i);
}

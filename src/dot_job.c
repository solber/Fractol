/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_job.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:30:47 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/27 10:36:37 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** init dot val
*/

void	setdot(t_dot *dot, int x, int y)
{
	dot->x = x;
	dot->y = y;
}

/*
** remaloc dot
*/

t_dot	*dot(int x, int y)
{
	t_dot	*dot;

	if (!(dot = (t_dot*)malloc(sizeof(t_dot))))
		return (NULL);
	dot->x = x;
	dot->y = y;
	return (dot);
}

/*
** free dot
*/

void	freedot(t_dot *d1, t_dot *d2, t_dot *d3, t_dot *d4)
{
	if (d1)
		free(d1);
	if (d2)
		free(d2);
	if (d3)
		free(d3);
	if (d4)
		free(d4);
}

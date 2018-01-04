/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:30:47 by wnoth             #+#    #+#             */
/*   Updated: 2017/12/11 10:13:59 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <complex.h>

/*
** Window size
*/

# define WIDTH 800
# define HEIGHT 600

/*
** Exit prog
*/

# define KEY_ESC 53

/*
** Translation
*/

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PADLEFT 86
# define KEY_PADRIGHT 88

/*
** Zoom in out
*/

# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_X 67
# define KEY_DIVIDE 75

/*
** Iteration
*/

# define KEY_CHEVRONL 43
# define KEY_CHREVONR 47

/*
** Unlock/lock mouse
*/

# define KEY_F 3

/*
** Switch fractal
*/

# define KEY_LBRACKET 33
# define KEY_RBRACKET 30

typedef struct	s_cam
{
	double		z;
	double		movex;
	double		movey;
	double		mousex;
	double		mousey;
	double		varx;
	double		vary;
	int			maxit;
	int			anim;
	int			color;
}				t_cam;

t_cam			*cam(void);

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*imgpix;
	int			bpp;
	int			size_line;
	int			endian;
	t_cam		*cam;
	int			fractale;
	int			fd;
	int			selectedcolor;
}				t_env;

/*
** about pixels
*/

typedef struct	s_dot
{
	int			x;
	int			y;
}				t_dot;

void			setdot(t_dot *dot, int x, int y);
void			draw_dot(t_env *e, int x, int y, int color);
void			draw_line(t_env *e, t_dot *p0, t_dot *p1, int color);
t_dot			*dot(int x, int y);
void			freedot(t_dot *d1, t_dot *d2, t_dot *d3, t_dot *d4);

/*
** about complex
*/

typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

t_complex		initcomplex(void);
t_complex		addcomplex(t_complex d1, t_complex d2);
t_complex		souscomplex(t_complex d1, t_complex d2);
t_complex		multcomplex(t_complex d1, t_complex d2);
t_complex		offsetcomplex(t_env *e, int x, int y);

/*
** setup et help
*/

void			setup(int f, int c);
void			help();
void			keyhelp();

/*
** hook
*/

int				mouse_hook(int button, int x, int y, t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				keyto(t_env *e, int keycode);
int				mouseto(t_env *e, int button, int x, int y);
int				mouse_motion(int x, int y, t_env *e);

/*
** drawing
*/

void			draw_img(t_env *e);
void			draw_fractal(t_env *e);
int				get_selected_fractal(t_env *e, int x, int y);
void			print_fractal_fdf(t_env *e);
void			draw_info(t_env *e);

/*
** Calcs
*/

int				mandelbrot(t_env *e, int x, int y);
int				julia(t_env *e, int x, int y);
int				crackdisappear(t_env *e, int x, int y);

/*
** color conversion
*/

int				rgb_to_int(int r, int g, int b, t_env *e);
int				hsv_to_rgb(unsigned int h, unsigned int s,
				unsigned int v, t_env *e);

#endif

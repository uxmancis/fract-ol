/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:07:19 by uxmancis          #+#    #+#             */
/*   Updated: 2024/01/07 12:10:26 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilib/mlx.h"
#include <stdio.h>
#include <stdlib.h> //exit

/*# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define R 114
# define Z 122
# define PLUS 65451
# define MINUS 65453*/

/*---------- Dimensions --------*/
# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITERATIONS 60

/*----------    Keys    --------*/
/*Mouse events*/
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
/*Keyboard events*/
# define ESC 53
/*Other events*/
# define CLOSE 17 //1L << 17

/*typedef struct s_fractal
{
	char		*name;
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	//t_complex	c;
	double		zoom;
	double		x;
	double		y;
	double		xarrow;
	double		yarrow;
	double		radius;
	int			iterations;
	int			color;
}				t_fractal;*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*window;

	double		x_min; //para que acepte decimales
	double		x_max;//para que acepte decimales
	double		y_min;//para que acepte decimales
	double		y_max;//para que acepte decimales
}				t_data;

/*typedef struct s_imaginari_number
{
	double			imaginari;
	double			real;
}				t_imaginari_number;*/


//burning.c
//void	miniburning(int x, int y, t_fractal *burning);
//void	burningset(t_fractal *burning);

//define.c
//void	define_fr(int	fr_type, t_fractal	*fractal);
//void	define_mandelbrot(t_fractal	*fractal, char *name);
//void	define_julia(t_fractal	*fractal, char *name);
//void	define_burning(t_fractal	*fractal, char *name);

//event_mgmt.c
int	mouse_event_mgmt(int keycode);
int	key_event_mgmt(int keycode);

//ft_fractol.c
//void	fractalsetup(t_fractal *fractal);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_message(void);
int	ft_render(/*int fr_type, */t_data *all);
int		mouse_event_mgmt(int keycode);
int		key_event_mgmt(int keycode);
void	ft_init(t_data *all);
void	set_pixel_colour(t_data *all, double x, double y, int nb_it);

//hooks.c
//int		close_game(t_fractal *fractal);
//int		key_hook(int keycode, t_fractal *fractal);
//int		mouse_hook(int key_code, int x, int y, t_fractal *fractal);

//julia.c
//int		my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
//void	juliaset(t_fractal *julia);

//mandelbrot.c
//void	minimandel(int x, int y, t_fractal *mandel);
//void	mandelbrotset(t_fractal *mandel);
int	ft_mandelbrot(double	x_complex, double	y_complex);

//utils.c
int		ft_strlen(char	*str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
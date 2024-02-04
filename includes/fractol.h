/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:07:19 by uxmancis          #+#    #+#             */
/*   Updated: 2024/02/04 16:47:51 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilib/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h> //exit

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
# define WIDTH 500
# define HEIGHT 500
# define MAX_ITERATIONS 100 //Impacts on image quality and rendering speed

/*----------    Keys    --------*/
/*Mouse events*/
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
/*Keyboard events*/
# define ESC 53
# define LEFT 124
# define RIGHT 123
# define UP 125
# define DOWN 126
/*Other events*/
# define CLOSE 17

/*
*	IMAGE: pixels' buffer values from mlx_get_data_addr()
*
*	- img_ptr: pointer to image struct
*	- pixels_ptr: points to actual pixels
*/
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

/*COMPLEX value
*	- x: real part
*	- y: imaginary part
*/
typedef struct s_complex
{
	double	x;
	double	y;
}		t_complex;

/* FRACTAL ID
*	- name: "mandelbrot" or "julia"
*	- MLX: mlx_connection, mlx_window
*	- Image: img
*	- Hooks values: shift_x (used for key_left and key_right)
*					shift_y (used for key_up and key_down)
*					zoom
*	- Complex number range definition: x_min, x_max, y_min, y_max
*	- my_mlx_pixel_put: addr, line_length, bits_per_pixel
*	- julia: julia_x, julia_y
*/
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;

	t_img	img;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	void	*addr;
	int		line_length;
	int		bits_per_pixel;
	double	julia_x;
	double	julia_y;
}		t_fractal;

typedef struct s_window_coordinates
{
	int	x;
	int	y;
}		t_window;

//event_handler.c
int		mouse_handler(int keycode, int x, int y, t_fractal *fractal);
int		key_handler(int keycode, t_fractal *fractal);
int		close_handler(t_fractal *fractal);

//ft_fractol.c
void	ft_message(void);
void	ft_events_init(t_fractal *fractal);
void	ft_fractal_init(t_fractal	*fractal);

//generate_colour.c
void	generate_colour3(int nb_iterations, int **color, int range_colour);
void	generate_colour2(int nb_iterations, int **color, int range_colour);
void	generate_colour(int nb_iterations, int **color);
void	sunset1_generate_colour(int nb_iterations, int ***color);
void	sunset2_generate_colour(int nb_iterations, int ***color);

//mandelbrot.c

void	ft_events_init(t_fractal *fractal);
void	ft_message(void);
void	ft_fractal_init(t_fractal	*fractal);
void	set_pixel_colour(t_fractal *all, double x, double y, int nb_it);

//render.c
void	my_mlx_pixel_put(t_fractal *fractal, t_window window, int color);
double	ft_scale_x(int x_window, t_fractal *fractal);
double	ft_scale_y(int y_window, t_fractal *fractal);
void	ft_handle_pixel(t_window window, t_fractal *fractal);
void	ft_render(t_fractal *fractal);
void	mandel_vs_julia(t_complex *c, t_complex *z, t_fractal *fractal);

void	ft_mandelbrot(t_complex c, t_complex z, t_window window,
			t_fractal *fractal);
int		rgb_to_int(int r, int g, int b);

//utils.c
int		ft_strlen(char	*str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char	*fr_type, char *arg);
double	ft_abs(double input);
int		ft_2scolour(int nb_iterations, int colour);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);

//utils_str2double.c
int		ft_get_integer_part(char	*str, int *dot_index);
double	ft_get_fractional_part(char *str, int dot_index);
int		check_arg(char *str, int *sign);
double	ft_str2double(char *str);

#endif
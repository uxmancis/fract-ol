/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:50:36 by uxmancis          #+#    #+#             */
/*   Updated: 2024/02/04 16:38:37 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

/* my_mlx_pixel_put: Puts a pixel in our image.*/
void	my_mlx_pixel_put(t_fractal *fractal, t_window window, int color)
{
	char	*dst;

	dst = fractal->img.pixels_ptr + (window.y * fractal->img.line_len
			+ window.x * (fractal->img.bpp / 8));
	*(unsigned int *)dst = color;
}

/* ft_scale_y: 
*	What? Returns complex plane equivalent from window coordinate (each pixel)
*		Input: y_window --> Output: y_complex
*		
*	Why? Each pixel represents 1 complex number (made 
*	of x and y axis 2D axis). This function gets the y (imaginary) 
*	part.
*
*	How? Rule of 3 tells how much to substract to y_max
*		When HEIGHT (total nb of pixels)      ------ y_window
*		When DIF.(total range of complex nb)  ------ y_complex
*/
double	ft_scale_y(int y_window, t_fractal *fractal)
{
	double	dif_total_complexnb;
	double	y_complex;

	dif_total_complexnb = ft_abs(fractal->y_max - (fractal->y_min));
	y_complex = 2 - dif_total_complexnb * y_window / HEIGHT;
	return (y_complex);
}

/* ft_scale_x: 
*	What? Returns complex plane equivalent from window coordinate (each pixel)
*		Input: x_window --> Output: x_complex
*		
*	Why? Each pixel represents 1 complex number (made of x and y axis 2D axis,
*	Cartesian plane coordinate). This function gets the x (real part). 
*	part.
*
*	How? Rule of 3 tells how much to sum to x_min
*		When WIDTH (total nb of pixels)      ------ x_window
*		When DIF.(total range of complex nb) ------ x_complex
*/
double	ft_scale_x(int x_window, t_fractal *fractal)
{
	double	dif_total_complexnb;
	double	x_complex;

	dif_total_complexnb = ft_abs(fractal->x_max - (fractal->x_min));
	x_complex = (fractal->x_min) + dif_total_complexnb * x_window / WIDTH;
	return (x_complex);
}

/* Function: ft_handle_pixel
*	Assign values to Z and C complex numbers.
*	the pixels by calling ft_handle_pixel.
*/
void	ft_handle_pixel(t_window window, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = ft_scale_x(window.x, fractal) * fractal->zoom + fractal->shift_x;
	z.y = ft_scale_y(window.y, fractal) * fractal->zoom + fractal->shift_y;
	mandel_vs_julia(&c, &z, fractal);
	ft_mandelbrot(c, z, window, fractal);
}

/*ft_render
*	We'll iterate through the whole window and handle each of
*	the pixels by calling ft_handle_pixel.
*/
void	ft_render(t_fractal *fractal)
{
	t_window	window;

	(void)fractal;
	window.y = 0;
	while (window.y < 500)
	{
		window.x = 0;
		while (window.x < 500)
		{
			ft_handle_pixel(window, fractal);
			window.x++;
		}
		window.y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}

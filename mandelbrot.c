/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:02:05 by uxmancis          #+#    #+#             */
/*   Updated: 2024/02/04 16:11:17 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

/*ft_mandelbrot
*	We will iterate through Z = Z * Z + c equation. 
*		*What is this equation? Mandelbrot formula. Check below for more info.
*
*	C is our complex number. 
*		*What are complex numbers? Numbers made of a real and imaginary part, 
*		made of i: a + b*i. Check below for more info.
*	Z is the result of doing C^2 and summing C through each iterations. Starts
*	being 0 at the beginning.
*
*	About if ((z.x * z.x + z.y + z.y) > 4): We assume that
*	the point has escaped. Pitagoras, radius of 2 (4), from 0,0.
*
*	About variables on the ft_mandelbrot function
*		c_x: real part of C complex number (x axis)
*		c_y: imaginary part of C complex number (y axis)
*		z_x: real part of Z complex number (x axis)
*		z_y: imaginary part of Z complex number (y axis)
*
* 	  	0xfff2da: Barbie blonde, inside Mandelbrot set.
*/
void	ft_mandelbrot(t_complex c, t_complex z, t_window win, t_fractal *fr)
{
	int		nb_iterations;
	double	tmp_x;
	int		*colour;

	nb_iterations = 0;
	colour = malloc(sizeof(int) * 3);
	while (nb_iterations < MAX_ITERATIONS)
	{
		if ((z.x * z.x + z.y + z.y) > 4)
		{
			generate_colour(nb_iterations, &colour);
			my_mlx_pixel_put(fr, win,
				rgb_to_int(colour[0], colour[1], colour[2]));
			break ;
		}
		tmp_x = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp_x + c.x;
		nb_iterations++;
		my_mlx_pixel_put(fr, win, 0xfff2da);
	}
	free(colour);
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

/*About Mandelbrot set:

	The Mandelbrot formula iterates the equation Z = Z * Z + c, 		
		> Beginning: z = 0, and c = the complex number to be analysed
				What are complex numbers (c)? a + bi
				//a = real part, b*i = imaginary part
				· a and b = real numbers
				· i = √-1, which means, i^2 = -1

		> At every iteration, Z is squared (^2) //Remember! i^2 = -1
				Z = (x + yi)^2 = (x + yi) * (x + yi) =
						   	   = x^2 + 2xyi + y^2*i^2 = 
						       = x^2 + 2xyi + y^2*(-1) =
						       = x^2 + 2xyi - y^2 = 
						   	   = x^2 - y^2 + 2xyi //New Z (complex number)

						   		x^2 - y^2 //real part
								2xyi //imaginary part
		*Suggested video: (min 17:00)
		https://www.youtube.com/watch?v=ANLW1zYbLcs&t=45s 
				
		
	After n number of iterations:
	> If result tends toward infinity = NOT part of Mandelbrot set.
	> If the result stays small = YES part of Mandelbrot set.
	
	We can't compute to infinity, but it's safe to say that if the
	absolut value of Z goes above 2, it will tend toward infinity.

	About complex numbers: 
		· Each point in the complex plane is represented by a pair of real
		and imaginary coordinates (r, i).
		· How to know if each point belongs to the Mandelbrot set or not?
		Based on: does this point escape to infinity or not?
		· r * r + i * i < 4 --> 
		*If the magnitude of a complex number (Z) is larger than 4, it's 
		considered to have escaped to infinity.
		**When Magnitude or module of any of the both complex numbers is 
		bigger than 2, |z| > 2 || or |c| > 2 --> means the complex number
		squares to infinity.
	*/

/* Function: mandel_vs_julia
*
* Mandelbrot: z = z^2 + c,    z initially is (0,0),    c is the actual complex
* number we are analysing.
*
* Julia: z = z^2 + c,    z initially is the actual complex number we are
*/
void	mandel_vs_julia(t_complex *c, t_complex *z, t_fractal *fractal)
{
	if (ft_strcmp(fractal->name, "julia") == 1)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else if (ft_strcmp(fractal->name, "mandelbrot") == 1)
	{
		c->x = z->x;
		c->y = z->y;
	}
}

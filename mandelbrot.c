/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:02:05 by uxmancis          #+#    #+#             */
/*   Updated: 2024/01/07 11:42:52 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fract-ol.h"

/*ft_mandelbrot
*	We will iterate through Z = Z * Z + c equation. 
*		*What is this equation? Mandelbrot formula. Check below for more info.
*
*	Z and C are 2 complex numbers. 
*		*What are complex numbers? Numbers made of a real and imaginary part, 
*		made of i: a + b*i. Check below for more info.
*
*	About variables on the ft_mandelbrot function
*		x_complex: real part of C complex number
*		y_complex: imaginary part of C complex number
*		z_real: real part of Z complex number
*		z_imag: imaginary part of Z complex number
*/
int	ft_mandelbrot(double	x_complex, double	y_complex)
{
	int nb_iterations;
	double	z_real;
	double	z_imaginary;
	double tmp;
	
	nb_iterations = 0;
	z_real = 0;
	z_imaginary = 0;
	while (nb_iterations < MAX_ITERATIONS)
	{
		if (((z_real * z_real) + (z_imaginary + z_imaginary)) > 4)
			break;
		tmp = 2 * z_real * z_imaginary + y_complex;
		z_real = z_real * z_real - z_imaginary * z_imaginary + x_complex;
		z_imaginary = tmp;
		nb_iterations++;
	}
	return (nb_iterations);
}

/*About Mandelbrot set:

	The Mandelbrot formula iterates the equation Z = Z * Z + c, 
	where Z and C are complex numbers. At every iteration, Z is squared.

	What are complex numbers? a + bi
		i^2 = -1
		a and b = real numbers
		a = real part of complex number
		b*i = imaginary part of complex number
		
	If the result tens toward infinity = NOT part of Mandelbrot set.
	If the result stays small = YES part of Mandelbrot set.
	
	
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
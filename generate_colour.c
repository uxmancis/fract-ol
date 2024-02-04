/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_colour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:26:29 by uxmancis          #+#    #+#             */
/*   Updated: 2024/02/04 16:54:22 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

/*generate_colour3
*	*8, [71-80] - violeta
*	*9, [81-90] - violeta iluntxua
*	*10, [91-100] - rubio barbie
*
*	*colour: RGB
*		(*colour)[0] = Red
*		(*colour)[1] = Green
*		(*colour)[2] = Blue	
*/
void	generate_colour3(int nb_iterations, int **color, int range_colour)
{
	(void)range_colour;
	(void)nb_iterations;
	(void)color;
	if (nb_iterations < range_colour * 8)
	{
		(*color)[0] = 230;
		(*color)[1] = 181;
		(*color)[2] = 218;
	}
	else if (nb_iterations < range_colour * 9)
	{
		(*color)[0] = 192;
		(*color)[1] = 88;
		(*color)[2] = 164;
	}
	else if (nb_iterations < range_colour * 10)
	{
		(*color)[0] = 255;
		(*color)[1] = 242;
		(*color)[2] = 218;
	}
}

/*generate_colour2
*	*4, [31-40] - baby blue
*	*5, [41-50] - urdin iluntxuaua gorputz gehitxuaukin
*	*6, [51-60] - urdin ilunena //eliminado por función demasiado larga
*	*7, [61-70] - barbie pink
*
*	*colour: RGB
*		(*colour)[0] = Red
*		(*colour)[1] = Green
*		(*colour)[2] = Blue	
*/
void	generate_colour2(int nb_iterations, int **color, int range_colour)
{
	(void)range_colour;
	(void)nb_iterations;
	(void)color;
	if (nb_iterations < range_colour * 4)
	{
		(*color)[0] = 174;
		(*color)[1] = 211;
		(*color)[2] = 246;
	}
	else if (nb_iterations < range_colour * 5)
	{
		(*color)[0] = 103;
		(*color)[1] = 166;
		(*color)[2] = 210;
	}
	else if (nb_iterations < range_colour * 7)
	{
		(*color)[0] = 254;
		(*color)[1] = 130;
		(*color)[2] = 179;
	}
}

/*generate_colour
*	*1, [0-10] - SALMON --> ixa pantalla osua hemen doia, fondua da.
	Zerua izen bihada. Urdintxo + sunset.
*	*2, [11-20] - NARANJA
*	*3, [21-30] - naranja argixena
*	
*	*colour: RGB
*		(*colour)[0] = Red
*		(*colour)[1] = Green
*		(*colour)[2] = Blue
*/
void	generate_colour(int nb_iterations, int **color)
{
	int	range_colour;

	range_colour = MAX_ITERATIONS / 10;
	if (nb_iterations < range_colour)
	{
		sunset1_generate_colour(nb_iterations, &color);
		sunset2_generate_colour(nb_iterations, &color);
	}
	else if (nb_iterations < range_colour * 2)
	{
		(*color)[0] = 255;
		(*color)[1] = 162;
		(*color)[2] = 78;
	}
	else if (nb_iterations < range_colour * 3)
	{
		(*color)[0] = 255;
		(*color)[1] = 209;
		(*color)[2] = 171;
	}
	else if (nb_iterations < range_colour * 7)
		generate_colour2(nb_iterations, color, range_colour);
	else
		generate_colour3(nb_iterations, color, range_colour);
}

/*colour: RGB
*   colour[0] = Red
*   colour[1] = Green
*   colour[2] = Blue
*/
void	sunset1_generate_colour(int nb_iterations, int ***color)
{
	if (nb_iterations == 1)
	{
		(**color)[0] = 174;
		(**color)[1] = 211;
		(**color)[2] = 246;
	}
	else if (nb_iterations == 2)
	{
		(**color)[0] = 103;
		(**color)[1] = 166;
		(**color)[2] = 210;
	}
	else if (nb_iterations == 3)
	{
		(**color)[0] = 255;
		(**color)[1] = 209;
		(**color)[2] = 171;
	}
	else if (nb_iterations == 4)
	{
		(**color)[0] = 255;
		(**color)[1] = 162;
		(**color)[2] = 78;
	}
}

void	sunset2_generate_colour(int nb_iterations, int ***color)
{
	if (nb_iterations == 5)
	{
		(**color)[0] = 254;
		(**color)[1] = 130;
		(**color)[2] = 179;
	}
	else if (nb_iterations > 5)
	{
		(**color)[0] = 212;
		(**color)[1] = 234;
		(**color)[2] = 255;
	}
}

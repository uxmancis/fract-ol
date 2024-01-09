/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:57:28 by uxmancis          #+#    #+#             */
/*   Updated: 2024/01/09 21:34:02 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fract-ol.h"

/*void	fractalsetup(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	if (!ft_strncmp(fractal->name, "julia", 5))
		juliaset(fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrotset(fractal);
	else if (!ft_strncmp(fractal->name, "burning", 7))
		burningset(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}*/

/*DESCRIPTION:
|checks looks for a match between arg[1] and fractal types allowed
by our fractol program. Returns which has been the match: 

0: no match between fractal types and argv[1]
1: match found - mandelbrot fractal
2: match found - julia fractal
3: match found - burning ship fractal
---------------------------------------------------------------*/
int	ft_check_fr(char	**argv)
{
	if (ft_strlen(argv[1]) == 10)
	{
		if (ft_strcmp("mandelbrot", argv[1]) == 1)
			return (1);
	}
	else if (ft_strlen(argv[1]) == 5)
	{
		if (ft_strcmp("julia", argv[1]) == 1)
			return (2);
		if (ft_strcmp("julio", argv[1]) == 1)
			return (3);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_message(void)
{
	printf("Non valid argument format. Recommended compillation possibilities:\n");
	printf("./fractol mandelbrot\n");
	printf("./fractol julia\n");
	printf("./fractol julio\n");
}


void	set_pixel_colour(t_data *all, double x_window, double y_window, int nb_it)
{
	//printf("nb_iterations = %d\n", nb_it);
	if(nb_it == MAX_ITERATIONS) //sí pertenece a Mandelbrot
		my_mlx_pixel_put(all, x_window, y_window, 0x00FF0000);
	//if(nb_it == 2)
		//my_mlx_pixel_put(all, x_window, y_window, 0x0000FF00);
	//if(nb_it == 3)
		//my_mlx_pixel_put(all, x_window, y_window, 0x000000FF);
	else
		my_mlx_pixel_put(all, x_window, y_window, 0xFF000000);    
}

/* ft_get_complex_x: 
*	What? Returns complex plane equivalent from window coordinate (each pixel)
*		Input: x_window --> Output: x_complex
*		
*	Why? Each pixel represents 1 complex number (made 
*	of x and y axis 2D axis). This function gets the x (real) 
*	part.
*
*	How? Rule of 3
*		When WIDTH (total nb of pixels)      ------ x_window
*		When DIF.(total range of complex nb) ------ x_complex
*/
double	ft_get_complex_x(int	x_window, t_data *all)
{
	double	dif_total_complexnb;
	double	x_complex;

	dif_total_complexnb = ft_abs(all->x_max - all->x_min);
	x_complex = dif_total_complexnb * x_window / WIDTH;
	return (x_complex);
}

/* ft_get_complex_x: 
*	What? Returns complex plane equivalent from window coordinate (each pixel)
*		Input: y_window --> Output: y_complex
*		
*	Why? Each pixel represents 1 complex number (made 
*	of x and y axis 2D axis). This function gets the y (imaginary) 
*	part.
*
*	How? Rule of 3
*		When HEIGHT (total nb of pixels)      ------ y_window
*		When DIF.(total range of complex nb)  ------ y_complex
*/
double	ft_get_complex_y(int	y_window, t_data *all)
{
	double	dif_total_complexnb;
	double	y_complex;

	dif_total_complexnb = ft_abs(all->y_max - all->y_min);
	y_complex = dif_total_complexnb * y_window / WIDTH;
	return (y_complex);
}

int	ft_render(/*int fr_type, */t_data *all)
{
	int	x_window;
	int	y_window;
	double	x_complex;
	double	y_complex;
	int		nb_iterations;
	
	//1. Define limits (max, min) to x and y coordinates = define complex numbers' range
		//They've already been set
	//2. Convertir x-y window a x-y complex numbers
	x_window = 0;
	while (x_window < WIDTH)
	{
		y_window = 0;
		while (y_window < HEIGHT)
		{
			//1.- Get complex number
			x_complex = ft_get_complex_x(x_window, all);
			y_complex = ft_get_complex_y(y_window, all);
			//2.- Mandelbrot: is it part of the set? //Hemen barruan, mandar a función que llame a cada fractal en base al contenido de la variable fr_type
			nb_iterations = ft_mandelbrot(x_complex, y_complex);
			//3.- Assign colour to pixel
			set_pixel_colour(all, x_window, y_window, nb_iterations);
			y_window++;
		}
		x_window++;
	}
	return (0);
	/*This is about rendering the image on the window in a way or in another
	based on the type of fractal that is wanted to be shown in the screen.
	if (fr_type = 1)
		//render_1
		//return (1) = DONE
	else if (fr_type = 2)
		//render_2
		//return (2) = DONE
	else if (fr_type = 3)
		//render_3
		//return (3) = DONE
	return (0) //some kind of error, as fr_type should have been 1-2-3*/
}

/*int	x_makeit_complex(int	x_window)
{
	int x_complex;

	x_complex = x_window - (WIDTH / 2);
	return (x_complex);
}

int y_makeit_complex (int	y_window)
{
	int	y_complex;
	int	dif;

	dif = HEIGHT - y_window;
	y_complex = ((HEIGHT / 2) * (-1)) + dif;
	return (y_complex);
}*/

void	ft_init(t_data *all)
{
	double	dif_x;
	double	dif_y;

	all->x_min = -0.4;
	all->x_max = 0.4;
	all->y_min = -0.4;
	dif_x = all->x_max - all->x_min;
	dif_y = dif_x * HEIGHT / WIDTH;
	all->y_max = all->y_min + dif_y;
	//printf("initialization: x_max=%f, x_min=%f, y_max=%f, x_min=%f\n", all->x_max, all->x_min, all->y_max, all->y_min);
}

/// @brief 
/// @param argc 
/// @param argv 
/// @return 
int	main(int argc, char **argv)
{
	int			fr_type;
	t_data		all;

	fr_type = 0;
	if (argv[1])
		fr_type = ft_check_fr(argv);
	if (argc != 2 || fr_type == 0)
	{
		ft_message();
		return (0);
	}
	all.mlx = mlx_init();
	all.window = mlx_new_window(all.mlx, WIDTH, HEIGHT, "Hello world!");
	all.img = mlx_new_image(all.mlx, WIDTH, HEIGHT);
	all.addr = mlx_get_data_addr(all.img, &all.bits_per_pixel, &all.line_length,
								&all.endian);
	ft_init(&all);
	ft_render(/*fr_type, */&all);
	mlx_mouse_hook(all.window, &mouse_event_mgmt, NULL);
	mlx_key_hook(all.window, &key_event_mgmt, NULL);
	mlx_hook(all.window, CLOSE, 0, key_event_mgmt, &all);
	mlx_put_image_to_window(all.mlx, all.window, all.img, 0, 0);
	mlx_loop(all.mlx); //k    eeps alive the program
	return (0);
}

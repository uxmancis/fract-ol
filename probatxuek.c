/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probatxuek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:19:42 by uxmancis          #+#    #+#             */
/*   Updated: 2024/01/03 15:25:57 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fract-ol.h"
#include "minilib/mlx.h"

/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;*/

/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/
/*int	ft_mandelbrot(int	x_window, int	y_window)
{
	int		nb_it;
	double	z_real;
	double	z_imag;
	double	z_new;
	int		x_calc;
	int		y_calc;
	int		y_dif; //diferentzia kalkulatzeko

	x_calc = x_window - (WIDTH / 2); //conversión
	y_dif = HEIGHT - y_window; //diferentzia kalkulau
	y_calc = ((HEIGHT / 2) * (-1)) + y_dif; //conversión
	//y_window + (HEIGHT - (y_window * 2));

	printf("x_window = %d, x_calc = %d || y_window = %d, y_calc = %d\n", x_window, x_calc, y_window, y_calc);
	if (((x_calc * x_calc) + (y_calc + y_calc)) < 4)
		return (0);
	else
		return (1);
	nb_it = 0;
	while (nb_it < MAX_ITERATIONS)
	{
		z_new = (x * x) + y
		nb_it++;
	}
	return (nb_it);
	return (0);
}

int main(void)
{
	int x_window;
	int y_window;

	x_window = 1920;
	y_window = 1080;
	ft_mandelbrot(x_window, y_window);
	return (0);
}*/

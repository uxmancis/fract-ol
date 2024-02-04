/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str2double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:30:17 by uxmancis          #+#    #+#             */
/*   Updated: 2024/02/04 16:08:11 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	ft_get_integer_part(char	*str, int *dot_index)
{
	int	i;
	int	integer_part;

	i = 0;
	integer_part = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '.' && str[i] != '\0')
	{
		integer_part = integer_part * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		*dot_index = i;
	return (integer_part);
}

double	ft_get_fractional_part(char *str, int dot_index)
{
	int		i;
	double	fractional_part;
	double	pow;

	i = 0;
	fractional_part = 0;
	pow = 1;
	while (str[i] != '\0')
	{
		if (i > dot_index)
		{
			fractional_part = fractional_part * 10 + (str[i] - '0');
			pow = pow * 10;
		}
		i++;
	}
	fractional_part = fractional_part / pow;
	return (fractional_part);
}

/*
 * Function: check_arg
 * ----------------------------
 *   Checks argument validity for Julia set
 *
 *   If argument is valid ('+','-', '.' and numbers), returns 0.
 *
 *   On the contrary, error message is printed and program exits.
 */
int	check_arg(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '+' && str[i] != '-'
			&& str[i] != '.' && (str[i] < '0' || str[i] > '9'))
		{
			ft_message();
			return (1);
		}
		i++;
	}
	if (str[0] == '-')
		*sign = -1;
	return (0);
}

/*
 * Function: ft_a2double
 * ----------------------------
 *   Converts a string to a double.
 *
 *   str: The string to be converted.
 *
 *   Returns: The double value of the string.
 */
double	ft_str2double(char *str)
{
	double	fractional_part;
	double	pow;
	int		sign;
	int		dot_index;
	int		integer_part;

	dot_index = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;
	if (check_arg(str, &sign) == 1)
		exit (0);
	integer_part = ft_get_integer_part(str, &dot_index);
	if (dot_index != 0)
		fractional_part = ft_get_fractional_part(str, dot_index);
	return ((integer_part + fractional_part) * sign);
}

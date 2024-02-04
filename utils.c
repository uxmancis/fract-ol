/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:39:52 by uxmancis          #+#    #+#             */
/*   Updated: 2024/02/04 16:08:16 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

//libft: len of string
int	ft_strlen(char	*str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

//libft: compare strings
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char ) s1[i] - (unsigned char) s2[i]);
	}
	return (0);
}

/*༊*·˚˚ ༘♡ ·˚꒰ ᥕᥱᥣᥴ᥆꧑ᥱ t᥆  ₊˚ˑ༄ ft_strcmp ═══════════════════╗
		Checks argument number 1 comparing it to accepted    
		fractal types by program.

		Returns 1 if argument is valid, 0 if not.                         
╚══ ═════════════ ═══════════  ═══════════════════ ══════ ༊═╝*/
int	ft_strcmp(char	*fr_name, char *arg)
{
	int	len;
	int	index;

	len = ft_strlen(arg);
	index = 0;
	while (len > 0)
	{
		if (fr_name[index] == arg[index])
			index++;
		else
			return (0);
		if (index == ft_strlen(arg))
			return (1);
	}
	return (0);
}

double	ft_abs(double input)
{
	if (input < 0)
		input = input * (-1);
	return (input);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

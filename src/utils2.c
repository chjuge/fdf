/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:49:05 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/12 18:36:15 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	my_ceil(int scale, int count)
{
	return (floor(scale / count) + 1);
}

int	my_pow(int x, int y)
{
	int	res;

	if (y == 0)
		return (1);
	if (y == 1)
		return (x);
	res = x;
	while (y > 1)
	{
		res *= x;
		y--;
	}
	return (res);
}

int	get_scale_z(t_map	*map)
{
	float	scale;

	scale = (map->max - map->min);
	if (scale > 30)
		return (1);
	if (map->w < 50)
	{
		if (scale < 3)
			scale *= 25;
		else if (scale < 6)
			scale *= 5;
		else if (scale < 10)
			scale *= 2;
		else
			scale /= 2;
	}
	return (scale);
}

int	get_color(char *str)
{
	int	len;
	int	i;
	int	res;

	i = 0;
	len = ft_strlen(str);
	res = 0;
	while (len > 2)
	{
		if (ft_isalpha(str[len - 1]))
			res += (ft_tolower(str[len - 1]) - 87) * my_pow(16, i);
		else
			res += (str[len - 1] - '0') * my_pow(16, i);
		len--;
		i++;
	}
	return (res);
}

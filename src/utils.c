/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:49:05 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 21:23:33 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (dst);
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		((char *)(dst))[i] = ((char *)(src))[i];
		i++;
	}
	return ((char *)(dst));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	my_ceil(int scale, int count)
{
	return (floor(scale/count) + 1);
}

int	get_scale_z(t_map	*map)
{
	float scale;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:27:04 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/07 12:32:15 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int	find_sign(int x1, int x2)
{
	if (x1 < x2)
		return (1);
	return (-1);
}

void	draw_line(int x1, int y1, int x2, int y2, t_data *img)
{
	int	delta[2];
	int	sign[2];
	int	error[2];

	x1 *= 50;
	x2 *= 50;
	y1 *= 50;
	y2 *= 50;
	delta[0] = abs(x2 - x1);
	delta[1] = abs(y2 - y1);
	sign[0] = find_sign(x1, x2);
	sign[1] = find_sign(y1, y2);
	error[0] = delta[0] - delta[1];
	my_mlx_pixel_put(img, x2, y2, 0xffffff);
	while (x1 != x2 || y1 != y2)
{
		my_mlx_pixel_put(img, x1, y1, 0xffffff);
        error[1] = error[0] * 2;
        if(error[1] > -delta[1]) 
        {
            error[0] -= delta[1];
            x1 += sign[0];
        }
        if(error[1] < delta[0]) 
        {
            error[0] += delta[0];
            y1 += sign[1];
        }
    }
}

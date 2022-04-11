/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:27:04 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 16:46:26 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	while (x < 0)
		x += data->w;
	while (x >= data->w)
		x -=data->w;
	while (y < 0)
		y += data->h;
	while (y >= data->h)
		y -= data->h;
	dst = data->mlx_addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int	find_sign(int x1, int x2)
{
	if (x1 < x2)
		return (1);
	return (-1);
}

void	draw_line(t_point *p1, t_point *p2, t_data *data)
{
	int	delta[2];
	int	sign[2];
	int	error[2];
	int	x[2];
	int	y[2];
	// x1 *= 10;
	// x2 *= 10;
	// y1 *= 10;
	// y2 *= 10;
	x[0] = p1->x;
	y[0] = p1->y;
	x[1] = p2->x;
	y[1] = p2->y;
	
	// show_point(p1);
	// show_point(p2);
	// printf("\n");
	delta[0] = abs(x[1] - x[0]);
	delta[1] = abs(y[1] - y[0]);
	sign[0] = find_sign(x[0], x[1]);
	sign[1] = find_sign(y[0], y[1]);
	error[0] = delta[0] - delta[1];
	// printf("color: %d\n", p1->color);
	my_mlx_pixel_put(data, x[1], y[1], p1->color);
	while (x[0] != x[1] || y[0] != y[1])
{
		my_mlx_pixel_put(data, x[0], y[0], p2->color);
        error[1] = error[0] * 2;
        if(error[1] > -delta[1]) 
        {
            error[0] -= delta[1];
            x[0] += sign[0];
        }
        if(error[1] < delta[0]) 
        {
            error[0] += delta[0];
            y[0] += sign[1];
        }
    }
}

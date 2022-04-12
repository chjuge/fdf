/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:56:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/12 18:23:20 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	draw_2_lines(t_point *p[2], t_data *img)
{
	draw_line(p[0], p[0]->next, img);
	draw_line(p[0], p[1], img);
}

void	draw_by_data(t_map *map, t_data *img)
{
	t_line	*line[2];
	t_point	*p[2];

	line[0] = map->head;
	line[1] = map->head->next;
	while (line[0]->next)
	{
		p[0] = line[0]->p_head;
		p[1] = line[1]->p_head;
		while (p[0]->next)
		{
			draw_2_lines(p, img);
			p[0] = p[0]->next;
			p[1] = p[1]->next;
		}
		draw_line(p[0], p[1], img);
		line[0] = line[0]->next;
		line[1] = line[1]->next;
	}
	p[0] = line[0]->p_head;
	while (p[0]->next)
	{
		draw_line(p[0], p[0]->next, img);
		p[0] = p[0]->next;
	}
}

void	drawmap(t_data *data)
{
	t_map	*map;

	data->state_m = state_matrix(data->state);
	map = instance_map(data->map, data->state_m,
			data->state->t_x, data->state->t_y);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w, data->h, "fdf");
	data->img = mlx_new_image(data->mlx, data->w, data->h);
	data->mlx_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_by_data(map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	free_map(map);
}

void	redraw(t_data *data)
{
	t_map	*map;

	data->state_m = state_matrix(data->state);
	map = instance_map(data->map, data->state_m,
			data->state->t_x, data->state->t_y);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->w, data->h);
	data->mlx_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_by_data(map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	free_map(map);
}

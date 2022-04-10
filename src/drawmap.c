/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:56:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/10 12:30:57 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	draw_2_lines(t_point *p[2], t_data *img)
{
	draw_line(p[0]->x, p[0]->y, p[0]->next->x, p[0]->next->y, img);
	draw_line(p[0]->x, p[0]->y, p[1]->x, p[1]->y, img);
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
		draw_line(p[0]->x, p[0]->y, p[1]->x, p[1]->y, img);
		line[0] = line[0]->next;
		line[1] = line[1]->next;
	}
	p[0] = line[0]->p_head;
	while (p[0]->next)
	{
		draw_line(p[0]->x, p[0]->y, p[0]->next->x, p[0]->next->y, img);
		p[0] = p[0]->next;
	}
}

void	drawmap(t_map *map, t_data *data)
{
	data->mlx = mlx_init();
	show_map(map);
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Hello world!");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->mlx_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	printf("drops 1\n");
	draw_by_data(map, data);
	printf("drops 1\n");
	mlx_put_image_to_window(data->mlx, data->win, data->img, 10, 10);
	mlx_key_hook(data->win, key_listener, data);
	// mlx_hook(data->win, 17, 0, close_program, data);
	mlx_hook(data->win, 17, 1L<<17, close_program, data);
	mlx_loop(data->mlx);
}
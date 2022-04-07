/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:56:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/07 12:49:44 by mproveme         ###   ########.fr       */
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

void	drawmap(t_map *map, t_data *img)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	show_map(map);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img->img = mlx_new_image(mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	// draw_line(90, 90, 550, 550, img);
	draw_by_data(map, img);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 10, 10);
	// mlx_string_put(mlx, mlx_win, 100, 100, 0xffffff, "Hello!");
	mlx_loop(mlx);
}
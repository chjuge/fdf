/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:56:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/07 12:32:44 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	draw_by_data(t_map *map, t_data *img)
{
	t_line	*line1;
	t_line	*line2;
	t_point	*p_l1;
	t_point	*p_l2;

	int n = 0;
	// printf("--- n:	%d\n", n++);
	line1 = map->head;
	// printf("--- n:	%d\n", n++);
	line2 = map->head->next;
	// printf("--- n:	%d\n", n++);
	while (line1->next)
	{
	printf("--- n:	%d\n", n++);
		p_l1 = line1->p_head;
		p_l2 = line2->p_head;
		while (p_l1->next)
		{
			draw_line(p_l1->x, p_l1->y, p_l1->next->x, p_l1->next->y, img);
			draw_line(p_l1->x, p_l1->y, p_l2->x, p_l2->y, img);
			p_l1 = p_l1->next;
			p_l2 = p_l2->next;
		}
		draw_line(p_l1->x, p_l1->y, p_l2->x, p_l2->y, img);
		line1 = line1->next;
		line2 = line2->next;
	}
	// printf("--- !!n:	%d\n", n++);
	p_l1 = line1->p_head;
	while (p_l1->next)
	{
		draw_line(p_l1->x, p_l1->y, p_l1->next->x, p_l1->next->y, img);
		p_l1 = p_l1->next;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:56:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/07 12:02:06 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

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
	draw_line(90, 90, 550, 550, img);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_string_put(mlx, mlx_win, 100, 100, 0xffffff, "Hello!");
	mlx_loop(mlx);
}
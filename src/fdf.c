/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:09:13 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 19:27:13 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
// #include "../minilibx_macos/mlx.h"

int	get_translation(t_map *map, int w)
{
	int	x;
	t_line	*line;

	line = map->head;
	while (line->next)
	{
		line = line->next;
	}
	x = w - (int)line->p_head->x;
	return (x + 1);
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
		else if (scale < 11)
			scale *= 2;
		else
			scale /= 2;
	}
	return (scale);
}

int	main(int argc, char **argv)
{

	t_data	data;

	if (argc != 2)
		return (0);
	data.map = fill_map(argv[1]);
	if (!data.map)
	{
		printf("error\n");
		return (1);
	}
	data.h = 800;
	data.w = 800;
	t_map *map1 = scale_map(data.map, my_ceil(data.w, data.map->w)/2, my_ceil(data.h, data.map->h)/2, get_scale_z(data.map));
	t_map *map2 = rotate_map(map1, 0, 45);
	t_map *map3 = rotate_map(map2, 1, 45);
	t_map *map4 = translate_map(map3, get_translation(map3, data.w), 0, 0);
	drawmap(map4, &data);
	return (0);
}

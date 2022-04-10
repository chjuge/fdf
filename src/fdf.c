/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:09:13 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/10 20:47:57 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
// #include "../minilibx_macos/mlx.h"

int	get_translation(t_map *map)
{
	int	x;
	t_line	*line;

	line = map->head;
	while (line->next)
	{
		line = line->next;
	}
	x = 1920 - (int)line->p_head->x;
	return (x);
}

int	main(int argc, char **argv)
{

	t_data	data;
	t_map	*map;

	if (argc != 2)
		return (0);
	// printf("1\n");
	map = fill_t_map(argv[1]);
	if (!map)
	{
		printf("error\n");
		return (1);
	}
	// printf("2\n");
	t_map *map1 = rotate_map(map, 0, 45);
	t_map *map2 = rotate_map(map1, 1, 45);
	t_map *map3 = scale_map(map2, 2, 1, 2);
	t_map *map4 = translate_map(map3, get_translation(map3), 0, 0);
	// printf("3\n");
	// t_map *map2 = translate_map(map1, 500, 0, 0);
	// printf("4\n");
	// printf("5\n");
	// printf("6\n");
	// t_map *map3 = rotate_map(map2, 2, 45);
	// printf("error\n");
	drawmap(map4, &data);
	return (0);
}

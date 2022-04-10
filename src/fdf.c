/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:09:13 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/10 12:33:48 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
// #include "../minilibx_macos/mlx.h"

int	main(int argc, char **argv)
{

	t_data	data;
	t_map	*map;

	if (argc != 2)
		return (0);
	map = fill_t_map(argv[1]);
	if (!map)
	{
		printf("error\n");
		return (1);
	}
	t_map *map1 = scale_map(map, 30, 30, 5);
	// t_map *map2 = translate_map(map1, 500, 0, 0);
	t_map *map2 = translate_map(map1, 500, 100, 0);
	t_map *map3 = rotate_map(map2, 0, 45);
	t_map *map4 = rotate_map(map3, 1, 45);
	// t_map *map3 = rotate_map(map2, 2, 45);
	// printf("error\n");
	drawmap(map4, &data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:09:13 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/10 20:24:03 by mproveme         ###   ########.fr       */
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
	// printf("3\n");
	// t_map *map2 = translate_map(map1, 500, 0, 0);
	// printf("4\n");
	// printf("5\n");
	// t_map *map4 = translate_map(map3, 400, 400, 0);
	// printf("6\n");
	// t_map *map3 = rotate_map(map2, 2, 45);
	// printf("error\n");
	drawmap(map3, &data);
	return (0);
}

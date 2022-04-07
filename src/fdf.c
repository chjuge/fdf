/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:09:13 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/07 12:01:02 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
// #include "../minilibx_macos/mlx.h"

int	main(int argc, char **argv)
{

	t_data	img;
	t_map	*map;
	// int		x = 5;
	// int		y = 5;
	// int		height;

	if (argc != 2)
		return (0);
	// height = fill_list(argv[1]);
	// if (height == -1)
	// {
	// 	printf("wrong map\n");
	// 	return (1);
	// }
	map = fill_t_map(argv[1]);
	// printf("2 2 10 -> %d %d %d\n", 
	// 				map->head->next->next->p_head->next->next->x,
	// 				map->head->next->next->p_head->next->next->y,
	// 				map->head->next->next->p_head->next->next->z);
	// printf("3 2 10 -> %d %d %d\n", 
	// 				map->head->next->next->p_head->next->next->next->x,
	// 				map->head->next->next->p_head->next->next->next->y,
	// 				map->head->next->next->p_head->next->next->next->z);
	if (!map)
		printf("error\n");
	drawmap(map, &img);
	// while (x < 100)
	// {
	// 	my_mlx_pixel_put(&img, x, y, 0xffffff);
	// 	x++;
	// 	y++;
	// }

	return (0);
}

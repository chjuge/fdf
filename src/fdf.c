/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:09:13 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/06 19:11:17 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
// #include "../minilibx_macos/mlx.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
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

	show_map(map);
	// printf("3 2 10 -> %d %d %d\n", 
	// 				map->head->next->next->p_head->next->next->next->x,
	// 				map->head->next->next->p_head->next->next->next->y,
	// 				map->head->next->next->p_head->next->next->next->z);
	if (!map)
		printf("error\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// while (x < 100)
	// {
	// 	my_mlx_pixel_put(&img, x, y, 0xffffff);
	// 	x++;
	// 	y++;
	// }
	draw_line(90, 90, 550, 550, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_string_put(mlx, mlx_win, 100, 100, 0xffffff, "Hello!");
	mlx_loop(mlx);
	return (0);
}

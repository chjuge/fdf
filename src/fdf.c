/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:09:13 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/12 18:13:28 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
// #include "../minilibx_macos/mlx.h"

int	get_translation(t_map *map, int w)
{
	int		x;
	t_line	*line;

	line = map->head;
	while (line->next)
	{
		line = line->next;
	}
	x = w - (int)line->p_head->x;
	return (x + 1);
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
	data.state = base_state(&data, data.map);
	drawmap(&data);
	mlx_key_hook(data.win, key_listener, &data);
	mlx_hook(data.win, 17, 1L << 17, close_program, &data);
	mlx_loop(data.mlx);
	return (0);
}

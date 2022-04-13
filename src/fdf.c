/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:09:13 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/13 17:59:16 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	init_data(t_data *data)
{
	data->h = 800;
	data->w = 800;
	data->state = base_state(data, data->map);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w, data->h, "fdf");
}

static int	check_file_fdf(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (s[len - 1] != 'f')
		return (0);
	if (s[len - 2] != 'd')
		return (0);
	if (s[len - 3] != 'f')
		return (0);
	if (s[len - 4] != '.')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || !check_file_fdf(argv[1]))
		return (0);
	data.map = init_map();
	data.map = fill_map(argv[1], data.map);
	if (!data.map)
	{
		write(2, "map error\n", 10);
		return (1);
	}
	init_data(&data);
	drawmap(&data);
	mlx_key_hook(data.win, key_listener, &data);
	mlx_hook(data.win, 17, 1L << 17, close_program, &data);
	mlx_loop(data.mlx);
	return (0);
}

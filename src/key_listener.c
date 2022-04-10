/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:57:51 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/10 12:34:50 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	close_program(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int	key_listener(int key, t_data *data)
{
	// printf("%d\n", key);
	if (key == 65307)
	{
		close_program(data);
			// data->img = mlx_new_image(data->mlx, 1920, 1080);
			// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 10, 10);
	}
	// (void)(data);
	// free_maps(data->map);
	return (0);
}
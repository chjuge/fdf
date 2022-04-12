/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:57:51 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/12 12:34:40 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	close_program(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int	check_for_rotation(int k)
{
	if (k == 113
	|| k == 119
	|| k == 97
	|| k == 115
	|| k == 122
	|| k == 120)
		return (1);
	return (0);
}

int	check_for_translation(int k)
{
	if (k == 65361
	|| k == 65362
	|| k == 65363
	|| k == 65364)
		return (1);
	return (0);	
}

int	check_for_scale(int k)
{
	if (k == 107
	|| k == 108)
		return (1);
	return (0);	
}
int	key_listener(int k, t_data *data)
{
	printf("%d\n", k);
	if (k == 65307)
		close_program(data);
	else if (check_for_rotation(k))
		change_rotation(k, data);
	else if (check_for_translation(k))
		change_translation(k, data);
	else if (check_for_scale(k))
		change_scale(k, data);
	else if (k == 99)
		clear_state(data);
	return (0);
}
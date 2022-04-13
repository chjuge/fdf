/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:57:51 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/13 17:02:04 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	close_program(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free_map(data->map);
	free(data->state);
	return (0);
}

static int	check_for_rotation(int k)
{
	if (k == Q
		|| k == W
		|| k == A
		|| k == S
		|| k == Z
		|| k == X)
		return (1);
	return (0);
}

static int	check_for_translation(int k)
{
	if (k == LEFT
		|| k == RIGHT
		|| k == TOP
		|| k == BOTTOM)
		return (1);
	return (0);
}

static int	check_for_scale(int k)
{
	if (k == K
		|| k == L)
		return (1);
	return (0);
}

int	key_listener(int k, t_data *data)
{
	if (k == ESC)
		close_program(data);
	else if (check_for_rotation(k))
		change_rotation(k, data);
	else if (check_for_translation(k))
		change_translation(k, data);
	else if (check_for_scale(k))
		change_scale(k, data);
	else if (k == C)
		clear_state(data);
	return (0);
}

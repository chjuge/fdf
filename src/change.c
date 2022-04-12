/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:12:55 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/12 19:02:10 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	change_rotation(int k, t_data *data)
{
	int	r;

	r = 1;
	if (k == 113)
		data->state->r_x -= r;
	else if (k == 119)
		data->state->r_x += r;
	else if (k == 97)
		data->state->r_y -= r;
	else if (k == 115)
		data->state->r_y += r;
	else if (k == 122)
		data->state->r_z -= r;
	else if (k == 120)
		data->state->r_z += r;
	redraw(data);
}

void	change_translation(int k, t_data *data)
{
	int	t;

	t = 5;
	if (k == 65361)
		data->state->t_x -= t;
	else if (k == 65363)
		data->state->t_x += t;
	else if (k == 65362)
		data->state->t_y -= t;
	else if (k == 65364)
		data->state->t_y += t;
	redraw(data);
}

void	change_scale(int k, t_data *data)
{
	int	sx;
	int	sy;

	sx = my_ceil(my_ceil(data->w, data->map->w), 30);
	sy = my_ceil(my_ceil(data->h, data->map->h), 30);
	if (k == 107)
	{
		data->state->s_x -= sx;
		data->state->s_y -= sy;
	}
	else if (k == 108)
	{
		data->state->s_x += sx;
		data->state->s_y += sy;
	}
	redraw(data);
}

void	clear_state(t_data *data)
{
	free(data->state);
	data->state = base_state(data, data->map);
	redraw(data);
}

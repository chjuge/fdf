/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:12:55 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/12 12:40:28 by mproveme         ###   ########.fr       */
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
	printf("change_r\n");
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
	printf("change_t\n");
	redraw(data);
}
void	change_scale(int k, t_data *data)
{
	int	s;

	s = 2;
		if (k == 107)
		data->state->t_x /= s;
	else if (k == 108)
		data->state->t_x *= s;
	redraw(data);
	printf("change_s\n");
}

void	clear_state(t_data *data)
{
	free(data->state);
	data->state = base_state(data, data->map);
	printf("clear_state\n");
	redraw(data);
}

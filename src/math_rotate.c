/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:47:15 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 18:54:15 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

float	*rotate_vector(float v[4], int mode, int angle)
{
	float	*new_v;

	if (mode == 1)
		new_v = rotate_x(v, angle);
	else if (mode == 2)
		new_v = rotate_y(v, angle);
	else
		new_v = rotate_z(v, angle);
	return (new_v);
}

t_point	*rotate_point(t_point *old_p, int mode, int angle)
{
	float	*old_v;
	float	*new_v;
	t_point	*new_p;

	old_v = point_to_vector(old_p);
	new_v = rotate_vector(old_v, mode, angle);
	new_p = vector_to_point(new_v);
	new_p->color = old_p->color;
	free(old_v);
	free(new_v);
	return (new_p);
}

t_line	*rotate_line(t_line *old_line, int mode, int angle)
{
	t_line	*new_line;
	t_point	*old;
	t_point	*new;

	new_line = malloc(sizeof(t_line));
	new_line->next = NULL;
	new_line->p_head = NULL;
	old = old_line->p_head;
	while (old)
	{
		new = rotate_point(old, mode, angle);
		add_back_point(&(new_line->p_head), new);
		old = old->next;
	}
	return (new_line);
}

t_map	*rotate_map(t_map *old_map, int mode, int angle)
{
	t_map	*new_map;
	t_line	*new_line;
	t_line	*old_line;

	new_map = malloc(sizeof(t_map));
	new_map->h = old_map->h;
	new_map->w = old_map->w;
	new_map->head = NULL;
	old_line = old_map->head;
	while (old_line)
	{
		new_line = rotate_line(old_line, mode, angle);
		add_back_line(&(new_map->head), new_line);
		old_line = old_line->next;
	}
	return (new_map);
}

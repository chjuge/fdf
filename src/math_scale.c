/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:47:08 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 18:50:42 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

float	*scale_vector(float v[4], int sx, int sy, int sz)
{
	float	*new_v;
	float	**m_scale;

	m_scale = get_m_scale(sx, sy, sz);
	new_v = m_v__multiply(m_scale, v);
	free_matrix(m_scale);
	return (new_v);
}

t_point	*scale_point(t_point *old_p, int sx, int sy, int sz)
{
	float	*old_v;
	float	*new_v;
	t_point	*new_p;

	old_v = point_to_vector(old_p);
	new_v = scale_vector(old_v, sx, sy, sz);
	new_p = vector_to_point(new_v);
	new_p->color = old_p->color;
	free(old_v);
	free(new_v);
	return (new_p);
}

t_line	*scale_line(t_line *old_line, int sx, int sy, int sz)
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
		new = scale_point(old, sx, sy, sz);
		add_back_point(&(new_line->p_head), new);
		old = old->next;
	}
	return (new_line);
}

t_map	*scale_map(t_map *old_map, int sx, int sy, int sz)
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
		new_line = scale_line(old_line, sx, sy, sz);
		add_back_line(&(new_map->head), new_line);
		old_line = old_line->next;
	}
	return (new_map);
}

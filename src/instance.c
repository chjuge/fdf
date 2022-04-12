/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:17:05 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/12 18:11:46 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

float	*instance_vector(float v[4], float **m_state, int x, int y)
{
	float	*new_v;

	new_v = m_v__multiply(m_state, v);
	new_v[0] += x;
	new_v[1] += y;
	return (new_v);
}

t_point	*instance_point(t_point *old_p, float **m_state, int x, int y)
{
	float	*old_v;
	float	*new_v;
	t_point	*new_p;

	old_v = point_to_vector(old_p);
	new_v = instance_vector(old_v, m_state, x, y);
	new_p = vector_to_point(new_v);
	new_p->color = old_p->color;
	free(old_v);
	free(new_v);
	return (new_p);
}

t_line	*instance_line(t_line *old_line, float **m_state, int x, int y)
{
	t_line	*new_line;
	t_point	*old;
	t_point	*new;

	new_line = init_line();
	old = old_line->p_head;
	while (old)
	{
		new = instance_point(old, m_state, x, y);
		add_back_point(&(new_line->p_head), new);
		old = old->next;
	}
	return (new_line);
}

t_map	*instance_map(t_map	*old_map, float	**m_state, int x, int y)
{
	t_map	*new_map;
	t_line	*new_line;
	t_line	*old_line;

	new_map = init_map();
	new_map->h = old_map->h;
	new_map->w = old_map->w;
	old_line = old_map->head;
	while (old_line)
	{
		new_line = instance_line(old_line, m_state, x, y);
		add_back_line(&(new_map->head), new_line);
		old_line = old_line->next;
	}
	free_matrix(m_state);
	return (new_map);
}

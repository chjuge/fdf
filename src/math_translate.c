/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:47:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 19:38:10 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

float	*translate_vector(float v[4], int dx, int dy, int dz)
{
	float	*new_v;
	float	**m_transl;

	m_transl = fill_m1();
	m_transl[0][3] = dx;
	m_transl[1][3] = dy;
	m_transl[2][3] = dz;
	new_v = m_v__multiply(m_transl, v);
	free_matrix(m_transl);
	return (new_v);
}

t_point	*translate_point(t_point *old_p, int dx, int dy, int dz)
{
	float	*old_v;
	float	*new_v;
	t_point	*new_p;

	old_v = point_to_vector(old_p);
	new_v = translate_vector(old_v, dx, dy, dz);
	new_p = vector_to_point(new_v);
	new_p->color = old_p->color;
	free(old_v);
	free(new_v);
	return (new_p);
}

t_line	*translate_line(t_line *old_line, int dx, int dy, int dz)
{
	t_line	*new_line;
	t_point	*old;
	t_point	*new;

	new_line = init_line();
	old = old_line->p_head;
	while (old)
	{
		new = translate_point(old, dx, dy, dz);
		add_back_point(&(new_line->p_head), new);
		old = old->next;
	}
	return (new_line);
}

t_map	*translate_map(t_map *old_map, int dx, int dy, int dz)
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
		new_line = translate_line(old_line, dx, dy, dz);
		add_back_line(&(new_map->head), new_line);
		old_line = old_line->next;
	}
	return (new_map);
}

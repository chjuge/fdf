/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:39:46 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/13 17:15:31 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

float	**state_matrix(t_state *s)
{
	float	**m;

	m = NULL;
	if (s->r_x)
		m = get_m_rotate_x(s->r_x);
	if (s->r_y)
	{
		if (m)
			m = m_m_multiply(m, get_m_rotate_y(s->r_y), 1);
		else
			m = get_m_rotate_y(s->r_y);
	}
	if (s->r_z)
	{
		if (m)
			m = m_m_multiply(m, get_m_rotate_z(s->r_z), 1);
		else
			m = get_m_rotate_z(s->r_z);
	}
	if (m)
		m = m_m_multiply(m, get_m_scale(s->s_x, s->s_y, s->s_z), 1);
	else
		m = get_m_scale(s->s_x, s->s_y, s->s_z);
	return (m);
}

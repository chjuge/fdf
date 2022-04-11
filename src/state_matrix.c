/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:39:46 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 20:47:03 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

float	**state_matrix(t_state *s)
{
	float	**m;

	m = get_m_scale(s->s_x, s->s_y, s->s_z);
	if (s->r_x)
		m = m_m_multiply(m, get_m_rotate_x(s->r_x), 1);
	if (s->r_y)
		m = m_m_multiply(m, get_m_rotate_y(s->r_y), 1);
	if (s->r_z)
		m = m_m_multiply(m, get_m_rotate_x(s->r_z), 1);
	if (s->t_x || s->t_y)
		m = m_m_multiply(m, get_m_translate(s->t_x, s->t_y, s->t_z), 1);
	return (m);
}

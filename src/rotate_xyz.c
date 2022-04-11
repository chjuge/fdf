/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_xyz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:40:14 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 18:54:08 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

float	*rotate_x(float v[4], int angle)
{
	float		**m_rotation;
	float		*new_v;

	m_rotation = get_m_rotate_x(angle);
	new_v = m_v__multiply(m_rotation, v);
	free_matrix(m_rotation);
	return (new_v);
}

float	*rotate_y(float v[4], int angle)
{
	float		**m_rotation;
	float		*new_v;

	m_rotation = get_m_rotate_y(angle);
	new_v = m_v__multiply(m_rotation, v);
	free_matrix(m_rotation);
	return (new_v);
}

float	*rotate_z(float v[4], int angle)
{
	float		**m_rotation;
	float		*new_v;

	m_rotation = get_m_rotate_z(angle);
	new_v = m_v__multiply(m_rotation, v);
	free_matrix(m_rotation);
	return (new_v);
}


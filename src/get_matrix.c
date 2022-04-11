/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:20:33 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 19:45:37 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

float	**get_m_scale(int sx, int sy, int sz)
{
	float	**m1;

	m1 = fill_m1();
	m1[0][0] = sx;
	m1[1][1] = sy;
	m1[2][2] = sz;
	return (m1);
}

float	**get_m_rotate_x(int angle)
{
	float	r;
	float	**m1;

	m1 = fill_m1();
	r = rad(angle);
	m1[1][1] = cos(r);
	m1[1][2] = -sin(r);
	m1[2][1] = sin(r);
	m1[2][2] = cos(r);
	return (m1);
}

float	**get_m_rotate_y(int angle)
{
	float	r;
	float	**m1;

	m1 = fill_m1();
	r = rad(angle);
	m1[0][0] = cos(r);
	m1[2][0] = -sin(r);
	m1[0][2] = sin(r);
	m1[2][2] = cos(r);
	return (m1);
}

float	**get_m_rotate_z(int angle)
{
	float	r;
	float	**m1;

	m1 = fill_m1();
	r = rad(angle);
	m1[0][0] = cos(r);
	m1[0][1] = -sin(r);
	m1[1][0] = sin(r);
	m1[1][1] = cos(r);
	return (m1);
}

float	**get_m_translate(int dx, int dy, int dz)
{
	float	**m1;

	m1 = fill_m1();
	m1[0][3] = dx;
	m1[1][3] = dy;
	m1[2][3] = dz;
	return (m1);
}

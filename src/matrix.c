/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:55:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/12 18:09:38 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

float	rad(int angle)
{
	float	rad;

	while (angle > 360)
		angle -= 360;
	rad = M_PI / 180 * angle;
	return (rad);
}

float	*m_v__multiply(float **m, float *v)
{
	float	*n_v;

	n_v = malloc(sizeof(float) * 4);
	n_v[0] = m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2] + m[0][3] * v[3];
	n_v[1] = m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2] + m[1][3] * v[3];
	n_v[2] = m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2] + m[2][3] * v[3];
	n_v[3] = m[3][0] * v[0] + m[3][1] * v[1] + m[3][2] * v[2] + m[3][3] * v[3];
	return (n_v);
}

float	**m_m_multiply(float **a, float **b, int mode)
{
	int		i;
	int		j;
	float	**m;

	i = 0;
	m = malloc(sizeof(float *) * 4);
	while (i < 4)
	{
		m[i] = malloc(sizeof(float) * 4);
		j = 0;
		while (j < 4)
		{
			m[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j]
				+ a[i][2] * b[2][j] + a[i][3] * b[3][j];
			j++;
		}
		i++;
	}
	if (mode)
	{
		free_matrix(a);
		free_matrix(b);
	}
	return (m);
}

float	**fill_m1(void)
{
	int		i;
	int		j;
	float	**m;

	i = 0;
	m = malloc(sizeof(float *) * 4);
	while (i < 4)
	{
		j = 0;
		m[i] = malloc(sizeof(float) * 4);
		while (j < 4)
		{
			if (i == j)
				m[i][j] = 1;
			else
				m[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:55:08 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 18:55:57 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

float	*point_to_vector(t_point *p)
{
	float	*vector;

	vector = malloc(sizeof(float) * 4);
	vector[0] = p->x;
	vector[1] = p->y;
	vector[2] = p->z;
	vector[3] = 1;
	return (vector);
}

t_point *vector_to_point(float vec[4])
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	p->next = NULL;
	p->x = vec[0];
	p->y = vec[1];
	p->z = vec[2];
	return (p);
}

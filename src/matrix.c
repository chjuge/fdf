/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:55:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/07 18:06:45 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	*point_to_vector(t_point *p)
{
	int	*vector;

	vector = malloc(sizeof(int) * 4);
	vector[0] = p->x;
	vector[1] = p->y;
	vector[2] = p->z;
	vector[3] = 1;
	return (vector);
}

t_point *vector_to_point(int vec[4])
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	p->next = NULL;
	p->x = vec[0];
	p->y = vec[1];
	p->z = vec[2];
	return (p);
}

int	*m_v__multiply(int **m, int *v)
{
	int	*n_v;

	n_v = malloc(sizeof(int) * 4);
	n_v[0] = m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2] + m[0][3] * v[3];
	n_v[1] = m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2] + m[1][3] * v[3];
	n_v[2] = m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2] + m[2][3] * v[3];
	n_v[3] = m[3][0] * v[0] + m[3][1] * v[1] + m[3][2] * v[2] + m[3][3] * v[3];
	return (n_v);
}

int	**fill_identity_m()
{
	int	i;
	int	j;
	int	**m;

	i = 0;
	m = malloc(sizeof(int*) * 4);
	while (i < 4)
	{
		j = 0;
		m[i] = malloc(sizeof(int) * 4);
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

int	*translate_vector(int v[4], int dx, int dy, int dz)
{
	int	*new_v;
	int	**m_transl;

	m_transl = fill_identity_m();
	m_transl[0][3] = dx;
	m_transl[1][3] = dy;
	m_transl[2][3] = dz;

	new_v = m_v__multiply(m_transl, v);
	return (new_v);
}

t_point	*translate_point(t_point *old_p, int dx, int dy, int dz)
{
	int	*old_v;
	int	*new_v;
	t_point	*new_p;

	// printf("\n\nold_p %d.%d.%d	", old_p->x, old_p->y, old_p->z);
	old_v = point_to_vector(old_p);
	new_v = translate_vector(old_v, dx, dy, dz);
	new_p = vector_to_point(new_v);
	// printf("\nnew_p %d.%d.%d	\n\n", new_p->x, new_p->y, new_p->z);
	return (new_p);
}

t_line	*translate_line(t_line *old_line, int dx, int dy, int dz)
{
	t_line	*new_line;
	t_point	*old;
	t_point	*new;

	// printf("--translate line starts---\n");
	// show_line(old_line);
	new_line = malloc(sizeof(t_line));
	new_line->next = NULL;
	new_line->p_head = NULL;
	old = old_line->p_head;
	while (old)
	{
		new = translate_point(old, dx, dy, dz);
		add_back_point(&(new_line->p_head), new);
		old = old->next;
	}
	show_line(new_line);
	// printf("--translate line ends-----\n");
	return (new_line);
}

t_map	*translate_map(t_map *old_map, int dx, int dy, int dz)
{
	t_map	*new_map;
	t_line	*new_line;
	t_line	*old_line;

	new_map = malloc(sizeof(t_map));
	new_map->h = old_map->h;
	new_map->w = old_map->w;
	new_map->head = NULL;
	old_line = old_map->head;
		// printf("--------------------\n");
	while (old_line)
	{
		// show_line(old_line);
		// printf("vodka\n");
		new_line = translate_line(old_line, dx, dy, dz);
		// show_line(new_line);
		// printf("seledka '%p'\n", new_line);
		add_back_line(&(new_map->head), new_line);
		// printf("ogurec\n");
		old_line = old_line->next;
	}

	return (new_map);
}
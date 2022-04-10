/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:55:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/10 20:18:47 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	free_matrix(float **m)
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		free(m[i]);
		i++;
	}
	free(m);
}

float	rad(int angle)
{
	float	rad;

	rad = M_PI / 180 * angle;
	return (rad);
}

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

float	**fill_identity_m()
{
	int	i;
	int	j;
	float	**m;

	i = 0;
	m = malloc(sizeof(float*) * 4);
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

float	*scale_vector(float v[4], int sx, int sy, int sz)
{
	float	*new_v;
	float	**m_scale;

	m_scale = fill_identity_m();
	m_scale[0][0] = sx;
	m_scale[1][1] = sy;
	m_scale[2][2] = sz;
	new_v = m_v__multiply(m_scale, v);
	free_matrix(m_scale);
	return (new_v);
}

float	*rotate_x(float v[4], int angle)
{
	float	r;
	float		**m_rotation;
	float		*new_v;

	m_rotation = fill_identity_m();
	r = rad(angle);
	m_rotation[1][1] = cos(r);
	m_rotation[1][2] = -sin(r);
	m_rotation[2][1] = sin(r);
	m_rotation[2][2] = cos(r);
	new_v = m_v__multiply(m_rotation, v);
	free_matrix(m_rotation);
	return (new_v);
}

float	*rotate_y(float v[4], int angle)
{
	float	r;
	float		**m_rotation;
	float		*new_v;

	m_rotation = fill_identity_m();
	r = rad(angle);
	m_rotation[0][0] = cos(r);
	m_rotation[2][0] = -sin(r);
	m_rotation[0][2] = sin(r);
	m_rotation[2][2] = cos(r);
	new_v = m_v__multiply(m_rotation, v);
	free_matrix(m_rotation);
	return (new_v);
}

float	*rotate_z(float v[4], int angle)
{
	float	r;
	float		**m_rotation;
	float		*new_v;

	m_rotation = fill_identity_m();
	r = rad(angle);
	m_rotation[0][0] = cos(r);
	m_rotation[0][1] = -sin(r);
	m_rotation[1][0] = sin(r);
	m_rotation[1][1] = cos(r);
	new_v = m_v__multiply(m_rotation, v);
	free_matrix(m_rotation);
	return (new_v);
}

float	*rotate_vector(float v[4], int mode, int angle)
{
	float	*new_v;

	if (mode == 1)
		new_v = rotate_x(v, angle);
	else if (mode == 2)
		new_v = rotate_y(v, angle);
	else
		new_v = rotate_z(v, angle);
	return (new_v);
}

float	*translate_vector(float v[4], int dx, int dy, int dz)
{
	float	*new_v;
	float	**m_transl;

	m_transl = fill_identity_m();
	m_transl[0][3] = dx;
	m_transl[1][3] = dy;
	m_transl[2][3] = dz;
	new_v = m_v__multiply(m_transl, v);
	free_matrix(m_transl);
	return (new_v);
}

t_point	*rotate_point(t_point *old_p, int mode, int angle)
{
	float	*old_v;
	float	*new_v;
	t_point	*new_p;

	// mode = 0;
	old_v = point_to_vector(old_p);
	new_v = rotate_vector(old_v, mode, angle);
	// new_v = rotate_vector(new_v, mode++, angle);
	// new_v = rotate_vector(old_v, mode++, angle);
	new_p = vector_to_point(new_v);
	new_p->color = old_p->color;
	free(old_v);
	free(new_v);
	return (new_p);
}

t_point	*rotate_point_alt(t_point *old_p, int angle)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	new->x = (old_p->x - old_p->y) * cos(rad(angle));
	new->y = (old_p->x + old_p->y) * sin(rad(angle)) - old_p->z;
	new->z = old_p->z;
	new->next = NULL;
	return (new);
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

t_point	*translate_point(t_point *old_p, int dx, int dy, int dz)
{
	float	*old_v;
	float	*new_v;
	t_point	*new_p;

	// printf("\n\nold_p %d.%d.%d	", old_p->x, old_p->y, old_p->z);
	old_v = point_to_vector(old_p);
	new_v = translate_vector(old_v, dx, dy, dz);
	new_p = vector_to_point(new_v);
	new_p->color = old_p->color;
	// printf("\nnew_p %d.%d.%d	\n\n", new_p->x, new_p->y, new_p->z);
	free(old_v);
	free(new_v);
	return (new_p);
}

t_line	*rotate_line(t_line *old_line, int mode, int angle)
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
		new = rotate_point(old, mode, angle);
		// (void)(mode);
		// new = rotate_point_alt(old, angle);
		add_back_point(&(new_line->p_head), new);
		old = old->next;
	}
	// show_line(new_line);
	return (new_line);
}

t_line	*translate_line(t_line *old_line, int dx, int dy, int dz)
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
		new = translate_point(old, dx, dy, dz);
		add_back_point(&(new_line->p_head), new);
		old = old->next;
	}
	// show_line(new_line);
	return (new_line);
}

t_line	*scale_line(t_line *old_line, int sx, int sy, int sz)
{
	t_line	*new_line;
	t_point	*old;
	t_point	*new;

	// printf("scale_line 1\n");
	new_line = malloc(sizeof(t_line));
	// printf("scale_line 2\n");
	new_line->next = NULL;
	new_line->p_head = NULL;
	old = old_line->p_head;
	// printf("scale_line 3\n");
	// int n = 0;
	while (old)
	{
		// printf("loop n = %d, p1\n", ++n);
		new = scale_point(old, sx, sy, sz);
		// printf("loop n = %d, p2\n", n);
		add_back_point(&(new_line->p_head), new);
		// printf("loop n = %d, p3\n", n);
		old = old->next;
		// printf("loop n = %d, p4\n", n);
	}
	// printf("scale_line 5\n");
	// show_line(new_line);
	return (new_line);
}

t_map	*rotate_map(t_map *old_map, int mode, int angle)
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
		new_line = rotate_line(old_line, mode, angle);
		add_back_line(&(new_map->head), new_line);
		old_line = old_line->next;
	}
	return (new_map);
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
	while (old_line)
	{
		new_line = translate_line(old_line, dx, dy, dz);
		add_back_line(&(new_map->head), new_line);
		old_line = old_line->next;
	}
	return (new_map);
}

t_map	*scale_map(t_map *old_map, int sx, int sy, int sz)
{
	t_map	*new_map;
	t_line	*new_line;
	t_line	*old_line;

	// printf("scale_map start\n");
	new_map = malloc(sizeof(t_map));
	// printf("scale_map 1\n");
	new_map->h = old_map->h;
	new_map->w = old_map->w;
	new_map->head = NULL;
	old_line = old_map->head;
	// printf("scale_map 2\n");
	// int n = 0;
	while (old_line)
	{
		// printf("loop 1, n = %d\n", ++n);
		new_line = scale_line(old_line, sx, sy, sz);
		// printf("loop 2\n");
		add_back_line(&(new_map->head), new_line);
		// printf("loop 3\n");
		old_line = old_line->next;
		// printf("loop 4\n");
	}
	// printf("scale_map start\n");
	return (new_map);
}

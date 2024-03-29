/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:19:23 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/12 18:05:57 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

t_point	*init_point(void)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	p->next = NULL;
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->color = WHITE;
	return (p);
}

t_line	*init_line(void)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	line->next = NULL;
	line->p_head = NULL;
	line->min = 0;
	line->max = 0;
	return (line);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->w = 0;
	map->h = 0;
	map->min = 0;
	map->max = 0;
	map->head = NULL;
	return (map);
}

t_state	*init_state(void)
{
	t_state	*s;

	s = malloc(sizeof(t_state));
	s->r_x = 0;
	s->r_y = 0;
	s->r_z = 0;
	s->s_x = 0;
	s->s_y = 0;
	s->s_z = 0;
	s->t_x = 0;
	s->t_y = 0;
	s->t_z = 0;
	return (s);
}

t_state	*base_state(t_data *data, t_map *map)
{
	t_state	*s;

	s = init_state();
	s->r_x = 35;
	s->r_y = -10;
	s->r_z = 0;
	s->s_x = my_ceil(data->w, data->map->w) / 2;
	s->s_y = my_ceil(data->h, data->map->h) / 2;
	s->s_z = get_scale_z(map);
	s->t_x = data->w / 5;
	s->t_y = data->h / 3;
	return (s);
}

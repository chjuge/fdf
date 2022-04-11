/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:34:07 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 18:59:01 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	show_point(t_point *p)
{
	printf("%.1f_%.1f  ", p->x, p->y);
}

void	show_line(t_line *line)
{
	t_point *p = line->p_head;

	while (p)
	{
		// printf("%d.%d.%d	", p->x, p->y, p->z);
		show_point(p);
		p = p->next;
	}
	printf("\n");	
}

void	show_map(t_map *map)
{
	t_line	*tmp;
	
	tmp = map->head;
	while (tmp)
	{
		// printf("'%p'\n", tmp);
		show_line(tmp);
		tmp = tmp->next;
	}
}
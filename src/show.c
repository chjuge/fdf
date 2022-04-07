/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:34:07 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/07 17:56:36 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	show_array(int *arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%5d	", arr[i]);
	printf("\n");
}

void	show_list(t_str *list)
{
	while (list)
	{
		show_array(list->arr, list->len);
		list = list->next;
	}
}

void	show_line(t_line *line)
{
	t_point *p = line->p_head;

	while (p)
	{
		// printf("%d.%d.%d	", p->x, p->y, p->z);
		printf("%3d", p->z);
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
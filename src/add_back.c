/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:33:02 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 19:05:29 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	add_back_line(t_line **head, t_line *new)
{
	t_line	*tmp;

	// printf("add_back_line start\n");
	if (!(*head))
	{
		// printf("add_back_line !head\n");
		// printf("no head!\n");
		// show_line(new);
		// printf("--------------------------\n");
		*head = new;
		return ;
	}
	// printf("add_back_line 1\n");
	tmp = *head;
	// printf("add_back_line 2\n");
	while (tmp->next)
	{
		// printf("---\n");
		// show_line(tmp);
		// sleep(1);
		tmp = tmp->next;
	}
	// printf("add_back_line 3\n");
	tmp->next = new;
	// printf("add_back_line end\n");
}

void	add_back_point(t_point **head, t_point *new)
{
	t_point	*tmp;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

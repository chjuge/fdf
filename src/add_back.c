/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:33:02 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/07 18:05:59 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	add_back(t_str **head, t_str *new)
{
	t_str	*tmp;

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

void	add_back_line(t_line **head, t_line *new)
{
	t_line	*tmp;

	if (!(*head))
	{
		// printf("no head!\n");
		// show_line(new);
		// printf("--------------------------\n");
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
	{
		// printf("---\n");
		// show_line(tmp);
		// sleep(1);
		tmp = tmp->next;
	}
	tmp->next = new;
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

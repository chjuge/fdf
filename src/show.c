/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:34:07 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/06 15:34:32 by mproveme         ###   ########.fr       */
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

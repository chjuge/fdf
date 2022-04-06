/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:31:29 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/06 15:31:55 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

t_str	*ft_lstnew(char *str)
{
	t_str	*new_el;

	new_el = malloc(sizeof(t_str));
	if (!new_el)
		return (0);
	new_el->arr = set_array(str, &new_el->len);
	new_el->next = NULL;
	return (new_el);
}

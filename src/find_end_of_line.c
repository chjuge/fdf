/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_end_of_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:56:53 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/02 22:57:12 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	find_end_of_line(char *remainder)
{
	int	i;

	i = 0;
	while (remainder[i])
	{
		if (remainder[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

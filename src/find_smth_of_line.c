/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smth_of_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:56:53 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/13 16:47:14 by mproveme         ###   ########.fr       */
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

int	find_lines_count(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	find_len_next_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\0')
		i--;
	return (i);
}

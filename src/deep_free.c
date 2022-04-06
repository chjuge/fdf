/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:37:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/06 15:38:02 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	deep_free(char **strs)
{
	int	lines;
	int	i;

	lines = find_lines_count(strs);
	i = 0;
	while (i < lines)
	{
		if (strs[i] && strs[i] != 0)
		{
			free(strs[i]);
		}
		i++;
	}
	free(strs);
}


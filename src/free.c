/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:37:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/12 12:22:28 by mproveme         ###   ########.fr       */
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
	free(strs[i]);
	free(strs);
}

void	free_matrix(float **m)
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		free(m[i]);
		i++;
	}
	free(m);
}

void	free_line(t_line *line)
{
	t_point	*p;
	t_point	*tmp;

	p = line->p_head;
	while (p)
	{
		tmp = p;
		p=p->next;
		free(tmp);
	}
	free(line);
}

void	free_map(t_map *map)
{
	t_line	*line;
	t_line	*tmp;

	line = map->head;
	while (line)
	{
		tmp = line;
		line = line->next;
		free_line(tmp);
	}
	free(map);
}
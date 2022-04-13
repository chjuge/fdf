/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:05:11 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/13 17:52:26 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	set_max_min_m(t_map *map, t_line *new_line)
{
	if (map->max < new_line->max)
		map->max = new_line->max;
	if (map->min > new_line->min)
		map->min = new_line->min;
}

t_map	*fill_map(char *param, t_map *map)
{
	int		fd;
	char	*str;
	t_line	*new_line;

	fd = open(param, O_RDONLY);
	if (fd < 0)
		return (NULL);
	new_line = NULL;
	str = get_next_line(fd);
	while (str)
	{
		str = ft_strtrim(str, "\n");
		new_line = ft_lstnew_line(str, map->h, &map->w);
		free(str);
		if (!new_line)
		{
			free_map(map);
			return (NULL);
		}
		add_back_line(&map->head, new_line);
		set_max_min_m(map, new_line);
		map->h++;
		str = get_next_line(fd);
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:05:11 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 19:28:28 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	find_cnt(char *str)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			cnt++;
		i++;
	}
	return (cnt + 1);
}

void	set_max_min_m(t_map *map, t_line *new_line)
{
	if (map->max < new_line->max)
		map->max = new_line->max;
	if (map->min > new_line->min)
		map->min = new_line->min;
}

t_map	*fill_map(char *param)
{
	int		fd;
	char	*str;
	t_map	*map;
	t_line	*new_line;

	map = init_map();
	fd = open(param, O_RDONLY);
	if (fd < 0)
		return NULL;
	new_line = NULL;
	while ((str = get_next_line(fd)))
	{
		str = ft_strtrim(str, "\n");
		new_line = ft_lstnew_line(str, map->h, &map->w);
		add_back_line(&map->head, new_line);
		set_max_min_m(map, new_line);
		free(str);
		map->h++;
	}
	return(map);
}
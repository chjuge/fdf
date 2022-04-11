/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:05:11 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 13:58:56 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	fill_list(char *map)
{
	int		fd;
	char	*str;
	t_str	*list;
	int		height;

	height = 0;
	list = NULL;
	fd = open(map, O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		str = ft_strtrim(str, "\n");
		add_back(&list, ft_lstnew(str));
		free(str);
		height++;
	}
	show_list(list);
	return (height);
}

t_map	*init_map()
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->w = 0;
	map->h = 0;
	map->head = NULL;
	return (map);
}

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

t_map	*fill_t_map(char *param)
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
		// printf("reading #%d, strlen: %d\n", ++n, find_cnt(str)); 
		str = ft_strtrim(str, "\n");
		// printf("1\n");
		new_line = ft_lstnew_line(str, map->h, &map->w);
		// printf("2\n");
		add_back_line(&map->head, new_line);
		set_max_min_m(map, new_line);
		free(str);
		// printf("4\n");
		map->h++;
	}
	return(map);
}
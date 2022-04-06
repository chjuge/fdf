/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:05:11 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/06 17:37:50 by mproveme         ###   ########.fr       */
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

t_map	*fill_t_map(char *param)
{
	int		fd;
	char	*str;
	t_map	*map;

	map = init_map();
	fd = open(param, O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		str = ft_strtrim(str, "\n");
		add_back_line(&map->head, ft_lstnew_line(str, map->h, &map->w));
		free(str);
		map->h++;
	}
	return(map);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:05:11 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/06 15:37:45 by mproveme         ###   ########.fr       */
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
		// printf ("%s",str);
		// printf("1\n");
		free(str);
		// printf("2\n");
		height++;
	}
	show_list(list);
	// if (!check_width(list))
	// {
		// full_free(list);
	// 	return (-1);
	// }
	return (height);
}
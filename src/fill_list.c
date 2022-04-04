/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:05:11 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/04 19:11:31 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static int	find_lines_count(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

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

int	*set_array(char *str, int *len)
{
	char	**vals;
	int		i;
	int		*arr;

	vals = ft_split(str, ' ');
	*len = find_lines_count(vals);
	arr = malloc(sizeof(int) * (*len));
	i = 0;
	while (i < *len)
	{
		arr[i] = ft_atoi(vals[i]);
		i++;
	}
	deep_free(vals);
	return (arr);
}

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

void	add_back(t_str **head, t_str *new)
{
	t_str	*tmp;

	if (!head)
	{
		head = &new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	fill_list(char *map)
{
	int		fd;
	char	*str;
	t_str	*list;
	int		height;

	height = 0;
	fd = open(map, O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		printf ("%s",str);
		add_back(&list, ft_lstnew(str));
		free(str);
		height++;
	}
	// if (!check_width(list))
	// {
		// full_free(list);
	// 	return (-1);
	// }
	return (height);
}
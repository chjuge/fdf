/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:31:29 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/10 20:10:55 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

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

int	check_for_coma(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (1);
		i++;
	}
	// printf("check_for_coma 0\n");
	return (0);
}

t_point *ft_lstnew_point(int x, int y, char *z)
{
	t_point	*p;
	char	**elems;

	p = malloc(sizeof(t_point));
	p->next = NULL;
	p->x = x;
	p->y = y;
	if (check_for_coma(z) == 0)
	{
		p->z = ft_atoi(z);
		p->color = WHITE;
		return (p);
	}
	elems = ft_split(z, ',');
	p->z = ft_atoi(elems[0]);
	p->color = strtol(elems[1], 0, 16);
	deep_free(elems);
	return (p);
}

t_line *ft_lstnew_line(char *str, int h, int *w)
{
	char	**vals;
	int		i;
	t_line	*line;

	vals = ft_split(str, ' ');
	// printf("str in line gen:	'%s'\n", str);
	i = 0;
	line = malloc(sizeof(t_line));
	line->p_head = NULL;
	line->next = NULL;
	while (vals[i])
	{
		add_back_point(&(line->p_head), ft_lstnew_point(i, h, vals[i]));
		i++;
	}
	// printf("%p\n", line);
	deep_free(vals);
	if (*w == 0)
		*w = i;
	if (*w != i)
	{
		// deep_free_1();
		printf("daite pravil'nuyu kartu, pidary\n");
		return (NULL);
	}
	return (line);
}


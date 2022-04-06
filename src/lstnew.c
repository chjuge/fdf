/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:31:29 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/06 19:11:33 by mproveme         ###   ########.fr       */
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

t_point *ft_lstnew_point(int x, int y, char *z)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	p->z = ft_atoi(z);
	// printf("in point-->	x: %d, y: %d, z(s): '%s', z: %d\n", x, y, z, p->z);
	p->next = NULL;
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


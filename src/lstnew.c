/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:31:29 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 19:01:58 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

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

t_line	*init_new_line()
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	line->p_head = NULL;
	line->next = NULL;
	line->max = 0;
	line->min = 0;
	return (line);
}

void	set_max_min_l(t_line *line, t_point *new)
{
	if (line->max < new->z)
		line->max = new->z;
	else if (line->min > new->z)
		line->min = new->z;
}

t_line	*ft_lstnew_line(char *str, int h, int *w)
{
	char	**vals;
	int		i;
	t_line	*line;
	t_point	*new;

	line = init_new_line();
	vals = ft_split(str, ' ');
	i = 0;
	while (vals[i])
	{
		new = ft_lstnew_point(i, h, vals[i]);
		add_back_point(&(line->p_head), new);
		set_max_min_l(line, new);
		i++;
	}
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


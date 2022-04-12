/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:31:29 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/12 17:09:20 by mproveme         ###   ########.fr       */
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

int	my_pow(int x, int y)
{
	int	res;

	if (y == 0)
		return (1);
	if (y == 1)
		return (x);
	res = x;
	while (y > 1)
	{
		res *= x;
		y--;
	}
	return (res);
}

int	get_color(char *str)
{
	int	len;
	int i;
	int res;

	i = 0;
	len = ft_strlen(str);
	res = 0;
	while (len > 2)
	{
		if (ft_isalpha(str[len - 1]))
			res +=  (ft_tolower(str[len - 1]) - 87) * my_pow(16, i);
		else
			res += (str[len - 1] - '0') * my_pow(16, i);
		len--;
		i++;
	}
	return (res);
}

t_point *ft_lstnew_point(int x, int y, char *z)
{
	t_point	*p;
	char	**elems;

	p = init_point();
	p->x = x;
	p->y = y;
	p->z = ft_atoi(z);
	if (check_for_coma(z) == 0)
		return (p);
	elems = ft_split(z, ',');
	// p->color = strtol(elems[1], 0, 16);
	p->color = get_color(elems[1]);
	printf("ecpected	16711680\nvalue		%d\n", p->color);
	deep_free(elems);
	return (p);
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

	line = init_line();
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


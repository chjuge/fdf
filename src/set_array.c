/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:37:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/06 15:37:56 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

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

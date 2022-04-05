/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:45:02 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/05 11:35:35 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static unsigned int	trim_count(char const *s1, unsigned int index,
char const *set, int add)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1[index] == set[i])
		{
			index += add;
			i = 0;
			continue ;
		}
		i++;
	}
	return (index);
}

char	*ft_strtrim(char *s1, char const *set)
{
	unsigned int	len;
	unsigned int	left;
	unsigned int	right;
	char			*new_str;

	len = ft_strlen(s1);
	left = trim_count(s1, 0, set, 1);
	if (left == len)
	{
		new_str = malloc(sizeof(char) * 1);
		if (!new_str)
			return (0);
		new_str[0] = '\0';
		return (new_str);
	}
	right = trim_count(s1, len - 1, set, -1);
	new_str = ft_substr(s1, left, right - left + 1);
	free(s1);
	return (new_str);
}

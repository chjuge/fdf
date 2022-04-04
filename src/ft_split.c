/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:20:20 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/04 19:15:06 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	skip_ch(const char *s, char c, int *i)
{
	while (s[*i] == c && s[*i])
		*i = *i + 1;
}

static int	find_count(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s[i] == '\0')
		return (0);
	skip_ch(s, c, &i);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			count++;
			skip_ch(s, c, &i);
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static int	find_len(const char *s, char c, int *ind)
{
	int	len;

	len = 0;
	while (s[*ind] != c && s[*ind])
	{
		len++;
		(*ind)++;
	}
	return (len);
}

static char	**alloc_err(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		strs_count;
	int		i;
	int		index;
	int		new_str_len;
	char	**new_arr;

	strs_count = find_count(s, c) + 1;
	new_arr = malloc(sizeof(char *) * strs_count);
	if (!new_arr)
		return (0);
	i = 0;
	index = 0;
	while (i < strs_count - 1)
	{
		skip_ch(s, c, &index);
		new_str_len = find_len(s, c, &index);
		new_arr[i] = malloc(new_str_len + 1);
		if (!new_arr[i])
			return (alloc_err(new_arr));
		ft_memcpy(new_arr[i], s + index - new_str_len, new_str_len);
		new_arr[i][new_str_len] = '\0';
		i++;
	}
	new_arr[i] = 0;
	return (new_arr);
}

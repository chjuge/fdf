/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:43:12 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/05 11:32:18 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start >= ft_strlen(s))
	{
		substr = malloc(sizeof(char) * 1);
		if (!substr)
			return (0);
		substr[0] = '\0';
	}
	else
	{
		if (len > ft_strlen(s))
			len = ft_strlen(s);
		substr = malloc(sizeof(char) * len + 1);
		if (!substr)
			return (0);
		if (ft_strlcpy(substr, s + start, len + 1))
			return (substr);
	}
	return (substr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:17:35 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/04 18:18:16 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char	tmp1;
	unsigned char	tmp2;

	while (len-- > 0)
	{
		tmp1 = (unsigned char) *s1++;
		tmp2 = (unsigned char) *s2++;
		if (tmp1 != tmp2)
			return (tmp1 - tmp2);
		if (tmp1 == '\0')
			return (0);
	}
	return (0);
}

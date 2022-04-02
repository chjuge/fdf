/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_remainder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:57:55 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/02 22:58:12 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

char	*create_new_remainder(char *old_rem, char *buf, int buf_len)
{
	char	*new_rem;
	int		len_old_rem;
	int		len_new_rem;

	len_old_rem = ft_strlen(old_rem);
	len_new_rem = len_old_rem + buf_len;
	new_rem = malloc(len_new_rem + 1);
	if (!new_rem)
		return (0);
	if (len_old_rem)
		ft_memcpy(new_rem, old_rem, len_old_rem);
	ft_memcpy(new_rem + len_old_rem, buf, buf_len);
	new_rem[len_new_rem] = '\0';
	free(old_rem);
	return (new_rem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_from_remainder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:58:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/02 22:58:37 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

char	*cut_from_remainder(char **old_rem)
{
	int		len_old_rem;
	int		len_new_rem;
	int		len_next_line;
	char	*next_line;
	char	*new_rem;

	len_old_rem = ft_strlen(*old_rem);
	len_next_line = find_len_next_line(*old_rem) + 1;
	len_new_rem = len_old_rem - len_next_line;
	next_line = malloc(len_next_line + 1);
	ft_memcpy(next_line, *old_rem, len_next_line);
	next_line[len_next_line] = '\0';
	new_rem = malloc(len_new_rem + 1);
	ft_memcpy(new_rem, (*old_rem) + len_next_line, len_new_rem);
	new_rem[len_new_rem] = '\0';
	free(*old_rem);
	*old_rem = new_rem;
	return (next_line);
}

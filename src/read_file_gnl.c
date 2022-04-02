/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:59:49 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/02 23:00:13 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	read_file(char **remainder, int fd)
{
	char	*buf;
	int		buf_len;
	int		check_end;
	int		count;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	check_end = -1;
	count = 0;
	buf_len = read(fd, buf, BUFFER_SIZE);
	buf[buf_len] = '\0';
	while (buf_len && check_end == -1)
	{
		check_end = find_end_of_line(buf);
		*remainder = create_new_remainder(*remainder, buf, buf_len);
		if (check_end < 0)
			buf_len = read(fd, buf, BUFFER_SIZE);
		count++;
	}
	free(buf);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:46:42 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/04 19:15:52 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_str
{
	struct s_str	*next;
	int				*arr;
	int				len;
}	t_str;

char	*get_next_line(int fd);
int		find_end_of_line(char *buf);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_atoi(const char *str);
char	*create_new_remainder(char *old_rem, char *buf, int buf_len);
char	*cut_from_remainder(char **old_rem);
int		read_file(char **remainder, int fd);
int		find_len_next_line(char *str);
char	**ft_split(char const *s, char c);
int		fill_list(char *map);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:46:42 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/07 12:00:19 by mproveme         ###   ########.fr       */
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
# include <string.h>
# include <stdlib.h>
// # include <mlx.h>
# include "../minilibx-linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_str
{
	struct s_str	*next;
	int				*arr;
	int				len;
}	t_str;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	struct	s_point *next;
}	t_point;

typedef struct	s_line
{
	struct s_line	*next;
	t_point			*p_head;
}	t_line;

typedef struct	s_map
{
	t_line	*head;
	int		w;
	int		h;
}	t_map;

char	*get_next_line(int fd);
int		find_end_of_line(char *buf);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strtrim(char *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
char	*create_new_remainder(char *old_rem, char *buf, int buf_len);
char	*cut_from_remainder(char **old_rem);
int		read_file(char **remainder, int fd);
int		find_len_next_line(char *str);
char	**ft_split(char const *s, char c);
int		fill_list(char *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(int x1, int y1, int x2, int y2, t_data *img);


t_str	*ft_lstnew(char *str);
void	add_back(t_str **head, t_str *new);

void	show_array(int *arr, int len);
void	show_list(t_str *list);
void	show_map(t_map *map);
void	show_line(t_line *line);

int		find_lines_count(char **strs);
void	deep_free(char **strs);
int		*set_array(char *str, int *len);

void	add_back_line(t_line **head, t_line *new);
void	add_back_point(t_point **head, t_point *new);
t_line	*ft_lstnew_line(char *str, int h, int *w);
t_point	*ft_lstnew_point(int x, int y, char *z);
t_map	*fill_t_map(char *param);

void	drawmap(t_map *map, t_data *img);

#endif

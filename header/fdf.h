/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:55:16 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/11 21:49:28 by mproveme         ###   ########.fr       */
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
# define WHITE 0xffffff

typedef struct	s_point
{
	struct	s_point	*next;
	float			x;
	float			y;
	float			z;
	int				color;
}	t_point;

typedef struct	s_line
{
	struct s_line	*next;
	t_point			*p_head;
	float			min;
	float			max;
}	t_line;

typedef struct	s_map
{
	t_line	*head;
	int		w;
	int		h;
	float	min;
	float	max;
}	t_map;

typedef	struct s_state
{
	int	s_x;
	int	s_y;
	int	s_z;
	int	r_x;
	int	r_y;
	int	r_z;
	int	t_x;
	int	t_y;
	int	t_z;
}	t_state;


typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*mlx_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;
	t_state	*state;
	float	**state_m;
	int		w;
	int		h;
}				t_data;

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
void	draw_line(t_point *p1, t_point *p2, t_data *img);


void	show_map(t_map *map);
void	show_line(t_line *line);
void	show_point(t_point *p);


int		find_lines_count(char **strs);
void	deep_free(char **strs);
int		*set_array(char *str, int *len);

void	add_back_line(t_line **head, t_line *new);
void	add_back_point(t_point **head, t_point *new);
t_line	*ft_lstnew_line(char *str, int h, int *w);
t_point	*ft_lstnew_point(int x, int y, char *z);
t_map	*fill_map(char *param);

void	drawmap(t_map *map, t_data *img);

float	*point_to_vector(t_point *p);
t_point *vector_to_point(float vec[4]);
float	*m_v__multiply(float **m, float *v);
float	**m_m_multiply(float **a, float **b, int mode);
float	*translate_vector(float v[4], int dx, int dy, int dz);
t_point	*translate_point(t_point *old_p, int dx, int dy, int dz);
t_line	*translate_line(t_line *old_line, int dx, int dy, int dz);
t_map	*translate_map(t_map *old_map, int dx, int dy, int dz);

t_map	*scale_map(t_map *old_map, int sx, int sy, int sz);
t_map	*rotate_map(t_map *old_map, int mode, int angle);

int	key_listener(int key, t_data *data);
int	close_program(t_data *data);


void	change_rotation(int k, t_data *data);
void	change_translation(int k, t_data *data);
void	change_scale(int k, t_data *data);

float	**fill_m1();
void	free_matrix(float **m);
float	**get_m_rotate_x(int angle);
float	**get_m_rotate_y(int angle);
float	**get_m_rotate_z(int angle);
float	**get_m_scale(int sx, int sy, int sz);
float	**get_m_translate(int dx, int dy, int dz);

float	rad(int angle);

float	*rotate_x(float v[4], int angle);
float	*rotate_y(float v[4], int angle);
float	*rotate_z(float v[4], int angle);
float	*rotate_vector(float v[4], int mode, int angle);


t_state *init_state();
t_map	*init_map();
t_line	*init_line();
t_point	*init_point();

float	**state_matrix(t_state *s);

float	*instance_vector(float v[4], float **m_state, int x, int y);
t_point	*instance_point(t_point *old_p, float **m_state, int x, int y);
t_line	*instance_line(t_line *old_line, float **m_state, int x, int y);
t_map	*instance_map(t_map	*old_map, float	**m_state, int x, int y);

int	my_ceil(int scale, int count);
int	get_scale_z(t_map	*map);

t_state	*base_state(t_data *data, t_map *map);

#endif

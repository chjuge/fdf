/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:55:16 by mproveme          #+#    #+#             */
/*   Updated: 2022/04/13 17:52:58 by mproveme         ###   ########.fr       */
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
# include <mlx.h>
// # include "../minilibx-linux/mlx.h"
# define WHITE 0xffffff
// # define LINUX
# ifdef LINUX
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define TOP 65362
#  define BOTTOM 65364
#  define Q 113
#  define W 119
#  define A 97
#  define S 115
#  define Z 122
#  define X 120
#  define C 99
#  define K 107
#  define L 108
# else 
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define TOP 126
#  define BOTTOM 125
#  define Q 12
#  define W 13
#  define A 0
#  define S 1
#  define Z 6
#  define X 7
#  define C 8
#  define K 40
#  define L 37
# endif

typedef struct s_point
{
	struct s_point	*next;
	float			x;
	float			y;
	float			z;
	int				color;
}	t_point;

typedef struct s_line
{
	struct s_line	*next;
	t_point			*p_head;
	float			min;
	float			max;
}	t_line;

typedef struct s_map
{
	t_line	*head;
	int		w;
	int		h;
	float	min;
	float	max;
}	t_map;

typedef struct s_state
{
	int	r_x;
	int	r_y;
	int	r_z;
	int	s_x;
	int	s_y;
	int	s_z;
	int	t_x;
	int	t_y;
	int	t_z;
}	t_state;

typedef struct s_data {
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
}	t_data;

/* ************************************************************************** */
/* *****	add_back.c	***** */
void	add_back_line(t_line **head, t_line *new);
void	add_back_point(t_point **head, t_point *new);
/* ************************** */
/* *****	change.c	***** */
void	change_rotation(int k, t_data *data);
void	change_translation(int k, t_data *data);
void	change_scale(int k, t_data *data);
void	clear_state(t_data *data);
/* ************************** */
/* *****	draw_line.c	***** */
void	draw_line(t_point *p1, t_point *p2, t_data *img);
/* ************************** */
/* *****	drawmap.c	***** */
void	drawmap(t_data *data);
void	redraw(t_data *data);
/* ************************** */
/* *****	fill_map.c	***** */
t_map	*fill_map(char *param, t_map *map);
/* ************************** */
/* *****	find_smth_of_line.c	***** */
int		find_end_of_line(char *buf);
int		find_len_next_line(char *str);
int		find_lines_count(char **strs);
/* ********************************** */
/* *****	free.c	***** */
void	deep_free(char **strs);
void	free_matrix(float **m);
void	free_line(t_line *line);
void	free_map(t_map *map);
/* ********************** */
/* *****	ft_atoi.c	***** */
int		ft_atoi(const char *str);
/* ************************** */
/* *****	ft_split.c	***** */
char	**ft_split(char const *s, char c);
/* ************************** */
/* *****	ft_strlcpy.c	***** */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/* ************************** */
/* *****	ft_strncmp.c	***** */
int		ft_strncmp(const char *s1, const char *s2, size_t len);
/* ****************************** */
/* *****	ft_strtrim.c	***** */
char	*ft_strtrim(char *s1, char const *set);
/* ****************************** */
/* *****	get_next_line.c	***** */
char	*get_next_line(int fd);
/* ****************************** */
/* *****	ft_substr.c	***** */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/* ****************************** */
/* *****	gnl_utils.c	***** */
char	*create_new_remainder(char *old_rem, char *buf, int buf_len);
char	*cut_from_remainder(char **old_rem);
int		read_file(char **remainder, int fd);
/* ************************** */
/* *****	initialization.c	***** */
t_point	*init_point(void);
t_line	*init_line(void);
t_map	*init_map(void);
t_state	*init_state(void);
t_state	*base_state(t_data *data, t_map *map);
/* ********************************** */
/* *****	instance.c	***** */
float	*instance_vector(float v[4], float **m_state, int x, int y);
t_point	*instance_point(t_point *old_p, float **m_state, int x, int y);
t_line	*instance_line(t_line *old_line, float **m_state, int x, int y);
t_map	*instance_map(t_map	*old_map, float	**m_state, int x, int y);
/* ************************** */
/* *****	key_listener.c	***** */
int		key_listener(int key, t_data *data);
int		close_program(t_data *data);
/* ****************************** */
/* *****	lstnew.c	***** */
t_line	*ft_lstnew_line(char *str, int h, int *w);
t_point	*ft_lstnew_point(int x, int y, char *z);
/* ************************** */
/* *****	matrix.c	***** */
float	rad(int angle);
float	*m_v__multiply(float **m, float *v);
float	**m_m_multiply(float **a, float **b, int mode);
float	**fill_m1(void);
/* ************************** */
/* *****	my_mlx_pixel_put.c	***** */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
/* ********************************** */
/* *****	point_vector.c	***** */
float	*point_to_vector(t_point *p);
t_point	*vector_to_point(float vec[4]);
/* ****************************** */
/* *****	rotate_xyz.c	***** */
float	*rotate_x(float v[4], int angle);
float	*rotate_y(float v[4], int angle);
float	*rotate_z(float v[4], int angle);
/* ****************************** */
/* *****	state_matrix.c	***** */
float	**state_matrix(t_state *s);
/* ****************************** */
/* *****	get_matrix.c	***** */
float	**get_m_rotate_x(int angle);
float	**get_m_rotate_y(int angle);
float	**get_m_rotate_z(int angle);
float	**get_m_scale(int sx, int sy, int sz);
float	**get_m_translate(int dx, int dy, int dz);
/* ****************************** */
/* *****	utils1.c	***** */
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_tolower(int ch);
int		ft_isalpha(int c);
/* ************************** */
/* *****	utils2.c	***** */
int		my_ceil(int scale, int count);
int		my_pow(int x, int y);
int		get_scale_z(t_map	*map);
int		get_color(char *str);
int		get_translation(t_map *map, int w);
/* ************************** */
/* ************************************************************************** */
#endif

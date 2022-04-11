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

typedef struct	s_str
{
	struct s_str	*next;
	int				*arr;
	int				len;
}	t_str;

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

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*mlx_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;
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



t_str	*ft_lstnew(char *str);
void	add_back(t_str **head, t_str *new);

void	show_array(int *arr, int len);
void	show_list(t_str *list);
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
t_map	*fill_t_map(char *param);

void	drawmap(t_map *map, t_data *img);

float	*point_to_vector(t_point *p);
t_point *vector_to_point(float vec[4]);
float	*m_v__multiply(float **m, float *v);
float	**fill_identity_m();
float	*translate_vector(float v[4], int dx, int dy, int dz);
t_point	*translate_point(t_point *old_p, int dx, int dy, int dz);
t_line	*translate_line(t_line *old_line, int dx, int dy, int dz);
t_map	*translate_map(t_map *old_map, int dx, int dy, int dz);

t_map	*scale_map(t_map *old_map, int sx, int sy, int sz);
t_map	*rotate_map(t_map *old_map, int mode, int angle);

int	key_listener(int key, t_data *data);
int	close_program(t_data *data);

#endif

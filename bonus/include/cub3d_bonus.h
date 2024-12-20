/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:30:04 by ael-hara          #+#    #+#             */
/*   Updated: 2024/11/26 12:29:33 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include </Users/ael-hara/MLX42/include/MLX42/MLX42.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}	t_node;

typedef struct s_player_data
{
	double		po_x;
	double		po_y;
	double		player_speed;
	double		player_angle;
	double		rotation_speed;
	double		ray_distance;
	double		distance;
	double		vertical_x;
	double		vertical_y;
	double		horizontal_x;
	double		horizontal_y;
	double		x_cord;
}	t_player_data;

typedef struct s_color_data
{
	int	red;
	int	green;
	int	blue;
}	t_color_data;

typedef struct s_texture_data
{
	mlx_texture_t	*texture_n;
	mlx_texture_t	*texture_s;
	mlx_texture_t	*texture_e;
	mlx_texture_t	*texture_w;
}	t_texture_data;

typedef struct s_map_data
{
	char			**map;
	int				vertical;
	int				count_textures;
	int				count_colors;
	int				map_height;
	int				elements;
	int				fd;
	int				max_width;
	char			**comp1;
	char			**comp2;
	int				count_directions;
	t_node			*collected_data;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*img2;
	mlx_texture_t	*def;
	t_texture_data	**shot_sprites;
	t_texture_data	**reload_sprites;
	t_color_data	*floor;
	t_color_data	*ceiling;
	t_player_data	*player;
	t_texture_data	*textures;
	int				player_x;
	int				player_y;
	double			wall_hit_x;
	double			wall_hit_y;
	double			wall_hit_x_h;
	double			wall_hit_y_h;
	double			wall_hit_x_v;
	double			wall_hit_y_v;
	mlx_texture_t	*choosen_texture;
}	t_map_data;

typedef struct s_split_args
{
	char		**tab;
	const char	*s;
	char		c;
	int			i;
}	t_split_args;

char			*get_next_line(int fd, t_map_data *map);
char			*ft_strchr(char *s, int c);
int				ft_strlen(char *s);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
char			*ft_strjoin(char *s1, char *s2, t_map_data *map);
char			*ft_strjoin2(char *s1, char *s2, t_map_data *map);
char			*ft_strdup(char *s1, t_map_data *map);
char			**ft_split2(char const *s, char c, t_map_data *map);
char			**ft_split(char const *s, t_map_data *map);;
int				ft_isspace(int c);
int				ft_strncmp(char *s1, char *s2, size_t n);
int				count_strings(char **s);
int				ft_isdigit(int c);
int				ft_atoi(char *number, t_map_data *map);
void			error(char	*message, int fd, t_map_data *map);
void			store_no_so(char *type, char *path, t_map_data *map);
void			store_we_ea(char *type, char *path, t_map_data *map);
void			check_file_extention(char *file, t_map_data *map);
int				is_empty_line(char *line);
int				et_map_width(char *line);
void			check_color_format(char *format, t_map_data *map, char type);
int				element_type(char *line, t_map_data *map);
void			check_wall(char *line, t_map_data *map);
void			check_map_matrix(t_map_data *map, char *line, int j);
void			load_file(char *file, t_map_data *map);
void			move_up(t_map_data *map, double old_x, double old_y);
void			move_down(t_map_data *map, double old_x, double old_y);
void			move_left(t_map_data *map, double old_x, double old_y);
void			move_right(t_map_data *map, double old_x, double old_y);
void			fill_matrix(char *file, t_map_data *map);
int				get_map_width(char *line);
void			load_shot_sprites(t_map_data *map);
void			load_reload_sprites(t_map_data *map);
char			*ft_itoa(int n, t_map_data *map);
void			*ft_memset(void *b, int c, size_t len);
void			free_allocated(t_node **garbage_collector, t_map_data *map);

void			*ft_lstnew(void *content);
void			ft_lstadd_back(t_node **list, t_node *new);
void			free_allocated(t_node **garbage_collector, t_map_data *map);
void			*ft_malloc(size_t size, t_map_data *map);
void			init_scene(t_map_data *map);
void			last_char_check(t_map_data *map, char *line, size_t i);
void			free_textures(t_map_data *map);
void			free_reload_sprites(t_map_data *map);
void			free_shot_sprites(t_map_data *map);

/////////////////////////raycasting ////////////////////////

# define WIDTH 1920
# define HEIGHT 1080
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF 
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define SKY_BLUE 0x87CEEBFF
# define FOV 60
# define GRID_SIZE 512
# define PLAYER_SIZE 4
# define PI 3.14159265359
# define ROTATION_SPEED 0.2
# define OFFSET  2
# define RELOAD_FRAMES 63
# define SHOT_FRAMES 8
# define MOUSE_SPEED 0.002
# define EPSILON 0.000001
# define MAX_DISTANCE 80

enum e_direction
{
	UP = 1,
	DOWN = 2,
	RIGHT = 3,
	LEFT = 4
};

typedef struct s_intersection
{
	double	angle;
	int		facing_down;
	int		facing_up;
	int		facing_right;
	int		facing_left;
	double	x_step;
	double	y_step;
	int		wall_hit_x;
	int		wall_hit_y;
	float	next_horizontal_x;
	float	next_horizontal_y;
	float	x_to_check;
	float	y_to_check;
	int		check_x;
	int		check_y;
}	t_intersection;

typedef struct s_vintersection
{
	double	angle;
	int		facing_down;
	int		facing_up;
	int		facing_right;
	int		facing_left;
	double	x_step;
	double	y_step;
	int		wall_hit_x;
	int		wall_hit_y;
	float	next_vertical_x;
	float	next_vertical_y;
	float	y_to_check;
	float	x_to_check;
	int		check_x;
	int		check_y;
}	t_vintersection;

typedef struct s_draw_data
{
	double	start;
	double	end;
	int		tex_y;
	int		color_b;
	double	step;
	double	tex_pos;
}	t_draw_data;

void			raycasting_scene(t_map_data *map);
int				border(t_map_data *map, int border_x, int border_y);
int				ft_border(t_map_data *map);
void			draw_ray(void *param);
void			map_init(t_map_data *map);
void			ft_move_player(t_map_data *map, int direction);
double			wall_projection(t_map_data *map);
void			init_vertical(t_vintersection *inter, int x, int y,
					double angle);
int				check_valid_vertical(t_vintersection *inter, t_map_data *map);
double			wall_hit_vertical(t_vintersection *inter, t_map_data *map,
					int x, int y);
double			wall_hit_horizontal(t_intersection *inter, t_map_data *map,
					int x, int y);
int				check_valid(t_intersection *inter, t_map_data *map);
void			min_intersection(t_map_data *map, int x, int y, double angle);
double			correct_distance(double distance, double angle,
					double player_angle);
int				get_rgba(int r, int g, int b, int a);
void			background(t_map_data *map);
int				ft_adjust_color(int color);
void			draw_line(t_map_data *map, int x, double wall_height,
					int *image_px);
void			get_xcord(t_map_data *map,
					mlx_texture_t *texture);
double			normal_angle(double angle);
void			min_intersection(t_map_data *map, int x, int y, double angle);
void			draw_ray(void *param);
void			endering_logic(t_map_data *map, double *angle, int i);
mlx_texture_t	*choose_texture(t_map_data *map, double angle);
void			ft_move(mlx_key_data_t key, void *param);
void			spirite(void *param);
void			cursor_func(double xpos, double ypos, void *param);
void			error_handling(int flag, t_map_data *map);
void			ft_mlx_start(t_map_data *map);
void			ft_close(void *param);
void			ft_rotate_player(t_map_data *map, mlx_key_data_t key);

#endif
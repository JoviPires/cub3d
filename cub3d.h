/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:30:49 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/26 14:30:49 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define BUFFER_SIZE 1024
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		set;
}	t_color;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	double	player_x;
	double	player_y;
	char	player_dir;
}	t_map;

typedef struct s_scene
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_color	floor;
	t_color	ceiling;
	t_map	map;
}	t_scene;

typedef struct s_tex
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	t_tex	tex[4];
	t_scene	scene;
}	t_game;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

/*--- check_map.c ---*/
int		check_cub(const char *file);

/*--- gnl.c ---*/
char	*fill_line(int fd, char *backup, char *buffer);
char	*set_line(char **backup);
char	*get_next_line(int fd);
int		count_lines(char *file);

/*--- parse_file.c ---*/
int		parse_file(char *file, t_scene *scene);
int		dispatch_line(char *line, t_scene *scene, int *map_started);
int		is_empty_line(char *line);

/*--- parse_map.c ---*/
int		parse_map_lines(char *file, t_scene *scene);
int		build_grid(t_list *lines, t_map *map);
char	*pad_line(char *line, int width);

/*--- parse_elements.c ---*/
int		parse_element(char *line, t_scene *scene);
int		parse_texture(char *line, char **dest);
int		parse_color_line(char *line, t_color *color);
int		is_element(char *line);

/*--- parse_color.c ---*/
int		parse_color(char *str, t_color *color);
int		validate_rgb(char *str);
int		count_parts(char **parts);
void	free_split(char **parts);

/*--- game.c ---*/
void	game_init(t_game *game);

/*--- events.c ---*/
int		handle_key_press(int keycode, t_game *game);
int		close_window(t_game *game);

/*--- render.c ---*/
int		render(t_game *game);
void	put_pixel(t_game *game, int x, int y, int color);
void	draw_column(t_game *game, t_ray *ray, int x);

/*--- raycasting.c ---*/
void	cast_rays(t_game *game);

/*--- textures.c ---*/
int		load_textures(t_game *game);
int		get_tex_index(t_ray *ray);
int		get_tex_x(t_game *game, t_ray *ray, int tex_i);
int		get_tex_pixel(t_tex *tex, int x, int y);

/*--- error.c ---*/
int		err_exit(char *msg, t_scene *scene);
void	free_scene(t_scene *scene);
void	free_grid(char **grid, int height);

/*--- validate_map.c ---*/
int		validate_map(t_map *map);
int		check_chars_and_spawn(t_map *map);

/*--- flood_fill.c ---*/
int		check_closed(t_map *map);
int		flood_fill(char **grid, int x, int y, t_map *map);
char	**copy_grid(char **grid, int height);

#endif

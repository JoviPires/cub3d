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

# define BUFFER_SIZE 1024

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

/*--- check_map.c ---*/
int		check_cub(const char *file);

/*--- gnl.c ---*/
char	*fill_line(int fd, char *backup, char *buffer);
char	*set_line(char **backup);
char	*get_next_line(int fd);
int		count_lines(char *file);

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

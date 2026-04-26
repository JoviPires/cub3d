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

/*--- error.c ---*/
int		err_exit(char *msg, t_scene *scene);
void	free_scene(t_scene *scene);
void	free_grid(char **grid, int height);

#endif

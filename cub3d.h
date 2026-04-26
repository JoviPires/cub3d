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

/*--- check_map.c ---*/
int		check_cub(const char *file);

/*--- gnl.c ---*/
char	*fill_line(int fd, char *backup, char *buffer);
char	*set_line(char **backup);
char	*get_next_line(int fd);
int		count_lines(char *file);

#endif

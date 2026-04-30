/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:42:10 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/29 21:54:26 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	move_fb(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x + game->dir_x * speed;
	new_y = game->pos_y + game->dir_y * speed;
	if (game->scene.map.grid[(int)game->pos_y][(int)new_x] != '1')
		game->pos_x = new_x;
	if (game->scene.map.grid[(int)new_y][(int)game->pos_x] != '1')
		game->pos_y = new_y;
}

static void	move_strafe(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x + game->plane_x * speed;
	new_y = game->pos_y + game->plane_y * speed;
	if (game->scene.map.grid[(int)game->pos_y][(int)new_x] != '1')
		game->pos_x = new_x;
	if (game->scene.map.grid[(int)new_y][(int)game->pos_x] != '1')
		game->pos_y = new_y;
}

static void	rotate(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(angle) - game->dir_y * sin(angle);
	game->dir_y = old_dir_x * sin(angle) + game->dir_y * cos(angle);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(angle)
		- game->plane_y * sin(angle);
	game->plane_y = old_plane_x * sin(angle)
		+ game->plane_y * cos(angle);
}

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_W)
		move_fb(game, MOVE_SPEED);
	if (keycode == KEY_S)
		move_fb(game, -MOVE_SPEED);
	if (keycode == KEY_A)
		move_strafe(game, -MOVE_SPEED);
	if (keycode == KEY_D)
		move_strafe(game, MOVE_SPEED);
	if (keycode == KEY_LEFT)
		rotate(game, -ROT_SPEED);
	if (keycode == KEY_RIGHT)
		rotate(game, ROT_SPEED);
	return (0);
}

int	close_window(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->tex[i].img)
			mlx_destroy_image(game->mlx, game->tex[i].img);
	}
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_scene(&game->scene);
	exit(0);
	return (0);
}

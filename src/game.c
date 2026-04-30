/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:07:14 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/28 21:25:21 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_dir_ns(t_game *game)
{
	if (game->scene.map.player_dir == 'N')
	{
		game->dir_y = -1;
		game->plane_x = 0.66;
	}
	else
	{
		game->dir_y = 1;
		game->plane_x = -0.66;
	}
}

static void	set_dir_ew(t_game *game)
{
	if (game->scene.map.player_dir == 'E')
	{
		game->dir_x = 1;
		game->plane_y = 0.66;
	}
	else
	{
		game->dir_x = -1;
		game->plane_y = -0.66;
	}
}

static void	init_camera(t_game *game)
{
	game->pos_x = game->scene.map.player_x;
	game->pos_y = game->scene.map.player_y;
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0;
	if (game->scene.map.player_dir == 'N'
		|| game->scene.map.player_dir == 'S')
		set_dir_ns(game);
	else
		set_dir_ew(game);
}

void	game_init(t_game *game)
{
	game->width = 1280;
	game->height = 720;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, "cub3d");
	game->img = mlx_new_image(game->mlx, game->width, game->height);
	game->img_data = mlx_get_data_addr(
			game->img, &game->bpp, &game->line_len, &game->endian);
	init_camera(game);
}

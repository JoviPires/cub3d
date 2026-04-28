/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:07:14 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/28 20:31:27 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	game_init(t_game *game)
{
	game->width = 1280;
	game->height = 720;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, "cub3d");
	game->img = mlx_new_image(game->mlx, game->width, game->height);
	game->img_data = mlx_get_data_addr(
			game->img, &game->bpp, &game->line_len, &game->endian);
}

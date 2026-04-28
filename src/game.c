/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:07:14 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/28 19:08:08 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1280, 720, "cub3d");
	game->img = mlx_new_image(game->mlx, 1280, 720);
	game->img_data = mlx_get_data_addr(
			game->img, &game->bpp, &game->line_len, &game->endian);
}

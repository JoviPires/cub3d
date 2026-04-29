/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:09:14 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/28 21:25:21 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return ;
	offset = (y * game->line_len) + (x * (game->bpp / 8));
	dst = game->img_data + offset;
	*(unsigned int *)dst = color;
}

static int	rgb_to_int(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

int	render(t_game *game)
{
	int	x;
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = rgb_to_int(game->scene.ceiling);
	floor_color = rgb_to_int(game->scene.floor);
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (y < game->height / 2)
				put_pixel(game, x, y, ceiling_color);
			else
				put_pixel(game, x, y, floor_color);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

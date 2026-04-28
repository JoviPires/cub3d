/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:09:14 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/28 20:21:54 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * game->line_len) + (x * (game->bpp / 8));
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return ;
	dst = game->img_data + offset;
	*(unsigned int *)dst = color;
}


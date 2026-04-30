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

static int	get_wall_color(t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
		return (0xCC3333);
	if (ray->side == 0 && ray->ray_dir_x <= 0)
		return (0x33CC33);
	if (ray->side == 1 && ray->ray_dir_y > 0)
		return (0x3333CC);
	return (0xCCCC33);
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	int	ceil_c;
	int	floor_c;
	int	wall_c;
	int	y;

	ceil_c = rgb_to_int(game->scene.ceiling);
	floor_c = rgb_to_int(game->scene.floor);
	wall_c = get_wall_color(ray);
	y = -1;
	while (++y < ray->draw_start)
		put_pixel(game, x, y, ceil_c);
	while (y <= ray->draw_end)
	{
		put_pixel(game, x, y, wall_c);
		y++;
	}
	while (y < game->height)
	{
		put_pixel(game, x, y, floor_c);
		y++;
	}
}

int	render(t_game *game)
{
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

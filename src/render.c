/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:09:14 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/29 21:54:26 by jpires-n         ###   ########.fr       */
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

static void	draw_wall_stripe(t_game *game, t_ray *ray, int x)
{
	int		tex_i;
	int		tex_x;
	int		y;
	double	step;
	double	tex_pos;

	tex_i = get_tex_index(ray);
	tex_x = get_tex_x(game, ray, tex_i);
	step = 1.0 * game->tex[tex_i].height / ray->line_height;
	tex_pos = (ray->draw_start - game->height / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		put_pixel(game, x, y, get_tex_pixel(&game->tex[tex_i],
				tex_x, (int)tex_pos % game->tex[tex_i].height));
		tex_pos += step;
		y++;
	}
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	int	y;

	y = -1;
	while (++y < ray->draw_start)
		put_pixel(game, x, y, rgb_to_int(game->scene.ceiling));
	draw_wall_stripe(game, ray, x);
	y = ray->draw_end + 1;
	while (y < game->height)
	{
		put_pixel(game, x, y, rgb_to_int(game->scene.floor));
		y++;
	}
}

int	render(t_game *game)
{
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

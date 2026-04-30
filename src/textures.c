/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:00:00 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/29 21:00:00 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	load_one_tex(t_game *game, t_tex *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
		return (1);
	tex->data = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	return (0);
}

int	load_textures(t_game *game)
{
	if (load_one_tex(game, &game->tex[0], game->scene.no)
		|| load_one_tex(game, &game->tex[1], game->scene.so)
		|| load_one_tex(game, &game->tex[2], game->scene.we)
		|| load_one_tex(game, &game->tex[3], game->scene.ea))
	{
		ft_putstr_fd("Error\nFailed to load texture\n", 2);
		return (1);
	}
	return (0);
}

int	get_tex_index(t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
		return (3);
	if (ray->side == 0 && ray->ray_dir_x <= 0)
		return (2);
	if (ray->side == 1 && ray->ray_dir_y > 0)
		return (1);
	return (0);
}

int	get_tex_x(t_game *game, t_ray *ray, int tex_i)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * game->tex[tex_i].width);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		tex_x = game->tex[tex_i].width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y > 0)
		tex_x = game->tex[tex_i].width - tex_x - 1;
	return (tex_x);
}

int	get_tex_pixel(t_tex *tex, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	dst = tex->data + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:30:00 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/26 16:30:00 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_spawn(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || is_spawn(c));
}

static int	save_spawn(t_map *map, int x, int y, int *count)
{
	map->player_x = (double)x + 0.5;
	map->player_y = (double)y + 0.5;
	map->player_dir = map->grid[y][x];
	(*count)++;
	if (*count > 1)
		return (1);
	return (0);
}

int	check_chars_and_spawn(t_map *map)
{
	int	x;
	int	y;
	int	spawn_count;

	spawn_count = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (!is_valid_char(map->grid[y][x]))
				return (1);
			if (is_spawn(map->grid[y][x]))
			{
				if (save_spawn(map, x, y, &spawn_count))
					return (1);
			}
		}
	}
	if (spawn_count != 1)
		return (1);
	return (0);
}

int	validate_map(t_map *map)
{
	if (!map->grid || map->height == 0 || map->width == 0)
		return (1);
	if (check_chars_and_spawn(map))
		return (1);
	return (0);
}

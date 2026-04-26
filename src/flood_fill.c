/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:30:00 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/26 16:30:00 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**copy_grid(char **grid, int height)
{
	char	**cpy;
	int		i;

	cpy = malloc(sizeof(char *) * (height + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		cpy[i] = ft_strdup(grid[i]);
		if (!cpy[i])
		{
			free_grid(cpy, i);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

int	flood_fill(char **grid, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (1);
	if (grid[y][x] == ' ')
		return (1);
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return (0);
	grid[y][x] = 'V';
	if (flood_fill(grid, x + 1, y, map))
		return (1);
	if (flood_fill(grid, x - 1, y, map))
		return (1);
	if (flood_fill(grid, x, y + 1, map))
		return (1);
	if (flood_fill(grid, x, y - 1, map))
		return (1);
	return (0);
}

int	check_closed(t_map *map)
{
	char	**cpy;
	int		px;
	int		py;
	int		ret;

	cpy = copy_grid(map->grid, map->height);
	if (!cpy)
		return (1);
	px = (int)map->player_x;
	py = (int)map->player_y;
	ret = flood_fill(cpy, px, py, map);
	free_grid(cpy, map->height);
	return (ret);
}

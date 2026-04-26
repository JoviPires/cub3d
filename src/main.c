/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:30:37 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/26 14:30:37 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	print_scene(t_scene *scene)
{
	int	i;

	printf("NO: %s\n", scene->no);
	printf("SO: %s\n", scene->so);
	printf("WE: %s\n", scene->we);
	printf("EA: %s\n", scene->ea);
	printf("F:  %d,%d,%d\n", scene->floor.r, scene->floor.g, scene->floor.b);
	printf("C:  %d,%d,%d\n", scene->ceiling.r, scene->ceiling.g,
		scene->ceiling.b);
	printf("Spawn: %c at (%.1f, %.1f)\n", scene->map.player_dir,
		scene->map.player_x, scene->map.player_y);
	printf("Map (%dx%d):\n", scene->map.width, scene->map.height);
	i = -1;
	while (++i < scene->map.height)
		printf("[%s]\n", scene->map.grid[i]);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3d map.cub\n", 2);
		return (1);
	}
	if (!check_cub(argv[1]))
	{
		ft_putstr_fd("Error\nFile must be .cub\n", 2);
		return (1);
	}
	if (parse_file(argv[1], &scene))
		return (1);
	print_scene(&scene);
	free_scene(&scene);
	return (0);
}

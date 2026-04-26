/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:30:00 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/26 16:30:00 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_grid(char **grid, int height)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->no)
		free(scene->no);
	if (scene->so)
		free(scene->so);
	if (scene->we)
		free(scene->we);
	if (scene->ea)
		free(scene->ea);
	free_grid(scene->map.grid, scene->map.height);
}

int	err_exit(char *msg, t_scene *scene)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	free_scene(scene);
	return (1);
}

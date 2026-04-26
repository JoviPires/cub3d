/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:30:00 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/26 16:30:00 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	dispatch_line(char *line, t_scene *scene, int *map_started)
{
	if (is_empty_line(line))
	{
		if (*map_started)
			return (-2);
		return (0);
	}
	if (!(*map_started) && is_element(line))
		return (parse_element(line, scene));
	*map_started = 1;
	return (-1);
}

static int	check_elements_complete(t_scene *scene)
{
	if (!scene->no || !scene->so || !scene->we || !scene->ea)
		return (0);
	if (!scene->floor.set || !scene->ceiling.set)
		return (0);
	return (1);
}

static int	read_and_dispatch(int fd, t_scene *scene)
{
	char	*line;
	int		map_started;
	int		ret;
	t_list	*map_lines;

	map_started = 0;
	map_lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ret = dispatch_line(line, scene, &map_started);
		if (ret == 1)
			return (free(line), ft_lstclear(&map_lines, &free), 1);
		if (ret == -1)
			ft_lstadd_back(&map_lines, ft_lstnew(ft_strdup(line)));
		else if (ret == -2 && map_lines)
			ft_lstadd_back(&map_lines, ft_lstnew(ft_strdup("")));
		free(line);
		line = get_next_line(fd);
	}
	if (!map_lines)
		return (ft_lstclear(&map_lines, &free), 1);
	ret = build_grid(map_lines, &scene->map);
	ft_lstclear(&map_lines, &free);
	return (ret);
}

int	parse_file(char *file, t_scene *scene)
{
	int	fd;

	ft_bzero(scene, sizeof(t_scene));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (err_exit("Failed to open file", scene));
	if (read_and_dispatch(fd, scene))
	{
		close(fd);
		return (err_exit("Invalid file content", scene));
	}
	close(fd);
	if (!check_elements_complete(scene))
		return (err_exit("Missing scene element (texture or color)", scene));
	if (validate_map(&scene->map))
		return (err_exit("Invalid map", scene));
	if (check_closed(&scene->map))
		return (err_exit("Map is not closed by walls", scene));
	return (0);
}

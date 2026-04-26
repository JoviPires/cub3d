/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:30:00 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/26 16:30:00 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_element(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3))
		return (1);
	if (!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		return (1);
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

int	parse_texture(char *line, char **dest)
{
	char	*path;

	if (*dest)
		return (1);
	line += 3;
	while (*line == ' ' || *line == '\t')
		line++;
	if (!*line)
		return (1);
	path = ft_strtrim(line, " \t\n");
	if (!path || !*path)
	{
		free(path);
		return (1);
	}
	*dest = path;
	return (0);
}

int	parse_color_line(char *line, t_color *color)
{
	line += 2;
	while (*line == ' ' || *line == '\t')
		line++;
	if (!*line)
		return (1);
	return (parse_color(line, color));
}

int	parse_element(char *line, t_scene *scene)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
		return (parse_texture(line, &scene->no));
	if (!ft_strncmp(line, "SO ", 3))
		return (parse_texture(line, &scene->so));
	if (!ft_strncmp(line, "WE ", 3))
		return (parse_texture(line, &scene->we));
	if (!ft_strncmp(line, "EA ", 3))
		return (parse_texture(line, &scene->ea));
	if (!ft_strncmp(line, "F ", 2))
		return (parse_color_line(line, &scene->floor));
	if (!ft_strncmp(line, "C ", 2))
		return (parse_color_line(line, &scene->ceiling));
	return (1);
}

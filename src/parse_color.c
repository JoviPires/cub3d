/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:30:00 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/26 16:30:00 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_split(char **parts)
{
	int	i;

	if (!parts)
		return ;
	i = 0;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
}

int	count_parts(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
		i++;
	return (i);
}

int	validate_rgb(char *str)
{
	int		i;
	int		val;
	char	*trimmed;

	trimmed = ft_strtrim(str, " \t\n");
	if (!trimmed || !*trimmed)
	{
		free(trimmed);
		return (-1);
	}
	i = 0;
	while (trimmed[i])
	{
		if (!ft_isdigit(trimmed[i]))
		{
			free(trimmed);
			return (-1);
		}
		i++;
	}
	val = ft_atoi(trimmed);
	free(trimmed);
	if (val < 0 || val > 255)
		return (-1);
	return (val);
}

int	parse_color(char *str, t_color *color)
{
	char	**parts;
	int		rgb[3];
	int		i;

	if (color->set)
		return (1);
	parts = ft_split(str, ',');
	if (!parts || count_parts(parts) != 3)
	{
		free_split(parts);
		return (1);
	}
	i = -1;
	while (++i < 3)
	{
		rgb[i] = validate_rgb(parts[i]);
		if (rgb[i] == -1)
		{
			free_split(parts);
			return (1);
		}
	}
	free_split(parts);
	color->r = rgb[0];
	color->g = rgb[1];
	color->b = rgb[2];
	color->set = 1;
	return (0);
}

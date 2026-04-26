/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:30:00 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/26 16:30:00 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*pad_line(char *line, int width)
{
	char	*padded;
	int		len;
	int		i;

	len = ft_strlen(line);
	if (len >= width)
		return (ft_strdup(line));
	padded = malloc(sizeof(char) * (width + 1));
	if (!padded)
		return (NULL);
	i = -1;
	while (++i < len)
		padded[i] = line[i];
	while (i < width)
		padded[i++] = ' ';
	padded[i] = '\0';
	return (padded);
}

static int	get_max_width(t_list *lines)
{
	int		max;
	int		len;

	max = 0;
	while (lines)
	{
		len = ft_strlen((char *)lines->content);
		if (len > max)
			max = len;
		lines = lines->next;
	}
	return (max);
}

static void	trim_trailing_empty(t_list **lines)
{
	t_list	*cur;
	t_list	*prev;
	t_list	*last_content;

	last_content = NULL;
	prev = NULL;
	cur = *lines;
	while (cur)
	{
		if (ft_strlen((char *)cur->content) > 0)
		{
			last_content = cur;
		}
		cur = cur->next;
	}
	if (last_content && last_content->next)
	{
		ft_lstclear(&last_content->next, &free);
		last_content->next = NULL;
	}
	(void)prev;
}

int	build_grid(t_list *lines, t_map *map)
{
	int		i;
	t_list	*cur;

	trim_trailing_empty(&lines);
	map->height = ft_lstsize(lines);
	map->width = get_max_width(lines);
	if (map->height == 0 || map->width == 0)
		return (1);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (1);
	i = 0;
	cur = lines;
	while (cur)
	{
		map->grid[i] = pad_line((char *)cur->content, map->width);
		if (!map->grid[i])
			return (free_grid(map->grid, i), map->grid = NULL, 1);
		i++;
		cur = cur->next;
	}
	map->grid[i] = NULL;
	return (0);
}

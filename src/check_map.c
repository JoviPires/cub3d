/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 15:16:53 by jpires-n          #+#    #+#             */
/*   Updated: 2026/04/26 15:17:06 by jpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_cub(const char *file)
{
	int	i;
	int	j;

	if (!file || ft_strlen(file) < 4)
		return (0);
	i = ft_strlen(file) - 4;
	j = 0;
	while (".cub"[j])
	{
		if (file[i + j] != ".cub"[j])
			return (0);
		j++;
	}
	return (1);
}

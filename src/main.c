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

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
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
	if (parse_file(argv[1], &game.scene))
		return (1);
	game_init(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &handle_key_press, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask,
		&close_window, &game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_loop(game.mlx);
	return (0);
}

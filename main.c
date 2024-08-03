/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:32:59 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/07/30 11:57:36 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.n_of_move = 0;
		map_handler(&game, argv);
		game_starter(&game);
		mlx_key_hook(game.win, walk_handle, &game);
		mlx_hook(game.win, 17, 1L << 17, handle_cross_event, &game);
		mlx_loop(game.mlx);
	}
	else if (argc == 1)
	{
		ft_printf("Map name should be given as parameter");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("Just one map can be playable at once");
		exit(EXIT_FAILURE);
	}
}

void	game_starter(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * 64,
			game->map.height * 64, "So Long");
	image_starter(game);
}

void	count_collect(t_game *game)
{
	int	i;
	int	j;

	game->collectable = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map_ptr[i][j] == 'C')
				game->collectable += 1;
			j++;
		}
		i++;
	}
}

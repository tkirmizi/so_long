/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:45:46 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/07/30 11:56:02 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walk_handle(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	game->npx = game->px;
	game->npy = game->py;
	if (keycode == 0 || keycode == 123)
		game->npx -= 64;
	else if (keycode == 1 || keycode == 125)
		game->npy += 64;
	else if (keycode == 13 || keycode == 126)
		game->npy -= 64;
	else if (keycode == 2 || keycode == 124)
		game->npx += 64;
	if (game->map.map_ptr[game->npy / 64]
		[game->npx / 64] != '1')
		walk_handle_2(game);
	mlx_clear_window(game->mlx, game->win);
	image_to_win(game);
	return (0);
}

void	walk_handle_2(t_game *game)
{
	if (game->map.map_ptr[game->npy / 64][game->npx / 64] == '0')
	{
		game->map.map_ptr[game->py / 64][game->px / 64] = '0';
		game->map.map_ptr[game->npy / 64][game->npx / 64] = 'P';
		game->n_of_move++;
		ft_printf("Number of movement is %d\n", game->n_of_move);
	}
	else if (game->map.map_ptr[game->npy / 64][game->npx / 64] == 'C')
	{
		game->map.map_ptr[game->py / 64][game->px / 64] = '0';
		game->map.map_ptr[game->npy / 64][game->npx / 64] = 'P';
		game->collectable--;
		game->n_of_move++;
		ft_printf("Number of movement is %d\n", game->n_of_move);
	}
	else if (game->map.map_ptr[game->npy / 64][game->npx / 64] == 'E')
	{
		if (game->collectable == 0)
			free_map_dest_win(game);
		else
			ft_printf("Collect all collectables!\n");
	}
}

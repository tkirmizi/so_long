/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:46:59 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/07/24 15:17:17 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_starter(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->image.block = mlx_xpm_file_to_image(game->mlx,
			"asset/lock.xpm", &x, &y);
	game->image.player = mlx_xpm_file_to_image(game->mlx,
			"asset/player.xpm", &x, &y);
	game->image.collect = mlx_xpm_file_to_image(game->mlx,
			"asset/collect.xpm", &x, &y);
	game->image.exit = mlx_xpm_file_to_image(game->mlx,
			"asset/exit.xpm", &x, &y);
	image_to_win(game);
}

void	draw_cell(t_game *game, int cell_type, int x, int y)
{
	if (cell_type == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->image.block, x, y);
	else if (cell_type == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->image.player, x, y);
		game->px = x;
		game->py = y;
	}
	else if (cell_type == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->image.collect, x, y);
	else if (cell_type == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->image.exit, x, y);
}

void	image_to_win(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (game->map.map_ptr[i] != NULL)
	{
		j = 0;
		x = 0;
		while (game->map.map_ptr[i][j] != '\n'
			&& game->map.map_ptr[i][j] != '\0')
		{
			draw_cell(game, game->map.map_ptr[i][j], x, y);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
}

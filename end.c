/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:46:25 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/07/30 11:57:55 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_error_free(const char *message, t_game *game)
{
	ft_printf("Error\n%s", message);
	free_map(game);
	exit(EXIT_FAILURE);
}

void	exit_with_error(const char *message)
{
	ft_printf("Error\n%s", message);
	exit (EXIT_FAILURE);
}

void	end_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image.block);
	mlx_destroy_image(game->mlx, game->image.player);
	mlx_destroy_image(game->mlx, game->image.collect);
	mlx_destroy_image(game->mlx, game->image.exit);
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
}

int	handle_cross_event(t_game *game)
{
	end_game(game);
	exit(0);
}

void	free_map_dest_win(t_game *game)
{
	ft_printf("YOU WIN THE GAME, CONGRATULATIONS!\n");
	free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

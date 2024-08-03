/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:14:12 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/07/30 11:34:25 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_and_free_buffer(const char *message, char *buffer)
{
	ft_printf("Error\n%s", message);
	free(buffer);
	exit(EXIT_FAILURE);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->map.map_ptr[i]);
		i++;
	}
	free(game->map.map_ptr);
}

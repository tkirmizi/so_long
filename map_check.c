/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:48:36 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/07/30 11:36:54 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_control(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.map_ptr[0][i] != '1')
			return (0);
		if (game->map.map_ptr[game->map.height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map.height)
	{
		if (game->map.map_ptr[i][0] != '1')
			return (0);
		else if (game->map.map_ptr[i][game->map.width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_char_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map_ptr[i][j] != '0'
				&& game->map.map_ptr[i][j] != '1'
				&& game->map.map_ptr[i][j] != 'P'
				&& game->map.map_ptr[i][j] != 'E'
				&& game->map.map_ptr[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	one_player_exit(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map_ptr[i][j] == 'E')
				x += 1;
			else if (game->map.map_ptr[i][j] == 'P')
				y += 1;
			j++;
		}
		i++;
	}
	if (x != 1 || y != 1)
		return (0);
	return (1);
}

int	ft_strlen_2(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int	collectable_exist(t_game *game)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map_ptr[i][j] == 'C')
				x += 1;
			j++;
		}
		i++;
	}
	if (x == 0)
		return (0);
	return (1);
}

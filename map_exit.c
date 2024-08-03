/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:49:25 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/07/30 11:36:37 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path_control(t_game *game)
{
	int	**visited;
	int	player_x;
	int	player_y;
	int	i;
	int	result;

	i = 0;
	visited = initialize_visited(game, &player_x, &player_y);
	dfs(game, player_x, player_y, visited);
	result = check_exit_reachable(game, visited);
	while (i < game->map.height)
		free(visited[i++]);
	free(visited);
	return (result);
}

int	**initialize_visited(t_game *game, int *player_x, int *player_y)
{
	int	**visited;
	int	i;
	int	j;

	visited = (int **)malloc(game->map.height * sizeof(int *));
	if (!visited)
		exit_with_error("Malloc problem");
	i = -1;
	while (++i < game->map.height)
	{
		visited[i] = (int *)malloc(game->map.width * sizeof(int));
		if (!visited[i])
			exit_with_error("Malloc problem");
		j = -1;
		while (++j < game->map.width)
		{
			visited[i][j] = 0;
			if (game->map.map_ptr[i][j] == 'P')
			{
				*player_x = i;
				*player_y = j;
			}
		}
	}
	return (visited);
}

void	dfs(t_game *game, int x, int y, int **visited)
{
	if (x < 0 || x >= game->map.height || y < 0 || y >= game->map.width)
		return ;
	if (game->map.map_ptr[x][y] == '1' || visited[x][y])
		return ;
	visited[x][y] = 1;
	dfs(game, x + 1, y, visited);
	dfs(game, x - 1, y, visited);
	dfs(game, x, y + 1, visited);
	dfs(game, x, y - 1, visited);
}

int	check_exit_reachable(t_game *game, int **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map_ptr[i][j] == 'E' && !visited[i][j])
				return (0);
			else if (game->map.map_ptr[i][j] == 'C' && !visited[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_ber_file(char **argv)
{
	int	i;

	i = ft_strlen_2(argv[1]);
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r' && argv[1][i - 2] != 'e' && argv[1][i - 3]
		!= 'b' && argv[1][i - 4] != '.')
		return (0);
	return (1);
}

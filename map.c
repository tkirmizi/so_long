/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:23:51 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/07/30 11:24:57 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "so_long.h"

void	map_handler(t_game *game, char **argv)
{
	if (!check_ber_file(argv))
		exit_with_error(".ber problem");
	map_handler2(game, argv);
	map_copy(game, argv);
	if (!rectular_control(game))
		exit_with_error_free("Map is not rectangular", game);
	if (!wall_control(game))
		exit_with_error_free("Map is not surrounded by wall", game);
	if (!valid_char_control(game))
		exit_with_error_free("Map include invalid char", game);
	if (!one_player_exit(game))
		exit_with_error_free("more than one player and exit, or none", game);
	if (!collectable_exist(game))
		exit_with_error_free("There is no collectable", game);
	if (!valid_path_control(game))
		exit_with_error_free("Exit is not accessible", game);
	count_collect(game);
}

void	map_handler2(t_game *game, char **argv)
{
	int		fd;
	char	*buffer;

	game->map.height = 0;
	buffer = (char *)malloc(100 * sizeof(char));
	if (!buffer)
		exit_with_error("malloc problem");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		exit_with_error("problem on opening file");
		free(buffer);
	}
	buffer = get_next_line(fd);
	if (buffer == NULL)
		exit_and_free_buffer("map file empty", buffer);
	game->map.width = map_width_check(buffer);
	while (buffer != NULL)
	{
		game->map.height++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	close(fd);
}

void	map_copy(t_game *game, char **argv)
{
	int		fd;
	int		i;
	char	*buffer;

	buffer = (char *)malloc(100 * sizeof(char));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	i = 0;
	game->map.map_ptr = (char **)malloc((game->map.height + 1)
			* (sizeof(char *)));
	if (!(game->map.map_ptr))
		exit_with_error("Malloc problem");
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		*(game->map.map_ptr + i) = ft_strdup(buffer);
		i++;
		free(buffer);
	}
	*(game->map.map_ptr + i) = NULL;
	close(fd);
}

int	rectular_control(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		if (ft_strlen_2(*(game->map.map_ptr + i)) != game->map.width)
			return (0);
		i++;
	}
	return (1);
}

int	map_width_check(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

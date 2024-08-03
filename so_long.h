/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:33:16 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/07/30 11:49:45 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h> 
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"

typedef struct s_image
{
	void	*block;
	void	*player;
	void	*collect;
	void	*exit;
}			t_image;

typedef struct s_map
{
	char	**map_ptr;
	int		height;
	int		width;
}			t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		px;
	int		py;
	int		npx;
	int		npy;
	int		collectable;
	int		n_of_move;
	t_map	map;
	t_image	image;
}			t_game;

void	map_handler(t_game *game, char **argv);
int		map_width_check(const char *str);
void	game_starter(t_game *game);
void	image_starter(t_game *game);
void	game_starter(t_game *game);
void	image_to_win(t_game *game);
int		walk_handle(int keycode, t_game *game);
void	count_collect(t_game *game);
void	walk_handle_2(t_game *game);
void	map_handler2(t_game *game, char **argv);
int		valid_char_control(t_game *game);
int		rectular_control(t_game *game);
void	map_copy(t_game *game, char **argv);
int		ft_strlen_2(const char *str);
int		wall_control(t_game *game);
int		one_player_exit(t_game *game);
int		valid_path_control(t_game *game);
void	exit_with_error(const char *message);
void	exit_with_error_free(const char *message, t_game *game);
void	free_map(t_game *game);
int		handle_cross_event(t_game *game);
void	dfs(t_game *game, int x, int y, int **visited);
int		**initialize_visited(t_game *game, int *player_x, int *player_y);
int		check_exit_reachable(t_game *game, int **visited);
int		valid_path_control(t_game *game);
void	end_game(t_game *game);
void	draw_cell(t_game *game, int cell_type, int x, int y);
int		check_ber_file(char **argv);
void	exit_and_free_buffer(const char *message, char *buffer);
int		collectable_exist(t_game *game);
void	free_map_dest_win(t_game *game);

#endif
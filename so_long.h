/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:37:10 by otangkab          #+#    #+#             */
/*   Updated: 2023/01/24 23:49:24 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "lib/Libft/libft.h"
# include "lib/gnl/get_next_line.h"
# include "key.h"
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>

# define FRAME_RATE	60

typedef struct s_map
{
	char	**area;
	char	*wall;
	char	*floor;
	char	*player;
	char	*collect;
	char	*enmy;
	char	*exit;
	int		p;
	int		c;
	int		e;
	int		counter;
}	t_map;

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_dim
{
	int	width;
	int	height;
}	t_dim;

typedef struct s_data
{
	void	*ptr;
	void	*win;
	void	*img;
	int		row;
	int		column;
	int		block;
	t_map	map;
	t_dim	window;
	t_vec	player;
	t_vec	exit;
	t_vec	foot_print;
}	t_data;

//check_file.c
void	check_argc(int number);
void	check_map_name(char *str);
void	check_rec_get_dim(t_data *data, char *name);
int		ft_open(char *name);

//check_pce.c
void	check_map_pce01m(t_data *data);
void	check_error_pce(t_data *data);
void	check_map_pce(t_data *data);
void	check_border(t_data *data);

//flood_fill.c
char	**dup_map(t_data *data);
void	show_ff_map(char **map, int row);
void	fill(char **area, t_data *data, int x, int y);
void	flood_fill(char **area, t_data *data);
void	flood_fill_test(t_data *data);

//so_long_utils.c
void	free_mem(char **area, int row);
int		ft_strlen_n(char *str);
//so_long.c
void	run_game(t_data *data);
void	init_data(t_data *data);
void	load_map(t_data *data, char *name);
int		close_game_x(t_data *game);

//render.c
void	render_bg(t_data *game);
void	draw(t_data *game, char *path, int j, int i);
void	render(t_data *game);
void	render_player(t_data *game);

//ft_mlx_hook.c
void	ft_move(t_data *game, int new_x, int new_y);
int		loop_hook(t_data *game);
int		check_move(t_data *game, int new_x, int new_y);
int		key_hook(int keycode, t_data *game);

#endif

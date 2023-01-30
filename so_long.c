/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:20:37 by otangkab          #+#    #+#             */
/*   Updated: 2023/01/25 14:13:46 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
//#include <stdio.h>

int	close_game_x(t_data *game)
{
	mlx_destroy_window(game->ptr, game->win);
	free_mem(game->map.area, game->row);
	free(game->ptr);
	exit(0);
	return (0);
}

void	run_game(t_data *game)
{
	game->ptr = mlx_init();
	game->win = mlx_new_window(game->ptr, game->window.width, \
			game->window.height, "so_long 2d game.");
	render_bg(game);
	render(game);
	game->foot_print.x = game->player.x;
	game->foot_print.y = game->player.y;
	mlx_hook(game->win, 17, 1L << 0, close_game_x, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->ptr, loop_hook, game);
	mlx_loop(game->ptr);
}

void	init_data(t_data *data)
{
	data->map.p = 0;
	data->map.c = 0;
	data->map.e = 0;
	data->map.counter = 0;
	data->map.wall = "./textures/wall.xpm";
	data->map.player = "./textures/player.xpm";
	data->map.floor = "./textures/floor.xpm";
	data->map.collect = "./textures/collect.xpm";
	data->map.exit = "./textures/exit.xpm";
	data->map.enmy = "./textures/enmy.xpm";
	data->block = 32;
	data->window.width = data->block * data->column;
	data->window.height = data->block * data->row;
}

void	load_map(t_data *data, char *name)
{
	char	*line;
	int		fd;
	int		i;

	line = "";
	fd = open(name, O_RDONLY);
	data->map.area = (char **)malloc(sizeof(char *) * data->row);
	i = 0;
	while (i < data->row)
	{
		data->map.area[i] = get_next_line(fd);
		ft_putstr_fd(data->map.area[i], 1);
		i++;
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	t_data	game;

	check_argc(argc);
	check_map_name(argv[1]);
	check_rec_get_dim(&game, argv[1]);
	init_data(&game);
	load_map(&game, argv[1]);
	check_map_pce01m(&game);
	check_map_pce(&game);
	check_error_pce(&game);
	check_border(&game);
	flood_fill_test(&game);
	run_game(&game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:47:35 by otangkab          #+#    #+#             */
/*   Updated: 2023/01/25 01:04:58 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_bg(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map.area[i][j] == 'P' || \
				game->map.area[i][j] == 'C' || \
				game->map.area[i][j] == 'E' || \
				game->map.area[i][j] == 'M')
			{
				game->img = mlx_xpm_file_to_image(game->ptr, \
				game->map.floor, &game->block, &game->block);
				mlx_put_image_to_window(game->ptr, game->win, \
				game->img, (j * game->block), (i * game->block));
			}
			j++;
		}
		i++;
	}
}

void	draw(t_data *game, char *path, int j, int i)
{
	game->img = mlx_xpm_file_to_image(game->ptr, \
			path, &game->block, &game->block);
	mlx_put_image_to_window(game->ptr, game->win, \
			game->img, (j * game->block), (i * game->block));
}

void	render(t_data *game)
{	
	int	i;
	int	j;

	i = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map.area[i][j] == '1')
				draw(game, game->map.wall, j, i);
			else if (game->map.area[i][j] == '0')
				draw(game, game->map.floor, j, i);
			else if (game->map.area[i][j] == 'P')
				draw(game, game->map.player, j, i);
			else if (game->map.area[i][j] == 'C')
				draw(game, game->map.collect, j, i);
			else if (game->map.area[i][j] == 'E')
				draw(game, game->map.exit, j, i);
			else if (game->map.area[i][j] == 'M')
				draw(game, game->map.enmy, j, i);
		j++;
		}
	i++;
	}
}

void	render_player(t_data *game)
{
	if (game->foot_print.x == game->exit.x && \
			game->foot_print.y == game->exit.y)
	{
		draw(game, game->map.floor, \
				game->foot_print.x, game->foot_print.y);
		draw(game, game->map.exit, \
				game->foot_print.x, game->foot_print.y);
	}
	else
		draw(game, game->map.floor, \
				game->foot_print.x, game->foot_print.y);
	draw(game, game->map.player, game->player.x, game->player.y);
}

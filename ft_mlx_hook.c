/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:18:48 by otangkab          #+#    #+#             */
/*   Updated: 2023/01/25 00:52:15 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "key.h"

int	check_move(t_data *game, int new_x, int new_y)
{
	char	pos;

	pos = game->map.area[new_y][new_x];
	if (pos == '0' || pos == 'C')
	{
		if (pos == 'C')
			game->map.c--;
		return (1);
	}
	if ((pos == 'E') && (game->map.c == 0))
	{
		ft_putstr_fd("----YOU WIN-----", 1);
		return (2);
	}
	if (pos == 'E')
		return (3);
	return (0);
}

void	display_map(t_data *game)
{
	int	i;

	write(1, "\n", 1);
	i = 0;
	while (i < game->row)
	{
		ft_putstr_fd(game->map.area[i], 1);
		i++;
	}	
	write(1, "\n", 1);
}

void	ft_move(t_data *game, int new_x, int new_y)
{
	if (game->player.x == game->exit.x && game->player.y == game->exit.y)
	{
		game->map.area[game->player.y][game->player.x] = 'E';
	}
	else
		game->map.area[game->player.y][game->player.x] = '0';
	game->map.area[new_y][new_x] = 'P';
	game->foot_print.x = game->player.x;
	game->foot_print.y = game->player.y;
	game->player.x = new_x;
	game->player.y = new_y;
	game->map.counter++;
	ft_putstr_fd("next player.x = ", 1);
	ft_putnbr_fd(game->player.x, 1);
	write(1, "\n", 1);
	ft_putstr_fd("next player.y = ", 1);
	ft_putnbr_fd(game->player.y, 1);
	write(1, "\n", 1);
	ft_putstr_fd("counter = ", 1);
	ft_putnbr_fd(game->map.counter, 1);
	display_map(game);
}

int	loop_hook(t_data *game)
{
	render_player(game);
	return (0);
}

int	key_hook(int keycode, t_data *game)
{
	int	new_x;
	int	new_y;
	int	check;

	new_x = game->player.x;
	new_y = game->player.y;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		new_x++;
	else if (keycode == KEY_W || keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_ESC)
		close_game_x(game);
	else
		return (0);
	check = check_move(game, new_x, new_y);
	if (check == 1 || check == 3)
		ft_move(game, new_x, new_y);
	if (check == 2)
		close_game_x(game);
	return (check);
}

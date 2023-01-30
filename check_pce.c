/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:18:00 by otangkab          #+#    #+#             */
/*   Updated: 2023/01/25 00:23:44 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_pce01m(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			if (data->map.area[i][j] == 'P' || \
					data->map.area[i][j] == 'C' || \
					data->map.area[i][j] == 'E' || \
					data->map.area[i][j] == '0' || \
					data->map.area[i][j] == '1')
			{
			}
			else
			{
				ft_putstr_fd("Error\nMap 's character not in scope", 1);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_error_pce(t_data *data)
{
	if (data->map.p != 1)
	{
		ft_putstr_fd("Error\nmap.player not equal 1", 1);
		exit(1);
	}
	if (data->map.c < 1)
	{
		ft_putstr_fd("Error\nmap.collectable less than 1", 1);
		exit(1);
	}
	if (data->map.e != 1)
	{
		ft_putstr_fd("Error\nmap.exit is not equal 1", 1);
		exit(1);
	}
}

void	check_map_pce(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			if (data->map.area[i][j] == 'P')
			{
			data->map.p++;
			data->player.x = j;
			data->player.y = i;
			}
			else if (data->map.area[i][j] == 'C')
				data->map.c++;
			else if (data->map.area[i][j] == 'E')
			{
				data->map.e++;
				data->exit.x = j;
				data->exit.y = i;
			}
		}
	}
}

void	check_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			if (data->map.area[0][j] != '1' || \
					data->map.area[data->row - 1][j] != '1' || \
					data->map.area[i][0] != '1' || \
					data->map.area[i][data->column - 1] != '1')
			{
				ft_putstr_fd("Error\nmap not surround by wall", 1);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

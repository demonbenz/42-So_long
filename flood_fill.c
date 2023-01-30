/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:47:57 by otangkab          #+#    #+#             */
/*   Updated: 2023/01/20 17:37:05 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_map(t_data *data)
{
	char	**area;
	int		i;
	int		j;

	area = (char **)malloc(sizeof(char *) * data->row);
	if (!area)
		return (0);
	i = 0;
	while (i < data->row)
	{
		area[i] = malloc(sizeof(char) * (data->column + 1));
		if (!area[i])
			return (0);
		j = 0;
		while (j < data->column)
		{
			area[i][j] = data->map.area[i][j];
			j++;
		}
		area[i][j] = '\0';
		i++;
	}
	return (area);
}

void	show_ff_map(char **map, int row)
{
	int	i;
	int	j;

	write (1, "\n", 1);
	i = 0;
	while (i < row)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			ft_putchar_fd(map[i][j], 1);
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				ft_putstr_fd("Error Map, you can not exit Map(flood fill)", 1);
				free_mem(map, row);
				exit (1);
			}
			j++;
		}
		write(1, "\n", 1);
	i++;
	}
}

void	fill(char **area, t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->column \
			|| y >= data->row || area[y][x] == '1' \
			|| area[y][x] == 'F' || area[y][x] == 'M')
		return ;
	area[y][x] = 'F';
	fill(area, data, x - 1, y);
	fill(area, data, x + 1, y);
	fill(area, data, x, y - 1);
	fill(area, data, x, y + 1);
	return ;
}

void	flood_fill(char	**area, t_data *data)
{
	fill(area, data, data->player.x, data->player.y);
}

void	flood_fill_test(t_data *data)
{
	char	**area;

	area = dup_map(data);
	flood_fill(area, data);
	show_ff_map(area, data->row);
	free_mem(area, data->row);
}

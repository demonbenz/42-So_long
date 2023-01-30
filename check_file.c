/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:24:32 by otangkab          #+#    #+#             */
/*   Updated: 2023/01/25 14:25:14 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	check_argc(int number)
{
	if (number > 2)
	{
		ft_putstr_fd("Error\nargument too much.", 1);
		exit (1);
	}
	else if (number < 2)
	{
		ft_putstr_fd("Error\nplease input map name.", 1);
		exit (1);
	}
}

void	check_map_name(char *str)
{
	char	*ber;

	ber = ".ber";
	if (ft_strnstr(str, ber, ft_strlen(str)))
	{
		ft_putstr_fd("Check Map name is following by .ber\n", 1);
	}
	else
	{
		ft_putstr_fd("Error\nmap name do not following by .ber\n", 1);
		exit(1);
	}
}

int	ft_open(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit (1);
	}
	return (fd);
}

void	check_rec_get_dim(t_data *data, char *name)
{
	char	*line;
	int		fd;

	data->row = 0;
	data->column = 0;
	fd = ft_open(name);
	line = get_next_line(fd);
	data->column = ft_strlen_n(line);
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL && data->column != ft_strlen_n(line))
		{
			ft_putstr_fd("Error\nMap :This map is not rectangle.", 1);
			free(line);
			close(fd);
			exit(1);
		}
		free(line);
		data->row++;
	}
	free(line);
	close(fd);
}

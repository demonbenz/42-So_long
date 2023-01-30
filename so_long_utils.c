/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:32:20 by otangkab          #+#    #+#             */
/*   Updated: 2023/01/24 23:16:00 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mem(char **area, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(area[i]);
		i++;
	}
	free (area);
}

int	ft_strlen_n(char *str)
{
	int	i;

	if (!str)
	{
		ft_putstr_fd("Error\nNotthing inside map.", 1);
		exit (1);
	}
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

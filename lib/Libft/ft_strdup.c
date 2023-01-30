/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:40:11 by otangkab          #+#    #+#             */
/*   Updated: 2022/08/14 15:14:40 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(char *s)
{
	char	*d;
	int		len;
	int		i;

	len = 0;
	while (s[len] != '\0')
	{
	len++;
	}
	d = malloc(sizeof(char) * (len + 1));
	if (d == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
	i++;
	}
	d[i] = '\0';
	return (d);
}

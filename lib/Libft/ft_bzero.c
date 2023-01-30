/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:46:49 by otangkab          #+#    #+#             */
/*   Updated: 2022/08/13 14:16:47 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include"libft.h"

void	ft_bzero(void *str, size_t num)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < num)
	{
		ptr[i] = '\0';
	i++;
	}
}
/*
int	main()
{
	int	num;
	int	i;

	char	s[20] = "abcdefghijkl";
	num = 5;
	ft_bzero(s, num);
	i = 0;
	while (i < 8)
	{
		printf("s[%d] = %c\n", i, s[i]);
	i++;
	}
}*/

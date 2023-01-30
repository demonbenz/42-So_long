/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:25:29 by otangkab          #+#    #+#             */
/*   Updated: 2022/08/15 21:10:54 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
//#include<stdio.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num >= SIZE_MAX && size >= SIZE_MAX)
		return (NULL);
	ptr = (void *)malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (num * size));
	return (ptr);
}
/*
int	main()
{
	char	*ptr;
	int	i;
	int	num;
	num = 5;
	
	ptr = ft_calloc(num, sizeof(int));
	if (ptr == NULL)
		return (0);
	i = 0;
	while (i < num)
	{
		printf("ptr%d = %d\n", i, ptr[i]);
	i++;
	}
	printf("-----input_some_value----\n");
	i = 0;
	while (i < num)
	{
		ptr[i] = i;
	i++;	
	}
	i = 0;
	while (i < num)
	{
		printf("ptr%d = %d\n", i, ptr[i]);
	i++;
	}
	free(ptr);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:06:09 by otangkab          #+#    #+#             */
/*   Updated: 2022/07/06 19:44:37 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		tmp[i] = s1[i];
	i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}
/*
int	main(void)
{
	//char	*st1 = "first string.";
	char	*st2 = "secound string";
	char	*ret;

	ret = ft_strjoin(NULL, st2);
	printf("ret = %s", ret);
	free(ret);
}*/

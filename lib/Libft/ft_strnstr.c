/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:25:23 by otangkab          #+#    #+#             */
/*   Updated: 2023/01/06 10:10:57 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include<stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			n = i;
			while (needle[j] == haystack[n] && n < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *)&haystack[i]);
			n++;
			j++;
			}
		}
	i++;
	}
	return (0);
}
/*
int	main()
{
	char	*hay;
	char	*ned;
	int	num;
	char	*ret;
	char	*ret2;
	
	num = 7; 
	hay = "map.ber";
	ned = "ber";
	ret = strnstr(hay, ned, num);
	ret2 = ft_strnstr(hay, ned, num);
	printf("ret = %s\n", ret);
	printf("ret2 = %s\n", ret2);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:52:44 by otangkab          #+#    #+#             */
/*   Updated: 2022/08/12 18:45:34 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}
/*
int	main()
{
	char *s;
	char c;
	char *ret;
	
	s = "abcdefghijklmnopqrstuvwxyz";
	c = '\0';
	ret = strchr(s, c);
	printf("%s",ret);
}*/

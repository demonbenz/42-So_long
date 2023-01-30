/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:16:25 by otangkab          #+#    #+#             */
/*   Updated: 2023/01/07 12:26:33 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_extract(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!src[i])
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	dest = (char *)malloc((i + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] && src[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

char	*ft_stradd(char *stash, char *buffer)
{
	char	*s;

	if (!stash)
	{
		stash = malloc(1);
		stash[0] = '\0';
		if (!stash)
			return (0);
	}
	s = ft_gstrjoin(stash, buffer);
	free(stash);
	return (s);
}

char	*ft_stash_clean(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_gstrlen(str) - i + 1));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*ft_read_line(int fd, char *stash)
{
	ssize_t	ret;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (0);
	}
	ret = 1;
	while ((ret != 0) && (!ft_gstrchr(stash, '\n')))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		stash = ft_stradd(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	stash = ft_read_line(fd, stash);
	if (!stash)
	{
		return (NULL);
	}
	line = ft_str_extract(stash);
	stash = ft_stash_clean(stash);
	return (line);
}
/*
#include<stdio.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
	line = "";

	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	fd = close(fd);
	return(0);
}
*/
/*
int	main(int argc, char *argv[])
{
	int	fd;
	char	*line;
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
	
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		//getchar();
	}
	
	free (line);
	fd = close(fd);
	return (0);	
}
*/

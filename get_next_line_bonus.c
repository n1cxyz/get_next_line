/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:41:03 by dasal             #+#    #+#             */
/*   Updated: 2024/05/13 11:41:04 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_stash(char *stash, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strxjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}

char	*str_snip(char *str)
{
	size_t	i;
	char	*result;
	size_t	len;

	len = 0;
	if (!str[len])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	result = (char *)malloc(sizeof(char) * len + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++; 
	}
	if (str[i] == '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*result;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	stash[fd] = ft_get_stash(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	result = str_snip(stash[fd]);
	stash[fd] = ft_substring(stash[fd]);
	return (result);
}
/* 
int	main(void)
{
	ssize_t		fd[3];
	char	*result;

	fd[0] = open("text1.txt", O_RDONLY);
	fd[1] = open("text2.txt", O_RDONLY);
	fd[2] = open("text3.txt", O_RDONLY);

	while ((result = get_next_line(fd[0])) != NULL)
	{
		printf("%s", result);
		result = get_next_line(fd[1]);
		printf("%s", result);
		result = get_next_line(fd[2]);
		printf("%s", result);
		//free (result);
	}

	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	return (0);
}  */
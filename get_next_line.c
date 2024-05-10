/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dominicasal <dominicasal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:58:47 by dominicasal       #+#    #+#             */
/*   Updated: 2024/05/11 01:25:15 by dominicasal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	char		*buffer;
	static char	*stash;
	ssize_t 	index;
	char		*result;
	
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (BUFFER_SIZE < 1 || fd < 0 || !buffer || read(fd, 0, 0) || 
		BUFFER_SIZE > INT_MAX)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strxjoin(stash, buffer);
		if ((index = ft_find_char(stash, '\n')) != -1 || bytes_read == 0)
			break ;
	}
	free (buffer);
	result = str_snip(stash, index);
	stash = ft_substring(stash, index);
	return (result);
}
/* 
int	main(void)
{
	ssize_t		fd;
	char	*result;
	int i = 6;

	fd = open("nonl.txt", O_RDONLY);

	while (i > 0)
	{
		result = get_next_line(fd);
		printf("%s", result);
		free (result);
		i--;
	}

	close(fd);
	return (0);
}  */
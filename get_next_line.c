/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dominicasal <dominicasal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:58:47 by dominicasal       #+#    #+#             */
/*   Updated: 2024/05/11 17:00:55 by dominicasal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*result;
	
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	stash = ft_get_stash(stash, fd);
	if (!stash)
		return (NULL);
	result = str_snip(stash);
	stash = ft_substring(stash);
	return (result);
}
/* 
int	main(void)
{
	ssize_t		fd;
	char	*result;

	fd = open("text.txt", O_RDONLY);

	while ((result = get_next_line(fd)) != NULL)
	{
		printf("%s", result);
		free (result);
	}

	close(fd);
	return (0);
}  */
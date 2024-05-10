/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dominicasal <dominicasal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:53:08 by dominicasal       #+#    #+#             */
/*   Updated: 2024/05/09 18:05:23 by dominicasal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


//cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c

char	*get_next_line(int fd);
char	*ft_strchr(char const *str, int c);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
char	*check_line(char *stash);

int	main(void)
{
	int		fd;
	ssize_t		bytes_read;
	char		*buffer;
	static char	*stash;
	char		*result;
	
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (printf("error opening file"));

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (printf("error allocating buffer"));
	
	while (((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		stash = ft_strdup(buffer);
		result = check_line(stash);
		if (result)
			printf("%s", result);
	}

	close(fd);
	//printf("%s", result);
	return (0);
}

char	*ft_strchr(char const *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

/* char	*ft_get_line(char	*str)
{
	while (*str)
	{
		if (*str == c)
			return ((*str = '\0'))

	}
	 */

char	*ft_strdup(const char *str)
{
	char	*dst;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*check_line(char *stash)
{
	size_t	i;
	char	*result;

	i = 0;
	while (stash)
	{
		if (stash[i] == '\n')
		{
			ft_strlcpy(result, stash, i + 1);
			stash = ft_strchr(stash, '\n');
			return (result);
		}
		i++;
	}
	return (NULL);
}

//"hello how are you \n doing";

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	while (src[j] != '\0' && j < size - 1)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

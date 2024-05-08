/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dominicasal <dominicasal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:17:54 by dasal             #+#    #+#             */
/*   Updated: 2024/05/08 19:07:38 by dominicasal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcpy(char *dest, char const *src, size_t size);
//size_t	ft_strlen(char const *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int	ft_strchr(char	*str, int c);
char *ft_strstr(char	*str);

//int	open(const char *path, int flags[, int mode]);
//char	*get_next_line(int fd);
//ssize_t	read(int fildes, void *buf, size_t nbyte);
//cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c

/*char	*get_next_line(int fd)
{
	char *result = NULL;
	static char buffer[BUFFER_SIZE];
	static char stash[BUFFER_SIZE];

	while (ft_strchr(stash, '\n') != 1)
	{
		read(fd, buffer, 5);
		ft_strlcat(stash, buffer, BUFFER_SIZE);
		//printf("stash is:%s\n", stash);
	}
	result = ft_strstr(stash);
	//printf("stash after is:%s\n", stash);
	return (result);
}*/

int	main(void)
{
	int	fd;
	/*char *s1 = NULL;
	char *s2 = NULL;
	char *s3 = NULL;
	char *s4 = NULL;*/
	char *r1 = NULL;
	//char *r2 = NULL;
	//char *r3 = NULL;
	static char buffer[BUFFER_SIZE];
	static char stash[BUFFER_SIZE];

	fd = open("text.txt", O_RDONLY);
	/*s1 = get_next_line(fd);
	read(fd, buffer, 5);
	ft_strlcat(stash, buffer, BUFFER_SIZE);
	printf("stash is:%s\n", stash);
	s2 = get_next_line(fd);
	s3 = get_next_line(fd);
	s4 = get_next_line(fd);
	printf("%s\n%s\n%s\n%s", s1, s2, s3 ,s4);*/
	/*while (ft_strchr(stash, '\n') != 1)
	{
		read(fd, buffer, 5);
		ft_strlcat(stash, buffer, BUFFER_SIZE);
		//printf("stash is:%s\n", stash);
	}*/
	read(fd, buffer, 5);
	ft_strlcat(stash, buffer, BUFFER_SIZE);
	read(fd, buffer, 5);
	ft_strlcat(stash, buffer, BUFFER_SIZE);
	read(fd, buffer, 5);
	ft_strlcat(stash, buffer, BUFFER_SIZE);
	read(fd, buffer, 5);
	ft_strlcat(stash, buffer, BUFFER_SIZE);
	read(fd, buffer, 5);
	ft_strlcat(stash, buffer, BUFFER_SIZE);
	r1 = ft_strstr(stash);
	printf("buffer is:%s\n", buffer);
	printf("stash is:%s\n", stash);
	printf("result is:%s\n", r1);
	//printf("stash is:%s", stash);
	close(fd);
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	dlen;
	size_t	slen;

	i = 0;
	j = 0;
	k = 0;
	while (dst[j] != '\0')
		j++;
	dlen = j;
	while (src[k] != '\0')
		k++;
	slen = k;
	if (size <= dlen || size == 0)
		return (slen + size);
	while (src[i] != '\0' && i < size - dlen - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	if (str[i] == (char)c)
		return (1);
	return (0);
}

char *ft_strstr(char *str)
{
		size_t  i;
		char *result;

		i = 0;
		while (str[i] != '\n')
				i++;
		i++;
		result = (char *)malloc(sizeof(char) * (i + 1));
		if (!result)
				return (NULL);
		ft_strlcpy(result, str, i + 1);
		return (result);
}

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
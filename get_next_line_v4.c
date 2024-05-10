#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *str);
char	*ft_strchr(char const *str, int c);
int		find_char(char *str, char c);
char	*str_snip(char *str, size_t index);
char	*get_next_line(int fd);
char	*ft_strchr(char const *str, int c);

int	main(void)
{
	ssize_t		fd;
	char	*result;
	char	*string2;
	char	*string3;

	fd = open("text.txt", O_RDONLY);

	result = get_next_line(fd);

	string2 = get_next_line(fd);

	string3 = get_next_line(fd);

	printf("result is:%s\nstring2 is:%s\nstring3 is:%s", result, string2, string3);

	close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	size_t		bytes_read;
	char		*buffer;
	static char	*stash;
	size_t 		index;
	char		*result;
	
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (stash == NULL)
		stash = (char *)malloc(0);
	if (BUFFER_SIZE == 0)
		return (0);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if ((index = find_char(stash, '\n')) != -1)
			break ;
	}
	result = str_snip(stash, index);
	stash = ft_strchr(stash, '\n');
	//printf("stash is:%s\n", stash);

	return (result);
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

char	*str_snip(char *str, size_t index)
{
	size_t		i;
	char	*result;

	i = 0;
	if (index > ft_strlen(str))
		return (0); 
	while (str[i] != '\0')
	{
		if (i == index)
			break ;
		i++;
	}
	result = (char *)malloc(sizeof(char) * i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i <= index)
	{
		result[i] = str[i];
		i++; 
	}
	result[i] = '\0';
	return (result);
}

int	find_char(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*result_ptr;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return ("aaa");
	result_ptr = result;
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (result_ptr);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

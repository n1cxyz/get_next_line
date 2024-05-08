#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcpy(char *dest, char const *src, size_t size);

char const	*ft_strstr(char const *str)
{
	size_t	i;
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

int	main(void)
{
	char const *s1 = "hello\n you";
	char const *s2 = ft_strstr(s1);

	printf("%s", s2);
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

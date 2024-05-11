#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlen(char const *str);

char	*ft_substring(char *str)
{
	ssize_t  len;
	ssize_t  i;
	char	*result;

	i = 0;
	len = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (str);
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!result)
		return (NULL);
    i++;
	ft_strlcpy(result, str + i, ft_strlen(str) - i + 1);
	//free (str);
	return (result);
}


int main(void)
{
    int i = 0;
    char    *s1 = "hello how are you\ndoing today\nI am";
    char    *s2 = "hello how are you\ndoing";
    char    *s3 = "hello";  

    char    *r1 = ft_substring(s1);
    char    *r2 = ft_substring(s2);
    char    *r3 = ft_substring(s3);

    printf("r1 is:%s\n", r1);
    printf("r2 is:%s\n", r2);
    printf("r3 is:%s\n", r3);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
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



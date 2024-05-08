/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dominicasal <dominicasal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:18:01 by dominicasal       #+#    #+#             */
/*   Updated: 2024/05/08 22:22:45 by dominicasal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void	*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
char	*print_stash(char *stash);
void	ft_bzero(void *s, size_t n);

char	*get_next_line(int fd)
{
	char	buffer[2];
	char	stash[BUFFER_SIZE];
	t_list		*new_node;
	int			j = 0;
	char	*result;

	while (1)
	{
		if (read(fd, buffer, 1) != 0)
		{
			new_node = ft_lstnew(buffer);
			stash[j] = *(char *)new_node->content;
			j++;
			if (buffer[0] == '\n')
			{
				result = print_stash(stash);
				ft_bzero(stash, j);
				return (result);
			}
		}
	}
	exit (0);
	return (0);
}

int	main(void)
{
	static int	fd;
	char	*result;
	
	fd = open("text.txt", O_RDONLY);

	while (1)
	{
		result = get_next_line(fd);
		printf("result is:%s", result);
	}
	close(fd);
	return (0);
}

char	*print_stash(char *stash)
{
	char	*result;
	size_t	len;

	len = 0;
	while (stash[len])
		len++;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, stash, len + 1);
	//printf("result is:%s\n", result);
	return (result);
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

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
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

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}
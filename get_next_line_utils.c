/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dominicasal <dominicasal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:18:06 by dasal             #+#    #+#             */
/*   Updated: 2024/05/11 01:24:49 by dominicasal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strxjoin(char *s1, char const *s2)
{
	ssize_t	s1_len;
	char	*result;
	char	*result_ptr;
	char	*cpy;

	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	result_ptr = result;
	cpy = s1;
	while (cpy && *cpy)
		*result_ptr++ = *cpy++;
	cpy = (char *)s2;
	while (cpy && *cpy)
		*result_ptr++ = *cpy++;
	free (s1);
	*result_ptr = '\0';
	return (result);
}

ssize_t	ft_strlen(char const *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

ssize_t	ft_find_char(char *str, char c)
{
	ssize_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*str_snip(char *str, ssize_t index)
{
	ssize_t		i;
	char	*result;

	i = 0;
	if ((!str) || index > ft_strlen(str)|| index < 0)
		return (NULL);
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

char	*ft_substring(char *str, ssize_t index)
{
	int		len;
	char	*result;

    if (!str)
		return (NULL);
	len = ft_strlen(str) - index;
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	len = 0;
	index++;
	while (str[index] != '\0')
	{
		result[len] = str[index];
		len++;
		index++;
	}
	result[len] = '\0';
	free (str);
	return (result);
}
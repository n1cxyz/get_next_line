/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dominicasal <dominicasal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:17:59 by dasal             #+#    #+#             */
/*   Updated: 2024/05/11 01:18:52 by dominicasal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char	*get_next_line(int fd);
char	*ft_strxjoin(char *s1, char const *s2);
ssize_t	ft_strlen(char const *str);
ssize_t	ft_find_char(char *str, char c);
char	*str_snip(char *str, ssize_t index);
char	*ft_substring(char *str, ssize_t index);

#endif
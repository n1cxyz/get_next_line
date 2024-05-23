/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:41:08 by dasal             #+#    #+#             */
/*   Updated: 2024/05/13 11:41:10 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef MAX_FD
#  define MAX_FD 3
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

char		*get_next_line(int fd);
char		*ft_substring(char *str);
char		*ft_strchr(char const *str, int c);
char		*ft_get_stash(char *stash, int fd);
char		*ft_strxjoin(char *line, char *buff);
ssize_t		ft_strlen(char const *str);
char		*str_snip(char *str);
size_t		ft_strlcpy(char *dest, char *src, size_t size);

#endif

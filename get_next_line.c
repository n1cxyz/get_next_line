/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:17:54 by dasal             #+#    #+#             */
/*   Updated: 2024/05/07 16:17:56 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcnt1.h>

int	open(const char *path, int flags[, int mode]);
ssize_t	read(int fildes, void *buf, size_t nbyte);
char	*get_next_line(int fd);
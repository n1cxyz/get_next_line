/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:41:03 by dasal             #+#    #+#             */
/*   Updated: 2024/05/13 11:41:04 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*result;
	
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	stash[fd] = ft_get_stash(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	result = str_snip(stash[fd]);
	stash[fd] = ft_substring(stash[fd]);
	return (result);
}	

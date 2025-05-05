/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:02:40 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/11/28 15:51:28 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	str = NULL;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
	{
		if (BUFFER_SIZE > 0 && fd > 0 && fd < FOPEN_MAX)
			ft_buffer_flusher(buffer, fd);
		return (NULL);
	}
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin_gnl(str, buffer[fd]);
		if (!str)
			return (NULL);
		ft_buffer_flusher(buffer, fd);
		if (str[ft_strlen_gnl(str) - 1] == '\n')
			break ;
	}
	return (str);
}

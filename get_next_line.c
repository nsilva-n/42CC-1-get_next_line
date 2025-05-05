/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:02:40 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/11/28 16:30:45 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	buffer[BUFFER_SIZE + 1];

	str = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		if (BUFFER_SIZE > 0)
			ft_buffer_flusher(buffer);
		return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin_gnl(str, buffer);
		if (!str)
			return (NULL);
		ft_buffer_flusher(buffer);
		if (str[ft_strlen_gnl(str) - 1] == '\n')
			break ;
	}
	return (str);
}

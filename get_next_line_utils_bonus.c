/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:41:31 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/11/29 14:18:12 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_gnl(const char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str && str[++i])
		if (str[i] == '\n')
			return (++i);
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = ft_strlen_gnl(s1);
	j = ft_strlen_gnl(s2);
	dest = malloc(sizeof(char) * (i + j + 1));
	if (!dest)
		return (free(s1), NULL);
	i = -1;
	while (++i >= 0 && s1 && s1[i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j] && j < ft_strlen_gnl(s2))
		dest[i++] = s2[j];
	dest[i] = '\0';
	if (s1)
		free(s1);
	return (dest);
}

void	ft_buffer_flusher(char buffer[FOPEN_MAX][BUFFER_SIZE + 1], int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!buffer[fd])
		return ;
	while (i < BUFFER_SIZE && buffer[fd][i] != '\n')
		i++;
	if (buffer[fd][i] == '\n' && i < BUFFER_SIZE)
		i++;
	while (i < BUFFER_SIZE)
	{
		buffer[fd][j++] = buffer[fd][i];
		buffer[fd][i++] = '\0';
	}
	while (j < BUFFER_SIZE)
		buffer[fd][j++] = '\0';
}

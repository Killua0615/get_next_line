/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:41:14 by nateshim          #+#    #+#             */
/*   Updated: 2024/11/17 20:41:33 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char *saved)
{
	int		len;
	char	*line;

	len = 0;
	if (!saved || !saved[len])
		return (NULL);
	while (saved[len] && saved[len] != '\n')
		len++;
	line = malloc(len + 2);
	if (!line)
		return (NULL);
	len = 0;
	while (saved[len] && saved[len] != '\n')
	{
		line[len] = saved[len];
		len++;
	}
	if (saved[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

static char	*update_saved(char *saved)
{
	int		start;
	char	*new_saved;
	int		len;

	start = 0;
	len = 0;
	while (saved[start] && saved[start] != '\n')
		start++;
	if (!saved[start++])
	{
		free(saved);
		return (NULL);
	}
	while (saved[start + len])
		len++;
	new_saved = malloc(len + 1);
	if (!new_saved)
		return (NULL);
	len = 0;
	while (saved[start])
		new_saved[len++] = saved[start++];
	new_saved[len] = '\0';
	free(saved);
	return (new_saved);
}

static char	*read_to_saved(int fd, char *saved)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(saved, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	free(buffer);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	saved[fd] = read_to_saved(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = extract_line(saved[fd]);
	saved[fd] = update_saved(saved[fd]);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayayamad <ayayamad@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 03:39:54 by ayayamad          #+#    #+#             */
/*   Updated: 2025/08/17 15:08:16 by ayayamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_all(char *buf, char *buffer)
{
	if (buf)
		free(buf);
	if (buffer)
		free(buffer);
	return (NULL);
}

static char	*read_file(int fd, char *save)
{
	int		bytes_read;
	char	*buf;

	if (!save)
		save = ft_calloc(1, sizeof(char));
	if (!save)
		return (NULL);
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while ((ft_strchr(save, '\n')) == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_all(buf, save));
		buf[bytes_read] = '\0';
		if (save && buf)
			save = ft_strjoin(save, buf);
		if (!save)
			return (NULL);
	}
	free(buf);
	return (save);
}

static char	*get_line(char *save)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!save || !save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*save_update(char *old_save)
{
	char	*new_save;
	size_t	line_len;
	size_t	j;
	size_t	i;

	line_len = ft_strlen(old_save);
	i = 0;
	while (old_save[i] && old_save[i] != '\n')
		i++;
	if (!old_save[i])
	{
		free(old_save);
		old_save = NULL;
		return (NULL);
	}
	new_save = ft_calloc((line_len - i + 1), sizeof(char));
	if (!new_save)
		return (NULL);
	i++;
	j = 0;
	while (old_save[i])
		new_save[j++] = old_save[i++];
	free(old_save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = read_file(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = save_update(save);
	return (line);
}

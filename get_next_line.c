/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayayamad <ayayamad@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 03:39:54 by ayayamad          #+#    #+#             */
/*   Updated: 2025/08/10 14:43:54 by ayayamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_find_new_line(int fd, BUFFER_SIZE)
{
	size_t	bytes_read;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(save));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(*save, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		ft_strjoin(save, buf);
	}
	return (ft_strchr(*save, '\n'));
}

static char	*get_line(char *line, char *save)

{
	int i;

	line = malloc((ft_strlen(save)) * sizeof(line));
	i = 0;
	while (save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	return (line);
}

static char	*save_update(char *old_save)
{
	char	*new_save;
	int		i;
	int		j;

	i = 0;
	while (old_save[i] != '\n')
		i++;
	j = 0;
	while (old_save[i] != '\0')
	{
		new_save[j] = old_save[i];
		j++;
		i++;
	}
	return (save);
}

char	*get_next_line(int fd, BUFFER_SIZE)
{
	static char	*save;
	char		*line;

	if (!read_to_find_new_line(fd, BUFFER_SIZE))
	{
		free(save);
		return (NULL);
	}
	line = get_line(*line, *save);
	save = save_update(*save);
	return (line);
}

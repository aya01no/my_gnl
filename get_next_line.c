/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayayamad <ayayamad@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 03:39:54 by ayayamad          #+#    #+#             */
/*   Updated: 2025/08/17 13:04:25 by ayayamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_find_new_line(int fd, char *save)
{
	int		bytes_read;
	char	*buf;
	char *temp;

	if (!save)
	save = malloc(1 * 1);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return ;
	bytes_read = 1;
	while (!(ft_strchr(buf, '\n')) || bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return(NULL) ;
		}
		buf[bytes_read] = '\0';
		temp = ft_strjoin(*save, buf);
		free(buf);
		save = temp;
	}
	free(buf);
	return(save);
}

static char	*get_line(char *save)
{
	size_t	i;
	char	*line;

	i = 0;
	if (save[i])
	return(NULL);
	while (save[i] && save[i] !='\n')
	i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*save_update(char *old_save)
{
	char	*new_save;
	size_t	j;
	size_t	i;

	i = 0;
	while (old_save[i] && old_save[i] == '\0')
	i++;
	if(!old_save[i])
	{
		free(old_save);
		return (NULL);
	}
	new_save = malloc((ft_strlen(old_save) - i + 1) * sizeof(char));
	if (!new_save)
	{
		free(old_save);
		return (NULL);
	}
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
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_to_find_new_line(fd, &save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = save_update(save);
	return (line);
}
int	main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}

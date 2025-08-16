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

static void	read_to_find_new_line(int fd, char **save_ptr)
{
	int		bytes_read;
	char	*buf;
	char	*temp;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return ;
	bytes_read = 1;
	while (!ft_strchr(*save_ptr, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return ;
		}
		buf[bytes_read] = '\0';
		temp = ft_strjoin(*save_ptr, buf);
		free(*save_ptr);
		*save_ptr = temp;
	}
	free(buf);
}

static char	*get_line(char *line, char *save)
{
	size_t	i;
	size_t	line_len;

	line_len = get_line_length(save);
	line = malloc((line_len + 2) * sizeof(char));
	i = 0;
	while (i < line_len)
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\n';
	i++;
	line[i] = '\0';
	return (line);
}

static char	*save_update(char *old_save)
{
	char	*new_save;
	size_t	line_len;
	size_t	total_len;
	size_t	remainder_len;
	size_t	i;

	line_len = get_line_length(old_save);
	total_len = ft_strlen(old_save);
	remainder_len = total_len - line_len - 1;
	new_save = malloc((remainder_len + 1) * sizeof(char));
	i = 0;
	while (old_save[line_len + 1 + i] != '\0')
	{
		new_save[i] = old_save[line_len + 1 + i];
		i++;
	}
	new_save[i] = '\0';
	free(old_save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	read_to_find_new_line(fd, &save);
	if (!save || *save == '\0')
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = get_line(line, save);
	save = save_update(save);
	return (line);
}
int	main(void)
{
	int fd;
	char *line;

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

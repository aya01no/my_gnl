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

static void	get_line(void)
	/*
	行の切り出し
	もしループを抜けたなら、saveの中に改行があったか、ファイルを読み終わったか
	改行まで、もしくは終端までの文字数を数える
	改行があったら
	　改行までをlineにコピー
	　改行以降をnew_saveにコピー
	old_saveはfree
	改行がなくて終端までいったら
	saveの文字を全部lineにいれる
	new_saveをlineにコピーしてnull
	old_saveはfree

	lineをreturnする

	*/
	int get_next_line(int fd, BUFFER_SIZE)
{
	static char	*save;
	char		*line;

	if (!read_to_find_new_line(fd, BUFFER_SIZE))
	{
		free(save);
		return (NULL);
	}
	else
		get_line();
}

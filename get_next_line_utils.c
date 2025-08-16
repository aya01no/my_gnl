/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayayamad <ayayamad@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 06:29:24 by ayayamad          #+#    #+#             */
/*   Updated: 2025/08/10 14:41:29 by ayayamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	size_t	s_len;

	s_len = 0;
	if (!s)
		return (0);
	while (s[s_len] != '\0')
		s_len++;
	return (s_len);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
	}
	return (0);
}

size_t	get_line_length(char *s)
{
	char	*newline_ptr;

	if (!s)
		return (0);
	newline_ptr = ft_strchr(s, '\n');
	if (newline_ptr != NULL)
		return (newline_ptr - s);
	return (ft_strlen(s));
}

char	*ft_strjoin(char *save, char *buf)
{
	int		i;
	int		j;
	int		save_len;
	int		buf_len;
	char	*new_str;

	i = 0;
	if (!save)
		save_len = 0;
	else
		save_len = ft_strlen(save);
	buf_len = ft_strlen(buf);
	new_str = malloc((save_len + buf_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	j = 0;
	if (save)
	{
		while (save[j] != '\0')
			new_str[i++] = save[j++];
		j = 0;
		while (buf[j] != '\0')
			new_str[i++] = buf[j++];
		new_str[i] = '\0';
	}
	return (new_str);
}

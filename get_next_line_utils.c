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
	int	s_len;

	s_len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		s_len++;
		s++;
	}
	return (s_len);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	// if (c == '\0')
	// 	return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
	}
	return (0);
}

char	*ft_strjoin(char *save, char *buf)
{
	int	i;

	int save_len; //あとで変数名変える
	i = 0;
	if (!save[0])
		save_len = 0;
	else
		save_len = ft_strlen(save);
	while (buf[i] != '\0')
	{
		save[save_len] = buf[i];
		i++;
		save_len++;
	}
	save[save_len] = '\0';
	free(buf);
	return (save);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayayamad <ayayamad@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 06:29:24 by ayayamad          #+#    #+#             */
/*   Updated: 2025/08/17 15:06:51 by ayayamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	s_len;

	s_len = 0;
	if (!s)
		return (0);
	while (s[s_len] != '\0')
		s_len++;
	return (s_len);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;

	temp = malloc(size * count);
	if (!temp)
		return (NULL);
	ft_bzero(temp, size * count);
	return (temp);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_calloc((total_len + 1), sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
		new_str[i++] = s2[j++];
	new_str[total_len] = '\0';
	if (s1)
		free(s1);
	return (new_str);
}

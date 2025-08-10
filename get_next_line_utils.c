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

	s_len == 0;
	if (!s)
		return(NULL);
	while (*s)
	{
		s_len++;
		s++;
	}
	return(s_len);

}

// 文字列（save一時保存場所）の改行までか終端までの文字数返す
int	*ft_save_len(char *save)
{
	int save_len;

	if (!save)
		return (NULL);
	while (*save)
	{
		save_len++;
		if (*save == '\n')
			return (save_len);
		save++;
	}
	// 終端でも改行でもない場合ってあるのか？ほかに考えるべきエラー処理は？
	//readで読んだだけだと終端ないんだっけ？
	return (save_len);
}

int	ft_strchr(char *s, int i)
{
	if (!s)
		return(NULL);
	while (s != i)
	{
		s++;
	}
}

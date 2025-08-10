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
/*
line　出力する文字列（改行まで）
static char *save　改行が出たあと、文字列が終わるまで保存しておく文字列
buf　readして読み込んだものが入ってる文字列

readで読み込む
bufの中に改行があるか調べる
−1ならbufとか全部freeして−1returnする
0ならそこで処理終了
1かつ改行が見つからなければ繰り返す

改行まで、もしくは終端までの文字数数える
改行があったらそこまでlineにコピーする
　　改行一致したら
	bufの改行までの文字数分strnjoinでlineに足す
　　saveにそれ以降の文字をコピーする
	strdupでmallocしつつ確保する
なかったらlineに全部いれる
　bufの文字数ぶんlineにコピーする
saveはnullにする



saveの確認
前回のsaveに改行が含まれているか確認する
if(ft_line_len(save, ))
もしあれば切り出しに進む

readtofindnewline関数
saveのなかに改行がない　かつ　ファイルを読み終わってない
save_lenに回して帰ってきた文字数がstrlenの文字数とどうか比較する
*/
//文字数が同じなら終端まで、少ないなら改行があったと判断
//ファイルを読み終わっていないかの判断はどうすればいい？
//戻ってきた数⁺1してなにかあるかどうか見る？
void	read_to_find_new_line (fd)
{
	size_t bytes_read;
	//saveがstatcであってる？なんのためか説明できる？

	static char *save;


	if (BUFFER_SIZE < 0)
		return (NULL);
	if (ft_save_len(save) < ft_strlen(save) && save[ft_save_len(save) + 1])
	{
		bytes_read = read(fd, save, BUFFER_SIZE);
	}
	//saveに改行があったら切り出し関数に回す
	while (ft_save_len(save) < ft_strlen(save))
	{
		/* code */
	}

/*
文字数数えよりもstrchrで見て改行あるか判定して
readして終端つけてもとのやつとくっつける関数のほうが
読みやすいし意図が伝わるのでは*/

/*
buffer_sizeぶんreadしてbufにいれていく
readの戻り値チェック
　0　break
 -1 lineとsaveをfreeして-1returnする
 0以上　saveにbufをくっつけたものを新しいsaveにする
*/
}
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
int	get_next_line

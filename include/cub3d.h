/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:13:57 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/07 18:56:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* header*/
# include "get_next_line.h"
# include "libft.h"

/* mlx library */
# include <mlx.h>

/* library */
/* ---- macの場合、以下2つをコメントアウト ---- */
// # include <X11/keysym.h>
// # include <X11/X.h>
# include <stdio.h>


/* macro */
# define ERR_SYSCALL 1
# define EMPTY	'0'
# define WALL	'1'
# define POS_NORTH	'N'
# define POS_SOUTH	'S'
# define POS_EAST	'E'
# define POS_WEST	'W'


/* struct */
typedef struct s_pos
{
	int	y;
	int	x;
}				t_pos;

typedef struct s_texture
{
	/*
	void	*no_img;//mlxで初期化して格納する
	void	*so_img;//mlxで初期化して格納する
	void	*we_img;//mlxで初期化して格納する
	void	*ea_img;//mlxで初期化して格納する
	int		f_color;//16進数に変換して格納する
	int		c_color;//16進数に変換して格納する
	*/
	char	*no_img;//一旦テスト用に文字列のままで格納
	char	*so_img;//一旦テスト用に文字列のままで格納
	char	*we_img;//一旦テスト用に文字列のままで格納
	char	*ea_img;//一旦テスト用に文字列のままで格納
	char	*f_color;//一旦テスト用に文字列のままで格納
	char	*c_color;//一旦テスト用に文字列のままで格納
}				t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_pos		player;//プレイヤーの位置を記録(動くたびに変わる)
	char		**map;//空白には空白を、最後の文字の次には改行or|0を入れる
	t_texture	*texture;
}				t_data;

/* function */
void	init_data(t_data **data, char *file);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);

#endif

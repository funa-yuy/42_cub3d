/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:13:57 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/08 16:50:04 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ------------------------------------------------
// include header
// ------------------------------------------------
# include "get_next_line.h"
# include "libft.h"

/* library */
# include <stdio.h>
# include <mlx.h>
/* ---- macの場合、以下2つをコメントアウト ---- */
// # include <X11/keysym.h>
// # include <X11/X.h>

// ------------------------------------------------
// macro
// ------------------------------------------------
# define ERR_SYSCALL 1
# define EMPTY	'0'
# define WALL	'1'
# define POS_NORTH	'N'
# define POS_SOUTH	'S'
# define POS_EAST	'E'
# define POS_WEST	'W'

// ------------------------------------------------
// struct
// ------------------------------------------------
typedef struct s_strlst
{
	char				*str;
	struct s_strlst		*next;
	struct s_strlst		*prev;
}				t_strlst;

typedef struct s_parse_tmp
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*f_rgb;
	char	*c_rgb;
	char	**map_lines; // 最後に map だけ残っていた行をまとめる（ここで一旦char **に）
}	t_parse_tmp;

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

// ------------------------------------------------
// function
// ------------------------------------------------
/* main */
t_data		*init_cubdata(char *file);

/* init */
t_strlst	*init_lst_data(char *file);
t_strlst	*normalize_cubdata(char *file);
/* utils */
void		str_lstadd_back(t_strlst **lst, t_strlst *new);
t_strlst	*str_lstnew(char *str);
size_t		str_lstsize(t_strlst *lst);

/* dedug 最終的には削除する*/
void		debug_print_data(t_data *data);
void		debug_print_strlst(t_strlst *lst);

#endif

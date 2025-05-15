/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:13:57 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/15 18:10:14 by miyuu            ###   ########.fr       */
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
# include <string.h>
# include <sys/errno.h>
# include <mlx.h>
/* ---- macの場合、以下2つをコメントアウト ---- */
// # include <X11/keysym.h>
// # include <X11/X.h>

// ------------------------------------------------
// macro
// ------------------------------------------------
# define IMG_SIZE	64

// # define EMPTY	'0'
// # define WALL	'1'
// # define POS_NORTH	'N'
// # define POS_SOUTH	'S'
// # define POS_EAST	'E'
// # define POS_WEST	'W'

// ------------------------------------------------
// struct
// ------------------------------------------------
typedef enum e_map_type
{
	EMPTY,//0
	WALL,//1
}	t_map_type;

typedef enum e_player_dir
{
	DIR_NORTH,//N
	DIR_SOUTH,//S
	DIR_EAST,//E
	DIR_WEST,//W
}	t_player_dir;

typedef struct s_pos
{
	unsigned int	y;
	unsigned int	x;
	char			dir;
	// t_player_dir	dir;//todo: enumにする
}				t_pos;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_pos			player;//プレイヤーの初期位置&向き
	unsigned int	width;
	unsigned int	height;
	char			**map;
	// int				*map;	//todo: mapを1次元配列にする→enumを格納する
	void			*no_img;//mlx_put_image_to_windowしたもの
	void			*so_img;//mlx_put_image_to_windowしたもの
	void			*we_img;//mlx_put_image_to_windowしたもの
	void			*ea_img;//mlx_put_image_to_windowしたもの
	int				f_color;//16進数　に変換したカラー
	int				c_color;//16進数　に変換したカラー
}				t_data;

typedef struct s_strlst
{
	char				*str;
	struct s_strlst		*next;
	struct s_strlst		*prev;
}				t_strlst;

typedef struct s_tokens_tmp
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*f_rgb;
	char	*c_rgb;
	char	**map_lines;
}	t_tokens_tmp;

// ------------------------------------------------
// function
// ------------------------------------------------
/* main */
t_data			*init_cubdata(char *file);

/* init */
t_strlst		*init_lst_data(char *file);
t_strlst		*normalize_cubdata(char *file);
t_tokens_tmp	*tokenize_lines(const t_strlst *lines);
t_data			*parse_to_data(const t_tokens_tmp *tokens);
void			fill_map(t_data *d, char **map_lines);
void			fill_images(t_data *data, const t_tokens_tmp *tokens);
void			fill_color(t_data *data, const t_tokens_tmp *tokens);
void			fill_player_position(t_data *data);
void			free_data(t_data *d);
/* init/utils */
void			str_lstadd_back(t_strlst **lst, t_strlst *new);
t_strlst		*str_lstnew(char *str);
size_t			str_lstsize(const t_strlst *lst);
void			free_str_array(char **str);
void			error_print_and_exit(char *str);
void			error_perror_and_exit(char *str);

/* dedug 最終的には削除する?*/
void			debug_print_data(t_data *data);
void			debug_print_strlst(t_strlst *lst);
void			debug_print_tokens_tmp(const t_tokens_tmp *p);
int				debug_dprintf(int fd, const char *format, ...);

#endif

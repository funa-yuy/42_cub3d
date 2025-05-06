/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:13:57 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/06 21:08:26 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* header*/
# include "get_next_line.h"

/* mlx library */
# include <mlx.h>

/* library */
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>


/* macro */
# define IMG_SIZE	32
# define MAX_MAP	100

# define EMPTY	'0'
# define WALL	'1'
# define POS_NORTH	'N'
# define POS_SOUTH	'S'
# define POS_EAST	'E'
# define POS_WEST	'W'


# define XPM_EMPTY		"textures/empty.xpm"
# define XPM_WALL		"textures/wall.xpm"
# define XPM_COLLECT	"textures/collects.xpm"
# define XPM_EXIT		"textures/exit.xpm"
# define XPM_PLAYER		"textures/souzou_got_01.xpm"

/* struct */
typedef struct pos
{
	int	i;
	int	j;
}				t_pos;

typedef struct s_img
{
	void	*em_img;
	void	*wall_img;
	void	*col_img;
	void	*exit_img;
	void	*p_img;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		*img;
	int			count;
	int			coll_con;
	int			y_column;
	int			x_row;
	void		*p[MAX_MAP][MAX_MAP];
	char		**map;
	t_pos		player;
	t_pos		exit;
}				t_data;

/* function */
void	init_map_data(t_data **data, char *file);

#endif

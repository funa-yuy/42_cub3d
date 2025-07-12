#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "frames.h"
# include "vec.h"
# include <stdint.h>

typedef struct s_fence
{
	uint32_t	*buf;
	int			height;
}				t_fence;

int				draw_vertical_line(void *mlx_addr, t_vec_i32x4 start,
					uint32_t vline[], int vline_len);

uint32_t		*get_vertical_arr_n(void *img_arr, int index, t_vec_i32x4 size,
					int out_size);

int				render_wall_to_screen(t_data *data,
					t_axis_xy_frames axis_xy_frames, t_f32x4 player);

t_f32x4			get_cross_wall(t_axis_xy_frames walls,
					t_line_segment player_ray,
					t_line_segment *wall_line_segment);

int				set_backcolor(void *mlx_addr, uint32_t ceil_color,
					uint32_t floor_color);
#endif

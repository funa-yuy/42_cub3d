#ifndef RENDER_H
#define RENDER_H

#include "vec.h"
#include "frames.h"

#include <stdint.h>
#include "cub3d.h"

typedef
struct s_fence{
	uint32_t *buf;
	int height;
} t_fence;

int draw_vertical_line(
	void *mlx_addr, // mut
	t_vec_i32x4 start, // スクリーン上で始点になるベクトル
	uint32_t vline[],
	int vline_len
);

uint32_t *get_vertical_arr_n(void *img_arr, int index, t_vec_i32x4 size, int out_size);

int render_wall_to_screen(
	t_data *data,
       	t_axis_xy_frames axis_xy_frames,
	t_f32x4 player // t_f32x4(reserved , player_x, player_y, player_angle)
);

t_f32x4 get_cross_wall(
	t_axis_xy_frames walls,            // 交わる可能性のある壁ベクトルの集合
	t_line_segment player_ray,         // playerからの視線ベクトル
	t_line_segment *wall_line_segment  // 交わった壁のベクトルがここに格納される
);
#endif

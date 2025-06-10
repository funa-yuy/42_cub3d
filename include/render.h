#ifndef RENDER_H
#define RENDER_H

#include "vec.h"
#include <stdint.h>

typedef
struct s_fence{
	uint32_t *buf;
	int height;
} t_fence;

int draw_vertical_line(
	void *mlx_addr, // mut
	t_vec_i32x4 start, // スクリーン上で始点になるベクトル
	uint32_t vline[],
	size_t vline_len
);

uint32_t *get_vertical_arr_n(void *img_arr, size_t index, t_vec_i32x4 size, int out_size);

#endif

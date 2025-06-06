#ifndef RENDER_H
#define RENDER_H

#include "vec.h"
#include <stdint.h>

int draw_vertical_line(
	void *mlx_addr, // mut
	t_vec_i32x4 start, // スクリーン上で始点になるベクトル
	uint32_t vline[],
	size_t vline_len
);

#endif

#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include "vec.h"

typedef struct s_line_segment t_line_segment;

struct s_line_segment 
{
	t_f32x4 s;
	t_f32x4 e;
};

bool has_cross_point(t_line_segment a, t_line_segment b);

t_line_segment *get_line_segment_arr(size_t width, size_t height);
#endif

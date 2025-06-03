#include <stdlib.h>
#include "line_segment.h"

t_line_segment *get_line_segment_arr(size_t width, size_t height)
{
	return (malloc(sizeof(t_line_segment) * width * height));
}

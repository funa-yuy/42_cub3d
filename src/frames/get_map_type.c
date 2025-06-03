#include "cub3d.h"
#include <stdlib.h>

/// 範囲外にアクセスした場合には
/// wallを返却します
enum e_map_type get_map_type(
	t_data *data,
	size_t x,
	size_t y
)
{
	if (!(0 <= x && x < data->width))
		return (WALL);
	if (!(0 <= y && y < data->height))
		return (WALL);
	return (
		data->map[y * data->width + x]
	);
}


#include "cub3d.h"
#include <stdlib.h>

/// 範囲外にアクセスした場合には
/// wallを返却します
enum e_map_type	get_map_type(t_data *data, size_t x, size_t y)
{
	if (!(x < data->width))
		return (WALL);
	if (!(y < data->height))
		return (WALL);
	return (data->map[y * data->width + x]);
}

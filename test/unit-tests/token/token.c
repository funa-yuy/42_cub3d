#include <stdio.h>
#include "cub3d.h"

int	main(void)
{
	const t_strlst		*lines_list;

	lines_list = NULL;
	lines_list = normalize_cubdata("map/test_parse/ok/simple.cub");
	debug_print_strlst((t_strlst *)lines_list);
	return (0);
}

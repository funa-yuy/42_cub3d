#include "cub3d.h"
#include "frames.h"
#include "vec.h"

t_wall_type get_wall_type_by_line_segment(t_line_segment a)
{
	t_vec_f32x4 s_v;
	t_vec_f32x4 e_v;

	s_v = f32x4_to_struct(a.s);
	e_v = f32x4_to_struct(a.e);
	if (s_v.x == e_v.x)
	{
		if (e_v.y < s_v.y)
			return (e_wall_type_we_img); // 西側
		else
			return (e_wall_type_ea_img);// 東側
	}
	else
	{
		if (e_v.x < s_v.x)
			return (e_wall_type_so_img);
		else
			return (e_wall_type_no_img);
	}
}

void *get_wall_img_by_wall_type_enum(t_data data, t_wall_type t)
{
	if (t == e_wall_type_no_img)
		return (data.no_img_addr);
	else if (t == e_wall_type_ea_img)
		return (data.ea_img_addr);
	else if (t == e_wall_type_so_img)
		return (data.so_img_addr);
	else 
		return (data.we_img_addr);
}

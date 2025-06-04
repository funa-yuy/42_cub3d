#include "vec.h"
#include "line_segment.h"
#include "cub3d.h"
#include <assert.h>
#include <unistd.h>

/// 交わるケース
void test00()
{
	t_f32x4 p;

	p = cross_point(
		// t_line_segment(線分)は２つの位置ベクトルから構成される
		// 今回は二次元平面しか扱わないため、x成分、y成分のみ有効
		(t_line_segment) { 
			.s=init_f32x4(0, 0, 0, 0),
			.e=init_f32x4(0, 1, 1, 0)
		},
		(t_line_segment) {
			.s=init_f32x4(0, 1, 0, 0),
			.e=init_f32x4(0, 0, 1, 0)
		}
	);
	print_f32x4("cross point", p);
	if (eq_f32x4(p, init_f32x4(0, 0.5, 0.5, 0))) // 予想される交点
		debug_dprintf(STDERR_FILENO, "Ok\n");
	else
		debug_dprintf(STDERR_FILENO, "KO\n");
}

/// 直線では交わるが線分では交わらないケース
void test01()
{
	t_f32x4 p;

	p = cross_point(
		// t_line_segment(線分)は２つの位置ベクトルから構成される
		// 今回は二次元平面しか扱わないため、x成分、y成分のみ有効
		(t_line_segment) { 
			.s=init_f32x4(0, 0, 0, 0),
			.e=init_f32x4(0, 1, 0, 0)
		},
		(t_line_segment) {
			.s=init_f32x4(0, 0, 3, 0),
			.e=init_f32x4(0, 1, 2, 0)
		}
	);
	print_f32x4("cross point", p);
	if (eq_f32x4(p, init_f32x4(1, 0, 0, 0))) // エラーの場合はwに1が格納される
		debug_dprintf(STDERR_FILENO, "Ok\n");
	else
		debug_dprintf(STDERR_FILENO, "KO\n");
}
/// ```
/// make test test/unit-tests/vec/vec_test02.c
/// ```
int main()
{
	test00();
	test01();
}

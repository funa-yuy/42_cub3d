#include "vec.h"
#include "cub3d.h"

#include <unistd.h>
#include <stdbool.h>
#include <assert.h>

t_f32x4 solve(
	t_f32x4 a,
	t_f32x4 b
)
{
	t_vec_f32x4 a_s;
	t_vec_f32x4 b_s;
	t_f32x4 ans;

	a_s = f32x4_to_struct(a);
	b_s = f32x4_to_struct(b);
	debug_dprintf(STDERR_FILENO, "%f*x + %f*y = %f\n", a_s.x, a_s.y, a_s.z);
	debug_dprintf(STDERR_FILENO, "%f*x + %f*y = %f\n", b_s.x, b_s.y, b_s.z);
	ans = linear_solver(a, b);
	print_f32x4("linear_solver", ans);
	return (ans);
}

bool
check_ans(t_f32x4 eqa, t_f32x4 ans)
{
	t_vec_f32x4 eqa_s;
	t_vec_f32x4 ans_s;

	eqa_s = f32x4_to_struct(eqa);
	ans_s = f32x4_to_struct(ans);
	if (ans_s.w == 1)
		return (true);
	return (eqa_s.x * ans_s.x + eqa_s.y * ans_s.y == eqa_s.z);
}

bool
test(
	t_f32x4 a,
	t_f32x4 b
)
{
	t_f32x4 ans;

	ans = solve(a, b);
	return (check_ans(a, ans) && check_ans(b, ans));
}


/// ```
/// make test test/unit-tests/vec/vec_test01.c
/// ```
int main()
{
	debug_dprintf(
		STDERR_FILENO,
		"二元一次連立方程式を解く関数のテスト\n");
	if (test(
		init_f32x4(0, 2, 8, 18), // 2x + 8y = 18
		init_f32x4(0, 1, 1, 3)   // x + y = 3
	))
		debug_dprintf(STDERR_FILENO, "Ok\n");
	else
		debug_dprintf(STDERR_FILENO, "KO\n");

	if (test(
		init_f32x4(0, 5, -5, 10), // 5x - 5y = 10
		init_f32x4(0, 1, 10, 57)  // x + 10y = 57
	))
		debug_dprintf(STDERR_FILENO, "Ok\n");
	else
		debug_dprintf(STDERR_FILENO, "KO\n");

	if (test(
		init_f32x4(0, 5, -5, 10), // 5x - 5y = 10
		init_f32x4(0, 10, -10, 20) // 10x - 10y = 20
	)) // 平行な場合はwに１が入る
		debug_dprintf(STDERR_FILENO, "Ok\n");
	else
		debug_dprintf(STDERR_FILENO, "KO\n");
}

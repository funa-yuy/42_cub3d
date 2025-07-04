#include "cub3d.h"
#include "move.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/* テスト用のヘルパー関数 */
void	test_assert_with_result(bool actual, bool expected, const char *test_name)
{
	if (actual == expected)
		printf("✅ %s: %s\n", test_name, actual ? "true(壁)" : "false(壁ではない)");
	else
		printf("❌ %s: expected %s, got %s\n", test_name,
			expected ? "true(壁)" : "false(壁ではない)", actual ? "true" : "false");
}

int	test00(void)
{
	enum e_map_type basic_map[] = {
		WALL, WALL, WALL,
		WALL, EMPTY, WALL,
		WALL, WALL, WALL
	};

	t_data basic_data = {
		.map = basic_map,
		.width = 3,
		.height = 3
	};

	// NOTHING位置テスト用マップ
	enum e_map_type nothing_map[] = {
		WALL, WALL, WALL,
		WALL, NOTHING, WALL,
		WALL, WALL, WALL
	};

	t_data nothing_data = {
		.map = nothing_map,
		.width = 3,
		.height = 3
	};

	printf("壁衝突判定テスト開始\n");
	printf("================================\n");
	// テスト: 範囲外の座標（負の値）
	test_assert_with_result(can_move_position(&basic_data, -1.0f, 1.0f), true, \
				"負の座標(-1.0f, 1.0f)は");

	// テスト: 範囲外の座標（xが0.0）
	test_assert_with_result(can_move_position(&basic_data, 0.0f, 1.0f), true, \
				"範囲外の座標(0.0f, 1.0f)は");

	// テスト: 範囲外の座標（yが0.0）
	test_assert_with_result(can_move_position(&basic_data, 1.0f, 0.0f), true, \
				"範囲外の座標(1.0f, 0.0f)は");

	// テスト: 範囲外の座標（xが4.0）
	test_assert_with_result(can_move_position(&basic_data, 0.0f, 4.0f), true, \
				"範囲外の座標(0.0f, 4.0f)は");

	// テスト: 範囲外の座標（yが4.0）
	test_assert_with_result(can_move_position(&basic_data, 4.0f, 0.0f), true, \
				"範囲外の座標(4.0f, 0.0f)は");

	// テスト: EMPTY位置の場合
	test_assert_with_result(can_move_position(&basic_data, 1.0f, 1.0f), false, \
				"  EMPTY位置(1.0f, 1.0f)は");

	// テスト: WALL位置の場合
	test_assert_with_result(can_move_position(&basic_data, 0.0f, 2.0f), true, \
				"   WALL位置(0.0f, 2.0f)は");

	// テスト: NOTHING位置の場合
	test_assert_with_result(can_move_position(&nothing_data, 1.0f, 1.0f), true, \
				"NOTHING位置(1.0f, 1.0f)は");

	// テスト: 境界値テスト（xの境界）
	test_assert_with_result(can_move_position(&basic_data, 1.9f, 1.0f), false, \
				"ギリギリEMPTYの位置(1.9f, 1.0f)は");
	test_assert_with_result(can_move_position(&basic_data, 0.9f, 1.0f), true, \
				"ギリギリWALLの位置(0.9f, 1.0f)は");

	// テスト: 境界値テスト（yの境界）
	test_assert_with_result(can_move_position(&basic_data, 1.0f, 1.9f), false, \
				"ギリギリEMPTYの位置1.0f, 1.9f)は");
	test_assert_with_result(can_move_position(&basic_data, 1.0f, 0.9f), true, \
				"ギリギリWALLの位置(1.0f, 0.9f)は");

	printf("================================\n");
	printf("✨ 壁衝突判定テスト完了\n");

	return (0);
}

/// ```bash
/// make test test/unit-tests/move/can_move_test00.c
/// ```
int	main(void)
{
	int	status;

	status = test00();
	return (status);
}

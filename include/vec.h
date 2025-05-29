#ifndef VEC_H 
#define VEC_H

// for sse/avx header
#include <immintrin.h>
#include <stdbool.h>

typedef __m128 t_f32x4; // t_f32x4(f32, f32, f32, f32)

typedef struct s_vec_f32x4 t_vec_f32x4;
struct s_vec_f32x4 {
	float z;
	float y;
	float x;
	float w;
};

t_f32x4 init_f32x4(float w,float x, float y, float z);

// instructions

t_f32x4 add_f32x4(t_f32x4 a, t_f32x4 b);

t_f32x4 sub_f32x4(t_f32x4 a, t_f32x4 b);

t_f32x4 mul_f32x4(t_f32x4 a, t_f32x4 b);

t_f32x4 div_f32x4(t_f32x4 a, t_f32x4 b);

// access to each elements of vec

float f32x4_w(t_f32x4 a);

float f32x4_x(t_f32x4 a);

float f32x4_y(t_f32x4 a);

float f32x4_z(t_f32x4 a);

void set_f32x4_to_arr(float arr[4], t_f32x4 a);

t_vec_f32x4 f32x4_to_struct(t_f32x4 a);

// debug function

void print_f32x4(char *str, t_f32x4 a);

bool eq_f32x4(t_f32x4 a, t_f32x4 b);

#endif


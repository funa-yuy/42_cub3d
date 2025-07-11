#include <stdbool.h>
#include <math.h>

bool	float_equal(float a, float b, float epsilon)
{
	return (fabsf(a - b) < epsilon);
}

bool	float_less_equal(float a, float b, float epsilon)
{
	return ((a < b) || float_equal(a, b, epsilon));
}

#include "MathLib/MathFunctions.h"

#include <cfloat>
#include <cmath>

namespace MathLib
{
	bool MathFunctions::Compare(float a, float b, float threshold)
	{
		return fabsf(a - b) <= (FLT_EPSILON + threshold) * fmaxf(1.f, fmaxf(fabsf(a), fabsf(b)));
	}

	float MathFunctions::Clamp(float value, float min, float max)
	{
		if (value < min)
		{
			return min;
		}

		if (value > max)
		{
			return max;
		}

		return value;
	}

	float MathFunctions::Clamp01(float value)
	{
		if (value < 0.f)
		{
			return 0.f;
		}

		if (value > 1.f)
		{
			return 1.f;
		}

		return value;
	}
}

#pragma once

namespace MathLib
{
	class MathFunctions
	{
	public:
		static bool Compare(float a, float b, float threshold = 0.00001f);
		static float Clamp(float value, float min, float max);
		static float Clamp01(float value);

	};
}
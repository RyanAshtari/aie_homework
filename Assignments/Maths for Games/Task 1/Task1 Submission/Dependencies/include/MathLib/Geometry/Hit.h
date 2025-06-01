#pragma once

#include "MathLib/Types/Vec2.h"

namespace MathLib
{
	class Hit
	{
	public:
		Vec2 point;
		Vec2 normal;
		Vec2 delta;

	public:
		Hit();
		Hit(Vec2 point, Vec2 normal, Vec2 delta);

	public:
		bool operator==(const Hit& rhs) const;
		bool operator!=(const Hit& rhs) const;
	};
}
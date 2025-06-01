#pragma once

#include "MathLib/Types/Vec2.h"

namespace MathLib
{
	class Hit;
	class Rect;

	class Circle
	{
	public:
		Vec2 center;
		float radius;

	public:
		Circle();
		Circle(Vec2 center, float radius);

	public:
		bool Overlaps(Rect* other);

		Hit* Intersects(const Vec2& point) const;
		Hit* Intersects(const Circle& circle) const;

		float SqrRadius() const;

	public:
		bool operator==(const Circle& rhs) const;
		bool operator!=(const Circle& rhs) const;
	};
}
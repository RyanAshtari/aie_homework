#pragma once

#include "MathLib/Types/Vec2.h"

namespace MathLib
{
	class Hit;
	class Circle;

	class Rect
	{
	public:
		Vec2 center;
		Vec2 extents;

	public:
		Rect();
		Rect(Vec2 center, Vec2 extents);

	public:
		Vec2 Min() const;
		Vec2 Max() const;

		bool Contains(const Vec2& point) const;
		bool Overlaps(Circle* other) const;

		Hit* Intersects(const Vec2& point) const;
		Hit* Intersects(const Rect& rect) const;

	public:
		operator Rectangle();

		bool operator==(const Rect& rhs) const;
		bool operator!=(const Rect& rhs) const;
	};
}
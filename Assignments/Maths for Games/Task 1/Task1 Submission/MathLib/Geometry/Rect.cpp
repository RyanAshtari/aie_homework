#include "MathLib/Geometry/Rect.h"

#include "MathLib/MathFunctions.h"
#include "MathLib/Geometry/Circle.h"
#include "MathLib/Geometry/Hit.h"

namespace MathLib
{
	Rect::Rect()
		: center{ 0 }, extents{ .5f }
	{
	}

	Rect::Rect(Vec2 center, Vec2 extents)
		: center{ std::move(center) }, extents{ std::move(extents) }
	{
	}

	Vec2 Rect::Min() const
	{
		return center - extents;
	}

	Vec2 Rect::Max() const
	{
		return center + extents;
	}

	bool Rect::Contains(const Vec2& point) const
	{
		Vec2 min = Min();
		Vec2 max = Max();

		return point.x > min.x && point.x < max.x &&
			point.y > min.y && point.y < max.y;
	}

	bool Rect::Overlaps(Circle* other) const
	{
		Vec2 min = Min();
		Vec2 max = Max();

		Vec2 a =
		{
			MathFunctions::Clamp(other->center.x, min.x, max.x),
			MathFunctions::Clamp(other->center.y, min.y, max.y)
		};

		Vec2 v = a - other->center;

		return v.Dot(v) <= other->SqrRadius();
	}

	Hit* Rect::Intersects(const Vec2& point) const
	{
		if (!Contains(point))
		{
			return nullptr;
		}

		Vec2 vec = point - center;
		Vec2 penetration = extents - Vec2{ fabsf(vec.x), fabsf(vec.y) };

		Vec2 position = { 0.f, 0.f };
		Vec2 normal = { 0.f, 0.f };
		Vec2 delta = { 0.f,0.f };

		if (penetration.x < penetration.y)
		{
			float xDir = vec.x < 0.f ? -1.f : 1.f;
			delta.x = penetration.x * xDir;
			normal.x = xDir;
			position.x = center.x + extents.x * xDir;
			position.y = point.y;
		}
		else
		{
			float yDir = vec.y < 0.f ? -1.f : 1.f;
			delta.y = penetration.y * yDir;
			normal.y = yDir;
			position.x = point.x;
			position.y = center.y + extents.y * yDir;
		}

		return new Hit
		{
			position,
			normal,
			delta
		};
	}

	Hit* Rect::Intersects(const Rect& rect) const
	{
		Vec2 vec = rect.center - center;
		Vec2 penetration = rect.extents + extents - Vec2{ fabsf(vec.x), fabsf(vec.y) };

		if (penetration.x <= 0.f || penetration.y <= 0.f)
		{
			return nullptr;
		}

		Vec2 position = { 0.f, 0.f };
		Vec2 normal = { 0.f, 0.f };
		Vec2 delta = { 0.f, 0.f };

		if (penetration.x < penetration.y)
		{
			float xDir = vec.x < 0.f ? -1.f : 1.f;
			delta.x = penetration.x * xDir;
			normal.x = xDir;
			position.x = center.x + extents.x * xDir;
			position.y = rect.center.y;
		}
		else
		{
			float yDir = vec.y < 0.f ? -1.f : 1.f;
			delta.y = penetration.y * yDir;
			normal.y = yDir;
			position.x = rect.center.x;
			position.y = center.y + extents.y * yDir;
		}

		return new Hit
		{
			position,
			normal,
			delta
		};
	}

	Rect::operator Rectangle()
	{
		return
		{
			center.x - extents.y,
			center.y - extents.x,
			extents.x * 2.f,
			extents.y * 2.f
		};
	}

	bool Rect::operator==(const Rect& rhs) const
	{
		return center == rhs.center && extents == rhs.extents;
	}

	bool Rect::operator!=(const Rect& rhs) const
	{
		return !(*this == rhs);
	}
}

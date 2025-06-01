#include "MathLib/Geometry/Circle.h"

#include "MathLib/MathFunctions.h"
#include "MathLib/Geometry/Hit.h"
#include "MathLib/Geometry/Rect.h"

namespace MathLib
{
	Circle::Circle() = default;

	Circle::Circle(Vec2 center, float radius)
		: center{ std::move(center) }, radius{ radius }
	{
	}

	bool Circle::Overlaps(Rect* other)
	{
		return other->Overlaps(this);
	}

	Hit* Circle::Intersects(const Vec2& point) const
	{
		Vec2 v = center - point;

		if ( v.Dot(v) > SqrRadius())
		{
			// There is no intersection here, so return nullptr
			return nullptr;
		}

		// This will project the incoming point onto the surface of the circle
		Vec2 closestPoint = center + Vec2::Normalised(point - center) * radius;
		// This will calculate the "penetration" of the point into the circle
		Vec2 delta = closestPoint - point;

		// We intersected the circle, so return a hit with the relevant data
		return new Hit
		{
		closestPoint,
		Vec2::Normalised(delta),
		delta
		};
	}

	Hit* Circle::Intersects(const Circle& circle) const
	{
		// Broad-phase detection
		Vec2 v = center - circle.center;
		float radiiSqr = (radius + circle.radius) * (radius + circle.radius);
		float d = v.Dot(v);

		if (d >= radiiSqr)
		{
			// There is no intersection between the two
			return nullptr;
		}

		// Narrow-phase calculations
		Vec2 normV = Vec2::Normalised(circle.center - center);
		Vec2 closestPoint = center + normV * radius;
		float penetration = radius + circle.radius - v.Magnitude();
		Vec2 delta = normV * penetration;

		return new Hit
		{
			closestPoint,
			normV,
			delta
		};

		return nullptr;
	}

	float Circle::SqrRadius() const
	{
		return radius * radius;
	}

	bool Circle::operator==(const Circle& rhs) const
	{
		return center == rhs.center && MathFunctions::Compare(radius, rhs.radius);
	}

	bool Circle::operator!=(const Circle& rhs) const
	{
		return !(*this == rhs);
	}
}

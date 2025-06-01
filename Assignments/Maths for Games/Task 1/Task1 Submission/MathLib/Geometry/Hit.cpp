#include "MathLib/Geometry/Hit.h"

namespace MathLib
{
	Hit::Hit() = default;


	Hit::Hit(Vec2 point, Vec2 normal, Vec2 delta)
		: point{ std::move(point) }, normal{ std::move(normal) },
		delta{ std::move(delta) }
	{
	}

	bool Hit::operator==(const Hit& rhs) const
	{
		return point == rhs.point && normal == rhs.normal && delta == rhs.delta;
	}

	bool Hit::operator!=(const Hit& rhs) const
	{
		return !(*this == rhs);
	}
}

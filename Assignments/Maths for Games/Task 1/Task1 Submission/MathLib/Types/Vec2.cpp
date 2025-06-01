#include "MathLib/Types/Vec2.h"

#include <format>

#include "MathLib/MathFunctions.h"

namespace MathLib
{
	Vec2::Vec2()
		: x{ 0.f }, y{ 0.f }
	{
	}

	Vec2::Vec2(float scalar)
		: x{ scalar }, y{ scalar }
	{
	}

	Vec2::Vec2(float x, float y)
		: x{ x }, y{ y }
	{
	}

	Vec2::Vec2(initializer_list<float> values)
	{
		int i = 0;
		for (float value : values)
		{
			data[i++] = value;
		}
	}

	Vec2::Vec2(Vector2 vec)
		: x{ vec.x }, y{ vec.y}
	{
	}

	Vec2::Vec2(const Vec2& other)
		: x{ other.x }, y{ other.y }
	{
	}

	Vec2::Vec2(Vec2&& other) noexcept
		: x{ other.x }, y{ other.y }
	{
	}

	Vec2::~Vec2() = default;

	Vec2 Vec2::Add(const Vec2& lhs, const Vec2& rhs)
	{
		return { lhs.x + rhs.x, lhs.y + rhs.y };
	}

	Vec2 Vec2::Subtract(const Vec2& lhs, const Vec2& rhs)
	{
		return { lhs.x - rhs.x, lhs.y - rhs.y };
	}

	Vec2 Vec2::Scale(const Vec2& lhs, float rhs)
	{
		return { lhs.x * rhs, lhs.y * rhs };
	}

	Vec2 Vec2::Normalised(const Vec2& vec)
	{
		return vec.Normalised();
	}

	float Vec2::Distance(const Vec2& a, const Vec2& b)
	{
		return (a - b).Magnitude();
	}

	float Vec2::Dot(const Vec2& lhs, const Vec2& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	Vec2 Vec2::Lerp(const Vec2& a, const Vec2& b, float t)
	{
		return {};
	}

	Vec2 Vec2::CreateRotationVector(float radians)
	{
		return {};
	}

	float Vec2::Dot(const Vec2& rhs) const
	{
		return x * rhs.x + y * rhs.y;
	}

	float Vec2::Magnitude() const
	{
		return sqrtf(MagnitudeSqr());
	}

	float Vec2::MagnitudeSqr() const
	{
		return x * x + y * y;
	}

	void Vec2::Normalise()
	{
		float magnitude = Magnitude();

		if (MathFunctions::Compare(magnitude, 0.f))
		{
			x = 0.f;
			y = 0.f;
		}
		else
		{
			x /= magnitude;
			y /= magnitude;
		}
	}

	Vec2 Vec2::Normalised() const
	{
		float magnitude = Magnitude();

		return MathFunctions::Compare(magnitude, 0.f) ?
			Vec2{ 0.f, 0.f } :
			Vec2{ x / magnitude, y / magnitude };
	}

	float Vec2::Rotation() const
	{
		return 0;
	}

	void Vec2::Rotate(float amount)
	{
	}

	void Vec2::RotateAround(const Vec2& pivot, float amount)
	{
	}

	string Vec2::ToString() const
	{
		return std::format("({}, {})", x, y);
	}

	Vec2::operator Vector2() const
	{
		return { x, y };
	}

	bool Vec2::operator==(const Vec2& other) const
	{
		return MathFunctions::Compare(x, other.x) && MathFunctions::Compare(y, other.y);
	}

	bool Vec2::operator!=(const Vec2& other) const
	{
		return !(*this == other);
	}

	Vec2 Vec2::operator-(const Vec2& other) const
	{
		return { x - other.x, y - other.y };
	}

	Vec2& Vec2::operator-=(const Vec2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	Vec2 Vec2::operator+(const Vec2& other) const
	{
		return { x + other.x, y + other.y };
	}

	Vec2& Vec2::operator+=(const Vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	Vec2 Vec2::operator*(float other) const
	{
		return { x * other, y * other };
	}

	Vec2& Vec2::operator*=(float other)
	{
		x *= other;
		y *= other;

		return *this;
	}

	Vec2 Vec2::operator*(const Vec2& other) const
	{
		return { x * other.x, y * other.y };
	}

	Vec2& Vec2::operator*=(const Vec2& other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}

	Vec2& Vec2::operator=(const Vec2& other)
	{
		return *this;
	}

	Vec2& Vec2::operator=(Vec2&& other) noexcept = default;

	Vec2& Vec2::operator=(Vector2 other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}

	Vec2 operator*(float lhs, const Vec2& rhs)
	{
		return rhs * lhs;
	}
}

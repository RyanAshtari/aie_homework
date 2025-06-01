#include "MathLib/Types/Vec3.h"

#include <format>

#include "MathLib/MathFunctions.h"

namespace MathLib
{
	Vec3 Vec3::Add(const Vec3& lhs, const Vec3& rhs)
	{
		return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
	}

	Vec3 Vec3::Subtract(const Vec3& lhs, const Vec3& rhs)
	{
		return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
	}

	Vec3 Vec3::Scale(const Vec3& lhs, float rhs)
	{
		return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
	}

	Vec3 Vec3::Normalised(const Vec3& vec)
	{
		return vec.Normalised();
	}

	float Vec3::Distance(const Vec3& a, const Vec3& b)
	{
		return (a - b).Magnitude();
	}

	float Vec3::Dot(const Vec3& lhs, const Vec3& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	Vec3 Vec3::Cross(const Vec3& lhs, const Vec3& rhs)
	{
		return
		{
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x
		};
	}

	Vec3 Vec3::Lerp(const Vec3& a, const Vec3& b, float t)
	{
		return {};
	}

	Vec3::Vec3()
		: x{ 0.f }, y{ 0.f }, z{ 0.f }
	{
	}

	Vec3::Vec3(float scalar)
		: x{ scalar }, y{ scalar }, z{ scalar }
	{
	}

	Vec3::Vec3(float x, float y, float z)
		: x{ x }, y{ y }, z{ z }
	{
	}

	Vec3::Vec3(initializer_list<float> values)
	{
		int i = 0;
		for (float value : values)
		{
			data[i++] = value;
		}
	}

	Vec3::Vec3(Vector3 vec)
		: x{ vec.x }, y{ vec.y }, z{ vec.z }
	{
	}

	Vec3::Vec3(const Vec3& other)
		: x{ other.x }, y{ other.y }, z{ other.z }
	{
	}

	Vec3::Vec3(Vec3&& other) noexcept
		: x{ other.x }, y{ other.y }, z{ other.z }
	{
	}

	Vec3::~Vec3() = default;

	float Vec3::Dot(const Vec3& rhs) const
	{
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}

	Vec3 Vec3::Cross(const Vec3& rhs) const
	{
		return
		{
			y * rhs.z - z * rhs.y,
			z * rhs.x - x * rhs.z,
			x * rhs.y - y * rhs.x
		};
	}

	float Vec3::Magnitude() const
	{
		return sqrtf(MagnitudeSqr());
	}

	float Vec3::MagnitudeSqr() const
	{
		return x * x + y * y + z * z;
	}

	void Vec3::Normalise()
	{
		float magnitude = Magnitude();

		if (MathFunctions::Compare(magnitude, 0.f))
		{
			x = 0.f;
			y = 0.f;
			z = 0.f;
		}
		else
		{
			x /= magnitude;
			y /= magnitude;
			z /= magnitude;
		}
	}

	Vec3 Vec3::Normalised() const
	{
		float magnitude = Magnitude();

		return MathFunctions::Compare(magnitude, 0.f) ?
			Vec3{ 0.f, 0.f , 0.f } :
			Vec3{ x / magnitude, y / magnitude , z / magnitude };
	}

	string Vec3::ToString() const
	{
		return std::format("({}, {}, {})", x, y, z);
	}

	Vec3::operator Vector3() const
	{
		return { x, y, z };
	}

	bool Vec3::operator==(const Vec3& other) const
	{
		return
			MathFunctions::Compare(x, other.x) &&
			MathFunctions::Compare(y, other.y) &&
			MathFunctions::Compare(z, other.z);
	}

	bool Vec3::operator!=(const Vec3& other) const
	{
		return !(*this == other);
	}

	Vec3 Vec3::operator-(const Vec3& other) const
	{
		return { x - other.x, y - other.y, z - other.z };
	}

	Vec3& Vec3::operator-=(const Vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	Vec3 Vec3::operator+(const Vec3& other) const
	{
		return { x + other.x, y + other.y, z + other.z };
	}

	Vec3& Vec3::operator+=(const Vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	Vec3 Vec3::operator*(float other) const
	{
		return { x * other, y * other, z * other };
	}

	Vec3& Vec3::operator*=(float other)
	{
		x *= other;
		y *= other;
		z *= other;

		return *this;
	}

	Vec3& Vec3::operator=(const Vec3& other)
	{
		return *this;
	}

	Vec3& Vec3::operator=(Vec3&& other) noexcept
	{
		return *this;
	}

	Vec3 operator*(float lhs, const Vec3& rhs)
	{
		return rhs * lhs;
	}
}

#include "MathLib/Types/Vec4.h"

#include <format>

#include "MathLib/MathFunctions.h"

namespace MathLib
{
	Vec4 Vec4::Add(const Vec4& lhs, const Vec4& rhs)
	{
		return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w };
	}

	Vec4 Vec4::Subtract(const Vec4& lhs, const Vec4& rhs)
	{
		return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w };
	}

	Vec4 Vec4::Scale(const Vec4& lhs, float rhs)
	{
		return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs };
	}

	Vec4 Vec4::Normalised(const Vec4& vec)
	{
		return vec.Normalised();
	}

	float Vec4::Distance(const Vec4& a, const Vec4& b)
	{
		return  (a - b).Magnitude();
	}

	float Vec4::Dot(const Vec4& lhs, const Vec4& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	Vec4 Vec4::Cross(const Vec4& lhs, const Vec4& rhs)
	{
		return
		{
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x,
			0.f
		};
	}

	Vec4 Vec4::Lerp(const Vec4& a, const Vec4& b, float t)
	{
		return {};
	}

	Vec4::Vec4()
		: x{ 0.f }, y{ 0.f }, z{ 0.f }, w{ 0.f }
	{
	}

	Vec4::Vec4(float scalar)
		: x{ scalar }, y{ scalar }, z{ scalar }, w{ scalar }
	{
	}

	Vec4::Vec4(float x, float y, float z, float w)
		: x{ x }, y{ y }, z{ z }, w{ w }
	{
	}

	Vec4::Vec4(initializer_list<float> values)
	{
		int i = 0;
		for (float value : values)
		{
			data[i++] = value;
		}
	}

	Vec4::Vec4(Vector4 value)
		: x{ value.x }, y{ value.y }, z{ value.z }, w{ value.w }
	{
	}

	Vec4::Vec4(const Vec4& other)
		: x{ other.x }, y{ other.y }, z{ other.z }, w{ other.w }
	{
	}

	Vec4::Vec4(Vec4&& other) noexcept
		: x{ other.x }, y{ other.y }, z{ other.z }, w{ other.w }
	{
	}

	Vec4::~Vec4() = default;

	float Vec4::Dot(const Vec4& rhs) const
	{
		return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	}

	Vec4 Vec4::Cross(const Vec4& rhs) const
	{
		return
		{
			y * rhs.z - z * rhs.y,
			z * rhs.x - x * rhs.z,
			x * rhs.y - y * rhs.x,
			0.f
		};
	}

	float Vec4::Magnitude() const
	{
		return sqrtf(MagnitudeSqr());
	}

	float Vec4::MagnitudeSqr() const
	{
		return x * x + y * y + z * z + w * w;
	}

	void Vec4::Normalise()
	{
		float magnitude = Magnitude();

		if (MathFunctions::Compare(magnitude, 0.f))
		{
			x = 0.f;
			y = 0.f;
			z = 0.f;
			w = 0.f;
		}
		else
		{
			x /= magnitude;
			y /= magnitude;
			z /= magnitude;
			w /= magnitude;
		}
	}

	Vec4 Vec4::Normalised() const
	{
		float magnitude = Magnitude();

		return MathFunctions::Compare(magnitude, 0.f) ?
			Vec4{ 0.f, 0.f, 0.f, 0.f } :
			Vec4{ x / magnitude, y / magnitude, z / magnitude, w / magnitude };
	}

	string Vec4::ToString() const
	{
		return std::format("({}, {}, {}, {})", x, y, z, w);
	}

	Vec4::operator Vector4() const
	{
		return { x, y, z, w };
	}

	bool Vec4::operator==(const Vec4& other) const
	{
		return
			MathFunctions::Compare(x, other.x) &&
			MathFunctions::Compare(y, other.y) &&
			MathFunctions::Compare(z, other.z) &&
			MathFunctions::Compare(w, other.w);
	}

	bool Vec4::operator!=(const Vec4& other) const
	{
		return !(*this == other);
	}

	Vec4 Vec4::operator-(const Vec4& other) const
	{
		return { x - other.x, y - other.y, z - other.z, w - other.w };
	}

	Vec4& Vec4::operator-=(const Vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}

	Vec4 Vec4::operator+(const Vec4& other) const
	{
		return { x + other.x, y + other.y, z + other.z, w + other.w };
	}

	Vec4& Vec4::operator+=(const Vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}

	Vec4 Vec4::operator*(float other) const
	{
		return { x * other, y * other, z * other, w * other };
	}

	Vec4& Vec4::operator*=(float other)
	{
		x *= other;
		y *= other;
		z *= other;
		w *= other;

		return *this;
	}

	Vec4& Vec4::operator=(const Vec4& other)
	{
		return *this;
	}

	Vec4& Vec4::operator=(Vec4&& other) noexcept
	{
		return *this;
	}

	Vec4 operator*(float _lhs, const Vec4& _rhs)
	{
		return _rhs * _lhs;
	}
}

#pragma once

#include <raylib/raylib.h>

#include <initializer_list>
#include <string>

using std::string;
using std::initializer_list;

#define VEC_3_SIZE 3

namespace MathLib
{
	class Vec3
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
			};

			float data[VEC_3_SIZE];
		};

	public:
		static Vec3 Add(const Vec3& lhs, const Vec3& rhs);
		static Vec3 Subtract(const Vec3& lhs, const Vec3& rhs);
		static Vec3 Scale(const Vec3& lhs, float rhs);

		static Vec3 Normalised(const Vec3& vec);
		static float Distance(const Vec3& a, const Vec3& b);

		static float Dot(const Vec3& lhs, const Vec3& rhs);
		static Vec3 Cross(const Vec3& lhs, const Vec3& rhs);

		static Vec3 Lerp(const Vec3& a, const Vec3& b, float t);

	public:
		Vec3();
		Vec3(float scalar);
		Vec3(float x, float y, float z);
		Vec3(initializer_list<float> values);
		Vec3(Vector3 vec);

		Vec3(const Vec3& other);
		Vec3(Vec3&& other) noexcept;

		~Vec3();

	public:
		float Dot(const Vec3& rhs) const;
		Vec3 Cross(const Vec3& rhs) const;

		float Magnitude() const;
		float MagnitudeSqr() const;

		void Normalise();
		Vec3 Normalised() const;

		string ToString() const;

	public:
		operator Vector3() const;

		bool operator ==(const Vec3& other) const;
		bool operator !=(const Vec3& other) const;

		Vec3 operator -(const Vec3& other) const;
		Vec3& operator -=(const Vec3& other);

		Vec3 operator +(const Vec3& other) const;
		Vec3& operator +=(const Vec3& other);

		Vec3 operator *(float other) const;
		Vec3& operator *=(float other);

		Vec3& operator=(const Vec3& other);
		Vec3& operator=(Vec3&& other) noexcept;

	};

	extern Vec3 operator*(float lhs, const Vec3& rhs);
}
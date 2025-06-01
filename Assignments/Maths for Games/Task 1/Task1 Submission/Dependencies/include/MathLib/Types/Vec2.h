#pragma once

#include <raylib/raylib.h>

#include <string>
#include <initializer_list>

using std::string;
using std::initializer_list;

#define VEC_2_SIZE 2

namespace MathLib
{
	class Vec2
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
			};

			float data[VEC_2_SIZE];
		};

	public:


	public:
		Vec2();
		Vec2(float scalar);
		Vec2(float x, float y);
		Vec2(initializer_list<float> values);
		Vec2(Vector2 vec);

		Vec2(const Vec2& other);
		Vec2(Vec2&& other) noexcept;

		~Vec2();

	public:
		static Vec2 Add(const Vec2& lhs, const Vec2& rhs);
		static Vec2 Subtract(const Vec2& lhs, const Vec2& rhs);
		static Vec2 Scale(const Vec2& lhs, float rhs);

		static Vec2 Normalised(const Vec2& vec);
		static float Distance(const Vec2& a, const Vec2& b);

		static float Dot(const Vec2& lhs, const Vec2& rhs);

		static Vec2 Lerp(const Vec2& a, const Vec2& b, float t);

		static Vec2 CreateRotationVector(float radians);

	public:
		float Dot(const Vec2& rhs) const;

		float Magnitude() const;
		float MagnitudeSqr() const;

		void Normalise();
		Vec2 Normalised() const;

		float Rotation() const;

		void Rotate(float amount);
		void RotateAround(const Vec2& pivot, float amount);

		string ToString() const;

	public:
		operator Vector2() const;

		bool operator ==(const Vec2& other) const;
		bool operator !=(const Vec2& other) const;

		Vec2 operator -(const Vec2& other) const;
		Vec2& operator -=(const Vec2& other);

		Vec2 operator +(const Vec2& other) const;
		Vec2& operator +=(const Vec2& other);

		Vec2 operator *(float other) const;
		Vec2& operator *=(float other);

		Vec2 operator *(const Vec2& other) const;
		Vec2& operator *=(const Vec2& other);

		Vec2& operator=(const Vec2& other);
		Vec2& operator=(Vec2&& other) noexcept;

		Vec2& operator=(Vector2 other);
	};

	extern Vec2 operator*(float lhs, const Vec2& rhs);
}
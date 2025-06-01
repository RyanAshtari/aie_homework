#pragma once

#include <raylib/raylib.h>

#include <initializer_list>
#include <string>

using std::string;
using std::initializer_list;

#define VEC_4_SIZE 4

namespace MathLib
{
	class Vec4
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};

			float data[VEC_4_SIZE];
		};

	public:
		static Vec4 Add(const Vec4& lhs, const Vec4& rhs);
		static Vec4 Subtract(const Vec4& lhs, const Vec4& rhs);
		static Vec4 Scale(const Vec4& lhs, float rhs);

		static Vec4 Normalised(const Vec4& vec);
		static float Distance(const Vec4& a, const Vec4& b);

		static float Dot(const Vec4& lhs, const Vec4& rhs);
		static Vec4 Cross(const Vec4& lhs, const Vec4& rhs);

		static Vec4 Lerp(const Vec4& a, const Vec4& b, float t);

	public:
		Vec4();
		Vec4(float scalar);
		Vec4(float x, float y, float z, float w);
		Vec4(initializer_list<float> values);
		Vec4(Vector4 value);

		Vec4(const Vec4& other);
		Vec4(Vec4&& other) noexcept;

		~Vec4();

	public:
		float Dot(const Vec4& rhs) const;
		Vec4 Cross(const Vec4& rhs) const;

		float Magnitude() const;
		float MagnitudeSqr() const;

		void Normalise();
		Vec4 Normalised() const;

		string ToString() const;

	public:
		operator Vector4() const;

		bool operator ==(const Vec4& other) const;
		bool operator !=(const Vec4& other) const;

		Vec4 operator -(const Vec4& other) const;
		Vec4& operator -=(const Vec4& other);

		Vec4 operator +(const Vec4& other) const;
		Vec4& operator +=(const Vec4& other);

		Vec4 operator *(float other) const;
		Vec4& operator *=(float other);

		Vec4& operator=(const Vec4& other);
		Vec4& operator=(Vec4&& other) noexcept;

	};

	extern Vec4 operator*(float _lhs, const Vec4& _rhs);
}
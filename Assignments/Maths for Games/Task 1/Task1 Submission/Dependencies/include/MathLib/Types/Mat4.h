#pragma once

#include "Vec3.h"
#include "Vec4.h"

#define MAT_4_SIZE (VEC_4_SIZE * VEC_4_SIZE)

namespace MathLib
{
	class Mat4
	{
	public:
		union
		{
			struct
			{
				float m1;
				float m2;
				float m3;
				float m4;
				float m5;
				float m6;
				float m7;
				float m8;
				float m9;
				float m10;
				float m11;
				float m12;
				float m13;
				float m14;
				float m15;
				float m16;
			};

			float data[MAT_4_SIZE];
		};

	public:
		static Mat4 MakeTransform(float transX = 0.f, float transY = 0.f, float transZ = 0.f, float xRot = 0.f,
		                          float yRot = 0.f, float zRot = 0.f, float scaleX = 1.f, float scaleY = 1.f,
		                          float scaleZ = 1.f);
		static Mat4 MakeTransform(const Vec3& trans, const Vec3& euler, const Vec3* scale = nullptr);

		static Mat4 MakeTranslation(const Vec3& trans);
		static Mat4 MakeTranslation(float x, float y, float z);

		static Mat4 MakeScale(const Vec3& scale);
		static Mat4 MakeScale(float x, float y, float z);

		static Mat4 MakeXRotation(float rot);
		static Mat4 MakeYRotation(float rot);
		static Mat4 MakeZRotation(float rot);

		static Mat4 MakeEuler(const Vec3& euler);
		static Mat4 MakeEuler(float x, float y, float z);

		static Mat4 MakeIdentity();

	public:
		Mat4();
		Mat4(float scalar);
		Mat4(float m1, float m5, float m9, float m13,
		     float m2, float m6, float m10, float m14,
		     float m3, float m7, float m11, float m15,
		     float m4, float m8, float m12, float m16);
		Mat4(float numbers[]);

		Mat4(const Mat4& other);
		Mat4(Mat4&& other) noexcept;

		~Mat4();

	public:
		void SetRotationX(float rot);
		float GetRotationX() const;

		void SetRotationY(float rot);
		float GetRotationY() const;

		void SetRotationZ(float rot);
		float GetRotationZ() const;

		void SetTranslation(const Vec3& trans);
		void Translate(const Vec3& trans);
		Vec3 GetTranslation();

		Mat4 Transposed();

		string ToString() const;

	public:
		Mat4 operator*(const Mat4& rhs) const;
		Vec4 operator*(const Vec4& rhs) const;

		bool operator==(const Mat4& other) const;
		bool operator!=(const Mat4& other) const;

		Mat4& operator=(const Mat4& other);
		Mat4& operator=(Mat4&& other) noexcept;
	};
}

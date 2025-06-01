#pragma once

#include "Vec2.h"
#include "Vec3.h"

#define MAT_3_SIZE (VEC_3_SIZE * VEC_3_SIZE)

namespace MathLib
{
	class Mat3
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
			};

			float data[MAT_3_SIZE];
		};

	public:
		static Mat3 MakeTransform(float transX = 0.f, float transY = 0.f, float transZ = 0.f, float xRot = 0.f,
		                          float yRot = 0.f, float zRot = 0.f, float scaleX = 1.f, float scaleY = 1.f,
		                          float scaleZ = 1.f);
		static Mat3 MakeTransform(const Vec2& trans, float rot = 0.f, const Vec2* scale = nullptr, float xRot = 0.f,
		                          float yRot = 0.f);

		static Mat3 MakeTranslation(const Vec3& trans);
		static Mat3 MakeTranslation(float x, float y, float z = 0.f);

		static Mat3 MakeScale(const Vec3& scale);
		static Mat3 MakeScale(float x, float y, float z = 1.f);

		static Mat3 MakeXRotation(float rot);
		static Mat3 MakeYRotation(float rot);
		static Mat3 MakeZRotation(float rot);

		static Mat3 MakeEuler(const Vec3& euler);
		static Mat3 MakeEuler(float x, float y, float z);

		static Mat3 MakeIdentity();

	public:
		Mat3();
		Mat3(float scalar);
		Mat3(float m1, float m4, float m7,
		     float m2, float m5, float m8,
		     float m3, float m6, float m9);
		Mat3(float numbers[]);

		Mat3(const Mat3& other);
		Mat3(Mat3&& other) noexcept;

		~Mat3();

	public:
		void SetRotationX(float rot);
		float GetRotationX() const;

		void SetRotationY(float rot);
		float GetRotationY() const;

		void SetRotationZ(float rot);
		float GetRotationZ() const;

		void SetTranslation(const Vec2& trans);
		void Translate(const Vec2& trans);
		Vec2 GetTranslation();

		void SetScale(const Vec2& scale);
		Vec2 GetScale() const;

		Vec2 TransformPoint(const Vec2& point) const;
		Vec2 TransformVector(const Vec2& vec) const;

		Mat3 Transposed();
		string ToString() const;

	public:
		Mat3 operator*(const Mat3& rhs) const;
		Vec3 operator*(const Vec3& rhs) const;

		bool operator==(const Mat3& other) const;
		bool operator!=(const Mat3& other) const;

		Mat3& operator=(const Mat3& other);
		Mat3& operator=(Mat3&& other) noexcept;
	};
}

#include "MathLib/Types/Mat4.h"

#include <format>

#include "MathLib/MathFunctions.h"

namespace MathLib
{
	Mat4 Mat4::MakeTransform(float transX, float transY, float transZ, float xRot, float yRot, float zRot, float scaleX,
		float scaleY, float scaleZ)
	{
		Mat4 transMat = MakeTranslation(transX, transY, transZ);
		Mat4 scaleMat = MakeScale(scaleX, scaleY, scaleZ);

		Mat4 rotMat = MakeEuler(xRot * RAD2DEG, yRot * RAD2DEG, zRot * RAD2DEG);

		return transMat * rotMat * scaleMat;
	}

	Mat4 Mat4::MakeTransform(const Vec3& trans, const Vec3& euler, const Vec3* scale)
	{
		Vec3 s = scale != nullptr ? *scale : Vec3{ 1.f, 1.f, 1.f };

		return MakeTransform(trans.x, trans.y, trans.z, euler.x, euler.y, euler.z, s.x, s.y, s.z);
	}

	Mat4 Mat4::MakeTranslation(const Vec3& trans)
	{
		return MakeTranslation(trans.x, trans.y, trans.z);
	}

	Mat4 Mat4::MakeTranslation(float x, float y, float z)
	{
		return
		{
			1.f, 0.f, 0.f, x,
			0.f, 1.f, 0.f, y,
			0.f, 0.f, 1.f, z,
			0.f, 0.f, 0.f, 1.f
		};
	}

	Mat4 Mat4::MakeScale(const Vec3& scale)
	{
		return MakeScale(scale.x, scale.y, scale.z);
	}

	Mat4 Mat4::MakeScale(float x, float y, float z)
	{
		return
		{
			x, 0.f, 0.f, 0.f,
			0.f, y, 0.f, 0.f,
			0.f, 0.f, z, 0.f,
			0.f, 0.f, 0.f, 1.f
		};
	}

	Mat4 Mat4::MakeXRotation(float rot)
	{
		float cos = cosf(rot);
		float sin = sinf(rot);

		return
		{
			1.f, 0.f, 0.f, 0.f,
			0.f, cos, -sin, 0.f,
			0.f, sin, cos, 0.f,
			0.f, 0.f, 0.f, 1.f
		};
	}

	Mat4 Mat4::MakeYRotation(float rot)
	{
		float cos = cosf(rot);
		float sin = sinf(rot);

		return
		{
			cos, 0.f, sin, 0.f,
			0.f, 1.f, 0.f, 0.f,
			-sin, 0.f, cos, 0.f,
			0.f, 0.f, 0.f, 1.f
		};
	}

	Mat4 Mat4::MakeZRotation(float rot)
	{
		float cos = cosf(rot);
		float sin = sinf(rot);

		return
		{
			cos, -sin, 0.f, 0.f,
			sin, cos, 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			0.f, 0.f, 0.f, 1.f
		};
	}

	Mat4 Mat4::MakeEuler(const Vec3& euler)
	{
		return MakeEuler(euler.x, euler.y, euler.z);
	}

	Mat4 Mat4::MakeEuler(float x, float y, float z)
	{
		Mat4 xRotMat = MakeXRotation(x * DEG2RAD);
		Mat4 yRotMat = MakeYRotation(y * DEG2RAD);
		Mat4 zRotMat = MakeZRotation(z * DEG2RAD);

		return xRotMat * yRotMat * zRotMat;
	}

	Mat4 Mat4::MakeIdentity()
	{
		return { 1.f };
	}

	Mat4::Mat4()
		: m1{ 0 }, m5{ 0 }, m9{ 0 }, m13{ 0 },
		m2{ 0 }, m6{ 0 }, m10{ 0 }, m14{ 0 },
		m3{ 0 }, m7{ 0 }, m11{ 0 }, m15{ 0 },
		m4{ 0 }, m8{ 0 }, m12{ 0 }, m16{ 0 }
	{
	}

	Mat4::Mat4(float scalar)
		: m1{ scalar }, m5{ 0 }, m9{ 0 }, m13{ 0 },
		m2{ 0 }, m6{ scalar }, m10{ 0 }, m14{ 0 },
		m3{ 0 }, m7{ 0 }, m11{ scalar }, m15{ 0 },
		m4{ 0 }, m8{ 0 }, m12{ 0 }, m16{ scalar }
	{
	}

	Mat4::Mat4(float m1, float m5, float m9, float m13, float m2, float m6, float m10, float m14, float m3,
		float m7, float m11, float m15, float m4, float m8, float m12, float m16)
		: m1{ m1 }, m5{ m5 }, m9{ m9 }, m13{ m13 },
		m2{ m2 }, m6{ m6 }, m10{ m10 }, m14{ m14 },
		m3{ m3 }, m7{ m7 }, m11{ m11 }, m15{ m15 },
		m4{ m4 }, m8{ m8 }, m12{ m12 }, m16{ m16 }
	{
	}

	Mat4::Mat4(float numbers[])
	{
		for (int i = 0; i < MAT_4_SIZE; ++i)
		{
			data[i] = numbers[i];
		}
	}

	Mat4::Mat4(const Mat4& other)
		: m1{ other.m1 }, m5{ other.m5 }, m9{ other.m9 }, m13{ other.m13 },
		m2{ other.m2 }, m6{ other.m6 }, m10{ other.m10 }, m14{ other.m14 },
		m3{ other.m3 }, m7{ other.m7 }, m11{ other.m11 }, m15{ other.m15 },
		m4{ other.m4 }, m8{ other.m8 }, m12{ other.m12 }, m16{ other.m16 }
	{
	}

	Mat4::Mat4(Mat4&& other) noexcept = default;

	Mat4::~Mat4() = default;

	void Mat4::SetRotationX(float rot)
	{
		float yAxisMag = sqrtf(m5 * m5 + m6 * m6 + m7 * m7);
		float zAxisMag = sqrtf(m9 * m9 + m10 * m10 + m11 * m11);

		float cos = cosf(rot);
		float sin = sinf(rot);

		m6 = cos * yAxisMag;
		m10 = -sin * zAxisMag;
		m7 = sin * yAxisMag;
		m11 = cos * zAxisMag;
	}

	float Mat4::GetRotationX() const
	{
		return atan2f(m7, m11);
	}

	void Mat4::SetRotationY(float rot)
	{
		float xAxisMag = sqrtf(m1 * m1 + m2 * m2 + m3 * m3);
		float zAxisMag = sqrtf(m9 * m9 + m10 * m10 + m11 * m11);

		float cos = cosf(rot);
		float sin = sinf(rot);

		m1 = cos * xAxisMag;
		m9 = sin * zAxisMag;
		m3 = -sin * xAxisMag;
		m11 = cos * zAxisMag;
	}

	float Mat4::GetRotationY() const
	{
		return atan2f(m3, m1);
	}

	void Mat4::SetRotationZ(float rot)
	{
		float xAxisMag = sqrtf(m1 * m1 + m2 * m2 + m3 * m3);
		float yAxisMag = sqrtf(m5 * m5 + m6 * m6 + m7 * m7);

		float cos = cosf(rot);
		float sin = sinf(rot);

		m1 = cos * xAxisMag;
		m5 = -sin * yAxisMag;
		m2 = sin * xAxisMag;
		m6 = cos * yAxisMag;
	}

	float Mat4::GetRotationZ() const
	{
		return atan2f(m2, m1);
	}

	void Mat4::SetTranslation(const Vec3& trans)
	{
		m13 = trans.x;
		m14 = trans.y;
		m15 = trans.z;
	}

	void Mat4::Translate(const Vec3& trans)
	{
		m13 += trans.x;
		m14 += trans.y;
		m15 += trans.z;
	}

	Vec3 Mat4::GetTranslation()
	{
		return { m13, m14, m15 };
	}

	Mat4 Mat4::Transposed()
	{
		return
		{
			m1, m2, m3, m4,
			m5, m6, m7, m8,
			m9, m10, m11, m12,
			m13, m14, m15, m16
		};
	}

	string Mat4::ToString() const
	{
		return std::format(
			"[{:.3f}, {:.3f}, {:.3f}, {:.3f}\n{:.3f}, {:.3f}, {:.3f}, {:.3f}\n"
			"{:.3f}, {:.3f}, {:.3f}, {:.3f}\n{:.3f}, {:.3f}, {:.3f}, {:.3f}]",
			m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16);
	}

	Mat4 Mat4::operator*(const Mat4& rhs) const
	{
		return
		{
			m1 * rhs.m1 + m2 * rhs.m5 + m3 * rhs.m9 + m4 * rhs.m13,
			m5 * rhs.m1 + m6 * rhs.m5 + m7 * rhs.m9 + m8 * rhs.m13,
			m9 * rhs.m1 + m10 * rhs.m5 + m11 * rhs.m9 + m12 * rhs.m13,
			m13 * rhs.m1 + m14 * rhs.m5 + m15 * rhs.m9 + m16 * rhs.m13,

			m1 * rhs.m2 + m2 * rhs.m6 + m3 * rhs.m10 + m4 * rhs.m14,
			m5 * rhs.m2 + m6 * rhs.m6 + m7 * rhs.m10 + m8 * rhs.m14,
			m9 * rhs.m2 + m10 * rhs.m6 + m11 * rhs.m10 + m12 * rhs.m14,
			m13 * rhs.m2 + m14 * rhs.m6 + m15 * rhs.m10 + m16 * rhs.m14,

			m1 * rhs.m3 + m2 * rhs.m7 + m3 * rhs.m11 + m4 * rhs.m15,
			m5 * rhs.m3 + m6 * rhs.m7 + m7 * rhs.m11 + m8 * rhs.m15,
			m9 * rhs.m3 + m10 * rhs.m7 + m11 * rhs.m11 + m12 * rhs.m15,
			m13* rhs.m3 + m14 * rhs.m7 + m15 * rhs.m11 + m16 * rhs.m15,

			m1 * rhs.m4 + m2 * rhs.m8 + m3 * rhs.m12 + m4 * rhs.m16,
			m5 * rhs.m4 + m6 * rhs.m8 + m7 * rhs.m12 + m8 * rhs.m16,
			m9 * rhs.m4 + m10 * rhs.m8 + m11 * rhs.m12 + m12 * rhs.m16,
			m13 * rhs.m4 + m14 * rhs.m8 + m15 * rhs.m12 + m16 * rhs.m16
		};
	}

	Vec4 Mat4::operator*(const Vec4& rhs) const
	{
		return
		{
			m1* rhs.x + m2 * rhs.y + m3 * rhs.z + m4 * rhs.w,
			m5* rhs.x + m6 * rhs.y + m7 * rhs.z + m8 * rhs.w,
			m9* rhs.x + m10 * rhs.y + m11 * rhs.z + m12 * rhs.w,
			m13* rhs.x + m14 * rhs.y + m15 * rhs.z + m16 * rhs.w
		};
	}

	bool Mat4::operator==(const Mat4& other) const
	{
		for (int i = 0; i < MAT_4_SIZE; ++i)
		{
			if (!MathFunctions::Compare(data[i], other.data[i]))
			{
				return false;
			}
		}

		return true;
	}

	bool Mat4::operator!=(const Mat4& other) const
	{
		return !(*this == other);
	}

	Mat4& Mat4::operator=(const Mat4& other)
	{
		if (*this == other)
		{
			return *this;
		}

		for (int i = 0; i < MAT_4_SIZE; ++i)
		{
			data[i] = other.data[i];
		}

		return *this;
	}

	Mat4& Mat4::operator=(Mat4&& other) noexcept = default;
}

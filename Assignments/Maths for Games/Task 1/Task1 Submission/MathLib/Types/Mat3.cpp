#include "MathLib/Types/Mat3.h"

#include <format>

#include "MathLib/MathFunctions.h"

namespace MathLib
{
	Mat3 Mat3::MakeTransform(float transX, float transY, float transZ, float xRot, float yRot, float zRot, float scaleX,
		float scaleY, float scaleZ)
	{
		Mat3 transMat = MakeTranslation(transX, transY, transZ);
		Mat3 scaleMat = MakeScale(scaleX, scaleY, scaleZ);

		Mat3 rotMat = MakeEuler(xRot * RAD2DEG, yRot * RAD2DEG, zRot * RAD2DEG);

		return transMat * rotMat * scaleMat;
	}

	Mat3 Mat3::MakeTransform(const Vec2& trans, float rot, const Vec2* scale, float xRot, float yRot)
	{
		Vec2 s = scale != nullptr ? *scale : Vec2{ 1.f, 1.f };

		return MakeTransform(trans.x, trans.y, 0.f, xRot, yRot, rot, s.x, s.y, 1.f);
	}

	Mat3 Mat3::MakeTranslation(const Vec3& trans)
	{
		return MakeTranslation(trans.x, trans.y, trans.z);
	}

	Mat3 Mat3::MakeTranslation(float x, float y, float z)
	{
		return
		{
			1.f, 0.f, x,
			0.f, 1.f, y,
			0.f, 0.f, z
		};
	}

	Mat3 Mat3::MakeScale(const Vec3& scale)
	{
		return MakeScale(scale.x, scale.y, scale.z);
	}

	Mat3 Mat3::MakeScale(float x, float y, float z)
	{
		return
		{
			x, 0.f, 0.f,
			0.f, y, 0.f,
			0.f, 0.f, z
		};
	}

	Mat3 Mat3::MakeXRotation(float rot)
	{
		float cos = cosf(rot);
		float sin = sinf(rot);

		return
		{
			1.f, 0.f, 0.f,
			0.f, cos, -sin,
			0.f, sin, cos
		};
	}

	Mat3 Mat3::MakeYRotation(float rot)
	{
		float cos = cosf(rot);
		float sin = sinf(rot);

		return
		{
			cos, 0.f, sin,
			0.f, 1.f, 0.f,
			-sin, 0.f, cos
		};
	}

	Mat3 Mat3::MakeZRotation(float rot)
	{
		float cos = cosf(rot);
		float sin = sinf(rot);

		return
		{
			cos, -sin, 0.f,
			sin, cos, 0.f,
			0.f, 0.f, 1.f
		};
	}

	Mat3 Mat3::MakeEuler(const Vec3& euler)
	{
		return MakeEuler(euler.x, euler.y, euler.z);
	}

	Mat3 Mat3::MakeEuler(float x, float y, float z)
	{
		Mat3 xRotMat = MakeXRotation(x * DEG2RAD);
		Mat3 yRotMat = MakeYRotation(y * DEG2RAD);
		Mat3 zRotMat = MakeZRotation(z * DEG2RAD);

		return xRotMat * yRotMat * zRotMat;
	}

	Mat3 Mat3::MakeIdentity()
	{
		return { 1.f };
	}

	Mat3::Mat3()
		: m1{ 0 }, m4{ 0 }, m7{ 0 },
		m2{ 0 }, m5{ 0 }, m8{ 0 },
		m3{ 0 }, m6{ 0 }, m9{ 0 }
	{
	}

	Mat3::Mat3(float scalar)
		: m1{ scalar }, m4{ 0 }, m7{ 0 },
		m2{ 0 }, m5{ scalar }, m8{ 0 },
		m3{ 0 }, m6{ 0 }, m9{ scalar }
	{
	}

	Mat3::Mat3(float m1, float m4, float m7, float m2, float m5, float m8, float m3, float m6, float m9)
		: m1{ m1 }, m4{ m4 }, m7{ m7 },
		m2{ m2 }, m5{ m5 }, m8{ m8 },
		m3{ m3 }, m6{ m6 }, m9{ m9 }
	{
	}

	Mat3::Mat3(float numbers[])
	{
		for (int i = 0; i < MAT_3_SIZE; ++i)
		{
			data[i] = numbers[i];
		}
	}

	Mat3::Mat3(const Mat3& other)
		: m1{ other.m1 }, m4{ other.m4 }, m7{ other.m7 },
		m2{ other.m2 }, m5{ other.m5 }, m8{ other.m8 },
		m3{ other.m3 }, m6{ other.m6 }, m9{ other.m9 }
	{
	}

	Mat3::Mat3(Mat3&& other) noexcept = default;

	Mat3::~Mat3() = default;

	void Mat3::SetRotationX(float rot)
	{
		float yAxisMag = sqrtf(m4 * m4 + m5 * m5 + m6 * m6);
		float zAxisMag = sqrtf(m7 * m7 + m8 * m8 + m9 * m9);

		float cos = cosf(rot);
		float sin = sinf(rot);

		m5 = cos * yAxisMag;
		m8 = -sin * zAxisMag;
		m6 = sin * yAxisMag;
		m9 = cos * zAxisMag;
	}

	float Mat3::GetRotationX() const
	{
		return atan2f(m2, m1);
	}

	void Mat3::SetRotationY(float rot)
	{
		float xAxisMag = sqrtf(m1 * m1 + m2 * m2 + m3 * m3);
		float zAxisMag = sqrtf(m7 * m7 + m8 * m8 + m9 * m9);

		float cos = cosf(rot);
		float sin = sinf(rot);

		m1 = cos * xAxisMag;
		m7 = sin * zAxisMag;
		m3 = -sin * xAxisMag;
		m9 = cos * zAxisMag;
	}

	float Mat3::GetRotationY() const
	{
		return atan2f(-m4, m5);
	}

	void Mat3::SetRotationZ(float rot)
	{
		float xAxisMag = sqrtf(m1 * m1 + m2 * m2 + m3 * m3);
		float yAxisMag = sqrtf(m4 * m4 + m5 * m5 + m6 * m6);

		float cos = cosf(rot);
		float sin = sinf(rot);

		m1 = cos * xAxisMag;
		m4 = -sin * yAxisMag;
		m2 = sin * xAxisMag;
		m5 = cos * yAxisMag;
	}

	float Mat3::GetRotationZ() const
	{
		return atan2(m7, m9);
	}

	void Mat3::SetTranslation(const Vec2& trans)
	{
		m7 = trans.x;
		m8 = trans.y;
	}

	void Mat3::Translate(const Vec2& trans)
	{
		m7 += trans.x;
		m8 += trans.y;
	}

	Vec2 Mat3::GetTranslation()
	{
		return { m7, m8 };
	}

	void Mat3::SetScale(const Vec2& scale)
	{
		const float xALen = sqrtf(m1 * m1 + m2 * m2);
		const float yALen = sqrtf(m4 * m4 + m5 * m5);

		// Is our x scale > 0
		if (xALen > 0.f)
		{
			// We need the divide to account for rotation
			m1 = m1 / xALen * scale.x;
			m2 = m2 / xALen * scale.x;
		}

		// Is our y scale > 0
		if (yALen > 0.f)
		{
			// We need the divide to account for rotation
			m4 = m4 / yALen * scale.x;
			m5 = m5 / yALen * scale.x;
		}
	}

	Vec2 Mat3::GetScale() const
	{
		// We get the length (magnitude) of the x and y axis
		// ignoring the w (m3 / m6 components as they are used
		// to tell us if it is a vector or point
		const float xALen = sqrtf(m1 * m1 + m2 * m2);
		const float yALen = sqrtf(m4 * m4 + m5 * m5);
		return { xALen, yALen };
	}

	Vec2 Mat3::TransformPoint(const Vec2& point) const
	{
		return
		{
			point.x * m1 + point.y * m4 + m7,
			point.x * m2 + point.y * m5 + m8
		};
	}

	Vec2 Mat3::TransformVector(const Vec2& vec) const
	{
		return
		{
			vec.x * m1 + vec.y * m4,
			vec.x * m2 + vec.y * m5
		};
	}

	Mat3 Mat3::Transposed()
	{
		return
		{
			m1, m2, m3,
			m4, m5, m6,
			m7, m8, m9
		};
	}

	string Mat3::ToString() const
	{
		return std::format(
			"[{:.3f}, {:.3f}, {:.3f}\n{:.3f}, {:.3f}, {:.3f}\n{:.3f}, {:.3f}, {:.3f}]",
			m1, m4, m7, m2, m5, m8, m3, m6, m9);
	}

	Mat3 Mat3::operator*(const Mat3& rhs) const
	{
		return
		{
			m1 * rhs.m1 + m2 * rhs.m4 + m3 * rhs.m7,
			m4 * rhs.m1 + m5 * rhs.m4 + m6 * rhs.m7,
			m7 * rhs.m1 + m8 * rhs.m4 + m9 * rhs.m7,
			m1 * rhs.m2 + m2 * rhs.m5 + m3 * rhs.m8,
			m4 * rhs.m2 + m5 * rhs.m5 + m6 * rhs.m8,
			m7 * rhs.m2 + m8 * rhs.m5 + m9 * rhs.m8,
			m1 * rhs.m3 + m2 * rhs.m6 + m3 * rhs.m9,
			m4 * rhs.m3 + m5 * rhs.m6 + m6 * rhs.m9,
			m7 * rhs.m3 + m8 * rhs.m6 + m9 * rhs.m9
		};
	}

	Vec3 Mat3::operator*(const Vec3& rhs) const
	{
		return
		{
			m1 * rhs.x + m2 * rhs.y + m3 * rhs.z,
			m4 * rhs.x + m5 * rhs.y + m6 * rhs.z,
			m7 * rhs.x + m8 * rhs.y + m9 * rhs.z
		};
	}

	bool Mat3::operator==(const Mat3& other) const
	{
		for (int i = 0; i < MAT_3_SIZE; ++i)
		{
			if (!MathFunctions::Compare(data[i], other.data[i]))
			{
				return false;
			}
		}

		return true;
	}

	bool Mat3::operator!=(const Mat3& other) const
	{
		return !(*this == other);
	}

	Mat3& Mat3::operator=(const Mat3& other)
	{
		if (*this == other)
		{
			return *this;
		}

		for (int i = 0; i < MAT_3_SIZE; ++i)
		{
			data[i] = other.data[i];
		}

		return *this;
	}

	Mat3& Mat3::operator=(Mat3&& other) noexcept = default;
}

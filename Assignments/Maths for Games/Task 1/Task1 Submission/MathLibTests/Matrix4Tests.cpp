#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "MathLib/Types/Mat4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathLib::Tests
{
	TEST_CLASS(Mat4Tests)
	{
	public:
		// default constructor
		TEST_METHOD(Constructor)
		{
			Mat4 mat;

			Assert::AreEqual(0.f, mat.m1);
			Assert::AreEqual(0.f, mat.m2);
			Assert::AreEqual(0.f, mat.m3);
			Assert::AreEqual(0.f, mat.m4);

			Assert::AreEqual(0.f, mat.m5);
			Assert::AreEqual(0.f, mat.m6);
			Assert::AreEqual(0.f, mat.m7);
			Assert::AreEqual(0.f, mat.m8);

			Assert::AreEqual(0.f, mat.m9);
			Assert::AreEqual(0.f, mat.m10);
			Assert::AreEqual(0.f, mat.m11);
			Assert::AreEqual(0.f, mat.m12);

			Assert::AreEqual(0.f, mat.m13);
			Assert::AreEqual(0.f, mat.m14);
			Assert::AreEqual(0.f, mat.m15);
			Assert::AreEqual(0.f, mat.m16);
		}

		// parameterized constructor (individual)
		TEST_METHOD(ConstructorParamFloats)
		{
			Mat4 mat =
			{
				1.f, 2.f, 3.f, 4.f,
				5.f, 6.f, 7.f, 8.f,
				9.f, 10.f, 11.f, 12.f,
				13.f, 14.f, 15.f, 16.f
			};

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(2.f, mat.m5);
			Assert::AreEqual(3.f, mat.m9);
			Assert::AreEqual(4.f, mat.m13);

			Assert::AreEqual(5.f, mat.m2);
			Assert::AreEqual(6.f, mat.m6);
			Assert::AreEqual(7.f, mat.m10);
			Assert::AreEqual(8.f, mat.m14);

			Assert::AreEqual(9.f, mat.m3);
			Assert::AreEqual(10.f, mat.m7);
			Assert::AreEqual(11.f, mat.m11);
			Assert::AreEqual(12.f, mat.m15);

			Assert::AreEqual(13.f, mat.m4);
			Assert::AreEqual(14.f, mat.m8);
			Assert::AreEqual(15.f, mat.m12);
			Assert::AreEqual(16.f, mat.m16);
		}

		// parameterized constructor (array)
		TEST_METHOD(ConstructorParamArray)
		{
			float numbers[] =
			{
				1.f, 2.f, 3.f, 4.f,
				5.f, 6.f, 7.f, 8.f,
				9.f, 10.f, 11.f, 12.f,
				13.f, 14.f, 15.f, 16.f
			};
			Mat4 mat(numbers);

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(2.f, mat.m2);
			Assert::AreEqual(3.f, mat.m3);
			Assert::AreEqual(4.f, mat.m4);

			Assert::AreEqual(5.f, mat.m5);
			Assert::AreEqual(6.f, mat.m6);
			Assert::AreEqual(7.f, mat.m7);
			Assert::AreEqual(8.f, mat.m8);

			Assert::AreEqual(9.f, mat.m9);
			Assert::AreEqual(10.f, mat.m10);
			Assert::AreEqual(11.f, mat.m11);
			Assert::AreEqual(12.f, mat.m12);

			Assert::AreEqual(13.f, mat.m13);
			Assert::AreEqual(14.f, mat.m14);
			Assert::AreEqual(15.f, mat.m15);
			Assert::AreEqual(16.f, mat.m16);
		}

		// mat4 * vec4
		TEST_METHOD(OperatorMultiplyMat4Vec4)
		{
			// homogeneous point translation
			Mat4 m4b =
			{
				1.f, 0.f, 0.f, 0.f,
				0.f, 1.f, 0.f, 0.f,
				0.f, 0.f, 1.f, 0.f,
				55.f, 44.f, 99.f, 1.f
			};

			Vec4 v4a(13.5f, -48.23f, -54.f, 1.f);

			Vec4 actual = m4b * v4a;
			Assert::AreEqual(Vec4(68.5f, -4.23f, 45.f, 1.f), actual);
		}

		// mat4 * mat4
		TEST_METHOD(OperatorMultiplyMat4Mat4)
		{
			Mat4 m4a =
			{
				1.f, 4.f, 1.f, 7.f,
				2.f, 3.f, 2.f, 8.f,
				3.f, 2.f, 3.f, 9.f,
				4.f, 1.f, 4.f, 1.f
			};

			Mat4 m4b =
			{
				4.f, 7.f, 3.f, 4.f,
				5.f, 6.f, 4.f, 6.f,
				6.f, 5.f, 6.f, 8.f,
				7.f, 4.f, 5.f, 2.f
			};

			Mat4 actual = m4a * m4b;

			Assert::AreEqual(
			                 {
				                 43.f, 47.f, 43.f, 115.f,
				                 53.f, 52.f, 53.f, 125.f,
				                 66.f, 59.f, 66.f, 144.f,
				                 38.f, 52.f, 38.f, 128.f
			                 },
			                 actual);
		}

		// make identity
		TEST_METHOD(MakeIdentity)
		{
			Mat4 mat = Mat4::MakeIdentity();

			Assert::AreEqual(1.f, mat.m1);
			Assert::AreEqual(0.f, mat.m2);
			Assert::AreEqual(0.f, mat.m3);
			Assert::AreEqual(0.f, mat.m4);

			Assert::AreEqual(0.f, mat.m5);
			Assert::AreEqual(1.f, mat.m6);
			Assert::AreEqual(0.f, mat.m7);
			Assert::AreEqual(0.f, mat.m8);

			Assert::AreEqual(0.f, mat.m9);
			Assert::AreEqual(0.f, mat.m10);
			Assert::AreEqual(1.f, mat.m11);
			Assert::AreEqual(0.f, mat.m12);

			Assert::AreEqual(0.f, mat.m13);
			Assert::AreEqual(0.f, mat.m14);
			Assert::AreEqual(0.f, mat.m15);
			Assert::AreEqual(1.f, mat.m16);
		}

		// Tranposed
		TEST_METHOD(Transposed)
		{
			Mat4 m3a =
			{
				1.f, 2.f, 3.f, 4.f,
				5.f, 6.f, 7.f, 8.f,
				9.f, 10.f, 11.f, 12.f,
				13.f, 14.f, 15.f, 16.f
			};

			m3a = m3a.Transposed();

			Assert::AreEqual(
			                 {
				                 1.f, 5.f, 9.f, 13.f,
				                 2.f, 6.f, 10.f, 14.f,
				                 3.f, 7.f, 11.f, 15.f,
				                 4.f, 8.f, 12.f, 16.f,
			                 }, m3a);
		}
	};
}

#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "MathLib/Types/Mat4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathLib::Tests
{
	TEST_CLASS(Mat4TransformTests)
	{
	public:
		// make trans from floats
		TEST_METHOD(MakeTranslationFloats)
		{
			Mat4 actual = Mat4::MakeTranslation(2.f, 3.f, 4.f);
			actual = actual.Transposed();

			Assert::AreEqual(
			                 {
				                 1.f, 0.f, 0.f, 0.f,
				                 0.f, 1.f, 0.f, 0.f,
				                 0.f, 0.f, 1.f, 0.f,
				                 2.f, 3.f, 4.f, 1.f
			                 }, actual);
		}

		// make trans from vector
		TEST_METHOD(MakeTranslationVector)
		{
			Mat4 actual = Mat4::MakeTranslation({ 2.0f, 3.0f, 4.0f });
			actual = actual.Transposed();

			Assert::AreEqual(
			                 {
				                 1.f, 0.f, 0.f, 0.f,
				                 0.f, 1.f, 0.f, 0.f,
				                 0.f, 0.f, 1.f, 0.f,
				                 2.f, 3.f, 4.f, 1.f
			                 }, actual);
		}

		// make rotX from float
		TEST_METHOD(MakeRotateXFloat)
		{
			Mat4 actual = Mat4::MakeXRotation(4.5f);

			Assert::AreEqual(
			                 {
				                 1.f, 0.f, 0.f, 0.f,
				                 0.f, -0.210796f, 0.97753f, 0.f,
				                 0.f, -0.97753f, -0.210796f, 0.f,
				                 0.f, 0.f, 0.f, 1.f
			                 }, actual);
		}

		// make rotY from float
		TEST_METHOD(MakeRotateYFloat)
		{
			Mat4 actual = Mat4::MakeYRotation(-2.6f);

			Assert::AreEqual(
			                 {
				                 -0.856889f, 0.f, -0.515501f, 0.f,
				                 0.f, 1.f, 0.f, 0.f,
				                 0.515501f, 0.f, -0.856889f, 0.f,
				                 0.f, 0.f, 0.f, 1.f
			                 }, actual);
		}

		// make rotZ from float
		TEST_METHOD(MakeRotateZFloat)
		{
			Mat4 actual = Mat4::MakeZRotation(0.72f);
			actual = actual.Transposed();

			Assert::AreEqual(
			                 {
				                 0.751806f, 0.659385f, 0.f, 0.f,
				                 -0.659385f, 0.751806f, 0.f, 0.f,
				                 0.f, 0.f, 1.f, 0.f,
				                 0.f, 0.f, 0.f, 1.f
			                 }, actual);
		}

		// make rot from euler (floats)
		TEST_METHOD(MakeRotateEulerFloat)
		{
			Mat4 actual = Mat4::MakeEuler(1.f * RAD2DEG, 2.f * RAD2DEG, 3.f * RAD2DEG);
		 

			Assert::AreEqual(
			                 {
				                 0.411982f, -0.058727f, -0.909297f, 0.f,
				                 -0.833738f, -0.426918f, -0.350175f, 0.f,
				                 -0.367630f, 0.902382f, -0.224845f, 0.f,
			                 	 0.f, 0.f, 0.f, 1.f
			                 },
			                 actual.Transposed());
		}

		// make rot from euler (vector)
		TEST_METHOD(MakeRotateEulerVector)
		{
			Mat4 actual = Mat4::MakeEuler({ 1.f * RAD2DEG, 2.f * RAD2DEG, 3.f * RAD2DEG });

			Assert::AreEqual(
			                 {
				                 0.411982f, -0.058727f, -0.909297f, 0.f,
				                 -0.833738f, -0.426918f, -0.350175f, 0.f,
				                 -0.367630f, 0.902382f, -0.224845f,
				                 0.f, 0.f, 0.f, 0.f, 1.f
			                 },
			                 actual.Transposed());
		}

		// make scale from floats
		TEST_METHOD(MakeScaleFloat3D)
		{
			Mat4 actual = Mat4::MakeScale(2.f, 3.f, 4.f);

			Assert::AreEqual(
			                 {
				                 2.f, 0.f, 0.f, 0.f,
				                 0.f, 3.f, 0.f, 0.f,
				                 0.f, 0.f, 4.f, 0.f,
				                 0.f, 0.f, 0.f, 1.f
			                 }, actual);
		}

		// make scale from vector
		TEST_METHOD(MakeScaleVec3)
		{
			Mat4 actual = Mat4::MakeScale({ 2.f, 3.f, 4.f });

			Assert::AreEqual(
			                 {
				                 2.f, 0.f, 0.f, 0.f,
				                 0.f, 3.f, 0.f, 0.f,
				                 0.f, 0.f, 4.f, 0.f,
				                 0.f, 0.f, 0.f, 1.f
			                 }
			                 , actual);
		}
	};
}

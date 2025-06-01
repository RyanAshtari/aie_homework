#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "MathLib/Types/Mat3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathLib::Tests
{
	TEST_CLASS(Mat3TransformTests)
	{
	public:
		// make trans from floats
		TEST_METHOD(MakeTranslationFloats)
		{
			Mat3 actual = Mat3::MakeTranslation(1.2f, 3.4f, 1.f);
			actual = actual.Transposed();

			Assert::AreEqual(
			                 {
				                 1.f, 0.f, 0.f,
				                 0.f, 1.f, 0.f,
				                 1.2f, 3.4f, 1.f
			                 },
			                 actual);
		}

		// make trans from vector
		TEST_METHOD(MakeTranslationVector)
		{
			Mat3 actual = Mat3::MakeTranslation({ 1.2f, 3.4f, 1.f });
			actual = actual.Transposed();

			Assert::AreEqual(
			                 {
				                 1.f, 0.f, 0.f,
				                 0.f, 1.f, 0.f,
				                 1.2f, 3.4f, 1.f
			                 },
			                 actual);
		}

		// make rotX from float
		TEST_METHOD(MakeRotateXFloat)
		{
			Mat3 actual = Mat3::MakeXRotation(3.98f);

			Assert::AreEqual(
			                 {
				                 1.f, 0.f, 0.f,
				                 0.f, -0.668648f, 0.743579f,
				                 0.f, -0.743579f, -0.668648f
			                 },
			                 actual);
		}

		// make rotY from float
		TEST_METHOD(MakeRotateYFloat)
		{
			Mat3 actual = Mat3::MakeYRotation(1.76f);

			Assert::AreEqual(
			                 {
				                 -0.188077f, 0.f, 0.982154f,
				                 0.f, 1.f, 0.f,
				                 -0.982154f, 0.f, -0.188077f
			                 },
			                 actual);
		}

		// make rotZ from float
		TEST_METHOD(MakeRotateZFloat)
		{
			Mat3 actual = Mat3::MakeZRotation(9.62f);
			actual = actual.Transposed();

			Assert::AreEqual(
			                 {
				                 -0.981005f, -0.193984f, 0.f,
				                 0.193984f, -0.981005f, 0.f,
				                 0.f, 0.f, 1.f
			                 },
			                 actual);
		}

		// make rot from euler (floats)
		TEST_METHOD(MakeRotateEulerFloat)
		{
			Mat3 actual = Mat3::MakeEuler(1.f * RAD2DEG, 2.f * RAD2DEG, 3.f * RAD2DEG);
			actual = actual.Transposed();

			Assert::AreEqual(
			                 {
				                 0.411982f, -0.058727f, -0.909297f,
				                 -0.833738f, -0.426918f, -0.350175f,
				                 -0.367630f, 0.902382f, -0.224845f
			                 },
			                 actual);
		}

		// make rot from euler (vector)
		TEST_METHOD(MakeRotateEulerVector)
		{
			Mat3 actual = Mat3::MakeEuler({ 1.f * RAD2DEG, 2.f * RAD2DEG, 3.f * RAD2DEG });
			actual = actual.Transposed();

			Assert::AreEqual(
			                 {
								 0.411982f, -0.058727f, -0.909297f,
								 -0.833738f, -0.426918f, -0.350175f,
								 -0.367630f, 0.902382f, -0.224845f
			                 },
			                 actual);
		}

		// make scale from floats
		TEST_METHOD(MakeScaleFloat2D)
		{
			Mat3 actual = Mat3::MakeScale(2.f, 3.f);

			Assert::AreEqual(
			                 {
				                 2.f, 0.f, 0.f,
				                 0.f, 3.f, 0.f,
				                 0.f, 0.f, 1.f
			                 }, actual);
		}

		// make scale from floats
		TEST_METHOD(MakeScaleFloat3D)
		{
			Mat3 actual = Mat3::MakeScale(2.f, 3.f, 4.f);

			Assert::AreEqual(
			                 {
				                 2.f, 0.f, 0.f,
				                 0.f, 3.f, 0.f,
				                 0.f, 0.f, 4.f
			                 }, actual);
		}

		// make scale from vector
		TEST_METHOD(MakeScaleVec3)
		{
			Mat3 actual = Mat3::MakeScale({ 2.f, 3.f, 4.f });

			Assert::AreEqual(
			                 {
				                 2.f, 0.f, 0.f,
				                 0.f, 3.f, 0.f,
				                 0.f, 0.f, 4.f
			                 }, actual);
		}
	};
}

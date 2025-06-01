#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "MathLib/Types/Vec3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathLib::Tests
{
	TEST_CLASS(Vec3Tests)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			Vec3 vec;
			Assert::AreEqual(0.f, vec.x);
			Assert::AreEqual(0.f, vec.y);
			Assert::AreEqual(0.f, vec.z);
		}

		TEST_METHOD(SpecializedConstructor)
		{
			Vec3 vec = { 1.f, 2.f, 3.f };
			Assert::AreEqual(1.f, vec.x);
			Assert::AreEqual(2.f, vec.y);
			Assert::AreEqual(3.f, vec.z);
		}

		TEST_METHOD(Magnitude)
		{
			Vec3 v3a = { 13.5f, -48.23f, 862.f };
			float mag3 = v3a.Magnitude();
			Assert::AreEqual(863.453735352f, mag3, MathLib::MAX_FLOAT_DELTA);

			Vec3 v3b = { 0.f, 0.f, 0.f };
			mag3 = v3b.Magnitude();
			Assert::AreEqual(0.f, mag3, MathLib::MAX_FLOAT_DELTA);
		}

		TEST_METHOD(Normalised)
		{
			Vec3 v3a = { 13.5f, -48.23f, 862.f };
			Assert::AreEqual({ 0.0156349f, -0.0558571f, 0.998316f }, v3a.Normalised());

			Vec3 v3b = { 0.f, 0.f, 0.f };
			Assert::AreEqual({ 0.f, 0.f, 0.f }, v3b.Normalised());
		}

		TEST_METHOD(Normalise)
		{
			Vec3 v3a = { 13.5f, -48.23f, 862.f };
			v3a.Normalise();
			Assert::AreEqual({ 0.0156349f, -0.0558571f, 0.998316f }, v3a);

			Vec3 v3b = { 0.f, 0.f, 0.f };
			v3b.Normalise();
			Assert::AreEqual({ 0.f, 0.f, 0.f }, v3b);
		}

		TEST_METHOD(Dot)
		{
			Vec3 v3a = { 13.5f, -48.23f, 862.f };
			Vec3 v3b = { 5.f, 3.99f, -12.f };
			float dot3 = v3a.Dot(v3b);

			Assert::AreEqual(-10468.9375f, dot3);

			Vec3 v3c = { 0.f, 0.f, 0.f };
			Vec3 v3d = { 5.f, 3.99f, -12.f };
			dot3 = v3c.Dot(v3d);

			Assert::AreEqual(0.0f, dot3);
		}

		TEST_METHOD(Cross)
		{
			Vec3 v3a = { 13.5f, -48.23f, 862.f };
			Vec3 v3b = { 5.f, 3.99f, -12.f };
			Vec3 v3c = v3a.Cross(v3b);

			Assert::AreEqual({ -2860.62011719f, 4472.00000000f, 295.01498413f }, v3c);
		}

		TEST_METHOD(Add)
		{
			Vec3 v3a = { 13.5f, -48.23f, 862.f };
			Vec3 v3b = { 5.f, 3.99f, -12.f };
			Vec3 v3c = v3a + v3b;

			Assert::AreEqual({ 18.5f, -44.24f, 850.f }, v3c);
		}

		TEST_METHOD(Subtract)
		{
			Vec3 v3a = { 13.5f, -48.23f, 862.f };
			Vec3 v3b = { 5.f, 3.99f, -12.f };
			Vec3 v3c = v3a - v3b;

			Assert::AreEqual({ 8.5f, -52.22f, 874.f }, v3c);
		}

		TEST_METHOD(ScalarMulVectorRight)
		{
			Vec3 v3a = { 13.5f, -48.23f, 862.f };
			Vec3 v3c = v3a * 0.256f;

			Assert::AreEqual({ 3.45600008965f, -12.3468809128f, 220.672012329f }, v3c);
		}

		TEST_METHOD(ScalarMulVectorLeft)
		{
			Vec3 v3a = { 13.5f, -48.23f, 862.f };
			Vec3 v3c = 0.256f * v3a;

			Assert::AreEqual({ 3.45600008965f, -12.3468809128f, 220.672012329f }, v3c);
		}
	};

}
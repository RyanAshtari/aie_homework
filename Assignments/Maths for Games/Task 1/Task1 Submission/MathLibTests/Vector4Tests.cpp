#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "MathLib/Types/Vec4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathLib::Tests
{
	TEST_CLASS(Vec4Tests)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			Vec4 vec;
			Assert::AreEqual(0.f, vec.x);
			Assert::AreEqual(0.f, vec.y);
			Assert::AreEqual(0.f, vec.z);
			Assert::AreEqual(0.f, vec.w);
		}

		TEST_METHOD(SpecializedConstructor)
		{
			Vec4 vec = { 1.f, 2.f, 3.f, 4.f };
			Assert::AreEqual(1.f, vec.x);
			Assert::AreEqual(2.f, vec.y);
			Assert::AreEqual(3.f, vec.z);
			Assert::AreEqual(4.f, vec.w);
		}

		TEST_METHOD(Magnitude)
		{
			{
				Vec4 v4a = { 13.5f, -48.23f, 862.f, 0.f };
				float mag4 = v4a.Magnitude();
				Assert::AreEqual(863.453735352f, mag4);
			}
			{
				Vec4 v4a = { 0.f, 0.f, 0.f, 0.f };
				float mag4 = v4a.Magnitude();
				Assert::AreEqual(0.f, mag4);
			}
		}

		TEST_METHOD(Normalised)
		{
			{
				Vec4 v4a = { 243.f, -48.23f, 862.f, 22.2f };
				Vec4 v4b = v4a.Normalised();
				Assert::AreEqual({ 0.270852f, -.053758f, 0.960800f, 0.024745f }, v4b);
			}
			{
				Vec4 v4a = { 0.f, 0.f, 0.f, 1.f };
				Vec4 v4b = v4a.Normalised();
				Assert::AreEqual({ 0.f, 0.f, 0.f, 1.f }, v4b);
			}
			{
				Vec4 v4a = { 0.f, 0.f, 0.f, 0.f };
				Vec4 v4b = v4a.Normalised();
				Assert::AreEqual({ 0.f, 0.f, 0.f, 0.f }, v4b);
			}
		}

		TEST_METHOD(Normalise)
		{
			{
				Vec4 v4a = { 243.f, -48.23f, 862.f, 22.2f };
				v4a.Normalise();
				Assert::AreEqual({ 0.270852f, -0.053758f, 0.960800f, 0.024745f }, v4a);
			}
			{
				Vec4 v4a = { 0.f, 0.f, 0.f, 1.f };
				v4a.Normalise();
				Assert::AreEqual({ 0.f, 0.f, 0.f, 1.f }, v4a);
			}
			{
				Vec4 v4a = { 0.f, 0.f, 0.f, 0.f };
				v4a.Normalise();
				Assert::AreEqual({ 0.f, 0.f, 0.f, 0.f }, v4a);
			}
		}

		TEST_METHOD(Dot)
		{
			Vec4 v4a = { 13.5f, -48.23f, 862.f, 0.f };
			Vec4 v4b = { 5.f, 3.99f, -12.f, 1.f };
			float dot4 = v4a.Dot(v4b);

			Assert::AreEqual(-10468.9375f, dot4, 0.0001f);
		}

		TEST_METHOD(Cross)
		{
			Vec4 v4a = { 13.5f, -48.23f, 862.f, 0.f };
			Vec4 v4b = { 5.f, 3.99f, -12.f, 1.f };
			Vec4 v4c = v4a.Cross(v4b);

			Assert::AreEqual({ -2860.62011719f, 4472.00000000f, 295.01498413f, 0.f }, v4c);
		}

		TEST_METHOD(Add)
		{
			Vec4 v4a = { 13.5f, -48.23f, 862.f, 0.f };
			Vec4 v4b = { 5.f, 3.99f, -12.f, 1.f };
			Vec4 v4c = v4a + v4b;

			Assert::AreEqual({ 18.5f, -44.24f, 850.f, 1.f }, v4c);
		}

		TEST_METHOD(Subtract)
		{
			Vec4 v4a = { 13.5f, -48.23f, 862.f, 0.f };
			Vec4 v4b = { 5.f, 3.99f, -12.f, 1.f };
			Vec4 v4c = v4a - v4b;

			Assert::AreEqual({ 8.5f, -52.22f, 874.f, -1.f }, v4c);
		}

		TEST_METHOD(MultiplyScalarPost)
		{
			Vec4 v4a = { 13.5f, -48.23f, 862.f, 0.f };
			Vec4 v4c = v4a * 4.89f;

			Assert::AreEqual({ 66.0149993896f, -235.844696045f, 4215.1796875f, 0.f }, v4c);
		}

		TEST_METHOD(MultiplyScalarPre)
		{
			Vec4 v4a = { 13.5f, -48.23f, 862.f, 0.f };
			Vec4 v4c = 4.89f * v4a;

			Assert::AreEqual({ 66.0149993896f, -235.844696045f, 4215.1796875f, 0.f }, v4c);
		}
	};
}

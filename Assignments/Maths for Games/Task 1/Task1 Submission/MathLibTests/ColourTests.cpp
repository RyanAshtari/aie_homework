#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "libs/UnitTestLib.h"
#include "MathLib/Types/Color.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using UnitLib::byte;

namespace MathLib::Tests
{
	TEST_CLASS(ColourTests)
	{
	public:
		// default constructor
		TEST_METHOD(ColourDefaultConstructor)
		{
			Color actual;
			Assert::AreEqual(Color{ 0, 0, 0, 255 }.value, UnitLib::BuildColour(0, 0, 0, 255));
		}

		// parameterized constructor
		TEST_METHOD(ColourParamConstructor)
		{
			Color actual{ 32, 64, 10, 255 };

			Assert::AreEqual(UnitLib::BuildColour(32, 64, 10, 255), actual.value);
		}

		// Check equality method
		TEST_METHOD(ColourEqualityOperator)
		{
			Color actual;
			Assert::IsTrue(Color{ 0, 0, 0, 255 } == actual);
		}

		// setting r
		TEST_METHOD(SetRed)
		{
			Color actual = { 32, 64, 10, 255 };
			actual.SetRed(128);
			Assert::AreEqual(UnitLib::BuildColour(128, 64, 10, 255), actual.value);
		}

		// setting g
		TEST_METHOD(SetGreen)
		{
			Color actual = { 32, 64, 10, 255 };
			actual.SetGreen(128);
			Assert::AreEqual(UnitLib::BuildColour(32, 128, 10, 255), actual.value);
		}

		// setting b
		TEST_METHOD(SetBlue)
		{
			Color actual = { 32, 64, 10, 255 };
			actual.SetBlue(128);
			Assert::AreEqual(UnitLib::BuildColour(32, 64, 128, 255), actual.value);
		}

		// setting a
		TEST_METHOD(SetAlpha)
		{
			Color actual = { 32, 64, 10, 255 };
			actual.SetAlpha(128);
			Assert::AreEqual(UnitLib::BuildColour(32, 64, 10, 128), actual.value);
		}

		// Get Red
		TEST_METHOD(GetRed)
		{
			Color actual = { 32, 64, 10, 255 };
			auto red = actual.Red();
			Assert::AreEqual(red, static_cast<byte>(32));
		}

		// Get Green
		TEST_METHOD(GetGreen)
		{
			Color actual = { 32, 64, 10, 255 };
			auto green = actual.Green();
			Assert::AreEqual(green, static_cast<byte>(64));
		}

		// Get Blue

		TEST_METHOD(GetBlue)
		{
			Color actual = { 32, 64, 10, 255 };
			auto blue = actual.Blue();
			Assert::AreEqual(blue, static_cast<byte>(10));
		}

		// Get Alpha
		TEST_METHOD(GetAlpha)
		{
			Color actual = { 32, 64, 0, 255 };
			auto alpha = actual.Alpha();
			Assert::AreEqual(alpha, static_cast<byte>(255));
		}
	};
}

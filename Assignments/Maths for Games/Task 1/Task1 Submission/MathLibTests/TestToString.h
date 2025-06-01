#pragma once

#include <cstdlib>
#include <string>

#include "CppUnitTestAssert.h"

#include "MathLib/Types/Color.h"
#include "MathLib/Types/Mat3.h"
#include "MathLib/Types/Mat4.h"
#include "MathLib/Types/Vec3.h"
#include "MathLib/Types/Vec4.h"

namespace Microsoft::VisualStudio::CppUnitTestFramework
{
	using MathLib::Vec3;
	using MathLib::Vec4;
	using MathLib::Mat3;
	using MathLib::Mat4;
	using MathLib::Color;

	template<> inline std::wstring ToString<Vec3>(const Vec3& t)
	{
		auto str = t.ToString();

		// mbstowcs_s will expect space to write L'\0' if it isn't already included
		// in the src buffer
		//
		// we don't expect that with ToString() which returns a std::string, so we
		// add 1 to the length here
		//
		// without it, it will raise a runtime "Invalid parameter" error
		// 
		// see https://en.cppreference.com/w/c/string/multibyte/mbstowcs
		std::wstring ws(str.length()+1, L' ');

		size_t size = 0;
		mbstowcs_s(&size, &ws[0], ws.length(), str.c_str(), str.length());

		ws.resize(size); // resize to actual fit
		return ws;
	}

	template<> inline std::wstring ToString<Vec4>(const Vec4& t)
	{
		auto str = t.ToString();

		// mbstowcs_s will expect space to write L'\0' if it isn't already included
		// in the src buffer
		//
		// we don't expect that with ToString() which returns a std::string, so we
		// add 1 to the length here
		//
		// without it, it will raise a runtime "Invalid parameter" error
		// 
		// see https://en.cppreference.com/w/c/string/multibyte/mbstowcs
		std::wstring ws(str.length() + 1, L' ');

		size_t size = 0;
		mbstowcs_s(&size, &ws[0], ws.length(), str.c_str(), str.length());

		ws.resize(size); // resize to actual fit
		return ws;
	}

	template<> inline std::wstring ToString<Mat3>(const Mat3& t)
	{
		auto str = t.ToString();

		// mbstowcs_s will expect space to write L'\0' if it isn't already included
		// in the src buffer
		//
		// we don't expect that with ToString() which returns a std::string, so we
		// add 1 to the length here
		//
		// without it, it will raise a runtime "Invalid parameter" error
		// 
		// see https://en.cppreference.com/w/c/string/multibyte/mbstowcs
		std::wstring ws(str.length() + 1, L' ');

		size_t size = 0;
		mbstowcs_s(&size, &ws[0], ws.length(), str.c_str(), str.length());

		ws.resize(size); // resize to actual fit
		return ws;
	}

	template<> inline std::wstring ToString<Mat4>(const Mat4& t)
	{
		auto str = t.ToString();

		// mbstowcs_s will expect space to write L'\0' if it isn't already included
		// in the src buffer
		//
		// we don't expect that with ToString() which returns a std::string, so we
		// add 1 to the length here
		//
		// without it, it will raise a runtime "Invalid parameter" error
		// 
		// see https://en.cppreference.com/w/c/string/multibyte/mbstowcs
		std::wstring ws(str.length() + 1, L' ');

		size_t size = 0;
		mbstowcs_s(&size, &ws[0], ws.length(), str.c_str(), str.length());

		ws.resize(size); // resize to actual fit
		return ws;
	}

	template<> inline std::wstring ToString<Color>(const Color& t)
	{
		auto str =	std::to_string(t.Red()) +
			std::to_string(t.Green()) +
			std::to_string(t.Blue()) +
			std::to_string(t.Alpha());

		// mbstowcs_s will expect space to write L'\0' if it isn't already included
		// in the src buffer
		//
		// we don't expect that with ToString() which returns a std::string, so we
		// add 1 to the length here
		//
		// without it, it will raise a runtime "Invalid parameter" error
		// 
		// see https://en.cppreference.com/w/c/string/multibyte/mbstowcs
		std::wstring ws(str.length() + 1, L' ');

		size_t size = 0;
		mbstowcs_s(&size, &ws[0], ws.length(), str.c_str(), str.length());

		ws.resize(size); // resize to actual fit
		return ws;
	}
}

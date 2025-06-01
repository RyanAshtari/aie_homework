#pragma once

#include <stdint.h>

#include <raylib/raylib.h>

namespace MathLib
{
	class Color
	{
	public:
		uint32_t value;

	public:
		Color();
		Color(uint32_t value);
		Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

		Color(const Color& other);
		Color(Color&& other) noexcept;

		~Color();

	public:
		uint8_t Red() const;
		uint8_t Green() const;
		uint8_t Blue() const;
		uint8_t Alpha() const;

		void SetRed(uint8_t r);
		void SetGreen(uint8_t g);
		void SetBlue(uint8_t b);
		void SetAlpha(uint8_t a);

	public:
		operator ::Color() const;

		bool operator==(const Color& rhs) const;
		bool operator!=(const Color& rhs) const;

		Color& operator=(const Color& other);
		Color& operator=(Color&& other) noexcept;

	};
}
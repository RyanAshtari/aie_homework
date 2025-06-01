#include "MathLib/Types/Color.h"

namespace MathLib
{
	Color::Color()
		: value{ 0x000000FF } //set everything to 0 but A
	{
	}

	Color::Color(uint32_t value)
		:value{ value }
	{

	}

	Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
	{
		SetRed(r);
		SetGreen(g);
		SetBlue(b);
		SetAlpha(a);
	}

	Color::Color(const Color& other)
		:value{ other.value }
	{
	}

	Color::~Color()
	{
	}

	uint8_t Color::Red() const
	{
		return value >> 24;
	}

	uint8_t Color::Green() const
	{
		return value >> 16;
	}

	uint8_t Color::Blue() const
	{
		return value >> 8;
	}

	uint8_t Color::Alpha() const
	{
		return value >> 0;
	}

	void Color::SetRed(uint8_t r)
	{
		constexpr uint32_t mask = 0x00FFFFFF;

		//move the incoming red into the right position
		const unsigned int v = static_cast<unsigned int>(r << 24);

		//clear the values of red in current colour
		value = value & mask;

		//put in new red value
		value = value | v;
	}

	void Color::SetGreen(uint8_t g)
	{
		constexpr uint32_t mask = 0xFF00FFFF;

		//move the incoming red into the right position
		const unsigned int v = static_cast<unsigned int>(g << 16);

		//clear the values of red in current colour
		value = value & mask;

		//put in new red value
		value = value | v;

	}

	void Color::SetBlue(uint8_t b)
	{
		constexpr uint32_t mask = 0xFFFF00FF;

		//move the incoming red into the right position
		const unsigned int v = static_cast<unsigned int>(b << 8);

		//clear the values of red in current colour
		value = value & mask;

		//put in new red value
		value = value | v;

	}

	void Color::SetAlpha(uint8_t a)
	{
		constexpr uint32_t mask = 0xFFFFFF00;

		//move the incoming red into the right position
		const unsigned int v = static_cast<unsigned int>(a << 0);

		//clear the values of red in current colour
		value = value & mask;

		//put in new red value
		value = value | v;
	}

	Color::operator ::Color() const
	{
		return { Red(),Green(),Blue(),Alpha() };
	}

	bool Color::operator==(const Color& rhs) const
	{
		return(value == rhs.value);

	}

	bool Color::operator!=(const Color& rhs) const
	{
		return(value != rhs.value);
	}

	Color& Color::operator=(const Color& other)
	{
		value = other.value;

		return *this;
	}
}

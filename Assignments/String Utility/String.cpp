#include "String.h"

#include <cstring>
#include <iostream>

using std::cout;
using std::cin;

// Initialising all members to 0/null
String::String()
	: m_Data{ nullptr }, m_Length{ 0 }, m_Capacity{ 0 }
{
	// Allocate memory for and add null terminator with m_Data 
	// and save how much space we allocated in m_capacity
	m_Data = new char[1];
	m_Data[0] = '\0';
	m_Capacity = 1;
}

// Constructor to make 'String' from c-style string
String::String(const char* _str)
{
	// If we get a null pointer we treat it like an empty string
	// If not we go ahead with the function
	if (_str == nullptr)
	{
		m_Data = new char[1];
		m_Data[0] = '\0';
		m_Length = 0;
		m_Capacity = 1;
	}
	else
	{
		m_Length = strlen(_str);
		m_Capacity = m_Length + 1; // Remembering to add room for the null terminator
		m_Data = new char[m_Capacity];
		strcpy(m_Data, _str);
	}
}

// Copy constructor to copy one string from another
String::String(const String& _other)
{
	m_Length = _other.m_Length;
	m_Capacity = _other.m_Capacity;
	m_Data = new char[m_Capacity];
	strcpy(m_Data, _other.m_Data);
}

// Destructor
String::~String()
{
	delete[] m_Data;
}

size_t String::Length() const
{
	return size_t();
}


void String::EnsureCapacity(size_t required)
{
}


String& String::Append(const String& _str)
{
	// TODO: insert return statement here
}

String& String::ToLower()
{
	// TODO: insert return statement here
}

String& String::ToUpper()
{
	// TODO: insert return statement here
}

int String::FindCharacter(const char _chr)
{
	return 0;
}

int String::Replace(const char _find, const char _replace)
{
	return 0;
}

String& String::ReadFromConsole()
{
	// TODO: insert return statement here
}

String& String::WriteToConsole()
{
	// TODO: insert return statement here
}

bool String::operator==(const String& _other)
{
	return false;
}

char& String::operator[](size_t _index)
{
	// TODO: insert return statement here
}

const char& String::operator[](size_t _index) const
{
	// TODO: insert return statement here
}

String& String::operator=(const String& _str)
{
	// TODO: insert return statement here
}

bool String::operator<(const String& _str)
{
	return false;
}

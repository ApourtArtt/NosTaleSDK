#pragma once
#include <cstring>
#include <stdlib.h>

/**
 * @brief Game string class.
 */
class String
{
public:
	String()
		: length(0)
		, buffer(nullptr)
	{}

	String(const char* str)
		: String()
	{
		set(str);
	}

	~String()
	{
		if (buffer != nullptr)
		{
			free(buffer);
			buffer = nullptr;
		}
	}

	void set(const char* str)
	{
		if (str == nullptr) return;
		if (buffer != nullptr) free(buffer);

		length = strlen(str);
		buffer = (char*)malloc(length + 0x08 + 1);

		if (buffer == nullptr) return;

		*(size_t*)(buffer + 0x00) = 1;
		*(size_t*)(buffer + 0x04) = length;
		memcpy(buffer + 0x08, str, length);
		buffer[length + 0x08] = '\0';
	}

	char* get() const { return buffer == nullptr ? nullptr : (char*)buffer + 0x08; }
	size_t size() const { return buffer == nullptr ? 0 : length; }

private:
	size_t length;
	char* buffer;  // -0x08 : refCounting ; -0x04 : size ; 0x00 : buffer
};

/**
 * @brief Game unicode string class.
 */
class AString
{
public:
	AString()
		: length(0)
		, buffer(nullptr)
	{}

	AString(const wchar_t* str)
		: AString()
	{
		set(str);
	}

	~AString()
	{
		if (buffer != nullptr)
		{
			free(buffer);
			buffer = nullptr;
		}
	}

	void set(const wchar_t* str)
	{
		if (str == nullptr) return;
		if (buffer != nullptr) free(buffer);

		length = wcslen(str) * 2;
		buffer = (wchar_t*)malloc(length + 0x08 + 1);

		if (buffer == nullptr) return;

		*(size_t*)((char*)buffer + 0x00) = 1;
		*(size_t*)((char*)buffer + 0x04) = length;
		memcpy((char*)buffer + 0x08, str, length);
		*(wchar_t*)((char*)buffer + length + 0x08) = L'\0';
	}

	wchar_t* get() const { return buffer == nullptr ? nullptr : (wchar_t*)((char*)buffer + 0x08); }
	size_t size() const { return buffer == nullptr ? 0 : length; }

private:
	size_t length;
	wchar_t* buffer; // -0x08 : refCounting ; -0x04 : size ; 0x00 : buffer
};

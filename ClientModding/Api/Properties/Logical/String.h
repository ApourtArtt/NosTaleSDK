#pragma once
#include <cstring>
#include <stdlib.h>

class String
{
public:
	String() {}
	String(const char* str)
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
	size_t length{ 0 };
	char* buffer{ nullptr };  // -0x08 : refCounting ; -0x04 : size ; 0x00 : buffer
};

class WString
{
public:
	WString(){}
	WString(const wchar_t* str)
	{
		set(str);
	}

	void set(const wchar_t* str)
	{
		if (str == nullptr) return;

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
	size_t length{ 0 };
	wchar_t* buffer{ nullptr }; // -0x08 : refCounting ; -0x04 : size ; 0x00 : buffer
};

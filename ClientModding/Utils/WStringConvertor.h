#pragma once
#include <locale>
#include <codecvt>
#include <string>

#pragma warning(once: 4996)
static std::wstring StringToW(const std::string& Str)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring wide = converter.from_bytes(Str);
	return wide;
}

static std::string WToString(const std::wstring& Wstr)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::string narrow = converter.to_bytes(Wstr);
	return narrow;
}
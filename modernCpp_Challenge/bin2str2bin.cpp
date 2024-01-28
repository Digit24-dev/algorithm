#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>		// 문자열의 경량 래퍼 타입
#include <vector>

template <typename Iter>
std::string bytes_to_hexstr(Iter begin, Iter end, bool const uppercase = false)
{
	std::ostringstream oss;
	if (uppercase) oss.setf(std::ios_base::uppercase);
	for (; begin != end; ++begin)
	{
		oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(*begin);
	}
	return oss.str();
}

template <typename C>
std::string bytes_to_hexstr(C const& c, bool const uppercase = false)
{
	return bytes_to_hexstr(std::cbegin(c), std::cend(c), uppercase);
}


// string -> binary
unsigned char hexcahr_to_int(char const ch)
{
	if (ch >= '0' && ch <= '9') return ch - '0';
	if (ch >= 'A' && ch <= 'F') return ch - 'A' + 10;
	if (ch >= 'a' && ch <= 'f') return ch - 'a' + 10;
	throw std::invalid_argument("Invalid hexadecimal charactor");
}

std::vector<unsigned char> hexstr_to_bytes(std::string_view str)
{
	std::vector<unsigned char> result;
	for (size_t i = 0; i < str.size(); i++)
	{
		result.push_back((hexcahr_to_int(str[i]) << 4) | hexcahr_to_int(str[i + 1]));
	}
	return result;
}


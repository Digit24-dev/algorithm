#include <iostream>
#include <memory.h>
#include <string>

class MyString {
	char* str;
	int len;

public:
	// 생성자와 복사 생성자
	MyString(char c) {
		str = new char[1]{ c };
		len = 1;
	}
	MyString(const char* s) {
		len = this->strlen(s);
		str = new char[len];
		for (int i = 0; i < len; i++)
		{
			str[i] = s[i];
		}
	}
	MyString(const MyString& s) {
		len = s.len;
		str = new char[len];
		for (int i = 0; i < len; i++)
		{
			this->str[i] = s.str[i];
		}
	}

	// 2. 문자열 길이를 구하는 함수 
	int length() {
		return this->len;
	}

	// 3. 문자열 뒤에 다른 문자열 붙이기
	MyString append(const char* s) {
		return *this;
	}
	MyString append(const MyString s) {
		char* tmp = new char[len + s.len];
		memcpy(tmp, str, len);
		memcpy(tmp + len, s.str, s.len);
		delete[] str;
		str = new char[len + s.len];
		memcpy(str, tmp, len + s.len);
		len += s.len;
		delete[] tmp;
		return *this;
	}

	// 4. 문자열 내에 포함되어 있는 문자열 구하기
	int find(const char* s) {
		if (strlen(s) == 0) return -1;
		for (int i = 0; i < len; i++)
		{
			if (s[0] == str[i])
			{
				for (int j = 1; j < strlen(s); j++)
				{
					if (s[j] == str[i + j] || j == strlen(s)) {
						return i;
					}
				}
			}
		}
		return -1;
	}

	// 5. 문자열 같은지 비교
	bool isEqual(const char* s) {
		int sl = strlen(s);
		if (len != sl) {
			return false;
		}
		else
		{
			for (int i = 0; i < len; i++)
			{
				if (s[i] != str[i])
				{
					return false;
				}
			}
			return true;
		}
	}

	// 6. 문자열 크기 비교
	int compare(const char* s) {
		int sl = strlen(s);
		if (len != sl)
		{
			for (int i = 0; i < len; i++)
			{
				if (str[i] != s[i]) {
					return str[i] - s[i];
				}
			}
			return 0;
		}
		else if (len > sl)
		{
			for (int i = 0; i < sl; i++)
			{
				if (str[i] != s[i]) {
					return str[i] - s[i];
				}
			}
			return 1;
		}
		else
		{
			for (int i = 0; i < len; i++)
			{
				if (str[i] != s[i]) {
					return str[i] - s[i];
				}
			}
			return -1;
		}
	}

	// 출력을 위한 함수 -> operator<< 오버라이딩해서 다시 만들기
	std::string toString() {
		std::string ret;
		ret.resize(len);
		for (int i = 0; i < len; i++)
		{
			ret[i] = str[i];
		}
		ret += "\n";
		return ret;
	}

	// operator[]
	char& operator[](const int index);

	void print() const;
	void println() const;

	// 소멸자
	~MyString()
	{
		delete[] str;
	}

private:
	int strlen(const char* s) {
		int cnt = 0;
		const char* c;
		for (c = s; *c != '\0'; ++c) {
			++cnt;
		}
		return cnt;
	}
};

char& MyString::operator[](const int index) {
	return str[index];
}

void MyString::print() const {
	for (int i = 0; i != len; i++) {
		std::cout << str[i];
	}
}

void MyString::println() const {
	for (int i = 0; i != len; i++) {
		std::cout << str[i];
	}
	std::cout << std::endl;
}

void main() {

	MyString ms("HELLO");
	ms[3] = 'c';

	ms.println();
}
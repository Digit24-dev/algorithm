#include <iostream>

class Complex
{

private:
	double real, img;

public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; };
	Complex(const char* str);

	Complex operator+(const char* str) const;
	Complex operator-(const char* str) const;
	Complex operator*(const char* str) const;
	Complex operator/(const char* str) const;

	friend Complex operator+(const Complex& a, const Complex& b);
	friend Complex operator-(const Complex& a, const Complex& b);
	friend Complex operator*(const Complex& a, const Complex& b);
	friend Complex operator/(const Complex& a, const Complex& b);
	
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);

	Complex& operator=(const Complex& c);

	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}

	int strlen(const char* s) {
		int cnt = 0;
		const char* c;
		for (c = s; *c != '\0'; ++c) {
			++cnt;
		}
		return cnt;
	}

	double get_number(const char* s, int begin, int end) const {
		bool minus = false;
		if (begin > end) return 0;
		if (s[begin] == '-') minus = true;
		if (s[begin] == '-' || s[begin] == '+') begin++;

		double num = 0.0;
		double decimal = 1.0;

		bool integer_part = true;

		for (int i = begin; i <= end; i++)
		{
			if (isdigit(s[i]) && integer_part) {
				num *= 10.0;
				num += (s[i] - '0');
			}
			else if (s[i] == '.')
			{
				integer_part = false;
			}
			else if (isdigit(s[i]) && !integer_part)
			{
				decimal /= 10.0;
				num += ((s[i] - '0') * decimal);
			}
			else
			{
				break;
			}
		}
		if (minus) num *= -1.0;

		return num;
	}
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << "( " << c.real << " , " << c.img << " ) ";
	return os;
}

Complex operator+(const Complex& a, const Complex& b) {
	Complex temp(a.real + b.real, a.img + b.img);
	return temp;
}
Complex operator-(const Complex& a, const Complex& b) {
	Complex temp(a.real - b.real, a.img - b.img);
	return temp;
}
Complex operator*(const Complex& a, const Complex& b) {
	Complex temp(a.real * b.real, a.img * b.img);
	return temp;
}
Complex operator/(const Complex& a, const Complex& b) {
	Complex temp(a.real / b.real, a.img / b.img);
	return temp;
}

Complex::Complex(const char* str) {

	int begin = 0, end = Complex::strlen(str);
	img = 0.0;
	real = 0.0;

	int pos_i = -1; // i의 위치 찾을 변수
	// i의 위치를 찾음
	for (int i = 0; i < Complex::strlen(str); i++)
	{
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}
	
	if (pos_i == -1) {		// i가 없을 경우
		real = get_number(str, begin, end - 1);
		return;
	}

	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);

	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

Complex Complex::operator+(const char* str) const {
	Complex temp(str);
	return (*this) + temp;
}
Complex Complex::operator-(const char* str) const {
	Complex temp(str);
	return (*this) - temp;
}
Complex Complex::operator*(const char* str) const {
	Complex temp(str);
	return (*this) * temp;
}
Complex Complex::operator/(const char* str) const {
	Complex temp(str);
	return (*this) / temp;
}

Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}

int main()
{
	Complex a(0, 0);
	a = "-1.1 + i3.923" + a;
	std::cout << "a 의 값은 : " << a << " 이다. " << std::endl;
}
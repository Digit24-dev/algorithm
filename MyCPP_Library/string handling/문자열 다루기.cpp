#include <iostream>

#include <string>
#include <regex>
using namespace std;

#define DEBUG
#define TEST

#define endl '\n'

#ifdef TEST
#include <vector>
#include <sstream>
vector<string> split(string str, char delim) {
	stringstream ss(str);
	string temp;
	vector<string> ret;

	while (getline(ss, temp, delim))
	{
		ret.push_back(temp);
	}
	return ret;
}

// 특정 문자 전부 제거
string trim(string str, string toErase) {
	while (str.find(toErase) != string::npos) str.erase(str.find(toErase), toErase.size());

	return str;
}

#endif // TEST


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string line;

#ifdef TEST
	//cin >> line;

	// 소수점 포맷팅
	double n = 12.6374;
	cout << fixed;
	cout.precision(0);
	cout << n << endl;
	cout.precision(1);
	cout << n << endl;
	cout.precision(2);
	cout << n << endl;


	// 문자열 수정
	string ex = "abcd123 hello !@#$ abcd 1234";

	cout << ex << endl;
	// replace
	ex.replace(0, 3, "cppaa");	// param1의 인덱스부터 param2만큼 지우고 그 자리에 param3 삽입
	cout << ex << endl;

	// 특정 인덱스 삭제
	//ex.erase(); -> 벡터에서 많이 다루어 봄.

	// 문자의 대소문자 변환
	string ex2 = "abcABC123!@#";
	cout << ex2 << endl;
	for (auto& c : ex2)
	{
		c = toupper(c);
	}
	cout << ex2 << endl;

	// 문자, 숫자 판별
	string ex3 = "0xFF fF16";
	for (auto& c : ex3)
	{
		cout << "숫자?: " << isdigit(c);
		cout << " 문자?: " << isalpha(c);
		cout << endl;
	}

	/*
	* ctype을 판별하는 것으로 다음 매크로를 return 함.
	*	// Bit masks for the possible character types
		#define _UPPER   0x01     // uppercase letter
		#define _LOWER   0x02     // lowercase letter
		#define _DIGIT   0x04     // digit[0-9]
		#define _SPACE   0x08     // tab, carriage return, newline, vertical tab, or form feed
		#define _PUNCT   0x10     // punctuation character
		#define _CONTROL 0x20     // control character
		#define _BLANK   0x40     // space char (tab is handled separately)
		#define _HEX     0x80     // hexadecimal digit
	*/

	// 부분 문자열
	string ex5 = "hello string";

	// str.substr(pos, cout = npos); -> 사실 느리다
	cout << ex5.substr(0, 5) << endl;
	cout << ex5.substr(0) << endl;
	cout << ex5.substr(0, string::npos) << endl;

	string ex5_2 = "hello cpp string cpp";
	cout << ex5_2.find("cpp") << endl;
	cout << ex5_2.find("cpp", 7) << endl;
	cout << ex5_2.find("java") /*string::npos 반환*/ << endl;

	// 특정 문자열 갯수 카운트
	string ex5_3 = "hello java and spring boot";
	regex re("java");
	
	auto end = sregex_iterator();
	auto iter = sregex_iterator(ex5_3.begin(), ex5_3.end(), re);
	cout << "\'a\' count : " << distance(iter, end) << '\n';

	

#endif // TEST

	return 0;
}
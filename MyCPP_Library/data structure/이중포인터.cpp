#include <iostream>
using namespace std;

int main() {
	string a[] = { "qwer","asdf","zxcv" };
	char b[][20] = { "qwer","asdf","zxcv" };
	const char* p = a[0].c_str();
	const char* pb = *b;

	cout << *p << endl;
	cout << **b << endl;

	return 0;
}

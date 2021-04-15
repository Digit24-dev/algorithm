#include <iostream>
#include <memory.h>
#define MAX 100
using namespace std;

void check(const char* a) {
	const char* p = a;
	int top = -1;
	char stack[MAX + 1];

	while (*p != '.')
	{
		if (*p == '(') {
			if (top == MAX) {
				cout << "no" << endl;
				return;
			}
			else {
				stack[++top] = '(';
			}
		}
		else if (*p == '[') {
			if (top == MAX) {
				cout << "no" << endl;
				return;
			}
			else {
				stack[++top] = '[';
			}
		}
		else if (*p == ')') {
			if (top == -1 || stack[top] == '[') {
				cout << "no" << endl;
				return;
			}
			else {
				top = top - 1;
			}
		}
		else if (*p == ']') {
			if (top == -1 || stack[top] == '(') {
				cout << "no" << endl;
				return;
			}
			else {
				top = top - 1;
			}
		}
		p++;
	}
	if (top == -1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

int main() {
	char a[MAX + 1] = { 0, };

	while (1) {
		cin.getline(a, MAX + 1);

		if (a[0] == '.')
			break;

		check(a);
		memset(a, 0, MAX + 1);
	}

	return 0;
}

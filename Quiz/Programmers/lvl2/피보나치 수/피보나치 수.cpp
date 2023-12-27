#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
	long long a[100001];
	a[0] = 0;
	a[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		a[i] = ((a[i - 1] + a[i - 2]) % 1234567);
	}

	return a[n];
}
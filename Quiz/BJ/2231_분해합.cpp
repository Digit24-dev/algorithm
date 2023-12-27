#include <iostream>
using namespace std;

int main() {

	int N, i, temp;
	int sum = 0;
	cin >> N;

	for (i = 1; i < N; i++) {
		sum = i;
		temp = i;
		while (temp > 0) {
			sum = sum + (temp % 10);
			temp = temp / 10;
		}

		if (sum == N) {
			break;
		}
		sum = 0;
	}
	if (sum == N)
		cout << i << endl;
	else
		cout << 0 << endl;

	return 0;
}

#include <stdio.h>

int main() {
	int n, m, sum, top = 0;
	scanf("%d %d", &n, &m);
	int cards[100] = { 0, };
	for (int i = 0; i < n; i++) {
		scanf("%d", &cards[i]);
	}
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			for (int k = i + 2; k < n; k++) {
				sum = cards[i] + cards[j] + cards[k];
				if (top < sum && sum <= m) top = sum;
			}
		}
	}
	printf("%d\n", top);
	return 0;
}

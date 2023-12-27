#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX_N 100000

int map[2*MAX_N + 1];
bool visited[2*MAX_N + 1];

int n, k;
int t = 0;

void bfs(int n) {
	queue<int> q;
	q.push(n);
	visited[n] = true;
	
	while (!q.empty())
	{
		int d = q.front();
		q.pop();

		if (d == k)
			break;

		for (int i = 1; i <= 3; i++)
		{
			int tmp;
			switch (i)
			{
			case 1:
				tmp = d + 1;
				break;
			case 2:
				tmp = d - 1;
				break;
			case 3:
				tmp = d * 2;
				break;
			default:
				break;
			}

			if (visited[tmp]) 
				continue;

			if (tmp < 0 || tmp > 2 * MAX_N)
				continue;

			q.push(tmp);
			map[tmp] = map[d] + 1;
			visited[tmp] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	bfs(n);
	cout << map[k];

	return 0;
}
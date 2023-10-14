#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;
int ans = 0;

int map[101];
bool visited[101];

void bfs(int r) {
	queue<int> q;
	q.push(r);
	visited[r] = true;

	while (!q.empty())
	{
		int d = q.front();
		q.pop();

		if (d == 100)
		{
			cout << map[100] << '\n';
			break;
		}
		
		for (int i = 1; i <= 6; i++)
		{
			int next = d + i;

			if (next > 100)
				continue;
			if (map[next] != 0) {
				next = map[next];
			}
			if (visited[next])
				continue;

			q.push(next);
			visited[next] = true;
			map[next] = map[d] + 1;
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int a, b;

	// n: »ç´Ù¸®, m: ¹ì
	cin >> n >> m;
	for (int i = 0; i < n+m; i++)
	{
		cin >> a >> b;
		map[a] = b;
	}

	bfs(1);

	return 0;
}
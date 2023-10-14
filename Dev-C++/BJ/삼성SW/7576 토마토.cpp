#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX 1000

int map[MAX + 1][MAX + 1];
int visited[MAX + 1][MAX + 1];

int n, m;
int ans = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(queue<pair<int, int>> q) {

	while (!q.empty())
	{
		pair<int, int> cord = q.front();
		q.pop();
		int oy = cord.first;
		int ox = cord.second;

		visited[oy][ox] = true;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = ox + dx[dir];
			int ny = oy + dy[dir];

			if (visited[ny][nx])
				continue;
			if (map[ny][nx] == 1 || map[ny][nx] == -1)
				continue;
			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;

			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
			map[ny][nx] = map[oy][ox] + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	queue<pair<int, int>> q;

	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	
	bfs(q);
	
	bool flagBreak = false;
	// ´ä
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (flagBreak)
				goto end;

			if (map[i][j] == 0)
				flagBreak = true;
			else
			{
				ans = max(ans, map[i][j]-1);
			}
		}
	}
end:
	if (flagBreak)
	{
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}

	return 0;
}
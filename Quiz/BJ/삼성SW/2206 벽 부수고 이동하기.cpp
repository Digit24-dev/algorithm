#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 1001

int n, m;

int map[MAX][MAX];
bool visited[MAX][MAX][2];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bfs() {
	// 
	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(1, 1), make_pair(0, 1)));
	visited[1][1][0] = true;

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int f = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (x == m && y == n)
			return c;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx > 0 && nx <= m && ny > 0 && ny <= n)
			{
				if (map[ny][nx] == 1 && f == 0)	// 방문 안하고 벽
				{
					q.push(make_pair(make_pair(ny, nx), make_pair(f + 1, c + 1)));
					visited[ny][nx][f + 1] = true;
				}
				else if (map[ny][nx] == 0 && visited[ny][nx][f] == false)
				{
					q.push(make_pair(make_pair(ny, nx), make_pair(f, c + 1)));
					visited[ny][nx][f] = true;
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		string line;
		cin >> line;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = line[j-1] - '0';
		}
	}

	cout << bfs();

	return 0;
}
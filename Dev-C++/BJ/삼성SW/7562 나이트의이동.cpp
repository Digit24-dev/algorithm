#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX 300

int T;
int L;
int x, y;
int kx1, ky1;
int kx2, ky2;

int map[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];

vector<int> ans;

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty())
	{
		pair<int, int> cord = q.front();
		q.pop();

		if (cord.first == kx2 && cord.second == ky2)
			break;

		for (int dir = 0; dir < 8; dir++)
		{
			int nx = cord.first + dx[dir];
			int ny = cord.second + dy[dir];

			if (visited[nx][ny])
				continue;
			if (nx < 0 || nx >= L || ny < 0 || ny >= L)
				continue;

			q.push(make_pair(nx, ny));
			visited[nx][ny] = true;
			map[nx][ny] = map[cord.first][cord.second] + 1;
		}
	}
	ans.push_back(map[kx2][ky2]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> T;
	
	while (T--)
	{
		cin >> L;
		cin >> kx1 >> ky1;
		cin >> kx2 >> ky2;

		bfs(kx1, ky1);
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < L; j++)
			{
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
	}

	for (int i : ans)
		cout << i << endl;

	return 0;
}
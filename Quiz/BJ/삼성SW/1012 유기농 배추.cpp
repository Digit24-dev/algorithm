#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX_N 50

int map[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1][MAX_N + 1];

vector<int> a;
int T;
int M, N, K;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty()) 
	{
		pair<int, int> cord = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cord.second+ dx[dir];
			int ny = cord.first + dy[dir];

			if (visited[ny][nx])
				continue;
			if (map[ny][nx] == 0)
				continue;
			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;

			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	vector<int> ans;
	int cnt = 0;

	cin >> T;

	while (T--)
	{
		cin >> M >> N >> K;
		while (K--)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (map[y][x] == 1 && visited[y][x] == false) {
					bfs(y, x);
					cnt++;
				}
			}
		}

		ans.push_back(cnt);
		cnt = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				map[y][x] = 0;
				visited[y][x] = false;
			}
		}
	}
	
	for (int i : ans)
	{
		cout << i << endl;
	}

	return 0;
}
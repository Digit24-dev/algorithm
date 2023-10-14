#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int map[101][101];
int visited[101][101] = { 0, };
int ans = 0;
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y) {
	// x:i, y:j
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	ans++;

	while (!q.empty())
	{
		pair<int, int> node = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = node.first + dx[dir];
			int ny = node.second + dy[dir];

			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				if (map[nx][ny] == 1 && visited[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = visited[node.first][node.second] + 1;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	string line;

	for (int i = 1; i <= n; i++)
	{
		cin >> line;
		for (int j = 1; j <= m; j++) {
			map[i][j] = (int)line[j-1] - 48;
		}
	}

	dfs(1, 1);

	cout << visited[n][m] << endl;

	return 0;
}
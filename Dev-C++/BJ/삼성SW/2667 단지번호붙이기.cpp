#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 25

int map[MAX_N+1][MAX_N+1];
bool visited[MAX_N+1][MAX_N+1];

vector<int> a;
int n;

int cnt = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs(int x, int y) {
	// x:i, y:j
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	cnt++;

	while (!q.empty())
	{
		pair<int, int> cord = q.front();
		q.pop();
		
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cord.first + dx[dir];
			int ny = cord.second + dy[dir];

			if (visited[nx][ny])
				continue;

			if (map[nx][ny] == 0)
				continue;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			q.push(make_pair(nx, ny));
			visited[nx][ny] = true;;
			cnt++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	string line;

	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = n - 1; j >= 0; j--) {
			map[i][j] = (int)line[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				bfs(i, j);
				a.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(a.begin(), a.end());
	cout << a.size() << endl;;
	for (int i : a) 
	{
		cout << i << endl;
	}

	return 0;
}
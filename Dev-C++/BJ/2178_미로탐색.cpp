#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 100

int N, M;
int a[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
int cnt = 0;


int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void input() {
	cin >> N >> M;
	int val;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &val);
			a[i][j] = val;
		}
	}
}

void check() {
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << visited[i][j];
		}
		cout << endl;
	}
}

void bfs() {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	visited[1][1] = true;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > 0 && nx <= M && ny > 0 && ny <= N && a[ny][nx] == 1 && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				a[ny][nx] = a[y][x] + 1;
			}
		}
	}
}

void solution() {
	input();
	//check();
	bfs();
	cout << a[N][M] << endl;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	solution();

	return 0;
}

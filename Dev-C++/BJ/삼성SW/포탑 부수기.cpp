#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_K 1000
#define MAX_ATK 5000

int ans = 0;
int N, M, K;
int map[11][11];
int hisMap[11][11];
int time = 0;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

pair<int, int> selectAttacker() {
	int sel = MAX_ATK;
	pair<int, int> cord = make_pair(1, 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (sel < map[i][j])
			{
				sel = map[i][j];
				cord = make_pair(i, j);
			}
			else
			{
				if (hisMap[i][j] > hisMap[cord.first][cord.second])
				{
					sel = map[i][j];
					cord = make_pair(i, j);
				}
				else {
					if (i + j > cord.first + cord.second) {
						sel = map[i][j];
						cord = make_pair(i, j);
					}
					else {
						if (j > cord.second) {
							sel = map[i][j];
							cord = make_pair(i, j);
						}
					}
				}
			}
		}
	}

	return cord;
}

pair<int, int> selectDefender() {
	int sel = 0;
	pair<int, int> cord = make_pair(N, M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (sel > map[i][j])
			{
				sel = map[i][j];
				cord = make_pair(i, j);
			}
			else
			{
				if (hisMap[i][j] < hisMap[cord.first][cord.second])
				{
					sel = map[i][j];
					cord = make_pair(i, j);
				}
				else {
					if (i + j < cord.first + cord.second) {
						sel = map[i][j];
						cord = make_pair(i, j);
					}
					else {
						if (j < cord.second) {
							sel = map[i][j];
							cord = make_pair(i, j);
						}
					}
				}
			}
		}
	}

	return cord;
}

void attack(pair<int, int> attacker) {
	pair<int, int> a = selectDefender();
	queue<pair<int, int>> q;
	
	// search
	do {
		for (size_t i = 0; i < 4; i++)
		{
			q.push(make_pair(attacker.first + dx[i], attacker.second + dy[i]));
		}
	}
	while (!q.empty())
	{
		break;
	}
}

void repair();

int main() {

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	while (K--) {

	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ans = max(ans, map[i][j]);
		}
	}

	cout << ans;

	return 0;
}

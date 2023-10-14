#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX_N 10

int N, M, K;
int map[MAX_N + 1][MAX_N + 1];
int map2[MAX_N + 1][MAX_N + 1];

pair<int, int> trav[MAX_N + 1];
pair<int, int> exits;

int ans;

int sx, sy, s_size;

void move() {
	for (int i = 1; i <= M; i++) {
		if (trav[i].first == exits.first && trav[i].second == exits.second)
			continue;

		if (trav[i].first != exits.first) {
			int nx = trav[i].first;
			int ny = trav[i].second;

			if (exits.first > nx) nx++;
			else nx--;

			if (!map[nx][ny]) {
				trav[i].first = nx;
				trav[i].second = ny;
				ans++;
				continue;
			}
		}

		if (trav[i].second != exits.second) {
			int nx = trav[i].first;
			int ny = trav[i].second;

			if (exits.second > ny) ny++;
			else ny--;

			if (!map[nx][ny]) {
				trav[i].first = nx;
				trav[i].second = ny;
				ans++;
				continue;
			}
		}
	}
}

void findSquare() {
	// 완전 탐색 공부하고 오기
	for (int sz = 2; sz <= N; sz++) {
		for (int x1 = 1; x1 <= N - sz + 1; x1++) {
			for (int y1 = 1; y1 <= N - sz + 1; y1++) {
				int x2 = x1 + sz - 1;
				int y2 = y1 + sz - 1;

				if (!(x1 <= exits.first && exits.first <= x2 && y1 <= exits.second && exits.second <= y2))
					continue;

				bool is_travler_in = false;
				for (int l = 1; l <= M; l++) {
					if (x1 <= trav[l].first && trav[l].first <= x2 && y1 <= trav[l].second && trav[l].second <= y2)
						if (!(trav[l].first == exits.first && trav[l].second == exits.second))
							is_travler_in = true;
				}

				if (is_travler_in) {
					sx = x1;
					sy = y1;
					s_size = sz;

					return;
				}
			}
		}
	}
}

void rotateSquare() {
	// 벽 감소 
	for (int x = sx; x < sx + s_size; x++) {
		for (int y = sy; y < sy + s_size; y++) {
			if (map[x][y]) map[x][y]--;
		}
	}

	// 시계방향 회전 
	for (int x = sx; x < sx + s_size; x++) {
		for (int y = sy; y < sy + s_size; y++) {
			int ox = x - sx, oy = y - sy;
			int rx = oy, ry = s_size - 1 - ox;

			map2[rx + sx][ry + sy] = map[x][y];
		}
	}

	// 원본으로 옮겨줌. 
	for (int x = sx; x < sx + s_size; x++) {
		for (int y = sy; y < sy + s_size; y++) {
			map[x][y] = map2[x][y];
		}
	}
}

void rotateTravelerAndExit() {
	// 참가자 회전 
	for (int i = 1; i <= M; i++) {
		int x = trav[i].first;
		int y = trav[i].second;

		if (x >= sx && x < sx + s_size && y >= sy && y < sy + s_size) {
			int ox = x - sx, oy = y - sy;
			int rx = oy, ry = s_size - 1 - ox;
			trav[i] = make_pair(rx + sx, ry + sy);
		}
	}

	// 출구 회전
	int x = exits.first;
	int y = exits.second;
	if (x >= sx && x < sx + s_size && y >= sy && y < sy + s_size) {
		int ox = x - sx, oy = y - sy;
		int rx = oy, ry = s_size - 1 - ox;
		exits = make_pair(rx + sx, ry + sy);
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> N >> M >> K;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i < M + 1; i++) {
		cin >> trav[i].first;
		cin >> trav[i].second;
	}
	cin >> exits.first;
	cin >> exits.second;

	while (K--) {
		// 이동
		move();
		// 회전
		bool is_all_escape = true;

		for (int i = 1; i <= M; i++) {
			if (!(trav[i].first == exits.first && trav[i].second == exits.second)) {
				is_all_escape = false;
			}
		}

		if (is_all_escape)
			break;

		findSquare();

		rotateSquare();

		rotateTravelerAndExit();
	}

	cout << ans << "\n";
	cout << exits.first << " " << exits.second;

	return 0;
}

#include <iostream>

using namespace std;

#define MIN -987654321
//#define DEBUG
// REFACTOR
// 1. 구조체 하나 선언해서 안에서 돌리는 것이 조금 더 간결할 듯.
// 2. inline 함수 선언해서 조금 더 간단하게 만들 것.

int N, T = 1, answer = MIN;
int map[100][100];

struct Tetris
{
	int rotation[5] = { 2,2,4,4,1 };
	int shape[5][2][4][4] =
	{
		{{ {0,0,0,0}, {0,1,2,3} }, { {0,1,2,3}, {0,0,0,0} }},		// t1
		{{ {0,0,1,1},{0,1,1,2} }, { {0,1,1,2},{0,0,-1,-1} } },		// t2

		{{{0,0,0,1},{0,1,2,2},{0,0,0,-1},{0,-1,-2,-2}}, { {0,1,2,2},{0,0,0,-1},{0,-1,-2,-2},{0,0,0,1} }},		// t3

		{{{0,0,0,1},{0,1,2,1},{0,0,0,-1},{0,-1,-2,-1}}, { {0,1,2,1},{0,0,0,-1},{0,-1,-2,-1},{0,0,0,1} }},		// t4

		{{{ 0,0,1,1 }},{{ 0,1,0,1 }} }									// t5
	};
	int chk[5][2][4] =
	{
		{{0,3},{3,0}},
		{{1,2},{2,-1}},
		{{1,2,-1,-2},{2,-1,-2,1}},
		{{1,2,-1,-2},{2,-1,-2,1}},
		{{1},{1}}
	};
}tetris;

bool check(int shape, int ni, int nj, int rot) {

	if (0 <= ni + tetris.chk[shape][0][rot] && ni + tetris.chk[shape][0][rot] < N &&
		0 <= nj + tetris.chk[shape][1][rot] && nj + tetris.chk[shape][1][rot] < N)
		return true;
	else return false;
}

inline void solve(int ci, int cj) {
	int ni, nj, ret = 0;
	for (size_t i = 0; i < 5; i++)		// shape
	{
		for (size_t k = 0; k < tetris.rotation[i]; k++)		// rotation
		{
			if (!check(i, ci, cj, k)) continue;
			ret = 0;
			for (size_t l = 0; l < 4; l++)					// blocks
			{
				ni = ci + tetris.shape[i][0][k][l];
				nj = cj + tetris.shape[i][1][k][l];
				
				ret += map[ni][nj];
			}
#ifdef DEBUG
			cout << "shape: " << i << " rotation: " << k << " ret: " << ret << endl;
#endif
			answer = max(answer, ret);
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	while (true)
	{
		cin >> N;
		answer = MIN;
		if (N == 0) break;

		// input
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		// solve
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				solve(i, j);
			}
		}

		cout << T++ << ". " << answer << endl;
	}
	
}
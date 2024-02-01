#include <iostream>

using namespace std;

#define MIN -987654321

// REFACTOR
// 1. 구조체 하나 선언해서 안에서 돌리는 것이 조금 더 간결할 듯.
// 2. inline 함수 선언해서 조금 더 간단하게 만들 것.

int N, T = 1, answer = MIN;
int map[100][100];

int t1_i[2][4] = { {0,0,0,0}, {0,1,2,3} };
int t1_j[2][4] = { {0,1,2,3}, {0,0,0,0} };

int t2_i[2][4] = { {0,0,1,1},{0,1,1,2} };
int t2_j[2][4] = { {0,1,1,2},{0,0,-1,-1} };

// ㅁㅁ
//   ㅁㅁ
//
//   ㅁ
// ㅁㅁ
// ㅁ

int t3_i[4][4] = { {0,0,0,1},{0,1,2,2},{0,0,0,-1},{0,-1,-2,-2} };
int t3_j[4][4] = { {0,1,2,2},{0,0,0,-1},{0,-1,-2,-2},{0,0,0,1} };

// ㅁㅁㅁ		ㅁ
//     ㅁ		ㅁㅁㅁ
//				
//   ㅁ			ㅁㅁ
//   ㅁ			ㅁ
// ㅁㅁ			ㅁ

int t4_i[4][4] = { {0,0,0,1},{0,1,2,1},{0,0,0,-1},{0,-1,-2,-1} };
int t4_j[4][4] = { {0,1,2,1},{0,0,0,-1},{0,-1,-2,-1},{0,0,0,1} };

// ㅁㅁㅁ		  ㅁ
//   ㅁ			ㅁㅁㅁ
// 
//   ㅁ			ㅁ
// ㅁㅁ			ㅁㅁ
//   ㅁ			ㅁ

int t5_i[4] = { 0,0,1,1 };
int t5_j[4] = { 0,1,0,1 };

void solve(int ci, int cj) {
	int ret = 0;

tetris1:
	for (size_t i = 0; i < 2; i++)
	{
		if (i == 0 && cj + 3 >= N) continue;
		if (i == 1 && ci + 3 >= N) continue;
		ret = 0;
		for (size_t j = 0; j < 4; j++)
		{
			int ni = ci + t1_i[i][j];
			int nj = cj + t1_j[i][j];
			ret += map[ni][nj];
		}
		answer = max(answer, ret);
	}

tetris2:
	for (size_t i = 0; i < 2; i++)
	{
		if (i == 0 && (ci + 1 >= N || cj + 2 >= N)) continue;
		if (i == 1 && (ci + 2 >= N || cj - 1 < 0)) continue;
		ret = 0;
		for (size_t j = 0; j < 4; j++)
		{
			int ni = ci + t2_i[i][j];
			int nj = cj + t2_j[i][j];
			ret += map[ni][nj];
		}
		answer = max(answer, ret);
	}

tetris3:
	for (size_t i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			if (cj + 2 >= N || ci + 1 >= N) continue;
			break;
		case 1:
			if (ci + 2 >= N || cj - 1 < 0) continue;
			break;
		case 2:
			if (cj - 2 < 0 || ci - 1 < 0) continue;
			break;
		case 3:
			if (ci - 2 < 0 || cj + 1 >= N) continue;
			break;
		}
		
		ret = 0;
		for (size_t j = 0; j < 4; j++)
		{
			int ni = ci + t3_i[i][j];
			int nj = cj + t3_j[i][j];
			ret += map[ni][nj];
		}
		answer = max(answer, ret);
	}

tetris4:
	for (size_t i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			if (cj + 2 >= N || ci + 1 >= N) continue;
			break;
		case 1:
			if (ci + 2 >= N || cj - 1 < 0) continue;
			break;
		case 2:
			if (cj - 2 < 0 || ci - 1 < 0) continue;
			break;
		case 3:
			if (ci - 2 < 0 || cj + 1 >= N) continue;
			break;
		}

		ret = 0;
		for (size_t j = 0; j < 4; j++)
		{
			int ni = ci + t4_i[i][j];
			int nj = cj + t4_j[i][j];
			ret += map[ni][nj];
		}
		answer = max(answer, ret);
	}

tetris5:
	if (ci + 1 >= N || cj + 1 >= N) return;
	ret = 0;
	for (size_t j = 0; j < 4; j++)
	{
		int ni = ci + t5_i[j];
		int nj = cj + t5_j[j];
		ret += map[ni][nj];
	}
	answer = max(answer, ret);
}

int main() {

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
#include <iostream>
#include <memory>
#define MIN -987654321

using namespace std;

int map[201][201];
int dp[201][201];

int answer = MIN;

int main() {
	// init
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	memset(dp, 0, sizeof(dp));

	// input
	size_t N, M;
	cin >> N >> M;
	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	// solution
	// dp insertion
	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1; j <= M; j++)
		{
			dp[i][j] = map[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	// dp check - sliding window
	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1; j <= M; j++)
		{
			for (size_t si = i; si <= N; si++)
			{
				for (size_t sj = j; sj <= M; sj++)
				{
					int current = dp[si][sj] - dp[si][j - 1] - dp[i - 1][sj] + dp[i - 1][j - 1];
					answer = max(answer, current);
				}
			}
		}
	}
	cout << answer << endl;
}
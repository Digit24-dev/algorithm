#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
    n번째 칸으로 이동하는 경우의 수는 다음의 두가지 이다.
    - [n-1] 칸에서 1칸 점프하는 경우
    - [n-2] 칸에서 2칸 점프하는 경우
    따라서 두 가지 방법에 중복되는 경우는 없다.
*/

long long dp[2001];
long long solution(int n) {
    dp[1] = 1, dp[2] = 2;
    for (size_t i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{

    cout << solution(4) << endl;
        
    return 0;
}
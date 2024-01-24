#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    std::vector<int> dp(n + 1, 0);

    // 기저 사례: 0을 만들 수 있는 경우는 1가지 (아무것도 선택하지 않는 경우)
    dp[0] = 1;

    // 1부터 n까지의 숫자에 대해 경우의 수를 계산
    for (int i = 1; i <= n; ++i) {
        if (i >= 1) {
            dp[i] = (dp[i] + dp[i - 1]) % 1000000007;
        }
        if (i >= 2) {
            dp[i] = (dp[i] + dp[i - 2]) % 1000000007;
        }
    }

    return dp[n];
}

int solution2(int n) {
    if (n == 0) {
        return 1;
    }

    int ways = 0;
    if (n >= 1) {
        ways += solution(n - 1);
    }
    if (n >= 2) {
        ways += solution(n - 2);
    }

    return ways;
}

int solution1(int n) {
    int answer = 0;

    // n을 1과 2로 선택하는 방법의 수.
    // 22 1111 211 211 121
    // 1과 2를 합하여 n이 되는 수 중 중복 조합으로 계산.
    // 1 ~ n 

    // 221 21111 111111
    // 2221 221111 2111111 1111111

    int cnt_one = 0;
    for (int i = n/2; i <= n; i++)
    {
        // i = 2의 갯수
        answer += solution(i);

        ++cnt_one;
    }

    return answer;
}

int main()
{

    cout << solution(4) << endl;

}
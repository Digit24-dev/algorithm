#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    std::vector<int> dp(n + 1, 0);

    // ���� ���: 0�� ���� �� �ִ� ���� 1���� (�ƹ��͵� �������� �ʴ� ���)
    dp[0] = 1;

    // 1���� n������ ���ڿ� ���� ����� ���� ���
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

    // n�� 1�� 2�� �����ϴ� ����� ��.
    // 22 1111 211 211 121
    // 1�� 2�� ���Ͽ� n�� �Ǵ� �� �� �ߺ� �������� ���.
    // 1 ~ n 

    // 221 21111 111111
    // 2221 221111 2111111 1111111

    int cnt_one = 0;
    for (int i = n/2; i <= n; i++)
    {
        // i = 2�� ����
        answer += solution(i);

        ++cnt_one;
    }

    return answer;
}

int main()
{

    cout << solution(4) << endl;

}
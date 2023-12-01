#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
    n��° ĭ���� �̵��ϴ� ����� ���� ������ �ΰ��� �̴�.
    - [n-1] ĭ���� 1ĭ �����ϴ� ���
    - [n-2] ĭ���� 2ĭ �����ϴ� ���
    ���� �� ���� ����� �ߺ��Ǵ� ���� ����.
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
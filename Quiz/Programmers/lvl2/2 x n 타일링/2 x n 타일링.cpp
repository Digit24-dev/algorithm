#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
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
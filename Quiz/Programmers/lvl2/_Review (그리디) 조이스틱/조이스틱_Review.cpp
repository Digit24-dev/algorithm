#include <iostream>

// 풀이
// 1. 상하로 움직이는 최수
// 2. 좌우로 움직이는 최소
//   - 한쪽으로 움직이는 경우와 반대 방향으로 움직이는 경우의 최솟값을 계산한다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();

    // 상하 조작 최소 횟수 계산
    for (int i = 0; i < len; ++i) {
        int up = name[i] - 'A';
        int down = 'Z' - name[i] + 1;
        answer += min(up, down);
    }

    int minMove = len - 1;  // 모든 문자를 오른쪽으로 이동하는 경우

    // 좌우 조작 최소 횟수 계산
    for (int i = 0; i < len; ++i) {
        int next = i + 1;
        while (next < len && name[next] == 'A') {
            next++;
        }
        int reverseMove = i + len - next + min(i, len - next);
        minMove = min(minMove, reverseMove);
    }

    answer += minMove;

    return answer;
}

int main() {

    //cout << solution("JEROEN") << endl;
    //cout << solution("JAN") << endl;
    cout << solution("NOTBAAAAD") << endl;

}
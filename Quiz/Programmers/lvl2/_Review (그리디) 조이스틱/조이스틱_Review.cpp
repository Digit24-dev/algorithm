#include <iostream>

// Ǯ��
// 1. ���Ϸ� �����̴� �ּ�
// 2. �¿�� �����̴� �ּ�
//   - �������� �����̴� ���� �ݴ� �������� �����̴� ����� �ּڰ��� ����Ѵ�.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();

    // ���� ���� �ּ� Ƚ�� ���
    for (int i = 0; i < len; ++i) {
        int up = name[i] - 'A';
        int down = 'Z' - name[i] + 1;
        answer += min(up, down);
    }

    int minMove = len - 1;  // ��� ���ڸ� ���������� �̵��ϴ� ���

    // �¿� ���� �ּ� Ƚ�� ���
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
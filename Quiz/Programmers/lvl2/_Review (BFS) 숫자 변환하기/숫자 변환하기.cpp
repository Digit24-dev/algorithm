#include <iostream>

#include <string>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>
using namespace std;

int dp[1000001] = { 0, };

// bfs Ǯ��
/*
1. BFS�� �����Ѵ�.
1.1 ������ �����͸� Q�� �ִ´�.
1.2 ������ ����Ѵ�.

2. ���ѵ� ������ Ȯ���Ѵ�.
2.1 ���� ������ y���� ū ���
2.2 �̹� ������ �������� ���
2.3 �� ���� �������� �ʾ��� ��� ���� �־��ش�. -> BFS�� Ž���ϴ� ���, ���� ���� ������ �ּ� ���� Ƚ���̴�.
*/

//// ����
//int solution(int x, int y, int n) {
//    if (x == y) return 0; // ���� ��� ���� 0
//
//    int cnt = 1;
//    memset(dp, -1, sizeof(dp));
//    queue<pair<int,int>> q; // data, round
//    set<int> s;
//
//    q.push(make_pair(x, cnt));
//
//    while (!q.empty())
//    {
//        pair<int, int> cur = q.front();
//        q.pop();
//
//        if (cur.first + n <= y) {
//            if (s.insert(cur.first + n).second) {
//                if (dp[cur.first + n] == -1) {
//                    q.push(make_pair(cur.first + n, cur.second + 1));
//                    dp[cur.first + n] = cur.second;
//                }
//                else {
//                    q.push(make_pair(cur.first + n, cur.second + 1));
//                    dp[cur.first + n] = min(dp[cur.first + n], cur.second);
//                }
//            }
//        }
//
//        if (cur.first * 2 <= y) {
//            if (s.insert(cur.first * 2).second) {
//                if (dp[cur.first * 2] == -1) {
//                    q.push(make_pair(cur.first * 2, cur.second + 1));
//                    dp[cur.first * 2] = cur.second;
//                }
//                else {
//                    q.push(make_pair(cur.first * 2, cur.second + 1));
//                    dp[cur.first * 2] = min(dp[cur.first * 2], cur.second);
//                }
//            }
//        }
//
//        if (cur.first * 3 <= y) {
//            if (s.insert(cur.first * 3).second) {
//                if (dp[cur.first * 3] == -1) {
//                    q.push(make_pair(cur.first * 3, cur.second + 1));
//                    dp[cur.first * 3] = cur.second;
//                }
//                else {
//                    q.push(make_pair(cur.first * 3, cur.second + 1));
//                    dp[cur.first * 3] = min(dp[cur.first * 3], cur.second);
//                }
//            }
//        }
//    }
//
//    return dp[y];
//}

// �� ��°
int solution(int x, int y, int n) {
    if (x == y) return 0; // ���� ��� ���� 0

    int cnt = 1;
    memset(dp, -1, sizeof(dp));
    queue<pair<int, int>> q; // data, round
    set<int> s;

    q.push(make_pair(x, cnt));

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first + n <= y) {
            if (s.insert(cur.first + n).second) {
                q.push(make_pair(cur.first + n, cur.second + 1));
                dp[cur.first + n] = cur.second;
            }
        }

        if (cur.first * 2 <= y) {
            if (s.insert(cur.first * 2).second) {
                q.push(make_pair(cur.first * 2, cur.second + 1));
                dp[cur.first * 2] = cur.second;
            }
        }

        if (cur.first * 3 <= y) {
            if (s.insert(cur.first * 3).second) {
                q.push(make_pair(cur.first * 3, cur.second + 1));
                dp[cur.first * 3] = cur.second;
            }
        }
    }

    return dp[y];
}

int main() {

    int x = 10;
    int y = 40;
    int n = 30;

    cout << solution(x, y, n);

    return 0;
}
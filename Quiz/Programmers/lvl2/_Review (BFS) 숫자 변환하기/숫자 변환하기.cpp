#include <iostream>

#include <string>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>
using namespace std;

int dp[1000001] = { 0, };

// bfs 풀이
/*
1. BFS로 구현한다.
1.1 연산할 데이터를 Q에 넣는다.
1.2 범위를 계산한다.

2. 제한된 범위를 확인한다.
2.1 연산 범위가 y보다 큰 경우
2.2 이미 연산한 데이터인 경우
2.3 한 번도 연산한지 않았을 경우 값을 넣어준다. -> BFS로 탐색하는 경우, 최초 도달 시점이 최소 연산 횟수이다.
*/

//// 최초
//int solution(int x, int y, int n) {
//    if (x == y) return 0; // 같을 경우 라운드 0
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

// 두 번째
int solution(int x, int y, int n) {
    if (x == y) return 0; // 같을 경우 라운드 0

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
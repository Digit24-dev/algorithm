#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

void dfs(vector<vector<int>>& d, int k, int cnt, vector<bool> check) {
    if (cnt > ans) ans = cnt;

    for (int i = 0; i < check.size(); i++)
    {
        if (!check[i] && k >= d[i][0]) {
            check[i] = true;
            dfs(d, k - d[i][1], cnt + 1, check);
            check[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    vector<bool> check(dungeons.size(), false);
    // 1: 최소 2: 소모
    // 완전 탐색
    dfs(dungeons, k, 0, check);

    return ans;
}

int main() {
    cout << solution(80, { {80,20},{50,40},{30,10} }) << endl;
    cout << solution(40, { {40, 20}, { 10, 10 }, { 10, 10 }, { 10, 10 }, { 10, 10 } }) << endl;
}
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
bool visited[8] = { false, };

int dfs(vector<vector<int>>& d, int cnt, int k) {
    if (cnt > answer) answer = cnt;

    for (int i = 0; i < d.size(); i++)
    {
        if (!visited[i] && d[i][0] <= k) {
            visited[i] = true;
            dfs(d, cnt + 1, k - d[i][1]);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    dfs(dungeons, 0, k);
    
    return answer;
}

int main() {
    cout << solution(80, { {80,20},{50,40},{30,10} }) << endl;
    cout << solution(40, { {40, 20}, { 10, 10 }, { 10, 10 }, { 10, 10 }, { 10, 10 } }) << endl;
}
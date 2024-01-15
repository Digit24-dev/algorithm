#include <iostream>

#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[200];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    memset(visited, false, sizeof(visited));
    
    queue<int> q; // value : n-th computer

    for (size_t i = 0; i < n; i++)
    {
        if (!visited[i]) answer++;
        else continue;
        
        visited[i] = true;
        q.push(i);

        while (!q.empty())
        {
            int cur = q.front(); q.pop();

            for (size_t idx = 0; idx < n; idx++)
            {
                if (cur == idx) continue;
                if (computers[cur][idx] == 1)
                    if (!visited[idx]) {
                        visited[idx] = true;
                        q.push(idx);
                    }
            }
        }
    }

    return answer;
}

int main() {

    int n = 3;
    vector<vector<int>> param = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };
    //vector<vector<int>> param = { {1, 1, 0}, { 1, 1, 1 }, { 0, 1, 1 }};

    cout << solution(n, param) << endl;

}
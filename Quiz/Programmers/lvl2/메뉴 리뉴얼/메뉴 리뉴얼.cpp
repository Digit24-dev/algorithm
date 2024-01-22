#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool visited[20];
unordered_map<string, int> uomap;

void dfs(string& a, int idx, int depth, int cNum, string d) {
    if (depth == cNum - 1) {
        std::sort(d.begin(), d.end(), [](char a, char b) {
            return a < b;
        });
        if (uomap.find(d) == uomap.end())
            uomap[d] = 1;
        else
            ++uomap[d];
        return;
    }

    for (int i = idx; i < a.size() - 1; i++)
    {
        if (visited[i + 1]) continue;
        visited[i + 1] = true;
        dfs(a, i + 1, depth + 1, cNum, d + a[i + 1]);
        visited[i + 1] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    memset(visited, false, sizeof(visited));
    
    

    // dfs 맵에 넣기
    for (auto& order : orders)
    {
        for (auto& courseNum : course)
        {
            // dfs
            visited[0] = true;
            string t = "";
            t += order[0];
            dfs(order, 0, 0, courseNum, t);
        }
    }
    
    // 정렬
    for (auto& item : uomap)
    {
        if (item.second >= 2) {
            answer.push_back(item.first);
        }
    }
    sort(answer.begin(), answer.end(), [](string& a, string& b) {
        return a < b;
    });

    return answer;
}

int main() {

    vector<string> param1 = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }; vector<int> param2 = { 2, 3, 4 }; //{"AC", "ACDE", "BCFG", "CDE"}
    //vector<string> param1 = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }; vector<int> param2 = { 2, 3, 5 }; //{"ACD", "AD", "ADE", "CD", "XYZ"}
    //vector<string> param1 = { "XYZ", "XWY", "WXA" }; vector<int> param2 = { 2, 3, 4 }; //{"WX", "XY"}

    vector<string> ret = solution(param1, param2);

    for (auto& i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
}



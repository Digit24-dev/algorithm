#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> ans;

bool isEmpty(unordered_map<string, vector<string>>& uomap) {
    for (auto& i : uomap)
    {
        if (i.second.size() != 0) return false;
    }
    return true;
}

void dfs(string w, unordered_map<string, vector<string>>& uomap) {
    
    string temp = "";

    for (int idx = 0; idx < uomap[w].size(); idx++)
    {
        temp = uomap[w][idx];
        
        if (uomap[w].size() == 0) return;

        ans.push_back(temp);
        uomap[w].erase(uomap[w].begin() + idx);

        dfs(temp, uomap);
        
        // backtracking
        if (isEmpty(uomap)) return;

        ans.pop_back();
        uomap[w].insert(uomap[w].begin() + idx, temp);
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    string start = "ICN";
    unordered_map<string, vector<string>> uomap;

    // 맵에 삽입
    for (auto& elem : tickets)
    {
        if (uomap.find(elem[0]) != uomap.end()) {
            uomap[elem[0]].push_back(elem[1]);
            // 이미 있을 경우 알파벳 순으로 정렬
            sort(uomap[elem[0]].begin(), uomap[elem[0]].end());
        }
        else {
            uomap[elem[0]].push_back(elem[1]);
        }
    }

    // dfs
    ans.push_back("ICN");
    dfs("ICN", uomap);
    
    return ans;
}


int main() {

    vector<vector<string>> param = { {"ICN", "JFK"}, { "HND", "IAD" }, { "JFK", "HND" } };
    //vector<vector<string>> param = { {"ICN", "SFO"}, { "ICN", "ATL" }, { "SFO", "ATL" }, { "ATL", "ICN" }, { "ATL","SFO" } };
    //vector<vector<string>> param = { { "ICN", "COO" }, { "ICN", "BOO" }, { "COO", "ICN" } };
    vector<string> ret;


    ret = solution(param);
    for (auto& i : ret)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();

    vector<char> s;
    vector<char> _cmp;
    int i;
    
    for (int i = 0; i < skill.size(); i++)
    {
        s.push_back(skill[i]);
    }

    for (auto& skillTree : skill_trees)
    {
        _cmp = s;
        for (i = 0; i < skillTree.size(); i++)
        {
            if (_cmp.empty()) {
                break;
            }
            if (_cmp.front() == skillTree[i]) {
                _cmp.erase(_cmp.begin());
            }
            else {
                if (find(_cmp.begin() + 1, _cmp.end(), skillTree[i]) != _cmp.end()) {
                    --answer;
                    break;
                }
            }
        }
    }

    return answer;
}

int main() {
    string param1 = "CBD";
    vector<string> param2 = { "BACDE", "CBADF", "AECB", "BDA" };
    //string param1 = "ABC";
    //vector<string> param2 = { "AB", "AC", "BC", "C" };
    cout << solution(param1, param2) << endl;
}
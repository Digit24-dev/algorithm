#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m;
    map<int, string> m_r;
    int num = 1;

    // 순서대로 맵에 넣기
    for (auto& i : players)
    {
        m.insert(make_pair(i, num));
        m_r.insert(make_pair(num, i));
        num++;
    }

    for (auto& i : callings)
    {
        int currentNum = m[i];
        string currentNumName = m_r[currentNum - 1];

        m[i]--;
        m[currentNumName]++;

        m_r[currentNum] = currentNumName;
        m_r[currentNum - 1] = i;
    }

    for (auto& i : m_r)
    {
        answer.push_back(i.second);
    }

    return answer;
}
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int temp_score;
    map<string, int> m;
    for (int i = 0; i < name.size(); i++)
    {
        m.insert(make_pair(name[i], yearning[i]));
    }

    for (auto& iter : photo)
    {
        temp_score = 0;
        for (auto& elem : iter)
        {
            temp_score += m[elem];
        }
        answer.push_back(temp_score);
    }

    return answer;
}
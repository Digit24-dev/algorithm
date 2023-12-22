#include <iostream>

#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    // 배열
    int rotation[3][11] = { { 5, 1, 2, 3, 4, 5 } 
                        , { 8, 2, 1, 2, 3, 2, 4, 2, 5 } 
                        , { 10, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };

    // STL
    vector<vector<int>> rot;
    rot = { { 1, 2, 3, 4, 5 }
        , { 2, 1, 2, 3, 2, 4, 2, 5 }
        , { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };

    vector<int> sc(3, 0);
    //map<int, int> sc;
    int scores[3] = { 0, };

    for (size_t i = 0; i < answers.size(); i++)
    {
        for (size_t student = 0; student < 3; student++)
        {
            if (answers[i] == rot[student][i % rot[student].size()])
                ++sc[student];

            if (answers[i] == rotation[student][i % rotation[student][0] + 1])
                ++scores[student];
        }
    }

    /* 생각하는데 오래 걸림 */
    int _max = 0;
    for (size_t i = 0; i < 3; i++)
    {
        if (_max < sc[i]) {
            _max = sc[i];
            answer.clear();
            answer.push_back(i + 1);
        }
        else if (_max == sc[i]) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}

int main()
{
    vector<int> ret = solution({ 3,3,3,3,2 });
    for (auto& i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
}
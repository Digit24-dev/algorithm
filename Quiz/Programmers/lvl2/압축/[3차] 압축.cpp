#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    
    vector<int> answer;

    unordered_map<string, int> m; // key, index number
    int i, j;

    // Initialization
    for (size_t i = 0; i < 26; i++)
    {
        m.insert(make_pair(to_string('A' + i), i + 1));
    }
    
    bool flag = false;
    int hashMapIndex = 27;
    for (i = 0; i < msg.size(); i++)
    {
        string temp;
        
        // 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾음.
        for (int j = 0; j < msg.size() - i; j++)
        {

        }

        // 두 문자열 이상으로 분기하여 생각했으므로 flag를 통해 나눈다... 주어진 로직 대로 다시 짜보자.
        for (j = 2; j < msg.size() - i + 2; j++) // 초기값 다시 확인
        {
            temp = msg.substr(i, j);
            auto findIter = m.find(temp);

            if (findIter == m.end()) {
                m[temp] = hashMapIndex++;
                break;
            }
            else {
                // max 값을 찾아야 함.
                flag = true;
            }
        }

        if (flag)
        {
            flag = false;
            answer.push_back(m[msg.substr(i, j - 1)]);
            i += j - 2;
        }
        else
        {
            answer.push_back(m[to_string(msg[i])]);
        }
    }

    return answer;
}

int main() {
    vector<int> ret;
    string param = "TOBEORNOTTOBEORTOBEORNOT";

    ret = solution(param);

    for (auto& i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
}
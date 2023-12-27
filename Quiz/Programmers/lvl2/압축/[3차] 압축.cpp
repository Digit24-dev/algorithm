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
        
        // �������� ���� �Է°� ��ġ�ϴ� ���� �� ���ڿ� w�� ã��.
        for (int j = 0; j < msg.size() - i; j++)
        {

        }

        // �� ���ڿ� �̻����� �б��Ͽ� ���������Ƿ� flag�� ���� ������... �־��� ���� ��� �ٽ� ¥����.
        for (j = 2; j < msg.size() - i + 2; j++) // �ʱⰪ �ٽ� Ȯ��
        {
            temp = msg.substr(i, j);
            auto findIter = m.find(temp);

            if (findIter == m.end()) {
                m[temp] = hashMapIndex++;
                break;
            }
            else {
                // max ���� ã�ƾ� ��.
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
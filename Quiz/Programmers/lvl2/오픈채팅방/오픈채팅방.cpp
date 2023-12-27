#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<string> split(string str, char delim) {
    vector<string> ret;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delim))
    {
        ret.push_back(temp);
    }

    return ret;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> chatHash; // uid, nickname
    string line;

    for (auto& elem : record)
    {
        vector<string> bucket = split(elem, ' ');
        // 0: enter, leave, change
        // 1: uid
        // 2: nickname

        if (bucket[0] == "Enter"){
            chatHash[bucket[1]] = bucket[2];
            answer.push_back(bucket[1] + "#E");
        }
        else if (bucket[0] == "Leave") {
            answer.push_back(bucket[1] + "#O");
        }
        else if (bucket[0] == "Change") {
            chatHash[bucket[1]] = bucket[2];
        }
    }

    string temp;
    for (auto& i : answer)
    {
        auto iter = i.find('#');
        char io = i[iter + 1];
        temp = i.substr(0, iter);
        if (io == 'E') {
            i = chatHash[temp] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        }
        else {
            i = chatHash[temp] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        }
    }

    return answer;
}

int main() {
    vector<string> ret;
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

    ret = solution(record);

    for (auto& i : ret)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
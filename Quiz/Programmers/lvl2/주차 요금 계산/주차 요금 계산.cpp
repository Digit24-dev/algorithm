#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;

vector<string> split(string str, char delim) {
    vector<string> ret;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delim)) {
        ret.push_back(temp);
    }
    return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map<string, int> m;

    unordered_map<string, int> tableIn;

    const int base_time = fees[0];
    const int base_fee = fees[1];
    const int per_time = fees[2];
    const int per_fee = fees[3];
    // fees 기본시간 / 기본요금 / 단위 시간 / 단위 요금
    // 
    // recored 0: 시간 / 1: 차량번호 / 2:IN OUT

    for (auto& rec : records)
    {
        vector<string> temp = split(rec, ' ');

        // temp[0] 시간 ':' 으로 분리
        auto _tmpStringTime = split(temp[0], ':');
        int _tmpIntTime = stoi(_tmpStringTime[0]) * 60 + stoi(_tmpStringTime[1]);

        if (temp[2] == "IN") {
            tableIn[temp[1]] = _tmpIntTime;
        }
        else if (temp[2] == "OUT") {
            m[temp[1]] += _tmpIntTime - tableIn[temp[1]];
            tableIn.erase(temp[1]);
        }
    }

    if (!tableIn.empty())
    {
        for (auto& car : tableIn)
        {
            m[car.first] += 1439 - car.second;
        }
    }

    // 요금 계산
    // 분으로 환산
    for (auto& i : m)
    {
        if (i.second > base_time){
            int ans = ceil(static_cast<double>(i.second - base_time) / per_time) * per_fee + base_fee;
            answer.push_back(ans);
        }
        else {
            answer.push_back(base_fee);
        }
    }

    return answer;
}

int main() {
    vector<int> param1 = { 180, 5000, 10, 600 };
    vector<string> param2= {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    vector<int> ret;
    
    ret = solution(param1, param2);
    for (auto& i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
}
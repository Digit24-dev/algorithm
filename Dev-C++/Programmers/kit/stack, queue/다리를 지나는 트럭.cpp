#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cnt = 0;
    vector<pair<int, int>> q; // f: 들어온 트럭 무게, s: 들어온 시간
    q.reserve(bridge_length);
    int sum = 0;

    while (!truck_weights.empty() || !q.empty())
    {
        ++answer;
        sum = 0;

        // 트럭이 다리를 다 지났는지 확인
        for (auto& i : q)
        {
            if (answer - i.second == bridge_length)
            {
                q.erase(q.begin());
            }
        }

        // 무게 검색
        for (auto& i : q)
        {
            sum += i.first;
        }

        // 다음 트럭이 들어올 수 있는지 확인
        if (!truck_weights.empty() && sum + truck_weights[0] <= weight && q.size() <= bridge_length)
        {
            q.push_back(make_pair(truck_weights[0], answer));
            truck_weights.erase(truck_weights.begin());
        }
    }

    return answer;
}

int main() {

    //cout << solution(2, 10, { 7,4,5,6 }) << endl;
    cout << solution(100, 10, { 10 }) << endl;

}
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cnt = 0;
    vector<pair<int, int>> q; // f: ���� Ʈ�� ����, s: ���� �ð�
    q.reserve(bridge_length);
    int sum = 0;

    while (!truck_weights.empty() || !q.empty())
    {
        ++answer;
        sum = 0;

        // Ʈ���� �ٸ��� �� �������� Ȯ��
        for (auto& i : q)
        {
            if (answer - i.second == bridge_length)
            {
                q.erase(q.begin());
            }
        }

        // ���� �˻�
        for (auto& i : q)
        {
            sum += i.first;
        }

        // ���� Ʈ���� ���� �� �ִ��� Ȯ��
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
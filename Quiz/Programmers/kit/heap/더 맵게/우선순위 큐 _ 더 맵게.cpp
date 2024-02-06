#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, sc;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto& i : scoville)
    {
        pq.push(i);
    }

    while (!pq.empty() && pq.top() < K)
    {
        sc = pq.top(); pq.pop();
        pq.push(sc + (pq.top() * 2));
        pq.pop();
        answer++;
    }

    if (pq.empty()) return -1;
    else return answer;
}


int main() {

    vector<int> p = { 1,1,2,3 };
    int K = 7;

    cout << solution(p, K) << endl;

    return 0;
}
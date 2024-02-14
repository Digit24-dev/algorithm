#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    
    long long answer = 0;
    int sum = 0;
    priority_queue<int, vector<int>, less<int>> pq;

    for (auto& i : works)
    {
        sum += i;
        pq.push(i);
    }
    if (sum <= n) return 0;

    while (n--)
    {
        int cur = pq.top(); pq.pop();
        pq.push(--cur);
        cout << n << " : " << cur << endl;
    }

    while (!pq.empty())
    {
        int cur = pq.top(); pq.pop();
        answer += pow(cur, 2);
    }

    return answer;
}

int main() {

    //int n = 4; vector<int> p = { 4,3,3 };
    //int n = 1; vector<int> p = { 2,1,2 };
    //int n = 3; vector<int> p = { 1,1 };
    int n = 99; vector<int> p = { 2,15,22,55,55 };

    cout << solution(n, p) << endl;

}
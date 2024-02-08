#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool visited[7] = { false, };

set<int> permutation;

bool isPrime(int target) {
    if (target == 1) return false;
    for (size_t i = 2; i < target; i++)
    {
        if (target % i == 0)
            return false;
    }

    return true;
}
// ¼¯¾î¼­ ³Ö±â 
void dfs(string& n, int cnt, string buf) {
    if (cnt == n.size()) return;
    
    permutation.insert(stoi(buf));

    for (size_t i = 0; i < n.size(); i++)
    {
        if (visited[i]) continue;
        
        visited[i] = true;
        string _t = buf + n[i];
        dfs(n, cnt + 1, _t);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;

    for (size_t i = 0; i < numbers.size(); i++)
    {
        visited[i] = true;
        string t;
        t += numbers[i];
        dfs(numbers, 0, t);
        visited[i] = false;
    }

    for (auto& i : permutation)
    {
        if (i == 0) continue;
        if (isPrime(i)) {
            cout << i << endl;
            ++answer;
        }
    }

    return answer;
}



int main() {
    cout << solution("17") << endl;
    
    /*for (auto& i : permutation)
    {
        cout << i << endl;
    }*/

}
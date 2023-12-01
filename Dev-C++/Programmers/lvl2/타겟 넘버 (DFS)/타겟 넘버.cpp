#include <string>
#include <vector>
#include <iostream>
using namespace std;

int g_target;
int answer = 0;

void dfs(const vector<int>& numbers,int idx, int sum) {
    if (idx == numbers.size()) {
        if (sum == g_target) {
            ++answer;
        }
            return;
    }

    dfs(numbers, idx + 1, sum + numbers[idx]);
    dfs(numbers, idx + 1, sum + (-1 * numbers[idx]));
}

int solution(vector<int> numbers, int target) {
    g_target = target;
    
    dfs(numbers, 0, 0);

    return answer;
}

int main()
{
    cout << solution({ 1,1,1,1,1 }, 3) << endl;
    return 0;
}
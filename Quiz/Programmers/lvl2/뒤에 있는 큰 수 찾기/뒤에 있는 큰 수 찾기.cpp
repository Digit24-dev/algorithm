#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    
    // 1. Normal
    /*vector<int> answer;
    answer.reserve(numbers.size());
    int t;

    for (int i = 0; i < numbers.size(); i++)
    {
        t = -1;
        for (int j = i; j < numbers.size(); j++)
        {
            if (numbers[i] < numbers[j])
            {
                t = numbers[j];
                break;
            }
        }
        answer.push_back(t);
    }

    return answer;*/

    // 2. Stack
    vector<int> ans(numbers.size(), -1);
    stack<pair<int, int>> st; // f: index s: data
    
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        st.push(make_pair(i, numbers[i]));

        while (!st.empty() && st.top().second < numbers[i + 1]) {
            ans[st.top().first] = numbers[i + 1];
            st.pop();
        }
    }

    return ans;
}

int main() {
    //vector<int> param = { 2,3,3,5 };
    vector<int> param = { 9,1,5,3,6,2 };
    vector<int> ret;

    ret = solution(param);

    for (auto& i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
}
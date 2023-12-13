/*

문제 설명
초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때,
가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

제한사항
prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
prices의 길이는 2 이상 100,000 이하입니다.

*/

#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    
    vector<int> answer(prices.size(), 0);
    stack<int> st; // 스택에 시간 푸시

    for (size_t i = 0; i < prices.size(); i++)
    {
        // 주식 가격이 떨어질 경우 팝하면서 값 대입
        while (!st.empty() && prices[i] < prices[st.top()])
        {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        // 이 외의 경우 푸시
        st.push(i);
    }

    // 이후 스택에 살아남은 데이터 정리
    while (!st.empty())
    {
        answer[st.top()] = prices.size() - st.top() - 1;
        st.pop();
    }

    return answer;
}

int main()
{
    vector<int> ans = solution({ 1,2,3,2,3 });
    //vector<int> ans = solution({ 9, 8, 7, 6, 5 });

    for (auto& i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

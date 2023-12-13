/*

���� ����
�� ������ ��ϵ� �ֽİ����� ��� �迭 prices�� �Ű������� �־��� ��,
������ �������� ���� �Ⱓ�� �� �������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���ѻ���
prices�� �� ������ 1 �̻� 10,000 ������ �ڿ����Դϴ�.
prices�� ���̴� 2 �̻� 100,000 �����Դϴ�.

*/

#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    
    vector<int> answer(prices.size(), 0);
    stack<int> st; // ���ÿ� �ð� Ǫ��

    for (size_t i = 0; i < prices.size(); i++)
    {
        // �ֽ� ������ ������ ��� ���ϸ鼭 �� ����
        while (!st.empty() && prices[i] < prices[st.top()])
        {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        // �� ���� ��� Ǫ��
        st.push(i);
    }

    // ���� ���ÿ� ��Ƴ��� ������ ����
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

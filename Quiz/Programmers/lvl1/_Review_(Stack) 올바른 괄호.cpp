#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<bool> st;
    if (s[0] == ')')
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(true);
        }
        else
        {
            if (st.empty())
            {
                continue;
            }
            else
            {
                st.pop();
            }
        }
    }
    if (st.empty())
    {
        return true;
    }

    return false;
}

int main() {

    cout << solution("(())()");
}
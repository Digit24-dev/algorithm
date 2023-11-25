#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

unordered_map<char, char> m;

bool check(string str) {
	stack<char> myst;

	for (size_t i = 0; i < str.size(); i++)
	{
		// 이 괄호 푸시
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			myst.push(str[i]);
		}
		// 닫는 괄호가 나오면
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			// 이전 스택이 비어있으면 false
			if (myst.empty())
				return false;
			// 비어있지 않은데
			else {
				// 최상단의 값이랑 매치하는 것이 같으면
				if (myst.top() == m[str[i]])
					myst.pop();
				// 다르면 false
				else
					return false;
			}
		}
	}
	if (myst.empty())
		return true;
	else
		return false;
}

int solution(string s) {
    int answer = 0;
	
	m['('] = ')';
	m['{'] = '}';
	m['['] = ']';
	m[')'] = '(';
	m['}'] = '{';
	m[']'] = '[';

	for (size_t i = 0; i < s.size() - 1; i++)
	{
		if (check(s))
		{
			answer++;
		}
		string t = s.substr(1, s.size() - 1) + s[0];
		s = t;
	}

    return answer;
}

int main()
{
	cout << solution(")") << endl;
}

/*
* 
* 다른 깔끔한 코드. (최적화 및 가독성)
* 
#include <string>
#include <stack>
#include <algorithm>
inline bool check(const std::string& s){
    std::stack<char> chk_stack;
    for(const char c:s)
        if(c=='(' | c=='[' | c=='{') chk_stack.push(c);
        else if(chk_stack.empty()) return false;
        else switch(c){
                case ')': if(chk_stack.top() == '(') chk_stack.pop(); else return false; break;
                case ']': if(chk_stack.top() == '[') chk_stack.pop(); else return false; break;
                case '}': if(chk_stack.top() == '{') chk_stack.pop(); else return false; break;
             }
    return chk_stack.empty();
}

int solution(std::string s) {
    int valid_count{0};
    for(int i=0;i<s.size();++i) {
        if(check(s)) ++valid_count;
        std::rotate(s.begin(),s.begin()+1,s.end());
    }
    return valid_count;
}*/
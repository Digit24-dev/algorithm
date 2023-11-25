#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
	vector<char> v;
	v.reserve(s.size());
	v.push_back(s[0]);

	for (int i = 1; i < s.size(); i++)
	{
		if (v.size() >= 1 && v.back() == s[i])
		{
			v.pop_back();
		}
		else
		{
			v.push_back(s[i]);
		}
	}

	if (v.empty())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	cout << solution("baabaa") << endl;
}
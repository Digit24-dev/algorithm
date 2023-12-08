#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
	int i, j;
	bool flag = false;

	for (i = 0; i < s.size(); i++)
	{
		flag = false;

		for (j = i - 1; j >= 0; j--)
		{
			if (s[i] == s[j])
			{
				answer.push_back(i - j);
				flag = true;
				break;
			}
		}

		if (!flag)
			answer.push_back(-1);
	}

    return answer;
}

int main()
{
	vector<int> ret = solution("banana");

	for (auto& i : ret)
	{
		cout << i << " ";
	}
	cout << endl;
}
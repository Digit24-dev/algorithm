#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
	bool nogo = false;
	map<string, int> m;
	map<string, int> test;
	
	// ∏  √ ±‚»≠
	for (int i = 0; i < number.size(); i++)
	{
		m[want[i]] = number[i];
	}

	for (int i = 0; i < discount.size() - 10; i++)
	{
		test = m;
		nogo = false;
		for (int j = 0; j < 10; j++)
		{
			test[discount[i + j]]--;
		}
		for (auto& i : test)
		{
			if (i.second != 0)
				nogo = true;
		}
		if (!nogo)
		{
			answer++;
		}
	}

    return answer;
}
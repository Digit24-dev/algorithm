#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;
string dp[50] = {};

int main()
{
	cin.tie();
	ios::sync_with_stdio(false);
	
	string word;
	int t;
	
	cin >> t;
	while (t--)
	{
		cin >> word;
		m.insert(pair<string, int>(word, word.length()));
	}

	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		dp[iter->second-1] += iter->first + "\n";
	}
	
	for (size_t i = 0; i < 50; i++)
	{
		cout << dp[i];
	}
	
	return 0;
}

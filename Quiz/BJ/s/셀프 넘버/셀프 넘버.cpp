#include <string>
#include <iostream>

using namespace std;

int doSome(string num) {
	int ret = stoi(num);
	for (size_t i = 0; i < num.size(); i++)
	{
		ret += num[i] - '0';
	}
	return ret;

}

int dp[10001];

int main() {
	
	memset(dp, 0, sizeof(dp));
	
	// Not Self Number
	for (size_t i = 1; i < 10000; i++)
	{
		dp[doSome(to_string(i))]++;
	}

	for (size_t i = 1; i < 10001; i++)
	{
		if (dp[i] == 0) cout << i << endl;
	}

	return 0;
}

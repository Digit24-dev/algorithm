#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//#define DEBUG

int main() {

	int N, K, temp, idx = 0, same_sum = 0;
	int flag = 0;
	cin >> N >> K;

	vector<vector<int>> nations(N);
	// 국가 금 은 동

	// input
	while (N--)
	{
		size_t i;
		for (i = 0; i < 4; i++)
		{
			cin >> temp;
			nations[idx].push_back(temp);
		}
		++idx;
	}

#ifdef DEBUG
	cout << endl;
	for (auto& elem : nations)
	{
		for (auto& c : elem)
		{
			cout << c << " ";
		}
		cout << endl;
	}
	
#endif // DEBUG

	sort(nations.begin(), nations.end(), [](vector<int> a, vector<int> b) {
		if (a[1] == b[1]) {
			if (a[2] == b[2])
				return a[3] > b[3];
			else
				return a[2] > b[2];
		}
		else
			return a[1] > b[1];
	});

#ifdef DEBUG
	cout << endl;
	for (auto& elem : nations)
	{
		for (auto& c : elem)
		{
			cout << c << " ";
		}
		cout << endl;
	}
#endif // DEBUG

	for (size_t i = 0; i < nations.size(); i++)
	{
		if (nations[i][0] == K) {
			// 금, 은, 동 점수가 같은 거 찾기
			// 왼쪽 찾기
			int idx = i;
			while (idx--)
			{
				if (nations[idx][1] == nations[i][1] && nations[idx][2] == nations[i][2] && nations[idx][3] == nations[i][3])
					++same_sum;
				else
					break;
			}
			cout << i - same_sum + 1 << endl;
			break;
		}
		
	}

}
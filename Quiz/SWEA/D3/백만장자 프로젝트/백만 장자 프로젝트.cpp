
#include<iostream>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int cnt = 0;
	vector<int> bucket;


	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		bucket.resize(N + 1, 0);
		cnt = 0;
		stack<int> s;
		int answer = 0;

		while (N--)
		{
			cin >> bucket[cnt++];
		}

		for (size_t i = 0; i < bucket.size() - 1; i++)
		{
			if (i < bucket.size() - 1 && bucket[i + 1] > bucket[i]) {
				s.push(i);
				continue;
			}
			while (!s.empty() && bucket[i] > bucket[s.top()])
			{
				answer += bucket[i] - bucket[s.top()];
				s.pop();
			}
			s.push(i);
		}

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}
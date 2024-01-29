
#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N, maxV;
	long answer;
	
	vector<int> bucket;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		bucket.resize(N);

		answer = 0;

		for (size_t i = 0; i < N; i++)
			cin >> bucket[i];

		maxV = bucket[N - 1];

		for (int i = N - 1; i >= 0; i--)
		{
			if (maxV >= bucket[i])
				answer += maxV - bucket[i];
			else
				maxV = bucket[i];
		}

		cout << "#" << test_case << " " << answer << endl;
	}

	return 0;
}
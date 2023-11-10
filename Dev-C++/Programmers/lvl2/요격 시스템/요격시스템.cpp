#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

#define MAX 100000000

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
	int answer = 0;
	int bound = 0;

	sort(targets.begin(), targets.end(), cmp);

	for (auto& i : targets)
	{
		if ( bound <= i[0] || i[1] < bound ) // 경계선이 미사일 구간 바깥에 있을 경우
		{
			answer++;
			bound = i[1];
		}
		else
		{
			continue;
		}
	}

	return answer;
}




int main() {

	vector<vector<int>> t = { {4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4} };

	cout << solution(t) << endl;
	
	return 0;
}

/*
모든 미사일 타겟을 정렬하고, 경계선을 왼쪽부터 쭉 훑는다.

경계선에 없을 경우 추가한다.
*/
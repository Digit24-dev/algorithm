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
		if ( bound <= i[0] || i[1] < bound ) // ��輱�� �̻��� ���� �ٱ��� ���� ���
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
��� �̻��� Ÿ���� �����ϰ�, ��輱�� ���ʺ��� �� �ȴ´�.

��輱�� ���� ��� �߰��Ѵ�.
*/
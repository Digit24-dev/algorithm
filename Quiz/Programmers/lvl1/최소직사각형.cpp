#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
	// 정렬 후에 최대 크기를 구한다.
	// 모든 범위를 돌며 리버시블 해도 안들어갈 경우 최소 길이의 길이를 증가시킨다.
	int _tmp;
	for (auto& i : sizes)
	{
		_tmp = max(i[0], i[1]);
		i[1] = min(i[0], i[1]);
		i[0] = _tmp;
	}

	sort(sizes.begin(), sizes.end(), [](vector<int> a, vector<int> b) {
		if (a[0] == b[0]) return a[1] > b[1];
		else return a[0] > b[0];
	}); // 내림차순 정렬

	int w = sizes[0][0];
	int h = sizes[0][1];

	for (auto& i : sizes)
	{
		if (w >= i[0] && h >= i[1]) {
			;
		}
		else if (w >= i[1] && h >= i[0]) {
			;
		}
		else {
			h = min(i[0], i[1]);
		}
	}

	return w * h;
}

int main() {
	vector<vector<int>> param = { {60, 50}, {30, 70}, {60, 30}, {80, 40} };
	vector<vector<int>> param1 = { {10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15} };
	vector<vector<int>> param2 = { {14, 4}, {19, 6}, {6, 16}, {18, 7}, {7, 11} };

	cout << solution(param) << endl;
	cout << solution(param1) << endl;
	cout << solution(param2) << endl;
}

/*
* 
* core idea : 주어진 w, h 중 최대 최소를 구하고,
* 다른 명함들의 w, h 최대 최수 중 최대 값을 정한다.
* 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes)
{
	int answer=0;

	int w=0, h=0;
	for(int i=0; i<sizes.size(); i++)
	{
		w=max(w,min(sizes[i][0],sizes[i][1]));
		h=max(h,max(sizes[i][0],sizes[i][1]));
	}
	answer=w*h;

	return answer;
}
*/
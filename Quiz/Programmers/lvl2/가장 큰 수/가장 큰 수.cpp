#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;

int idx = 0;

string getLeftPaddingStr(string const& str) {
	if (str.size() < 5) {
		return string(5 - str.size(), '0') + str;
	}
	else {
		return str;
	}
}

string solution(vector<int> numbers) {
	
	vector<string> bucket;
	bucket.reserve(numbers.size());

	string _t;
	for (auto& i : numbers)
	{
		bucket.push_back(to_string(i));
	}

	// 1. 앞자리가 높은 순서대로 정렬
	sort(bucket.begin(), bucket.end(), [](string a, string b) {
		idx = 0;

		if (a.size() == b.size()) {
			return a > b;
		}
		else {
			// 30 3
			// 34 3
			while (a[idx] == b[idx])
			{
				if (idx + 1 < a.size() && idx + 1 < b.size())
					++idx;
				else
					break;
			}// idx를 같은 숫자가 아닐 때까지 증가

			if (a.size() > b.size()) {
				return a[idx + 1] > b[idx] ? true : false;
			}
			else if (a.size() < b.size()) {
				return b[idx + 1] > a[idx] ? true : false;
			}
		}
	});

	string ret = "";
	for (auto& i : bucket)
	{
		ret += i;
	}

    return ret;
}

int main() {

	//vector<int> param = { 6,10,2 };
	vector<int> param = { 3,30,34,5,9 };

	cout << solution(param) << endl;
	/*int a = 4569;
	
	cout << a % 1000 << endl;
	cout << a / 1000 << endl;*/
}
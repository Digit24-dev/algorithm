#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<string> split(string str, char delim) {
	vector<string> ret;
	stringstream ss(str);
	string t;

	while (getline(ss, t, delim))
	{
		ret.push_back(t);
	}

	return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
	unordered_set<string> b_answer;

	// 문제 쉽게 풀기 위해서 일단 모두 받아오기.
	string bucket;
	vector<vector<string>> w;

	for (size_t i = 1; i < s.size() - 1; i++)
	{
		if (s[i] == '{') {
			int cnt = 1;
			while (s[i + cnt] != '}')
				++cnt;
			bucket = s.substr(i + 1, cnt - 1);
			w.push_back(split(bucket, ','));
		}
	}
	
	// 판단
	// 벡터 w에 안에 있는 것들 중 숫 자가 제일 적은 것 부터 정렬해서 answer 벡터에 삽입.
	// 우선 내부 벡터의 크기를 기준으로 오름차순으로 정렬
	sort(w.begin(), w.end(), [](vector<string> a, vector<string> b) { return a.size() < b.size(); });

	// 프로그래머스에서 unordered_set이 동작하지 않아서, vector에 바로 삽입하는 구문으로 변경 3중 for문으로 복잡도 너무 높다.
	for (auto& item : w)
	{
		for (auto& elem : item)
		{
			// answer에 elem이 있는지 조회
			for (auto& i : answer)
			{
				if (to_string(i) == elem) goto end;
			}
			// 여기 오면 answer에 없는 것임
			answer.push_back(stoi(elem));

		end:
			;
		}

	}

	//for (auto& i : b_answer)
	//{
	//	answer.push_back(stoi(i));
	//}

    return answer;
}

int main()
{
	//vector<int> ret = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	//vector<int> ret = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
	vector<int> ret = solution("{{123}}");
	//vector<int> ret = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
	//vector<int> ret = solution("{{20,111},{111}}");

	for (auto& item : ret)
	{
		cout << item << " ";
	}
	cout << endl;

	return 0;
}
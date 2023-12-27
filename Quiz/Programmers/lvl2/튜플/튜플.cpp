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

	// ���� ���� Ǯ�� ���ؼ� �ϴ� ��� �޾ƿ���.
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
	
	// �Ǵ�
	// ���� w�� �ȿ� �ִ� �͵� �� �� �ڰ� ���� ���� �� ���� �����ؼ� answer ���Ϳ� ����.
	// �켱 ���� ������ ũ�⸦ �������� ������������ ����
	sort(w.begin(), w.end(), [](vector<string> a, vector<string> b) { return a.size() < b.size(); });

	// ���α׷��ӽ����� unordered_set�� �������� �ʾƼ�, vector�� �ٷ� �����ϴ� �������� ���� 3�� for������ ���⵵ �ʹ� ����.
	for (auto& item : w)
	{
		for (auto& elem : item)
		{
			// answer�� elem�� �ִ��� ��ȸ
			for (auto& i : answer)
			{
				if (to_string(i) == elem) goto end;
			}
			// ���� ���� answer�� ���� ����
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
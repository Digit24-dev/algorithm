/*
�ּ����� ���Ǹ��� ���, ���� �մ��� �޴´�. 
�ѹ� ����� ������ ��� �ð��� �������� 10�а� û��.
���� �ð��� ���ڿ� ���·� ��� 2���� �迭 book_time �Ű������� �־�����.
�ʿ��� �ּ� ������ ���� return 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(vector<vector<string>> param);
int whole_times(string times);
vector<pair<int, int>> rooms_times;

int main(){
	vector<vector<string>> book_time;
	vector<string> time; // first: ���� �ð�, second: ���� �ð�
	time.push_back("1500");
	time.push_back("1700");
	int n;
	
	book_time.push_back(time);
	
	solution(book_time);
	
	int rooms = 0;
}

int solution(vector<vector<string>> param){
	int ans = 0;
	
	// 00:00 ~ 23:59 -> 23*60 = 1380 + 59 = 1439 min
	
	vector<string> times;
	pair<string, string> p; // first: ����, second: �� 
	
	
	for(auto iter=param.begin() ; iter != param.end() ; ++iter){
		times = *iter;
		p = pair<string, string>{times[0], times[1]};
		
		int whole = whole_times(times[0]);
		int whole2 = whole_times(times[1]);
		
		rooms_times.push_back(make_pair(whole, whole2));
		//cout << whole << " " << whole2 << endl;
	}
	
	return ans;
}

int whole_times(string times){
		// hours -> minutes
		int hours = stoi(times.substr(0, 2));
		int mins = stoi(times.substr(2, 2));
		
		return hours*60 + mins;
}

/*
최소한의 객실만을 사용, 예약 손님을 받는다. 
한번 사용한 객실은 퇴실 시간을 기준으로 10분간 청소.
예약 시간이 문자열 형태로 담긴 2차원 배열 book_time 매개변수로 주어진다.
필요한 최소 객실의 수를 return 
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> param);
int whole_times(string times);
vector<pair<int, int>> rooms_times;

int main(){
	vector<vector<string>> book_time;
	vector<string> time; // first: 예약 시간, second: 마감 시간
	time.push_back("15:00");
	time.push_back("17:00");
	book_time.push_back(time);
	time.clear();
	time.push_back("16:40");
	time.push_back("18:20");
	book_time.push_back(time);
	time.clear();
	time.push_back("14:20");
	time.push_back("15:20");
	book_time.push_back(time);
	time.clear();
	time.push_back("14:10");
	time.push_back("19:20");
	book_time.push_back(time);
	time.clear();
	time.push_back("18:20");
	time.push_back("21:20");
	book_time.push_back(time);
	
	cout << solution(book_time);
	
	return 0;
}

int convertToInt(string s, bool isEndTime)
{
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    
    if (isEndTime)
    {
        if (minute >= 50)
        {
            hour += 1;
            minute -= 50;
        }
        else
        {
            minute += 10;
        }
    }
    
    return hour * 100 + minute;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> v;
    
    for (vector<string> time : book_time)
    {
        int start = convertToInt(time[0], false);
        int end = convertToInt(time[1], true);
        
        v.push_back({start, end});
    }
    
    sort(v.begin(), v.end());
    
    int answer = 0;
    vector<pair<int, int>> filled;
    
    for (pair<int, int> time : v)
    {
        int start = time.first;
        vector<pair<int, int>> temp;
        
        for (pair<int ,int> room : filled)
        {
            if (start < room.second)
            {
                temp.push_back(room);
            }
        }
        
        filled = temp;
        filled.push_back(time);
        answer = max(answer, (int) filled.size());
    }
    
    return answer;
}

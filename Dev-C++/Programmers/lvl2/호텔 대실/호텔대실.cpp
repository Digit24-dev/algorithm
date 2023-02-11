#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> book_time);

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

int timeConvert(string s)
{
	int hour = stoi(s.substr(0,2));
	int min = stoi(s.substr(3,2));
	
	return hour*100 + min;
}

int solution(vector<vector<string>> book_time){
	int answer = 0;
	vector<pair<int, int>> rev_book_time;
	
	for(vector<string> times : book_time)
	{
		int startTime = timeConvert(times[0]);
		int endTime = timeConvert(times[1]);
		
		if(endTime % 100 >= 50)
		{
			endTime += 60;
		}
		else
		{
			endTime += 10;
		}
		rev_book_time.push_back({startTime, endTime});
	}
	
	sort(rev_book_time.begin(), rev_book_time.end());
	
	vector<pair<int, int>> rooms;
	
	for(pair<int, int> booked : rev_book_time){
		int start = booked.first;
		int end = booked.second;
		vector<pair<int, int>> temp;
		
		for(pair<int, int> room : rooms)
		{
			if(start < room.second)
			{
				temp.push_back(room);
			}
		}
		
		rooms = temp;
		rooms.push_back(booked);
		answer = max(answer, (int)rooms.size());
	}
	
	
	return answer;
}

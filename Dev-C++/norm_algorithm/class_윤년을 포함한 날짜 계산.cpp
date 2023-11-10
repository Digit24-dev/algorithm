#include <iostream>

using namespace std;


class Date{
	int year_;
	int month_;
	int day_;
	int m_dayOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
public:
	
	/*
	按眉 积己矫 规过
	Date day(2011,3,1);			// 鞠矫利 规过 implicit 
	Date day = Date(2011,3,1);	// 疙矫利 规过 explicit 
	*/
	
	Date(int year, int month, int day){
		year_ = year;
		month_ = month;
		day_ = day;
	}
	
	// 叼弃飘 积己磊
	Date(){
		year_ = 2023;
		month_ = 11;
		day_ = 4;
	} 
	
	///////////////////////////////////////////////////////////////////////////////
	//			reference from internet, checking leap year and date			 //
	///////////////////////////////////////////////////////////////////////////////
	int leapCheck()
	{
		if(year_ %  4 ==0 && year_ % 100 != 0 || year_ % 400 == 0){
			if( month_ == 2){
				return 29;
			}
			else{
				return m_dayOfMonth[month_ - 1];
			}
		}
		else{
			return m_dayOfMonth[month_ - 1];
		}
	}
	
	void AddDay(int inc){
		int day_of_cur_month = leapCheck();
		int tmp_day = day_ + inc;
		if( tmp_day > day_of_cur_month ){
			while(tmp_day > day_of_cur_month){
				tmp_day -= day_of_cur_month;
				AddMonth(1);
				day_of_cur_month = leapCheck();
			}
			day_ = tmp_day;
		}
		else{
			day_ = tmp_day;
		}
	}
	
	///////////////////////////////////////////////////////////////////////////////
	
	void SetDate(int year, int month, int date){
		year_ = year;
		month_ = month;
		day_ = date;
	}
	
	void AddMonth(int inc){
		int tmp = month_ + inc;
		if(tmp > 12){
			year_ = year_ + (tmp/12);
		}
		month_ += (tmp%12);
	}
	
	void AddYear(int inc){
		year_ = year_ + inc;
	}
	
	void ShowDate(){
		cout << year_ << "斥 " << month_ << "岿 " << day_ << "老 " << endl; 
	}
};

int main(){
	
	return 0;
}

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
	//const char* buf = s.c_str();
	int cnt_p = 0, cnt_y = 0;
	
	for(const char* buf = s.c_str(); *buf != '\n'; ++buf)
	{
		if(*buf == 'p' || *buf == 'P'){
			++cnt_p;
		}else if(*buf == 'y' || *buf == 'Y'){
			++cnt_y;
		}
	}
	if(cnt_p == cnt_y){
		return true;
	}else{
		return false;
	}
	
	
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
// string을 cahr[] 로 풀음 

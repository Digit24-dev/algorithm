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
	
	
    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;

    return answer;
}
// string�� cahr[] �� Ǯ�� 

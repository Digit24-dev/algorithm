#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    for(int i=0; i < n/2; ++i){
    	answer += "¼ö¹Ú";
	}
	
	if(n & 0x01)
		answer += "¼ö";
    
    return answer;
}

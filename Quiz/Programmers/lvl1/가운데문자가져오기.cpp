#include <iostream>
#include <string>
using namespace std;


string solution(string s){
	
	string answer = "";
	if(s.size() & 0x01){
		answer = s.substr(s.size()/2, 1);
	}else{
		answer = s.substr(s.size()/2-1, 2);
	}
	
	return answer;
}

int main(){
	
	string a;
	cin >> a;
	cout << solution(a) << endl;
	
	return 0;
}

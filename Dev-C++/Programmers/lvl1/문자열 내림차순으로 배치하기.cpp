#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char a, char b){
	return a > b  ?  true : false;
}

string solution(string s) {
    string answer = "";
    //const char *p = s;
    
    sort(s.begin(), s.end(), greater<char>());
    
    return s;
}

int main(){
	
	string a = "ASDFADFD";
	
	cout << solution(a) << endl;
	
	return 0;
}

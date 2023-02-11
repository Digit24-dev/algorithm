#include <string>
#include <vector>
#include <iostream>

using namespace std;

const string day[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
const int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b) {
    string answer = "";
    int temp = 0;
    
    for(int i=1; i<a ; ++i){
        b += month[i-1];
    }
    
    answer = day[b%7];
    
    return answer;
}

int main(){
	
	int a=0, b;
	
	while(a != 22){
		cin >> a >> b;
		cout << solution(a,b) << endl;
	}
		
	
	return 0;
}

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    
    for(int i=0; i<s.size(); ++i){
        if(s[i] == ' '){
            cnt = 0;
            continue;
        }
        if(!(cnt & 0x01)){
            if(s[i] >= 97 && s[i] <= 122)
                s[i] -= 32;
        }else{
            if(s[i] >= 65 && s[i] <= 90)
                s[i] += 32;
        }
        ++cnt;
    }
    answer = s;
    return answer;
}


/*
toupper()
tolower() 
*/

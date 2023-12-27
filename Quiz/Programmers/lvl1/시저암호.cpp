#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0; i<s.length(); ++i){
        char a = s[i];
        if(a == ' '){
            continue;
        }else{
            if('A' <= a && a <= 'Z'){
                if(a + n > 'Z') s[i] = s[i] + n - 26;
                else s[i] += n;
            }else{
                if(a + n > 'z') s[i] = s[i] + n - 26;
                else s[i] += n;
            }
        }
    }
    answer = s;
    return answer;
}

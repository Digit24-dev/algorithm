#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> num_3;
    
    while(n > 0){
        num_3.push_back(n%3);
        n /= 3;
    }
    int cnt = num_3.size()-1;
    for(int i=0; i<num_3.size(); ++i){
        answer += num_3[i] * pow(3, cnt--);
    }
    
    return answer;
}

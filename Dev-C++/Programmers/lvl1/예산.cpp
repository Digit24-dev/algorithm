#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a < b;
}

int solution(vector<int> d, int budget) {
    int answer = 0;
    int temp = 0;
    
    sort(d.begin(), d.end(), cmp);
    
    for(int i=0; i<d.size(); ++i){
		temp += d[i];
        if(temp <= budget){
            ++answer;
        }else
            break;
	}
    
    return answer;
}

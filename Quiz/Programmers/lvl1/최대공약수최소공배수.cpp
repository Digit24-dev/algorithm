#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gnd(int a, int b){
    int min = a < b ? a : b;
    int answer = 1;
    for(int i=1; i<=min; ++i){
        if(b%i == 0){
            answer = i;
        }
    }

    return answer;
}

int lcd(int a, int b, int gnd){
    int cnt = 1;
    int temp;
    while(1){
        temp = gnd * cnt++;
        if(temp % a == 0)
            if(temp % b == 0)
                break;
    }
    return temp;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int _gnd = gnd(n, m);

    cout << _gnd << " " << lcd(n, m, _gnd);

    return answer;
}
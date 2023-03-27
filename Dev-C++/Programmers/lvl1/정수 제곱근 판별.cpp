#include <string>
#include <vector>
#include <cmath>
using namespace std;
// 1 - 7,071,067
long long solution(long long n) {
    long long answer = 0;
    long long bucket = sqrt(n);
    if(pow(bucket, 2) == n){
       answer = pow(bucket+1, 2);
    }else
        return -1;
    
    return answer;
}
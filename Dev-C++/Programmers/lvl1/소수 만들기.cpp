// <에라토스테네스의 체>
여러 개의 수가 소수인지 아닌지를 판별할 때 사용한다.
N보다 작거나 같은 모든 소수를 찾을 때 사용한다.

1. 2부터 N까지의 모든 자연수를 나열한다.
2. 남은 수 중에서 아직 처리하지 않은 가장 작은 수 i를 찾는다.
3. 남은 수 중에서 i의 배수를 모두 제거한다. (i는 제거하지 않는다.)
4. 더 이상 반복할 수 없을 때까지 2번과 3번 과정을 반복한다.

#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

bool a[2999] = {};

void chk_prime(int n){
    int cnt;
    fill_n(a, 2999, true);
    for(int i=2; i<sqrt(n)+1; ++i){
        if(a[i]){
            cnt = 2;
            while(i * cnt <= n){
                a[i*cnt++] = false;
            }
        } 
    }
}

int solution(vector<int> nums) {
    int answer = 0;
     vector<int> sums;
    
    for(int i=0; i<nums.size()-2; ++i){
        for(int j=i+1; j<nums.size()-1; ++j){
            for(int k=j+1; k<nums.size(); ++k){
                sums.push_back(nums[i] + nums[j] + nums[k]);
            }
        }
    }
    
    sort(sums.begin(), sums.end());
    chk_prime(*(sums.end()-1));
    
    for(int i=0; i < sums.size(); i++){
        if(a[sums[i]]){
            answer++;
            cout << sums[i];
        }

    }

    return answer;
}

// <�����佺�׳׽��� ü>
���� ���� ���� �Ҽ����� �ƴ����� �Ǻ��� �� ����Ѵ�.
N���� �۰ų� ���� ��� �Ҽ��� ã�� �� ����Ѵ�.

1. 2���� N������ ��� �ڿ����� �����Ѵ�.
2. ���� �� �߿��� ���� ó������ ���� ���� ���� �� i�� ã�´�.
3. ���� �� �߿��� i�� ����� ��� �����Ѵ�. (i�� �������� �ʴ´�.)
4. �� �̻� �ݺ��� �� ���� ������ 2���� 3�� ������ �ݺ��Ѵ�.

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

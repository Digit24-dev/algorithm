#include <string>
#include <vector>
using namespace std;

bool go(vector<int>& c,int mid){
    int ret = 0;
    for (int i = 0; i < c.size(); i++){
        if (c[i] >= mid)ret++;
    }
    return ret >= mid;
}

int solution(vector<int> c) {
    int left = 0, right = 10000;
    int ans = 0;
    while (left <= right){
        int mid = (left + right) / 2;
        if (go(c,mid)){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}
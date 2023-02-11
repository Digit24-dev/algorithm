#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> m;
    for(int i=0; i<nums.size() ; ++i){
        m.insert(make_pair(nums[i], m[nums[i]]));  
    }
    
    return answer > nums.size()/2 ? nums.size()/2 : answer;
}

int main(){
	
	vector<int> a;
	a.push_back(1); 
}

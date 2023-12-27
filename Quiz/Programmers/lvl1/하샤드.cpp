#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    int bucket = x;
    
	while(x > 0) {
		sum += (x%10);
		x /= 10;
	}
    
    if(bucket % sum == 0)
    	return true;
	else
		return false;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    
    for(int i=0; i<cookie.size()-1; i++){
    	int lsum = cookie[i];
    	int rsum = cookie[i+1];
    	int lidx = i;
    	int ridx = i+1;
    	
    	while(true){
    		if(lsum == rsum)
    			answer = max(answer, lsum);
    		
			if(lsum > rsum){
    			if(ridx + 1 == cookie.size()) break;
    			rsum += cookie[++ridx];
			}else{
				if(lidx - 1 < 0) break;
				lsum += cookie[--lidx];
			}
		}
	}
    
    return answer;
}

int main(){
	
	vector<int> zeros;
	
	zeros.push_back(1);
	zeros.push_back(1);
	zeros.push_back(2);
	zeros.push_back(3);
	
	cout << solution(zeros) << endl;
	
	return 0;
}

//using namespace std;
//int dp[2000];
//
//int solution(vector<int> cookie) {
//    if (cookie.size() == 1)
//        return 0;
//    else if(cookie.size() == 2){
//        if(cookie[0] == cookie[1])
//            return cookie[0];
//        else
//            return 0;
//    }
//    int answer = -1;
//    dp[0] = cookie[0];
//    for(int i=1; i<cookie.size(); i++){
//        dp[i] = dp[i-1] + cookie[i];
//    }
//    
//    for(int j=cookie.size()-1; j>= 0; j--){
//        int temp = 0;
//        
//        for(int k=0; k<=j ; k++){
//            if(k==j){
//                temp=dp[j];
//                break;
//            }
//            temp = dp[j] - dp[k];
//            
//            if(temp & 0x01 == 1)
//                continue;
//            else{
//                int half = dp[j] / 2;
//                
//                for(int i=1; i<j; i++){
//                    if((dp[j] - dp[j-i]) == half){
//                        answer = answer > half ? answer : half;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//    
//    if(answer == -1)
//        answer = 0;
//    
//    return answer;
//}

//int solution(vector<int> cookie) {
//    if (cookie.size() == 1)
//        return 0;
//    else if(cookie.size() == 2){
//        if(cookie[0] == cookie[1])
//            return cookie[0];
//        else
//            return 0;
//    }
//    int answer = -1;
//    dp[0] = cookie[0];
//    for(int i=1; i<cookie.size(); i++){
//        dp[i] = dp[i-1] + cookie[i];
//    }
//    
//    for(int j=cookie.size()-1; j>= 0; j--){
//        int temp = 0;
//        
//        for(int k=0; k<=j ; k++){
//            if(k==j){
//                temp=dp[j];
//                break;
//            }
//            temp = dp[j] - dp[k];
//            
//            if(temp & 0x01 == 1)
//                continue;
//            else{
//                int half = dp[j] / 2;
//                
//                for(int i=1; i<j; i++){
//                    if((dp[j] - dp[j-i]) == half){
//                        answer = answer > half ? answer : half;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//    
//    if(answer == -1)
//        answer = 0;
//    
//    return answer;
//}

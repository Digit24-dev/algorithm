#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> bucket;
    int line;
    for(int i=0; i<n; ++i){
    	line = arr1[i] | arr2[i];
    	bucket.push_back(line);
	}
    
    for(int i=0; i<n; ++i){
    	line = bucket[i];
    	string str = "";
    	int pointer = 0x01;
    	int size = n-1;
		for(int j=0; j<n; ++j){
    		if(line & (pointer << size--)){
    			str.push_back('#');
			}else{
				str.push_back(' ');
			}
		}
		answer.push_back(str);
	}
    
    return answer;
}

/*
vector<int> 는 배열 처럼 사용할 수 있다. 

*/


#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i=0; i<arr1.size(); ++i){
    	vector<int> line = &arr1[i];
    	vector<int> line2 = &arr2[i];
		for(int j=0; j<line.size(); ++j){
    		line[j] += line2[j];
		}
	}
	
	answer = arr1;
    
    return answer;
}

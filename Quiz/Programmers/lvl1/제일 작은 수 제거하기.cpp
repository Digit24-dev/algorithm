#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int min=arr[0];
    int ptr;
    
    for(int i=0; i<arr.size(); ++i){
    	min = arr[i] < min ? arr[i] : min;
	}
	
	for(int i=0; i<arr.size(); ++i){
		if(arr[i] == min)
			ptr = i;
	}
	
	answer.erase(answer.begin() + ptr);
	
	if(answer.empty())
		answer.push_back(-1);
    
    return answer;
}

/*
 erase 사용 방법!
 
 vector<int> a 형태의 일차원 배열 사용시

 a.erase(a.begin() + i); 형태로 사용한다.


 *추가 다른 명령어들
 
 iterator min_element(iterator begin, iterator end){
 	// 해당 배열에서 가장 작은 값의 인덱스를 반환한다. 
 }
  
 iterator find(iterator begin, iterator end, value_type toFind){
 	// 해당 배열에서 toFind 값을 찾아 인덱스로 반환한다. -> int 값으로 변환을 원하면 - a.begin()을 사용한다. 
 }
  
*/



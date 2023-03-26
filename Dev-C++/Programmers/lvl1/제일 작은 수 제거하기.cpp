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
 erase ��� ���!
 
 vector<int> a ������ ������ �迭 ����

 a.erase(a.begin() + i); ���·� ����Ѵ�.


 *�߰� �ٸ� ��ɾ��
 
 iterator min_element(iterator begin, iterator end){
 	// �ش� �迭���� ���� ���� ���� �ε����� ��ȯ�Ѵ�. 
 }
  
 iterator find(iterator begin, iterator end, value_type toFind){
 	// �ش� �迭���� toFind ���� ã�� �ε����� ��ȯ�Ѵ�. -> int ������ ��ȯ�� ���ϸ� - a.begin()�� ����Ѵ�. 
 }
  
*/



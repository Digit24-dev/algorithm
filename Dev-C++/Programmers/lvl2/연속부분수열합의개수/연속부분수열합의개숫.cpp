#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

	set<int> set_1;
	set_1.insert(2);
	
	int n = 1, size;
	vector<int> elements;
	vector<int> ans;
	
	elements.push_back(7);
	elements.push_back(9);
	elements.push_back(1);
	elements.push_back(1);
	elements.push_back(4);
	
	size = elements.size();
	
	while(n <= size){
		int temp = 0;
		int bucket = 0;
		int round = (size * n) / (size - n);
		
		// moving windows
		while(--round){
			
			int iter = 0;
			iter = ++iter % size;
			while(++temp <= n){
				bucket += elements[iter++ % size];
			}
			
			/*vector<int>::iterator iter = elements.begin();
			iter = ++iter % size;
			
			// adding in elements
			while(++temp == n){
				bucket += *(iter++%size);
			}*/
		}
		
		set_1.insert(bucket);
		
		++n;
	}
	
	printf("%d \n", set_1.size());
	
}

#include <iostream>
using namespace std;

void quickSort(int *a, int begin, int end){
	if(begin>=end)
		return;
	
	int L = begin;
	int R = end;
	int pivot = a[(begin + end) / 2];
	
	while(L <= R){
		while(a[L] < pivot) L++;
		while(a[R] > pivot) R--;
		if(L <= R){
			swap(a[L], a[R]);
			L++; R--;
		}
	}
	quickSort(a, begin, R);
	quickSort(a, L, end);
}

int main(){
	int a[10] = {0,3,5,2,6,1,8,9,4,7};
	
	quickSort(a, 0, 9);
	
	for(int i=0; i<10; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

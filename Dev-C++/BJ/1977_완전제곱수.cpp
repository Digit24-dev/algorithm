#include <iostream>
using namespace std;

int main(){
	
	int M, N, square = 10000;
	int sum = 0, min = 10000;
	cin>>M>>N;
	
	for(int i=1; i<=N; i++){
	
		if(square >= M)
			min = min < square ? min : square;
		
		square = i*i;
		
		if(square > N)
			break;
		
		if(square >= M)
			sum += square;
		
	}
	if(sum != 0)
		cout<<sum<<endl<<min<<endl;
	else
		cout<<-1<<endl;
	
	return 0;
}

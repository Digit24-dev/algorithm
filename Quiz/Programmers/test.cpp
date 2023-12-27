#include <iostream>
#include <vector>
using namespace std;
int func(int num);
int lcd(int n, int m);

int gcd(int n, int m){
    int ans = 1;
    int max = n > m ? n : m;
    int min = n > m ? m : n;
    
    for(int i=1; i<=min; i++){
        if((max % i) == 0 && (min %i) == 0){
            ans = ans > i ? ans : i;
        }
    }

    return ans;
}

int main()
{
	cout << gcd(10, 50) << endl;
	cout << lcd(101233, 150) << endl;
	cout << func(10) << endl;
	
	return 0;
}


int func(int num){
	vector<int> temp;
	for(int i=1; i<=num; i++){
		if(num % i == 0){
			temp.push_back(i);
		}
		
	}
	
	return temp.size();
}

int lcd(int n, int m){
    int max = n > m ? n : m;
    int min = n > m ? m : n;
    
    for(int i=1; i<1000; i++){
        if((max * i) % min == 0)
            return max*i;
    }
}

#include <iostream>
using namespace std;

int main() {
    int n,m,i,j,k; 
    int result = 0;
    
    cin>>n>>m;
    int a[n];
    
    for(i=0; i<n; i++){
    	cin>>a[i];
	}
    
    for(i=0; i<n-2;i++){
    	for(j=i+1; j<n-1; j++){
    		for(k=j+1; k<n; k++){
    			if(a[i]+a[j]+a[k] > m)
    				continue;
    			else if(a[i]+a[j]+a[k] == m){
					result = m;
					goto ans;
				}
				else if(a[i]+a[j]+a[k] < m)
					result = a[i]+a[j]+a[k] < result ? result : a[i]+a[j]+a[k];
			}
		}
	}
	
	ans:
		cout<<result;
    
    return 0;
}

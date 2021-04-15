#include <iostream>
#include <vector>
using namespace std;

#define MAX 500

int _max = 0;
int cnt = 0;
int N, M;
int map[MAX][MAX];
int _pair[MAX][2];

void input(){
	cin>>N>>M;
	int a;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>a;
			map[i][j] = a;
			if(_max < a){
				_max = a;
				_pair[cnt][0] = i;
				_pair[cnt++][1] = j;
			}
		}
	}
}

void check(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout<<map[i][j];
		}
		cout<<endl;
	}
}

void bfs(){
	
}

void solution(){
	input();
	check();
}

int main(){
	solution();
	
	return 0;
}

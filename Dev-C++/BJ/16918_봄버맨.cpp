#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char map[200][200];
queue<pair<int,int> > bomb_q;

void scan_boom(int c, int r);
void scan_set(int c, int r);
void boom(int c, int r);

int main(){
	
	cin.tie();
	
	int r, c, n;
	int cnt = 0;
	cin >> r >> c >> n;
	
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			cin >> map[j][i];
		}
	}
	
	while(--n){
		switch(cnt % 3){
			case 0:
				
				break;
			case 1:
				scan_set(c, r);
				break;
			case 2:
				scan_boom(c, r);
				break;
			default:
				break;
		}
		++cnt;
	}
	
	cout << endl;
	
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			cout << map[j][i];
		}
		cout << endl;
	}
	
	cout << endl;
	
	return 0;
}

void queue_bomb(int c, int r){
	
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			if(map[j][i] == '0')
				bomb_q.push(make_pair(i,j)); 
		}
	}
}

void scan_set(int c, int r){
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			if(map[j][i] == '.')
				map[j][i] = '0';
		}
	}
}

void scan_boom(){
	
}

void boom(int c, int r){
	if(c == 0){
		map[c][r] = '.';
		map[c+1][r] = '.';
		map[c][r+1] = '.';
		map[c][r-1] = '.';
	}else if(r == 0){
		map[c][r] = '.';
		map[c+1][r] = '.';
		map[c-1][r] = '.';
		map[c][r+1] = '.';
	}else if(c==0 && r==0){
		map[c][r] = '.';
		map[c+1][r] = '.';
		map[c][r+1] = '.';
	}else{
		map[c][r] = '.';
		map[c+1][r] = '.';
		map[c-1][r] = '.';
		map[c][r+1] = '.';
		map[c][r-1] = '.';
	}
}


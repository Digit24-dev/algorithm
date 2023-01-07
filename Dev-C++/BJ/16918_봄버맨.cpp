#include <iostream>
#include <queue>
using namespace std;

char map[200][200];
queue<pair<int,int> > bomb_q;

void scan_boom();
void scan_set(int c, int r);
void boom(int c, int r);
void queue_bomb(int c, int r);
void show_map(int r, int c);

int main(){
	
	cout.tie();
	
	int r, c, n;
	int cnt = 0;
	
	scanf("%d %d %d", &r, &c, &n);
	//cin >> r >> c >> n;
	
	/*
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			cin >> map[i][j];
		}
	}
	*/
	for(int i=0; i<r; ++i){
		scanf("%s", map[i]);
	}
	
	--n;
	
	while(n--){
		switch(cnt & 0x01){
			case 0:
				queue_bomb(c, r);
				scan_set(c, r);
				break;
			case 1:
				scan_boom();
				break;				
			default:
				break;
		}
		++cnt;
	}
	show_map(r, c);
	
	return 0;
}

void show_map(int r, int c){
	for(int i=0; i<r; ++i){
		//puts(map[i]);
		for(int j=0; j<c; ++j){
			cout << map[i][j];
		}
		cout << "\n";
	}
}

void queue_bomb(int c, int r){
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			if(map[i][j] == 'O')
				bomb_q.push(make_pair(i,j)); 
		}
	}
}

void scan_set(int c, int r){
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			if(map[i][j] == '.')
				map[i][j] = 'O';
		}
	}
}

void scan_boom(){
	while(!bomb_q.empty()){
		pair<int,int> temp = bomb_q.front();
		bomb_q.pop();
		boom(temp.first, temp.second);
	}
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


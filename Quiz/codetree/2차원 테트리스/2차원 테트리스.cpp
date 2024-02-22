#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int K;
int map_red[5][7];
int map_yellow[7][5];

int score = 0;

void processing(int type, int x, int y)
{
	// 1. draw in map.
	// 2. delete lines
	// 3. process the pale colored map
	// In yellow, should check Type2's side.
	// In red, check Type3.

	// 1. draw in map
	int yellow = 6, red = 6;
	// find where to put block
	for (int i = 3; i < 7; i++)				// Yellow 
	{
		if (map_yellow[i][x] == 1){
			yellow = i - 1; break;
		}
		if (type == 2) {
			if (map_yellow[i][x + 1] == 1) {
				yellow = i - 1; break;
			}
		}
	}
	for (int i = 3; i < 7; i++)				// Red 
	{
		if (map_red[y][i] == 1) {
			red = i - 1; break;
		}
		if (type == 3) {
			if (map_red[y + 1][i] == 1) {
				red = i - 1; break;
			}
		}
	}

	// draw
	switch (type)
	{
	case 1:
		map_yellow[yellow][x] = 1;
		map_red[y][red] = 1;
		break;
	case 2:
		map_yellow[yellow][x] = 1;
		map_yellow[yellow][x + 1] = 1;
		map_red[y][red] = 1;
		map_red[y][red - 1] = 1;
		break;
	case 3:
		map_yellow[yellow][x] = 1;
		map_yellow[yellow - 1][x] = 1;
		map_red[y][red] = 1;
		map_red[y + 1][red] = 1;
		break;
	}
}

void clear() {

	for (int i = 3; i < 7; i++)
	{
		int sum_r = 0, sum_y = 0;
		for (int j = 0; j < 4; j++)
		{
			if (map_yellow[i][j] == 1) ++sum_y;
			if (map_red[j][i] == 1) ++sum_r;
		}

		// Yellow
		if (sum_y == 4) 
		{
			++score;
			for (int t = i; t >= 1; t--)
			{
				for (int j = 0; j < 4; j++)
				{
					map_yellow[t][j] = map_yellow[t - 1][j];
				}
			}
		}
		// Red
		if (sum_r == 4)
		{
			++score;
			for (int t = i; t >= 1; t--)
			{
				for (int j = 0; j < 4; j++)
				{
					map_red[j][t] = map_red[j][t - 1];
				}
			}
		}
	}
}

void push() {
	// 1. inspection
	int flag_r = 0, flag_y = 0;

	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (map_yellow[i][j] == 1) { ++flag_y; break; }
		}
	}
	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (map_red[j][i] == 1) { ++flag_r; break; }
		}
	}
	// push yellow
	while (flag_y--)
	{
		for (int i = 7 - 1; i >= 1; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				map_yellow[i][j] = map_yellow[i - 1][j];
			}
		}
	}
	// push red
	while (flag_r--)
	{
		for (int i = 7 - 1; i >= 1; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				map_red[j][i] = map_red[j][i - 1];
			}
		}
	}
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	//ifstream cin;
	//cin.open("input (1).txt");

	cin >> K;
	while (K--)
	{
		int type, x, y;
		cin >> type >> y >> x;
		
		processing(type, x, y);
		clear();
		push();
	}

	int remains = 0;
	for (int i = 3; i < 7; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			remains += map_yellow[i][j];
			remains += map_red[j][i];
		}
	}

	cout << score << endl;
	cout << remains << endl;

}

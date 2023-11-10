#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    int number;
	ifstream fin;
	fin.open("t.txt");
	
	string trash;

	while(1)
	{
		fin >> number;
		if(fin.eof())
			break;
		if(fin.fail())
		{
			fin.clear();
			fin >> trash;
		}else{
			cout << number << endl;
		}
	}
	fin.close();
	
    return 0;
}

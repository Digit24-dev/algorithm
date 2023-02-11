#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	cout << "벡터 컨테이너의 데이터" << endl;
	for(vector<int>::iterator iter=v.begin(); iter!=v.end(); ++iter){
		cout << *iter << " ";
	}
	
	cout << endl << "벡터의 사이즈 : " << v.size() << endl << "벡터의 캐패시티 : " << v.capacity() << endl;
	
	return 0;
}

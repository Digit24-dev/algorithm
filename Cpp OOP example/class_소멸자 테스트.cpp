#include <string.h>
#include <iostream>

class Test{
	char c;
public:
	Test(char _c){
		c = _c;
		std::cout<<"������ ȣ�� " << c << std::endl; 
	}
	~Test() {
		std::cout << "�Ҹ��� ȣ�� " << c << std::endl; 
	}	
};

void simplefunc() {
	Test b('b');
}

int main(){
	Test a('a');
	simplefunc();
}

#include <string.h>
#include <memory.h>

class MyString{
	char *str;
	int len;
	
public:
	MyString(char c){
		str = new char[1] {c};
	}
	MyString(const char *s){
		
	}
	// 2. ���ڿ� ���̸� ���ϴ� �Լ� 
	int length(){
		return this->len;
	}
	// 3. ���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�
	MyString append(const char *str){
		
	}
	MyString append(const MyString str){
		this->len += str.len;
	}
	
private:
	size_t strlen(const char* s){
		int cnt = 0;
		const char *c;
		for(c = s; *c != '\n' ; ++c){
			++cnt;
		}
		return cnt;
	}
};

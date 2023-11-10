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
	// 2. 문자열 길이를 구하는 함수 
	int length(){
		return this->len;
	}
	// 3. 문자열 뒤에 다른 문자열 붙이기
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

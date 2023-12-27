#include <iostream>
#include <string>

class Base {
    std::string s;

public:
    Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

    void what() { std::cout << s << std::endl; }
};
class Derived : public Base {
    std::string s;

public:
    Derived() : Base(), s("파생") {
        std::cout << "파생 클래스" << std::endl;

        // Base 에서 what() 을 물려 받았으므로
        // Derived 에서 당연히 호출 가능하다
        what();
    }

    void what() { std::cout << s << std::endl; }
};
int main() {
    std::cout << " === 기반 클래스 생성 ===" << std::endl;
    Base p;

    std::cout << " === 파생 클래스 생성 ===" << std::endl;
    Derived c;

    return 0;
}
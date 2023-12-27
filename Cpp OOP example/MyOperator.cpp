#include <iostream>

class Test {
    int x;
    int* p;
public:
    Test(int x) : x(x) {}
    Test(const Test& t) : x(t.x) {}

    int& operator[](const int index);

    Test& operator++() {
        x++;
        std::cout << "전위 증감 연산자" << std::endl;
        return *this;
    }

    // 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를
    // 받지만 실제로는 아무것도 전달되지 않는다.
    Test operator++(int) {
        Test temp(*this);
        x++;
        std::cout << "후위 증감 연산자" << std::endl;
        return temp;
    }

    int get_x() const {
        return x;
    }
};

int& Test::operator[](const int index) {

}

void func(const Test& t) {
    std::cout << "x : " << t.get_x() << std::endl;
}

int main() {
    Test t(3);

    func(++t); // 4
    func(t++); // 4 가 출력됨
    std::cout << "x : " << t.get_x() << std::endl;
}
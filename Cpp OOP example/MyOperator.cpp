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
        std::cout << "���� ���� ������" << std::endl;
        return *this;
    }

    // ���� ������ ���� ������ ���̸� �α� ���� ���� ������ ��� ���ڷ� int ��
    // ������ �����δ� �ƹ��͵� ���޵��� �ʴ´�.
    Test operator++(int) {
        Test temp(*this);
        x++;
        std::cout << "���� ���� ������" << std::endl;
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
    func(t++); // 4 �� ��µ�
    std::cout << "x : " << t.get_x() << std::endl;
}
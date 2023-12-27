#include <memory>
#include <iostream>

using namespace std;

int main()
{
	//unique_ptr<int> num1 = make_unique<int>(10);
	//unique_ptr<char> char1 = make_unique<char>('d');

	int a = 10;
	int c = 20;
	int* const p = &a;	// ����� ���ÿ� �Ҵ� �ʿ���. �����͸� ������ �� ����. (���� ���氡��)
	const int* p2;		// �����͸� ������ �� ����. (���δ� ������ �� ����.)
	p2 = &a;

	unique_ptr<int> uptr1 = make_unique<int>(a);

	cout << "p :" << p << endl;
	cout << "p2 :" << p2 << endl;
	cout << "a :" << a << endl;
	cout << "c :" << c << endl;
	cout << "uptr1 : " << uptr1 << endl;
	cout << "&uptr1 : " << &uptr1 << endl;
	cout << "*uptr1 : " << *uptr1 << endl;

	// ������ ����
	cout << "=========== ������ ���� ===========" << endl;
	
	p2 = &c;
	unique_ptr<int> uptr2(move(uptr1));
	
	cout << "p :" << p << endl;
	cout << "p2 :" << p2 << endl;
	cout << "a :" << a << endl;
	cout << "c :" << c << endl;
	cout << "uptr1 : " << uptr1 << "(������)" << endl;
	cout << "&uptr1 : " << &uptr1 << "(������)" << endl;
	//cout << "*uptr1 : " << *uptr1 << endl;

	cout << "uptr2 : " << uptr2 << endl;
	cout << "&uptr2 : " << &uptr2 << endl;
	cout << "*uptr2 : " << *uptr2 << endl;

	cout << "=========== �� ���� ===========" << endl;
	// �� ����
	//*b = 30;
	*p = 30;
	*uptr2 = 100;

	cout << "p :" << p << endl;
	cout << "p2 :" << p2 << endl;
	cout << "a :" << a << endl;
	cout << "c :" << c << endl;

	cout << "uptr1 : " << uptr1 << "(������)" << endl;
	cout << "&uptr1 : " << &uptr1 << "(������)" << endl;
	//cout << "*uptr1 : " << *uptr1 << endl;
	
	cout << "uptr2 : " << uptr2 << endl;
	cout << "&uptr2 : " << &uptr2 << endl;
	cout << "*uptr2 : " << *uptr2 << endl;

	return 0;
}
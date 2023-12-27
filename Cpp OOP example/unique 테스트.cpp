#include <memory>
#include <iostream>

using namespace std;

int main()
{
	//unique_ptr<int> num1 = make_unique<int>(10);
	//unique_ptr<char> char1 = make_unique<char>('d');

	int a = 10;
	int c = 20;
	int* const p = &a;	// 선언과 동시에 할당 필요함. 포인터를 변경할 수 없음. (내부 변경가능)
	const int* p2;		// 포인터를 변경할 수 있음. (내부는 변경할 수 없음.)
	p2 = &a;

	unique_ptr<int> uptr1 = make_unique<int>(a);

	cout << "p :" << p << endl;
	cout << "p2 :" << p2 << endl;
	cout << "a :" << a << endl;
	cout << "c :" << c << endl;
	cout << "uptr1 : " << uptr1 << endl;
	cout << "&uptr1 : " << &uptr1 << endl;
	cout << "*uptr1 : " << *uptr1 << endl;

	// 포인터 변경
	cout << "=========== 포인터 변경 ===========" << endl;
	
	p2 = &c;
	unique_ptr<int> uptr2(move(uptr1));
	
	cout << "p :" << p << endl;
	cout << "p2 :" << p2 << endl;
	cout << "a :" << a << endl;
	cout << "c :" << c << endl;
	cout << "uptr1 : " << uptr1 << "(해제됨)" << endl;
	cout << "&uptr1 : " << &uptr1 << "(해제됨)" << endl;
	//cout << "*uptr1 : " << *uptr1 << endl;

	cout << "uptr2 : " << uptr2 << endl;
	cout << "&uptr2 : " << &uptr2 << endl;
	cout << "*uptr2 : " << *uptr2 << endl;

	cout << "=========== 값 변경 ===========" << endl;
	// 값 변경
	//*b = 30;
	*p = 30;
	*uptr2 = 100;

	cout << "p :" << p << endl;
	cout << "p2 :" << p2 << endl;
	cout << "a :" << a << endl;
	cout << "c :" << c << endl;

	cout << "uptr1 : " << uptr1 << "(해제됨)" << endl;
	cout << "&uptr1 : " << &uptr1 << "(해제됨)" << endl;
	//cout << "*uptr1 : " << *uptr1 << endl;
	
	cout << "uptr2 : " << uptr2 << endl;
	cout << "&uptr2 : " << &uptr2 << endl;
	cout << "*uptr2 : " << *uptr2 << endl;

	return 0;
}
#include <iostream>
#include <string>
using namespace std;

class MyQueue {
private:
	const int Q_size;
	int* arr;
	int start;
	int arr_size;
public:
	MyQueue() : arr_size(0), Q_size(2000001), start(0) { arr = new int[Q_size]; }
	void push(int n) {
		arr_size+=1;
		arr[start + arr_size - 1] = n;
	}
	void pop() {
		if (arr_size == 0)
			cout << -1 << "\n";
		else {
			cout << arr[start] << "\n";
			start+=1;
			arr_size-=1;
		}
	}
	void front() {
		if (arr_size == 0)
			cout << -1 << "\n";
		else
			cout << arr[start] << "\n";
	}
	void back() {
		if (arr_size == 0)
			cout << -1 << "\n";
		else
			cout << arr[start + arr_size - 1] << "\n";
	}
	void size() {
		cout << arr_size << "\n";
	}
	void empty() {
		if (arr_size == 0)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	~MyQueue() { delete[]arr; }
};

int main() {
	std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int T, n;
	string ord;
	MyQueue Q;

	cin >> T;
	while (T--) {
		cin >> ord;

		if (ord == "push") {
			cin >> n;
			Q.push(n);
		}
		else if (ord == "pop") {
			Q.pop();
		}
		else if (ord == "front") {
			Q.front();
		}
		else if (ord == "back") {
			Q.back();
		}
		else if (ord == "size") {
			Q.size();
		}
		else if (ord == "empty") {
			Q.empty();
		}
	}

	return 0;
}

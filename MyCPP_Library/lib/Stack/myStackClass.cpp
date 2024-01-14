#include <stack>
#include <vector>

/// <summary>
/// My Stack Library
/// used vector instead of using `new` keyword.
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class myStackClass
{
public:
	myStackClass() { top = -1; };
	
	void push(T element) {
		s.push_back(element);
		++top;
	};
	void pop() {
		if (empty) return;
		s.erase(s.end() - 1);
		--top;
	};
	T topOrNULL() {
		if (!empty()) return s[top];
		else NULL;
	};
	T top() {
		return s[top];
	}
	bool empty() {
		// vector
		return s.empty();

		// safety
		if (top == -1) return true;
		else return false;
	};
	size_t size() {
		// vector
		return s.size();
		// safety
		return top + 1;
	};
	// TODO: 복사 생성자 -> 오버로딩 시 자동으로 복사생성자 완성.
	myStackClass& operator=(const myStackClass& c) {
		top = c.top;
		s = c.s;
	};

private:
	std::vector<T> s;
	size_t top;
};


void main() {
	std::stack<int> s;
	
}
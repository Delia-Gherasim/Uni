#include <vector>
#include <cassert>
#include <string>
#include <iostream>
using namespace std;
//
//
//			ROW 2		//
//
//template<typename TElem>
//TElem fct(std::vector<typename TElem> vect) {
//	if (vect.size() == 0) {
//		throw std::exception();
//	}
//	TElem result=TElem();
//	for (TElem a : vect) {
//		result += a;
//	}
//	return result;
//}
//
//void testfct() {
//	std::vector<int> v1{ 4, 2, 1, -4 };
//	assert(fct<int>(v1) == 3);
//	std::vector<int> v2;
//	try {
//		fct<int>(v2);
//		assert(false);
//	}
//	catch (std::exception&) {
//		assert(true);
//	}
//	std::vector<double> v3{ 2, 10.5, 5, -10 };
//	assert(fct<double>(v3) == 7.5);
//
//	std::vector<std::string> v4{ "y", "q", "a", "m" };
//	assert(fct<std::string>(v4) == "yqam");
//}
//
//int main() {
//	testfct();
//}
//
//
///////////////////////////////////////////////////////////////////////////////////////////
//class B {
//public:
//	virtual void f() {
//		cout << "b.f \n";
//	}
//	virtual ~B() {
//		cout << "~ b \n";
//	}
//};
//
//class d :public B {
//private:
//	B& b;
//public:
//	d(B& _b) : b(_b) {
//		cout << "d \n";
//		b.f();
//	}
//	void f()override {
//		cout << "d \n";
//	}
//	~d() {
//		cout << "~d ";
//	}
//};
//
//int main() {
//	B* b1 = new B{};
//	b1->f();
//	B* b2 = new d{ *b1 };
//	b2->f();
//	delete b2; delete b1;
//	return 0;
//}
/////b.f d b.f d ~d ~b ~b
//
//
//
/////////////////////////////////////
//template <typename t, typename u>
//u fct2(t a, t b, u x, u y) {
//	cout << a << " " << b << " ";
//	if (a == b)
//		return x + y;
//	return x;
//}
//class A {
//	int a;
//public:
//	A(int _a) : a{ _a } {
//
//	}
//};
//int main() {
//	cout << fct2<int, int>(10, 10, 5, 5) << "\n";
//	cout << fct2<double, int>(10, 10.5, 5, 5) << "\n";
//	cout << fct2<int, string>(-2, -2, "good", "luck")<<"\n";
//	cout << fct2<int, A>(1, 1, A{ 2 }, A{ 3 });
//}
////	binary '<<': no operator found which takes a right - hand operand of type 'u' (or there is no acceptable conversion)	C
//
//
/////////////////////////////////////////////////////////////////
//
//int main() {
//	vector<string> str{ "a", "b", "c", "d" };
//	str.erase(str.begin() + 2);
//	vector<string>::iterator it = str.begin();
//	str.insert(it + 2, "b");
//	str.insert(str.end() - 1, "a");
//	str.pop_back();
//	it = str.begin();
//	while (it != str.end()) {
//		cout << *it << " ";
//		it++;
//	}
//}
////abba
//
//			ROW 1			//
//
//int except(bool ex) {
//	if (ex)
//		throw 10;
//	cout << "fin \n";
//}
//int main() {
//	cout << 1 << " ";
//	try {
//		cout << except(true) << " ";
//		cout << except(5 < 5) << " ";
//	}
//	catch (int& ex) {
//		cout << ex ;
//	}
//	cout << 40;
//}
/////1 10 40
//
//////////////////////////////////////
//
//class B {
//public:
//	virtual void f() {
//		cout << "b.f \n";
//	}
//	virtual ~B() {
//		cout << "~b \n";
//	}
//};
//
//class d :public B {
//private:
//	B& b;
//public: 
//	d(B* b): b(*b){
//	}
//	void f() override {
//		b.f();
//		cout << "d.f \n";
//	}
//	virtual ~d() {
//		cout << "~d";
//	}
//};
//
//int main() {
//	B* b1 = new B{};
//	b1->f();
//	B* b2 = new d{ b1 };
//	b2->f();
//	delete b2;
//	delete b1;
//
//}
/////b.f b.f d.f ~d ~b ~b
//
////////////////////////////////////////////////
//
//template <typename t>
//class elem {
//private:
//	t x;
//public:
//	elem(t _x): x{_x}{}
//	static t add(t a, t b) {
//		return a + b;
//	}
//	elem& operator+=(const t& a) {
//		x += a;
//		return *this;
//	}
//	t get() {
//		return x;
//	}
//};
//int main() {
//	cout << elem < string>:: add("ala", "bala");
//	elem<int> e{ 3 };
//	e += 39;
//	cout << e.get();
//
//}
////alabala42
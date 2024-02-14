#include <string>
#include <vector>
#include <iostream>

template <typename t>
class Adder {
private:
	std::vector<t> elements;
	t initial_value;
public:
	Adder<t>(t initial_value) : initial_value{ initial_value } {
		elements.push_back(initial_value);
	}
	 Adder<t>& operator--() {
		 if (elements.size() > 0)
		 {
			 elements.pop_back();
			 return *this;
		 }
		else
			throw std::runtime_error("No more values");
	}

	std::vector<t> operator++() {
		if (elements.size() > 0)
		{
			elements.push_back(elements[elements.size() - 1]);
			return elements;
		}

		else
			throw "no element added";
	}
	Adder<t>& operator+(t element) {
		elements.push_back(element);
		return *this;
	}


	int sum() {
		int sum = 0;
		for (int i = 0; i < elements.size(); i++)
			sum += elements[i];
		return sum;
	}


};
void function2() {
	Adder<int> add{ 5 };
	add = add + 5 + 2;
	++add;
	add + 8;
	std::cout << add.sum()<<" \n";
	--add;
	std::cout << add.sum()<<" \n";
	--(--add);
	std::cout << add.sum()<< " \n";
	try {
		--(--(--add));
	}
	catch (std::runtime_error& ex) {
		std::cout << ex.what();
	}
}


//////////////////////////////////////////////////////////////////////////////////////

//int fct(std::string v) {
//	if (v == " ")
//		throw std::string{ "2" };
//	std::cout << "1";
//	if (v.size() > 4)
//		throw std::runtime_error("not empty");
//	return 0;
//}
//
//int main() {
//	try {
//		std::cout << fct("h1") << " ";
//		std::cout << fct("hello") << " ";
//		std::cout << fct("") << " ";
//	}
//	catch (std::string& e) {
//		std::cout << e;
//	}
//	catch (std::runtime_error& e) {
//		std::cout << e.what();
//	}
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////
//
//int main() {
//	std::vector<int> v(1, 2, 3, 4, 5);
//	std::vector<int>::iterator it = std::find(v.begin(), v.end(), 4);
//	v.insert(it, 7);
//	it = v.begin() + 2;
//	*it = 11;
//	vector<int> x;
//	std::copy_if(v.begin(), v.end(), back_inserter(x), [](int a) {return a % 2 == 1});
//	for (auto a : x)
//		std::cout << a << " ";
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////
//class B {
//public:
//	B(){}
//	B(const B& b) {
//		std::cout << "copy \n";
//	}
//	virtual void f() {
//		std::cout << "b.f \n";
//	}
//	void g(B b) {
//		std::cout << "b.g \n";
//	}
//	virtual ~B() {
//		std::cout << "~B \n";
//	}
//};
//
//class D : public B {
//public:
//	D(){}
//	void f() {
//		B::f();
//		std::cout << "d. f \n";
//	}
//	void g(D d) {
//		B::g(d);
//		std::cout << " d. g \n";
//	}
//};
//
//int main() {
//	B* b = new B{};
//	B* d = new D{};
//	d->f();
//	d->g(*b);
//	delete b;
//	delete d;
//}

//////////////////////////////////////////////////////////////////////////////////

class A {
private:
	int* x;
public:
	A(int _x = 0) {
		x = new int(_x);
	}
	A(const A& a) {
		x = new int{ *a.x };
	}
	int get() {
		return *x;
	}
	void set(int _x) {
		*x = _x;
	}

	~A() {
		delete x;
	}
};

//int main() {
//	A a1, a2;
//	a1.set(8);
//	A a3;
//	a3 = a1;
//	a1.set(5);
//	std::cout << a1.get() << "\n" << a2.get() << "\n" << a3.get() << "\n" << "a4.get()";
//	system("pause");
//	return 0;
//}
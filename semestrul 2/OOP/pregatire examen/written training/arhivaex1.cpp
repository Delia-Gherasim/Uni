#include <string>
#include <exception>
#include <cassert>
#include <iostream>
#include <vector>

//class Complex {
//private:
//	int real;
//	int imaginary;
//public:
//	Complex() {
//		real = 0;
//		imaginary = 0;
//	}
//	Complex(int real, int imaginary) : real{ real }, imaginary{ imaginary } {
//
//	}
//	Complex(Complex* b) :real{ b->getReal()}, imaginary{b->getImaginary()} {
//
//	}
//	int getReal() {
//		return real;
//	}
//	int getImaginary(){
//		return imaginary;
//	}
//	Complex operator/ (int n) {
//		if (n != 0) {
//			real = real / n;
//			imaginary = imaginary / n;
//			Complex c{ real, imaginary };
//			return c;
//		}
//		else
//			throw std::runtime_error("Division by zero!");
//	}
//
//	friend bool operator==(Complex a, Complex b);
//	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
//};
//
//bool operator== (Complex a, Complex b) {
//	return a.getReal() == b.getReal() && a.getImaginary() == b.getImaginary();
//}
//std::ostream& operator<<(std::ostream& os, Complex& c) {
//	os << c.getReal() << "+" << c.getImaginary() << "i";
//	return os;
//}

//template <typename t>
//class Vector {
//private:
//	std::vector<t> vect;
//public:
//	Vector<t>(std::vector<t> _vect) :vect{ _vect } {
//
//	}
//	std::ostream& printAll(std::ostream& os) {
//		for (int i = 0; i < vect.size()-1; i++) {
//			os << vect[i];
//			os << " , ";
//		}
//		os << vect[vect.size()-1];
//		
//		return os;
//	}
//};
//
//int main() {
//	Complex a{}, b{ 1, 2 }, c{ 4, 6 }, d{ b };
//	assert(a.getReal() == 0);
//	assert(b == d);
//	Complex res1 = c / 2;
//	std::cout << res1 << "\n";
//	try {
//		Complex res2 = b / 0;
//	}
//	catch (std::runtime_error& e) {
//		assert(strcmp(e.what(), "Division by zero!") == 0);
//	}
//
//
//	Vector<std::string> v1(std::vector<std::string>{"hello", "bye"});
//	v1.printAll(std::cout);
//
//	Vector<Complex> v2{ std::vector<Complex>{a,b, c, d} };
//	v2.printAll(std::cout);
//}


///////////////////////////////////

//int main() {
//	std::vector<int> v{ 1,2,3,4,5 };
//	std::vector<int>::iterator it = std::find(v.begin(), v.end(), 4);
//	v.insert(it, 8);
//	it = v.begin() + 2;
//	*it = 10;
//	std::vector<int> x;
//	std::copy_if(v.begin(), v.end(), back_inserter(x), [](int a) {return a % 2 == 0 });
//	for (auto a : x)
//		std::cout << a << " ";
//	return 0;
//}

///////////////////////////////////

//class Ex1 {
//public:
//	Ex1() {
//		std::cout << "Exception 1 \n";
//	}
//	Ex1(const Ex1& ex) {
//		std::cout << "Copy_ex1 \n";
//	}
//};
//
//class Ex2 :public Ex1 {
//public:
//	Ex2() {
//		std::cout << "Exception2 \n";
//	}
//	Ex2(const Ex2& ex) {
//		std::cout << "Copy_ex2 \n";
//	}
//};
//void except(int x) {
//	if (x < 0)
//		throw Ex1{};
//	else if (x == 0)
//		throw Ex2{};
//	std::cout << "Done";
//}
//int main() {
//	try {
//		std::cout << "Start \n";
//		try {
//			except(0);
//		}
//		catch (Ex1& e) {}
//		except(-2);
//	}
//	catch(Ex1 e){}
//	return 0;
//}

///////////////////////////////
//class b {
//public:
//	void f() {
//		std::cout << "b.f \n";
//	}
//	virtual ~b(){}
//};
//class d1 : public b {
//public:
//	virtual void f() {
//		std::cout << "d1.f \n";
//	}
//	virtual ~d1() {}
//};
//class d2 :public d1 {
//public: 
//	void f() {
//		std::cout << "d2.f \n";
//	}
//};
//int main() {
//	b* b1 = new b{}; b1->f(); delete b1;
//	b* b2 = new d1{}; b2->f(); delete b2;
//	b* b3 = new d2{}; b3->f(); delete b3;
//	d1* d = new d2{}; d->f(); delete d;
//	return 0;
//}

/////////////////////////////////
//class Vector {
//	int* elems;
//	int size;
//public:
//	Vector() :size{ 0 } {
//		elems = new int[10];
//	}
//	void add(int elem) {
//		elems[size++] = elem;
//	}
//	int& operator[] (int pos) {
//		if (pos < 0 || pos >= size)
//			//throw std::runtime_error{ "index cv" };
//			throw std::exception("cv");
//		return elems[pos];
//	}
//	~Vector() {
//		delete[] elems;
//	}
//};
//int main() {
//	Vector v1;
//	v1.add(0);
//	v1.add(1);
//	Vector v2 = v1;
//	try {
//		v1[0] = 2;
//		std::cout << v1[0] << " " << v1[1] << " ";
//		std::cout << v2[0] << " " << v2[1] << " ";
//	}
//	catch (std::exception& e) {
//		std::cout << e.what();
//	}
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////

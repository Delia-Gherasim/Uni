#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <stdlib.h>
using namespace std;

//template <typename t>
//class SmartPointer {
//private:
//	t* variable;
//public:
//	SmartPointer<t>(t* var) :variable{ var } {
//
//	}
//
//};
//
//template <typename t>
//class Set {
//private:
//	std::vector<t> elements;
//public:
//	Set() {
//	}
//	std::vector<t> getElements() {
//		return elements;
//	}
//	Set operator+ (t p) {
//		for (auto a : elements)
//			if (a == p)
//				throw runtime_error("Element already exists!");
//		elements.push_back(p);
//	}
//	void operator= (Set s) {
//		elements = s.getElements();
//	}
//	Set remove(t elem) {
//		for (auto a : elements) {
//			if (a == e)
//			{
//				elements.erase(a);
//			}
//		}
//	}
//};
//
//void function() {
//	SmartPointer<std::string> s1{ new std::string{"a"} };
//	SmartPointer<std::string> s2 = s1;
//	SmartPointer<std::string> s3{ new std::string{"c"} };
//	Set<SmartPointer<std::string>> set1{};
//
//	try {
//		set1 = set1 + s1;
//		set1 = set1 + s2;
//	}
//	catch (std::runtime_error& ex) {
//		std::cout << ex.what();
//	}
//
//	SmartPointer<int> i1{ new int{1} };
//	SmartPointer<int> i2{ new int{2} };
//	SmartPointer<int> i3{ new int{3} };
//	Set<SmartPointer<int>> set2{};
//	set2 = set2 + i1;
//	set2 = set2 + i2;
//	set2 = set2 + i3;
//	set2.remove(i1).remove(i2);
//	for (auto e : set2) {
//		std::cout << *e << " ";
//	}
//}


///////////////////////////////////////////////////////////////////////////

//int except(int v) {
//	if (v < 0) {
//		throw std::string{"1"};
//	}
//	else if (v > 0) {
//		throw std::runtime_error("2 ");
//	}
//	return 0;
//}
//
//int main() {
//	try {
//		std::cout << except(10 < 2) << " ";
//		std::cout << except(-2) << " ";
//		std::cout << except(2) << " ";
//	}
//	catch (std::runtime_error& e) {
//		std::cout << e.what();
//	}
//	catch (std::string x) {
//		std::cout << x;
//	}
//	std::cout << "done";
//
//}

//////////////////////////////////////////////////////////////

//int main() {
//	vector<int> v{ 10, 9, 8, 7, 6, 5 };
//	vector<int>::iterator it = v.begin() + 2;
//	v.erase(it);
//	*it = 11;
//	it++;
//	*it = 1;
//	deque<int> x;
//	std::copy_if(v.begin(), v.end(), front_inserter(x), [](int a) { return a % 2 == 1; });
//	for (auto a : x)
//		cout << a << " ";
//	return 0;
//}

/////////////////////////////////////////////////////////

//class B {
//public: 
//	B(){}
//	B(const B&) { cout << "copy "; }
//	virtual B f() {
//		cout << "b. f \n";
//		return *this;
//	}
//	virtual ~B() {
//		cout << "~B \n";
//	}
//};
//
//class D :public B {
//private:
//	B* b;
//public:
//	D(B* _b) : b{ _b } {
//		cout << " d \n";
//	}
//	B f() override {
//		cout << "d.f \n";
//		return b->f();
//	}
//};
//
//int main() {
//	B* b = new B();
//	B* d = new D{ b };
//	d->f();
//	delete d;
//	delete b;
//	return 0;
//
//}


//////////////////////////////////////////////////////

//class A {
//private:
//	int* x;
//public:
//	static int noOfInstances;
//	A(int _x = 5) {
//		x = new int{ _x };
//		noOfInstances++;
//	}
//	int get() {
//		return *x;
//	}
//	void set(int _x) {
//		*x = _x;
//	}
//	~A() {
//		delete x;
//	}
//};
//
//int A::noOfInstances = 0;
//int main() {
//	A a1, a2;
//	cout << a1.noOfInstances << "\n";
//	A a3 = a1;
//	cout << A::noOfInstances << "\n";
//	a1.set(10);
//	cout << a1.get() << "\n"<<a2.get()<<"\n"<<a3.get();
//
//	return 0;
//
//}

////////////////////////////////////////////////////////////
class Encoder {
	virtual std::string encode(std::string message) = 0;
};

class AlienEncoder:public Encoder {
private:
	std::string header;
public:
	AlienEncoder(std::string header): header{header}{}
	std::string encode(std::string message) override {
		message = header + message;
		return message;
	}
};

class MorseEncoder :public Encoder {
public:
	std::string encode(std::string message) override {
		for (int i = 0; i < message.length(); i++)
		{
			message[i] = '.';
		}
		return message;
	}
};
class Mixer :public Encoder {
private:
	std::string header;
public:
	Mixer(std::string header) : header{ header }{}
	std::string encode(std::string message) override {
		AlienEncoder alien{ header};
		std::string alienEncoded = alien.encode(message);
		MorseEncoder morse{};
		std::string morseEncoded = morse.encode(message);
		for (int i = 0; i < alienEncoded.length(); i++)
		{
			if (i < message.length())
				if (i % 2 == 0)
					message[i] = alienEncoded[i];
				else
					message[i] = morseEncoded[i];
			else
				message+= alienEncoded[i];

		}
		return message;
	}

};

class Communication {
private:
	std::string method;
	std::string header;
	std::vector <std::string> messages;
public:
	Communication(std::string method, std::string header, std::vector<std::string> messages):method{method},
																							header{header},
																							messages{messages}
	{}
	void addMessage(std::string message) {
		messages.push_back(message);
	}

	std::vector<std::string> communicate() {
		for (int i = 0; i < messages.size(); i++)
			for (int j = i; j < messages.size(); j++)
				if (messages[j] > messages[i])
				{
					std::string m = messages[i];
					messages[i] = messages[j];
					messages[j] = m;
				}
		if (method == "morse")
		{
			MorseEncoder morse{};
			for (int i = 0; i < messages.size(); i++)
				messages[i] = morse.encode(messages[i]);
		}
		else if (method == "mixer")
		{
			Mixer mix{ header };
			for (int i = 0; i < messages.size(); i++)
				messages[i] = mix.encode(messages[i]);
		}

		return messages;
	}
};

//int main() {
//	std::vector<std::string> messages = { "plm", "nuj", "ma las de facultate" };
//	Communication c1{ "mixer", "et",messages};
//	messages=c1.communicate();
//	for (auto a : messages)
//		cout << a << " ";
//	std::vector<std::string> messages2 = { "plm", "nuj", "ma las de facultate" };
//	Communication c2{ "morse", "", messages2 };
//	messages2=c2.communicate();
//	for (auto a : messages2)
//		cout << a << " ";
//	
//}
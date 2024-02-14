#include <vector>
#include <iostream>
#include <string>

template <typename TElem>
class stack {
private:
	int capacity;
	int size;
	TElem* elements;
public:
	stack(int capacity) :capacity{ capacity }
	{
		size = 0;
		elements = new TElem[size];
	}
	int getMaxCapacity()
	{
		return this->capacity;
	}
	void operator+ (std::string newVar) {
		if (size == capacity)
			throw std::exception("Stack is full!");
		else {
			if (size == 0)
				elements[0] = newVar;
			else
			{
				for (int i = size+1; i > 0; i--)
					elements[i] = elements[i - 1];
				elements[0] = newVar;
			}
			size++;
		}
	}
	TElem pop() {
		TElem varToReturn = elements[0];
		for (int i = 0; i < size; i++)
			elements[i] = elements[i + 1];
		return varToReturn;
	}
};


/////////////////////////////

class Activity {
private:
	std::string activity;
	std::string time;
public:
	Activity(std::string activity, std::string time) :activity{ activity }, time{ time }{
	};
	std::string ToString() {
		return "Activity " + activity + " will take place at " + time;
	}
};

template<typename Activity>
class ToDo {
private:
	std::vector<Activity> elements;
public:
	ToDo(){};
	void operator+= (Activity newV) {
		std::string newElement = newV.ToString();
		elements.push_back(newV);
	}
	void reversePrint(std::string command)
	{
		for (int i = elements.size()-1; i >= 0; i--)
			command << elements[i] << "\n";
	}
};

////////////////////////

//class B
//{
//public:
//	B() { std::cout << "B{}"; }
//	virtual void print() {
//		std::cout <<"B"<<"\n";
//	}
//	virtual ~B() { std::cout << "~B()" << "\n"; }
//};
//class D : public B
//{
//public:
//	D() { std::cout << "D{}" << "\n"; }
//	void print() override {
//		std::cout <<"D" << "\n";
//	}
//	virtual ~D() { std::cout << "~D()" << "\n"; }
//};
//int main()
//{
//	B* b[] = { new B{}, new D{} };
//	b[0]->print();
//	b[1]->print();
//	delete b[0];
//	delete b[1];
//	return 0;
//}
/////////////////////
//
//class Person
//{
//public:
//	Person() { std::cout << "Person{}"; }
//	virtual void print() = 0;
//	virtual ~Person() {
//		std::cout <<"~Person()";
//	}
//};
//class Student : public Person
//{
//public:
//	Student() {
//		std::cout << "Student{}";
//	}
//	void print() override {
//		std::cout <<
//			"Student";
//	}
//	virtual ~Student() {
//		std::cout <<"~Student()";
//	}
//};
//
//int main()
//{
//	Person* p = new Person{};
//	delete p;
//	Person* s = new Student{};
//	s->print();
//	delete s;
//	return 0;
//}

///////////////////////////////////
//class E
//{
//public:
//	E() { std::cout << "E{}"; }
//	virtual ~E() { std::cout << "~E()"; }
//};
//class DE : public E
//{
//public:
//	static int n;
//	DE() { n++; }
//};
//int DE::n = 0;
//int fct2(int x)
//{
//	if (x < 0)
//	{
//		throw E{};
//		std::cout << "number less than 0" << std::endl;
//	}
//	else if (x == 0)
//	{
//		throw DE{};
//		std::cout << "number equal to 0"
//			<< std::endl;
//	}
//	return x % 10;
//}
//int main()
//{
//	try
//	{
//
//		int res = 0;
//		res = fct2(25);
//		std::cout << DE::n;
//		res = fct2(-5);
//		std::cout << DE::n;
//		res = fct2(0);
//		std::cout << DE::n;
//		
//	}
//	catch (E&)
//	{
//		std::cout << DE::n;
//	}
//	return 0;
//}

/////////////////
//#include <deque>
//#include <string>
//#include <iostream>
//int main()
//{
//	std::deque<std::string> d;
//	d.push_back("A");
//	d.push_front("B");
//	d.push_back("C");
//	d.push_front("D");
//	for (auto a : d)
//		std::cout << a << " ";
//	auto itBegin = d.begin();
//	auto itEnd = d.end();
//	itBegin++;
//	itEnd--;
//	while (itBegin != itEnd)
//	{
//		std::cout << *itBegin << " ";
//		itBegin++;
//	}
//	return 0;
//}

/// <summary>/// /// </summary>////////#include <iostream>
#include <string>

class Beverage {
protected:
    std::string description;
public:
    virtual ~Beverage() = default;
    virtual double price() = 0;
    virtual void print() {
        std::cout << description << " " << price() << " RON";
    }
};

class Coffee : public Beverage {
public:
    Coffee() {
        description = "Coffee";
    }
    double price() override {
        return 2.5;
    }
};

class Tea : public Beverage {
public:
    Tea() {
        description = "Tea";
    }
    double price() override {
        return 1.5;
    }
};

class BeverageWithMilk : public Beverage {
private:
    int milkCount;
    Beverage* beverage;
public:
    BeverageWithMilk(Beverage* beverage, int milkCount) : beverage(beverage), milkCount(milkCount) {}

    double price() override {
        return beverage->price() + 0.5 * milkCount;
    }

    void print() override {
        beverage->print();
        std::cout << " + " << milkCount << " portion(s) of milk";
    }
};

class BeverageMachine {
public:
    void prepare(const std::string& beverageType, int milkCount) {
        Beverage* beverage = nullptr;

        if (beverageType == "Coffee") {
            beverage = new Coffee();
        }
        else if (beverageType == "Tea") {
            beverage = new Tea();
        }

        if (beverage) {
            if (milkCount > 0) {
                BeverageWithMilk beverageWithMilk(beverage, milkCount);
                beverageWithMilk.print();
            }
            else {
                beverage->print();
            }

            delete beverage;
        }
    }
};

//int main() {
//    BeverageMachine machine;
//    machine.prepare("Tea", 0);     // Tea, no milk
//    std::cout << std::endl;
//    machine.prepare("Coffee", 1);  // Coffee, with milk
//    std::cout << std::endl;
//    machine.prepare("Coffee", 2);  // Coffee, with double milk
//
//    return 0;
//}

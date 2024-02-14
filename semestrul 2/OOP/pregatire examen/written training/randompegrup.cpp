//#include <iostream>
//#include <vector>
//#include <string>
//#include <exception>
//
//class Channel {
//public:
//
//	virtual std::string send(std::string message) = 0;
//};
//
//class Telephone:public Channel {
//private:
//	std::string number;
//public:
//	Telephone(const std::string& _number) : number{ _number } {};
//
//	std::string send(std::string message) override {
//		srand(time(NULL));
//		int r = rand() % 10;
//		if (r == 7) {
//			throw std::exception("Line busy");
//		}
//		else {
//			std::cout << "Dialing  " + number << std::endl;
//			return "Message sent";
//		}
//	}
//};
//
//class Fax :public Channel{
//
//public:
//	std::string send(std::string message) override {
//		srand(time(NULL));
//		int r = rand() % 10;
//		if (r == 7) {
//			throw std::exception("Line busy");
//		}
//		else {
//			std::cout << "sending fax" << std::endl;
//			return "fax sent";
//		}
//	}
//	
//};
//
//class SMS : public Channel {
//
//public:
//	std::string send(std::string message) override {
//		srand(time(NULL));
//		int r = rand() % 10;
//		if (r == 7) {
//			throw std::exception("Line busy");
//		}
//		else {
//			std::cout << "sending sms" << std::endl;
//			return "Sms sent";
//		}
//	}
//};
//
//class Contact {
//private:
//	Telephone& t;
//	SMS& s;
//	Fax& f;
//public:
//	Contact(Telephone& _t, Fax& _f, SMS& _s) :t{ _t }, s{ _s }, f{ _f } {};
//	bool sendAlarm(std::string message) {
//		bool sent = false;
//		while (sent == false) {
//
//			try {
//				t.send(message);
//				sent = true;
//			}
//			catch (std::exception& e) {
//				try {
//					f.send(message);
//					sent = true;
//
//				}
//				catch (std::exception& e) {
//					s.send(message);
//					sent = true;
//				}
//			}
//		}
//		return sent;
//	}
//};
//
//class FailOver {
//private:
//	Fax& f;
//	SMS& s;
//public:
//	FailOver(Fax& _f, SMS& _s) :f{ _f }, s{ _s } {};
//	bool send(std::string message) {
//		bool sent = false;
//		while (sent == false) {
//
//			try {
//					f.send(message);
//					sent = true;
//
//				}
//				catch (std::exception& e) {
//					s.send(message);
//					sent = true;
//				}
//		}
//		return sent;
//	}
//};
//
//int main() {
//	std::string number = "07234567";
//	Telephone t{number};
//	Fax f;
//	SMS s;
//	Contact c{t, f, s};
//	c.sendAlarm("alarm");
//
//}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//class IceCream {
//public:
//    virtual std::string getDescription() const = 0;
//    virtual double computePrice() const = 0;
//};
//
//class SimpleIceCream : public IceCream {
//private:
//    std::string description;
//    double price;
//public:
//    SimpleIceCream(const std::string& _description, double _price)
//        : description(_description), price(_price) {}
//
//    std::string getDescription() const override {
//        return "Simple ice cream with " + description;
//    }
//
//    double computePrice() const override {
//        return price;
//    }
//};
//
//class IceCreamWithTopping : public IceCream {
//private:
//    IceCream* iceCream;
//    std::string toppingDescription;
//    double toppingPrice;
//public:
//    IceCreamWithTopping(IceCream* _iceCream, const std::string& _toppingDescription, double _toppingPrice)
//        : iceCream(_iceCream), toppingDescription(_toppingDescription), toppingPrice(_toppingPrice) {}
//
//    std::string getDescription() const override {
//        return iceCream->getDescription() + " " + toppingDescription;
//    }
//
//    double computePrice() const override {
//        return iceCream->computePrice() + toppingPrice;
//    }
//};
//
//class IceCreamWithChocolateTopping : public IceCreamWithTopping {
//public:
//    IceCreamWithChocolateTopping(IceCream* _iceCream)
//        : IceCreamWithTopping(_iceCream, "with chocolate topping", 3.0) {}
//};
//
//class IceCreamWithCaramelTopping : public IceCreamWithTopping {
//public:
//    IceCreamWithCaramelTopping(IceCream* _iceCream)
//        : IceCreamWithTopping(_iceCream, "with caramel topping", 2.0) {}
//};
//
//class Order {
//private:
//    std::vector<IceCream*> iceCreams;
//public:
//    void addIceCream(IceCream* iceCream) {
//        iceCreams.push_back(iceCream);
//    }
//
//    void printOrder() const {
//        std::sort(iceCreams.begin(), iceCreams.end(), [](IceCream* a, IceCream* b) {
//            return a->computePrice() > b->computePrice();
//            });
//
//        for (const IceCream* iceCream : iceCreams) {
//            std::cout << iceCream->getDescription() << " - Price: " << iceCream->computePrice() << " RON" << std::endl;
//        }
//    }
//
//    ~Order() {
//        for (IceCream* iceCream : iceCreams) {
//            delete iceCream;
//        }
//    }
//};
//
//int main() {
//    Order order;
//
//    // Create ice creams
//    IceCream* vanillaIceCream = new SimpleIceCream("vanilla", 5.0);
//    IceCream* pistachioIceCream = new IceCreamWithChocolateTopping(
//        new IceCreamWithCaramelTopping(new SimpleIceCream("pistachio", 7.0))
//    );
//    IceCream* chocolateIceCream = new IceCreamWithCaramelTopping(new SimpleIceCream("chocolate", 6.0));
//    IceCream* hazelnutsIceCream = new SimpleIceCream("hazelnuts", 4.0);
//
//    // Add ice creams to order
//    order.addIceCream(vanillaIceCream);
//    order.addIceCream(pistachioIceCream);
//    order.addIceCream(chocolateIceCream);
//    order.addIceCream(hazelnutsIceCream);
//
//    // Print the order
//    order.printOrder();
//
//    return 0;
//}

//void function() {
//	NyObjectList list();
//	list.add(new Integer{ 2 }).add(new String{ "Hi" });
//	String* s = new String{ "BYE" };
//	assert(*s == "Bye");
//	list.add(s).add(new Integer{ 5 }); //implement this operation
//	assert(list.length() == 4);
//
//	//prints 2hi bye 5
//	for (Object* o : list)
//		o->print();
//}
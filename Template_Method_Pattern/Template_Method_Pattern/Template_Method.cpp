#include <iostream>
using namespace std;

class AbstractClass
{
public:
	virtual void Operation1() = 0;
	virtual void Operation2() = 0;

	/* template method */
	void Operation3() {
		cout << "Operation3" << endl;
	};
};

class ConcreteClass : public AbstractClass
{
public:
	void Operation1() {
		cout << "Operation1" << endl;
	};
	void Operation2() {
		cout << "Operation2" << endl;
	};
};

void main()
{
	AbstractClass* pClass = new ConcreteClass();

	pClass->Operation1();
	pClass->Operation2();
	pClass->Operation3();

	delete pClass;
}


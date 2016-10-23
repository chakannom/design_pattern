#include <iostream>
#include <string>
using namespace std;

class Element
{
public:
	virtual void accept(class Visitor& rVisitor) = 0;
};

class Visitor
{
public:
	virtual void visit(class This* pElement) = 0;
	virtual void visit(class That* pElement) = 0;
	virtual void visit(class TheOther* pElement) = 0;
};

class This : public Element
{
public:
	void accept(Visitor& rVisitor) {
		rVisitor.visit(this);
	};
	string thiss() {
		return "This";
	};
};

class That : public Element
{
public:
	void accept(Visitor& rVisitor) {
		rVisitor.visit(this);
	};
	string that() {
		return "That";
	};
};

class TheOther : public Element
{
public:
	void accept(Visitor& rVisitor) {
		rVisitor.visit(this);
	};
	string theOther() {
		return "TheOther";
	};
};

class UpVisitor : public Visitor
{
	void visit(This* pElement) {
		cout << "do Up on" + pElement->thiss() << endl;
	};
	void visit(That* pElement) {
		cout << "do Up on" + pElement->that() << endl;
	};
	void visit(TheOther* pElement) {
		cout << "do Up on" + pElement->theOther() << endl;
	};
};

class DownVisitor : public Visitor
{
	void visit(This* pElement) {
		cout << "do Down on" + pElement->thiss() << endl;
	};
	void visit(That* pElement) {
		cout << "do Down on" + pElement->that() << endl;
	};
	void visit(TheOther* pElement) {
		cout << "do Down on" + pElement->theOther() << endl;
	};
};

void main()
{
	Element* pArrayElement[] = { new This(), new That(), new TheOther() };
	UpVisitor upVisitor;
	DownVisitor downVisitor;

	for each (Element* pElement in pArrayElement) {
		pElement->accept(upVisitor);
	}
	for each (Element* pElement in pArrayElement) {
		pElement->accept(downVisitor);
	}

	for each (Element* pElement in pArrayElement) {
		delete pElement;
	}
}
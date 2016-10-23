#include <iostream>
#include <sstream>
#include <string>


using namespace std;

class CBread abstract
{
public:
	CBread() {}
	virtual ~CBread() {}

	string ToString() {
		ostringstream sout;
		sout << "Name: " << m_strName << ",\t" << "Price: $" << m_nPrice << endl;
		return sout.str();
	}

protected:
	string m_strName;
	int m_nPrice;
};

class CBaguetteBread : public CBread
{
public:
	CBaguetteBread() {
		m_strName = "BaguetteBread";
		m_nPrice = 3;
	}
	virtual ~CBaguetteBread() {}
};

class CPizzaBread : public CBread
{
public:
	CPizzaBread() {
		m_strName = "PizzaBread";
		m_nPrice = 2;
	}
	virtual ~CPizzaBread() {}
};

class Make
{
public:
	virtual CBread* CreateBread() = 0;
};

class MakePizzaBread
{

};

class BreadStore
{
public:
	static CBread* GetBread() {}
};

int main()
{
	CBread* pBread1 = new CBaguetteBread();
	CBread* pBread2 = new CPizzaBread();

	cout << pBread1->ToString() << endl;
	cout << pBread2->ToString() << endl;

	return 0;
}
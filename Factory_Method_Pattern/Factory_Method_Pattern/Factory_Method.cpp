#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

class CProduct
{
public:
	CProduct() {};
	virtual ~CProduct() {};
	virtual string ToString() = 0;
};

class CPhone : public CProduct
{
public:
	CPhone(string strName, int nPrice) { m_strName = strName; m_nPrice = nPrice; };
	virtual ~CPhone() {};

	virtual string ToString() {
		ostringstream sout;
		sout << "Name: " << m_strName << ", Price: $" << m_nPrice;
		return sout.str();
	}
private:
	string m_strName;
	int m_nPrice;
};

class CFactory
{
public:
	CFactory() {};
	virtual ~CFactory() {};
	virtual CProduct* MakeProduct() = 0;
};

class CPhoneFactory : public CFactory
{
public:
	CPhoneFactory(string strName, int nPrice) { m_strName = strName; m_nPrice = nPrice; };
	virtual ~CPhoneFactory() {};
	CProduct* MakeProduct() {
		return new CPhone(m_strName, m_nPrice);
	}
private:
	string m_strName;
	int m_nPrice;
};

void main()
{
	auto_ptr<CFactory> apPhoneFactory(new CPhoneFactory("Phone1", 20));
	auto_ptr<CProduct> apPhone(apPhoneFactory->MakeProduct());

	cout << apPhone->ToString() << endl;
}
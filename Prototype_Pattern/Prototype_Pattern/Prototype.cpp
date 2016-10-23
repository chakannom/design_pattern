#include <iostream>
using namespace std;

class CProduct
{
public:
	virtual CProduct* Clone() = 0;
};

class CPhone : public CProduct
{
public:
	CPhone() {};
	CPhone(const CPhone& rPhone) {};
	virtual CProduct* Clone() {
		return new CPhone(*this);
	};
};

class CCar : public CProduct
{
public:
	CCar() {};
	CCar(const CCar& rCar) {};
	virtual CProduct* Clone() {
		return new CCar(*this);
	};
};

void main()
{
	CProduct* pPhone1 = new CPhone();
	CProduct* pPhone2 = pPhone1->Clone();

	delete pPhone1;
	delete pPhone2;

	CProduct* pCar1 = new CCar();
	CProduct* pCar2 = pCar1->Clone();

	delete pCar1;
	delete pCar2;
}
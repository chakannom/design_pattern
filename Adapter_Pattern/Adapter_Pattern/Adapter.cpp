#include <iostream>
#include <memory>

using namespace std;

class AndroidPhone
{
public:
	void charge() { cout << "charging..." << endl; };
};

class USB
{
public:
	virtual void plug() = 0;
};
// object adapter
class USBtoMicro5pinA : public USB
{
public:
	USBtoMicro5pinA() { pAndroidPhone = new AndroidPhone(); };
	~USBtoMicro5pinA() {
		if (pAndroidPhone)
			delete pAndroidPhone;
		pAndroidPhone = NULL;
	}
	virtual void plug() {
		cout << "A Type :";
		pAndroidPhone->charge();
	};
private:
	AndroidPhone* pAndroidPhone;
};
// class adapter
class USBtoMicro5pinB : public USB, public AndroidPhone
{
public:
	virtual void plug() {
		cout << "B Type :";
		charge();
	};
};

void main()
{
	// object adapter
	auto_ptr<USB> pUSBtoMicro5pinA(new USBtoMicro5pinA());
	pUSBtoMicro5pinA->plug();

	// class adapter
	auto_ptr<USB> pUSBtoMicro5pinB(new USBtoMicro5pinB());
	pUSBtoMicro5pinB->plug();
}
#include <iostream>
using namespace std;

class CEarth
{
public:
	static CEarth* GetInstance() {
		if (pEarth == NULL)
			pEarth = new CEarth();
		return pEarth;
	};

private:
	CEarth() {};
private:
	static CEarth* pEarth;
};

CEarth* CEarth::pEarth = NULL;
void main()
{
	CEarth* pEarth1 = CEarth::GetInstance();
	CEarth* pEarth2 = CEarth::GetInstance();

	if (pEarth1 == pEarth2)
		cout << "The 'pEarth1' is equal to The 'pEarth2'." << endl;
	else
		cout << "The 'pEarth1' isn't equal to The 'pEarth2'." << endl;
}
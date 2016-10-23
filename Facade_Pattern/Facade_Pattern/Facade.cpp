#include <iostream>
#include <memory>

using namespace std;

class CExec
{
public:
	CExec(string str) { m_str = str; };
	void Print() { cout << m_str.c_str() << endl; }
private:
	string m_str;
};

class CSubClassOne
{
public:
	void Exec() {
		auto_ptr<CExec> pExec(new CExec("Sub Class One"));
		pExec->Print();
	};
};

class CSubClassTwo
{
public:
	void Exec() {
		auto_ptr<CExec> pExec(new CExec("Sub Class Two"));
		pExec->Print();
	};
};

class CSubClassThree
{
public:
	void Exec() {
		auto_ptr<CExec> pExec(new CExec("Sub Class Three"));
		pExec->Print();
	};
};

class CFacade
{
public:
	CFacade() {
		m_pSubClassOne = new CSubClassOne();
		m_pSubClassTwo = new CSubClassTwo();
		m_pSubClassThree = new CSubClassThree();
	};

	~CFacade() {
		delete m_pSubClassOne;
		delete m_pSubClassTwo;
		delete m_pSubClassThree;
	};

	
	void ExecOne() {
		m_pSubClassOne->Exec();
		m_pSubClassTwo->Exec();
	};

	void ExecTwo() {
		m_pSubClassThree->Exec();
	}

private:
	CSubClassOne* m_pSubClassOne;
	CSubClassTwo* m_pSubClassTwo;
	CSubClassThree* m_pSubClassThree;
};


void main()
{
	auto_ptr<CFacade> pFacade(new CFacade());
	pFacade->ExecOne();
	pFacade->ExecTwo();
}
#include <iostream>
using namespace std;

class State
{
public:
	virtual void Handle() = 0;
};

class ConcreteStateA : public State
{
public:
	void Handle() {
		cout << "ConcreteStateA" << endl;
	};
};

class ConcreteStateB : public State
{
public:
	void Handle() {
		cout << "ConcreteStateB" << endl;
	};
};

class Context
{
public:
	Context(State* pState)
		: m_pState(pState) {};
	~Context() {
		m_pState = NULL;
	};

	void SetState(State* pState) {
		m_pState = pState;
	};
	void Request() {
		m_pState->Handle();
	};
private:
	State* m_pState;
};

void main()
{
	State* pConcreteStateA = new ConcreteStateA();
	State* pConcreteStateB = new ConcreteStateB();

	Context* pContext = new Context(pConcreteStateA);
	pContext->Request();

	pContext->SetState(pConcreteStateB);
	pContext->Request();

	delete pConcreteStateA;
	delete pConcreteStateB;
	delete pContext;
}
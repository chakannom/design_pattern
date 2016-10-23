#include <iostream>
using namespace std;

class Strategy
{
public:
	virtual void Algorithm() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
	void Algorithm() {
		cout << "ConcreteStrategyA" << endl;
	};
};

class ConcreteStrategyB : public Strategy
{
public:
	void Algorithm() {
		cout << "ConcreteStrategyB" << endl;
	};
};

class Context
{
public:
	Context() {};
	void SetStrategy(Strategy* pStrategy) {
		m_pStrategy = pStrategy;
	};
	void Do() {
		m_pStrategy->Algorithm();
	};
private:
	Strategy* m_pStrategy;
};

void main()
{
	Context* pContext = new Context();

	Strategy* pStrategyA = new ConcreteStrategyA();
	pContext->SetStrategy(pStrategyA);
	pContext->Do();

	Strategy* pStrategyB = new ConcreteStrategyB();
	pContext->SetStrategy(pStrategyB);
	pContext->Do();

	delete pStrategyA;
	delete pStrategyB;
	delete pContext;
}
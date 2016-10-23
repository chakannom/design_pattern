#include <iostream>
#include <memory>

using namespace std;

class Context
{
public:
	Context(string str) : m_str(str) {};
	const char* GetStr()  { return m_str.c_str(); };
private:
	string m_str;
};

class AbstractExpression
{
public:
	virtual void Interpret(Context* pContext) = 0;
};

class TerminalExpression : public AbstractExpression
{
public:
	void Interpret(Context* pContext) {
		cout << "TerminalExpression: " << pContext->GetStr() << endl;
	};
};

class NonterminalExpression : public AbstractExpression
{
public:
	void Interpret(Context* pContext) {
		cout << "NonterminalExpression: " << pContext->GetStr() << endl;
	};
};

void main()
{
	auto_ptr<Context> pContext(new Context("Context"));

	auto_ptr<AbstractExpression> pTerminal(new TerminalExpression());
	pTerminal->Interpret(pContext.get());

	auto_ptr<AbstractExpression> pNonterminal(new NonterminalExpression());
	pNonterminal->Interpret(pContext.get());
}
#include <iostream>
using namespace std;

class Context
{
public:
	Context(char* pData)
		: m_strData(pData) {};
	const char* GetData()  {
		return m_strData.c_str();
	};
private:
	string m_strData;
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
		cout << "TerminalExpression: " << pContext->GetData() << endl;
	};
};

class NonterminalExpression : public AbstractExpression
{
public:
	void Interpret(Context* pContext) {
		cout << "NonterminalExpression: " << pContext->GetData() << endl;
	};
};

void main()
{
	Context* pContext = new Context("Data");

	AbstractExpression* pTerminal = new TerminalExpression();
	pTerminal->Interpret(pContext);

	AbstractExpression* pNonterminal = new NonterminalExpression();
	pNonterminal->Interpret(pContext);

	delete pTerminal;
	delete pNonterminal;
	delete pContext;
}
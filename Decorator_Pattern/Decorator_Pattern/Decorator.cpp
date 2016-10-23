#include <iostream>
#include <memory>
using namespace std;

class Coffee
{
public:
	virtual int GetCost() = 0;
	virtual string GetIngredients() = 0;
};

class DefaultCoffee : public Coffee
{
public:
	virtual int GetCost() {
		return 500;
	};
	virtual string GetIngredients() {
		return "Coffee";
	};
};

class CoffeeDecorator : public Coffee
{
public:
	CoffeeDecorator(Coffee* pCoffee) {
		m_pCoffee = pCoffee;
	};
protected:
	Coffee* m_pCoffee;
};

class Milk :public CoffeeDecorator
{
public:
	Milk(Coffee* pCoffee)
		: CoffeeDecorator(pCoffee) {};
	virtual int GetCost() {
		return m_pCoffee->GetCost() + 200;
	};
	virtual string GetIngredients() {
		return m_pCoffee->GetIngredients() + ", Milk";
	};
};

class WhippingCream :public CoffeeDecorator
{
public:
	WhippingCream(Coffee* pCoffee)
		: CoffeeDecorator(pCoffee) {};
	virtual int GetCost() {
		return m_pCoffee->GetCost() + 100;
	};
	virtual string GetIngredients() {
		return m_pCoffee->GetIngredients() + ", Whipping Cream";
	};
};

void main()
{
	auto_ptr<Coffee> pCoffee(new DefaultCoffee());
	cout << "-- DefaultCoffee -- " << endl;
	cout << "Cost: " << pCoffee->GetCost() << endl;
	cout << "Ingredients: " << pCoffee->GetIngredients().c_str() << endl;

	auto_ptr<Coffee> pCoffeeDec1(new Milk(pCoffee.get()));
	cout << "-- DefaultCoffee + Milk -- " << endl;
	cout << "Cost: " << pCoffeeDec1->GetCost() << endl;
	cout << "Ingredients: " << pCoffeeDec1->GetIngredients().c_str() << endl;

	auto_ptr<Coffee> pCoffeeDec2(new WhippingCream(pCoffeeDec1.get()));
	cout << "-- DefaultCoffee + Milk + WhippingCream -- " << endl;
	cout << "Cost: " << pCoffeeDec2->GetCost() << endl;
	cout << "Ingredients: " << pCoffeeDec2->GetIngredients().c_str() << endl;
}
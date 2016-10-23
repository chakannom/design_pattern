#include <iostream>
#include <list>

using namespace std;

class Component
{
public:
	virtual void Operation() = 0;
	virtual void Add(Component* pComponent) {};
	virtual void Remove(Component* pComponent) {};
	virtual Component* GetChild(int i) { return 0; };
};

class Leaf1 : public Component
{
public:
	virtual void Operation() {
		cout << "Leaf1 operation.." << endl;
	};
};

class Leaf2 : public Component
{
public:
	virtual void Operation() {
		cout << "Leaf2 operation.." << endl;
	};
};

class Composite : public Component
{
public:
	virtual void Operation() {
		for each (Component* pComponent in m_listComponent) {
			pComponent->Operation();
		}
	};
	virtual void Add(Component* pComponent) {
		m_listComponent.push_back(pComponent);
	};
	virtual void Remove(Component* pComponent) {
		m_listComponent.remove(pComponent);

	};
	virtual Component* GetChild(int i) {
		int nCnt = 0;
		for (auto iter = m_listComponent.begin(); iter != m_listComponent.end(); iter++, nCnt++) {
			if (i == nCnt) return *iter;
		}
		return NULL;
	};
private:
	list<Component*> m_listComponent;
};

void main()
{
	Leaf1 leaf1;
	Leaf2 leaf2;
	Composite composite;

	composite.Add(&leaf1);
	composite.Add(&leaf2);

	composite.Operation();
}
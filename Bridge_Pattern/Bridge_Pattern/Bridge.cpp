#include <iostream>
#include <memory>

using namespace std;

class DrawingAPI
{
public:
	virtual void drawCircle(double nX, double nY, double nRadius) = 0;
};

class DrawingAPI1 : public DrawingAPI
{
	virtual void drawCircle(double nX, double nY, double nRadius) {
		cout << "===================" << endl;
		cout << "API1 Cricle" << endl;
		cout << "x : " << nX << endl;
		cout << "y : " << nY << endl;
		cout << "radius : " << nRadius << endl;
		cout << "===================" << endl;
	}
};

class DrawingAPI2 : public DrawingAPI
{
	virtual void drawCircle(double nX, double nY, double nRadius) {
		cout << "===================" << endl;
		cout << "API2 Cricle" << endl;
		cout << "x : " << nX << endl;
		cout << "y : " << nY << endl;
		cout << "radius : " << nRadius << endl;
		cout << "===================" << endl;
	}
};

class Shape
{
public:
	virtual void draw() = 0;
	virtual void resizeByPercentage(double nPercentage) = 0;

protected:
	DrawingAPI* m_pDrawingAPI;
};

class CircleShape : public Shape
{
public:
	CircleShape(double nX, double nY, double nRadius, DrawingAPI* pDrawingAPI) {
		m_pDrawingAPI = pDrawingAPI;
		m_nX = nX;
		m_nY = nY;
		m_nRadius = nRadius;
	}
	virtual void draw() {
		m_pDrawingAPI->drawCircle(m_nX, m_nY, m_nRadius);
	}
	virtual void resizeByPercentage(double nPercentage) {
		m_nRadius *= (1.0 + (nPercentage / 100.0));
	}

private:
	double m_nX;
	double m_nY;
	double m_nRadius;
};

void main()
{
	auto_ptr<DrawingAPI> pDrawingAPI1(new DrawingAPI1());
	auto_ptr<DrawingAPI> pDrawingAPI2(new DrawingAPI2());

	auto_ptr<Shape> pCircleShape1(new CircleShape(3, 2, 10, pDrawingAPI1.get()));
	auto_ptr<Shape> pCircleShape2(new CircleShape(5, 1, 20, pDrawingAPI2.get()));

	pCircleShape1->draw();
	pCircleShape2->draw();

}
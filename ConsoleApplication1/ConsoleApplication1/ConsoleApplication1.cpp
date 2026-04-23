#include <iostream>
#include <string>
using namespace std;

class Point {
protected:
	double x;
	double y;

public:
	Point() {
		x = 0;
		y = 0;
	}

	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	Point(const Point& other) {
		x = other.x;
		y = other.y;
	}

	~Point() {
		printf("Point destructed");
	}

	void setPosition(double x, double y) {
		this->x = x;
		this->y = y;
	}

	void reset(){}
};

void Point::reset() {
	this->x = 0;
	this->y = 0;
}

int main() {
	Point point;
	Point point1(1., 2.);
	Point point2(point1);

	Point* pointP = new Point();
	Point* point1P = new Point(1., 2.);
	Point* point2P = new Point(*point1P);

	delete pointP;
	delete point1P;
	delete point2P;
	return 0;
}
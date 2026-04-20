#include <iostream>
#include <string>
using namespace std;

class Point {
public:
	double x;
	double y;
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
};
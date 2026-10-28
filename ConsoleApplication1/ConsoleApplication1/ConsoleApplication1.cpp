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
		printf("Point with default x:%f y:%f\n", x, y);
	}

	Point(double x, double y) {
		this->x = x;
		this->y = y;
		printf("Point created with x:%f y:%f\n", this->x, this->y);
	}

	Point(const Point& other) {
		printf("Point copied\n");
		x = other.x;
		y = other.y;
	}

	~Point() {
		printf("Point destructed\n");
	}

	void setPosition(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double getX(){
		return x;
	}
	double getY(){
		return y;
	}

	void reset();
};

void Point::reset() {
	x = 0;
	y = 0;
	printf("Point resetted\n");
}

class Circle: public Point {
protected:
	double radius;
public:
	Circle() : Point(){
		radius = 1.;
		printf("Circle created with default radius:%f\n", radius);
	}

	Circle(double x, double y, double radius) : Point(x, y) {
		this->x = x;
		this->y = y;
		printf("Circle created with x:%f y:%f\n", x, y);
	}

	Circle(const Circle& other) {
		printf("Circle copied\n");
		x = other.x;
		y = other.y;
		radius = other.radius;
	}

	~Circle() {
		printf("Circle destructed\n");
	}
	double getRadius(){
		return radius;
	}

	void setRadius(double radius) {
		this->radius = radius;
	}

	void reset() {
        Point::reset();
        radius = 0.;
        printf("Circle reseted\n");
    }
};

class Canvas1{
protected:
	Circle c1;
	Circle c2;
public:
	Canvas1(){
		printf("Canvas1 created\n");
	}

	Canvas1(double x, double y, double radius, double x2, double y2, double radius2) : c1(x, y, radius), c2(x2, y2, radius2) {
		printf("Canvas1 created with parametres\n");
	}

	Canvas1(const Canvas1& other) : c1(other.c1), c2(other.c2) {
        printf("Canvas1 copied\n");
    }

	~Canvas1() {
		printf("Canvas1 destructed\n");
	}
};

class Canvas2{
protected:
	Circle *c1;
	Circle *c2;
public:
	Canvas2(){
		c1 = new Circle();
		c2 = new Circle();
		printf("Canvas2 created\n");
	}

	Canvas2(double x, double y, double radius, double x2, double y2, double radius2){
		c1 = new Circle(x, y, radius);
		c2 = new Circle(x2, y2, radius2);
		printf("Canvas2 created with parametres\n");
	}

	Canvas2(const Canvas2& other){
		this->c1 = new Circle(*(other.c1));
		this->c2 = new Circle(*(other.c2));
        printf("Canvas2 copied\n");
    }

	~Canvas2() {
		delete c1;
		delete c2;
		printf("Canvas2 destructed\n");
	}
};

int main() {
	Point point;
	Point point1(1., 2.);
	Circle circle;
	printf("---\n");
	Point* pointP = new Point();
	Point* point1P = new Point(1., 2.);
	Point* point2P = new Point(*point1P);

	delete pointP;
	delete point1P;
	delete point2P;
	printf("---\n");
	Circle* pointWithRadius = new Circle(1., 2., 3.);
	delete pointWithRadius;
	printf("---\n");
	Point* pwr = new Circle(2., 1., 1.);
	pwr->reset();
	delete pwr;
	printf("---\n");
	Canvas1 *can1 = new Canvas1();
	delete can1;
	printf("---\n");
	Canvas2 *can2 = new Canvas2();
	delete can2;
	printf("---\n");
	Circle a(1., 2., 3.);
    Circle b = a;
	printf("---\n");
	printf("a: x=%f y=%f radius=%f\n", a.getX(), a.getY(), a.getRadius());
	a = Circle(2., 5., 1.);
	printf("---\n");
	printf("a: x=%f y=%f radius=%f\n", a.getX(), a.getY(), a.getRadius());
    printf("b: x=%f y=%f radius=%f\n", b.getX(), b.getY(), b.getRadius());
	printf("---\n");
	Circle* p1 = new Circle(1., 2., 3.);
    Circle* p2 = p1;  
	p1->setRadius(10.);
    p1->setPosition(100., 200.);
    printf("p1: x=%f y=%f r=%f\n", p1->getX(), p1->getY(), p1->getRadius());
    printf("p2: x=%f y=%f r=%f\n", p2->getX(), p2->getY(), p2->getRadius());
	delete p1;
	getchar();
	return 0;
}
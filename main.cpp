
#include <cmath>
using std::string;

class Point {
public:
	double x;
	double y;
	double distance(const Point& p) const
	{
		return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
	}
};

class Shape {
public:
	virtual bool contains(const Point& p)const = 0;
};

class Rectangle : public Shape {
protected:
	Point p1;
	Point p2;
	Point p3;
	Point p4;
	double length;
	double height;
public:

	Rectangle(double length, double height) : length(length), height(height)
	{

	}
	virtual ~Rectangle() = default;
	virtual bool contains(const Point& p)const
	{
		if (p.x >= p1.x && p.x <= p2.x && p.y >= p3.y && p.y <= p4.y)
		{
			return true;
		}
	}
};

class Square : public Rectangle {
protected:
	Point p1;
	Point p2;
	Point p3;
	Point p4;

	 bool contains(const Point& p)const
	{
		if (p.x >= p1.x && p.x <= p2.x && p.y >= p3.y && p.y <= p4.y)
		{
			return true;
		}
	}
};

class Ellipse : public Shape {
protected:
	Point f1;
	Point f2;
	double distance;
	virtual bool contains(const Point& p)const
	{
		double d1=f1.distance(p);
		double d2 = f2.distance(p);
		if (d1+d2==distance)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Circle : public Ellipse {
protected:
	Point f1;
	double radius;
	 bool contains(const Point& p)const
	{
		if (radius == f1.distance(p))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};



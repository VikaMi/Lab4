#include "stdafx.h"
#include <iostream>
using namespace std;

class Shapes
{
public:
	virtual double Square()
	{
		return 0;
	}
	virtual int Get()
	{
		return 0;
	}
};

class OnPlaneShapes : public Shapes
{
public:
	virtual double Square()
	{
		return 0;
	}
	virtual int Get()
	{
		return 0;
	}
};

class InSpaceShapes : public Shapes
{
public:
	virtual int Get()
	{
		return 0;
	}
	virtual double Square()
	{
		return 0;
	}
	virtual double Extend()
	{
		return 0;
	}
};


class Point : public OnPlaneShapes
{
public:
	int Get()
	{
		cout << "Enter x :";
		cin >> x;
		cout << "Enter  y:";
		cin >> y;
		cout << "X" << '(' << x << ',' << y << ')' << '\n';
		return 0;
	}
private: int x, y;
};



class Segment : public OnPlaneShapes
{
public:
	int Get()
	{
		cout << "Enter the coordinates of the segment:" << endl;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << "Length:";
		size = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		if (size > 0)
		{
			cout << size << "\n";
		}
		else
		{
			cout << -size << "\n";
		}
		return 0;
	}
private:
	double x1, y1, x2, y2, size;
};


class Circle : public OnPlaneShapes
{
public:
	int Get()
	{
		cout << " Enter radius :";
		cin >> r;
		return 0;
	}
	double Square()
	{
		return 3.14*r*r;
	}
private:
	int r;
};

class Rectangle : public OnPlaneShapes
{
public:
	int Get()
	{
		cout << "Enter a : ";
		cin >> a;
		cout << "Enter  b : ";
		cin >> b;
		return 0;
	}
	double Square()
	{
		return a*b;
	}
private:
	int a, b;
};



class Sphere : public InSpaceShapes
{
public:
	int Get()
	{
		cout << "Enter radius: ";
		cin >> r;
		return 0;
	}
	double Square()
	{
		return 4 * 3.14*r*r;
	}
	double Extend()
	{
		return 4 / 3 * 3.14*r*r*r;
	}
private:
	int r;
};

class Parallelepiped : public InSpaceShapes
{
public:
	int Get()
	{
		cout << "Enter a :";
		cin >> a;
		cout << "Enter  b:";
		cin >> b;
		cout << "Enter c :";
		cin >> c;
		return 0;
	}
	double Square()
	{
		return 2 * (a*b + a*c + b*c);
	}
	virtual double Extend()
	{
		return a*b*c;
	}
private:
	int a, b, c;
};



int main()

{
	cout << "Enter figure:" << endl;
	cout << "1) Circle" << endl;
	cout << "2) Rectangle" << endl;
	cout << "3) Point" << endl;
	cout << "4) Segment" << endl;
	cout << "5) Parallelepiped" << endl;
	cout << "6) Sphere" << endl;

	int choise;
	cin >> choise;
	if (choise == 1)
	{
		OnPlaneShapes *ptr1 = new Circle;
		ptr1->Get();
		cout << "Square:" << (ptr1->Square()) << endl;
	}
	else if (choise == 2)
	{
		OnPlaneShapes *ptr2 = new Rectangle;
		ptr2->Get();
		cout << "Square:" << (ptr2->Square()) << endl;
	}
	else if (choise == 3)
	{
		OnPlaneShapes *ptr3 = new Point;
		ptr3->Get();

	}
	else if (choise == 4)
	{
		Segment ptr4;
		ptr4.Get();
	}
	else if (choise == 5)
	{
		InSpaceShapes *ptr5 = new Parallelepiped;
		ptr5->Get();
		cout << "Square:" << (ptr5->Square()) << endl;
		cout << "Volume: " << (ptr5->Extend()) << endl;
	}
	else if (choise == 6)
	{
		InSpaceShapes *ptr6 = new Sphere;
		ptr6->Get();
		cout << "Square:" << (ptr6->Square()) << endl;
		cout << "Volume: " << (ptr6->Extend()) << endl;
	}
	else
		cout << "Please select number from 1 to 6" << endl;

	system("pause");
	return 0;
}

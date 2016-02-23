// boxit.cpp : Defines the entry point for the console application.
////
//Design a class named Box whose dimensions are integers and private to the class.
//The dimensions are labeled : length ll, breadth bb, and height hh.
//
//The default constructor of the class should initialize ll, bb, and hh to 00.
//
//The parameterized constructor Box(int length, int breadth, int height) should initialize Box's l,bl,b and hh 
//to length, breadth and height.
//
//The copy constructor Box((Box BB) should set l, bl, b and hh to BB's l,bl,b and hh, respectively.
//
//	Every constructor should increment the global variable BoxesCreated.
//
//	The destructor should increment the global variable BoxesDestroyed.
//
//	Apart from the constructor and destructor, the class should have 44 functions :
//
//	int getLength() - Return box's length
//	int getBreadth() - Return box's breadth
//	int getHeight() - Return box's height
//	long long CalculateVolume() - Return the volume of the box
//	Overload the operator << for the class Box.Box AA << Box BB if :
//
//	A.lA.l < B.lB.l
//	A.bA.b < B.bB.b and A.lA.l == B.lB.l
//	A.hA.h < B.hB.h and A.bA.b == B.bB.b and A.lA.l == B.lB.l
//	Overload operator << << for the class Box().
//	If BB is an object of class Box :
//
//	cout << Bcout << B should print B.lB.l, B.bB.b and B.hB.h on a single line separated by spaces.
//
//	Constraints
//
//	0≤l, b, h≤1050≤l, b, h≤105
//	Two boxes being compared using the << operator will not have all three dimensions equal.

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated, BoxesDestroyed;

class Box
{
	static int count;
	int l, b, h;
public:
	static int getCount() { return count; }
	Box() :l(0), b(0), h(0)
	{
		BoxesCreated++;
	}
	Box(int len,int br,int he):l(len),b(br),h(he)
	{
		BoxesCreated++;
	}

	virtual ~Box()
	{
		
		BoxesDestroyed++;
		count++;
	}

	Box(Box &B)
	{
		l = B.getLength();
		b = B.getBreadth();
		h = B.getHeight();
		BoxesCreated++;
	}

	/*Box & operator=(const Box B) {
		if (&B == this) return *this;
		l = B.getLength();
		b = B.getBreadth();
		h = B.getHeight();
		return *this;
	}*/
	
	int getLength() const  { return l; }
	int getBreadth()const { return b; }
	int getHeight() const { return h; }
	long long CalculateVolume() { return l*h*b; }
	bool operator < (Box &B) {
		return ((l < B.getLength()) || (b < B.getBreadth() && l == B.getLength() ||
			h < B.getHeight() && l == B.getLength() && b == B.getBreadth()));
	}

	friend ostream & operator << (ostream & os, Box B) {
		os << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
		return os;
	}
};

int Box::count = 0;

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0;i<n;i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox<temp)
			{
				cout << "Lesser" << endl;
			}
			else
			{
				cout << "Greater" << endl;
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	BoxesCreated = 0;
	BoxesDestroyed = 0;
	check2();
	cout << "Boxes Created : " << BoxesCreated << endl << "Boxes Destroyed : " << BoxesDestroyed << endl;
	cout << "count = " << Box::getCount() << endl;
	return 0;
}

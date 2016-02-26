// funny_string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_funny(const string str)
{
	auto res = false;
	auto len = str.size();
	string rts = str;
	//create the reverse string
	reverse(rts.begin(), rts.end());
	size_t i, count = 0;
	for (i = 1; i < len; i++)
		if (abs(str[i] - str[i - 1]) == abs(rts[i] - rts[i - 1]))
			count++;

	if (count == len - 1)
		res = true;

	return res;
}

int main()
{
	string str = "acxz";
	if (is_funny(str))
		cout << "Funny" << endl;
	else
		cout << "Not Funny" << endl;

	str = "bcxz";
	if (is_funny(str))
		cout << "Funny" << endl;
	else
		cout << "Not Funny" << endl;
    return 0;
}


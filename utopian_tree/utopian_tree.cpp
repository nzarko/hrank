// utopian_tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t;
	cin >> t;
	vector<int> life_cycle_no;
	int height = 1;
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		cin >> n;
		life_cycle_no.push_back(n);
	}

	for (auto i = 0; i < life_cycle_no.size(); i++)
	{
		height = 1;
		if (life_cycle_no[i] > 0)
			for (auto j = 1; j <= life_cycle_no[i]; j++)
			{
				if (j % 2 != 0)
					height *= 2;
				else
					height = height  + 1;
			}
		cout << height << endl;
	}

	return 0;
}
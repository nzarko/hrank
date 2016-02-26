// attending_workshops.cpp : Defines the entry point for the console application.
//

/*
A student signed up for n workshops and wants to attend the maximum number 
of workshops where no two workshops overlap. You must do the following:

Implement 2 structures:

struct Workshop having the following members:

The workshop's start time.
The workshop's duration.
The workshop's end time.
struct Available_Workshops having the following members:

An integer, n (the number of workshops the student signed up for).
An array of type Workshop array having size n.
Implement 22 functions:

Available_Workshops* initialize (int start_time[], int duration[], int n)
Creates an Available_Workshops object and initializes its elements using the 
elements in the start_time[] and duration[] parameters (both are of size nn). 
Here, start_time[i] and duration[i] are the respective start time and duration for 
the ithith workshop. This function must return a pointer to an 
Available_Workshops object.

int CalculateMaxWorkshops(Available_Workshops* ptr)
Returns the maximum number of workshops the student can attend—without overlap. 
The next workshop cannot be attended until the previous workshop ends.

Note: An array of unkown size (n) should be declared as follows:

DataType* arrayName = new DataType[n];
Input Format

Input from stdin is handled by the locked code in the editor; you simply need to write your 
functions to meet the specifications of the problem statement above.

Constraints

1≤N≤10^5
0≤start_time≤10^3
0≤duration≤10^3
Output Format

Output to stdout is handled for you.

Your initialize function must return a pointer to an Available_Workshops object.
Your CalculateMaxWorkshops function must return maximum number of non-overlapping 
workshops the student can attend.

Sample Input

6
1 3 0 5 5 8
1 1 6 2 4 1
Sample Output

CalculateMaxWorkshops should return 4.

Explanation

The first line denotes n, the number of workshops.
The next line contains n space-separated integers where the ithith integer 
is the ithith workshop's start time.
The next line contains n space-separated integers where the ithith integer 
is the ithith workshop's duration.

The student can attend the workshops 0,1,3, and 5 without overlap, 
so CalculateMaxWorkshops returns 4 to main (which then prints 4 to stdout).
*/
#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
	int start, end, duration;

	bool operator < (const Workshop &x) const {
		if (end != x.end)
			return end < x.end;
		return start < x.start;
	}
};


struct Available_Workshops {
	int n;
	vector<Workshop> ws;
};

Available_Workshops *initialize(int start_time[], int duration[], int n) {
	Available_Workshops *aws = new Available_Workshops;
	aws->ws.resize(n);
	aws->n = n;

	for (int i = 0; i < n; i++) {
		aws->ws[i].start = start_time[i];
		aws->ws[i].duration = duration[i];
		aws->ws[i].end = start_time[i] + duration[i];
	}
	return aws;
}

int CalculateMaxWorkshops(Available_Workshops* aw) {
	vector<Workshop>intervals = aw->ws;
	int N, i, last_finished;

	N = aw->n;
	sort(intervals.begin(), intervals.end());
	queue<int> opt;

	//construct the optimal solution
	for (i = 0, last_finished = 0; i<N; i++)
		if (intervals[i].start >= last_finished) {
			opt.push(i);
			last_finished = intervals[i].end;
		}

	return opt.size();
}

int main()
{
	static int n = 6;
	//cin >> n;
	int start_time[n], duration[n];
	for (int i = 0;i<n;i++)
	{
		cin >> start_time[i];
	}
	for (int i = 0;i<n;i++)
	{
		cin >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;
	return 0;
}

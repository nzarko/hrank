// pangrams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <locale>
using namespace std;

string & to_lower_str(string &str)
{
	locale loc;
	for (std::string::size_type i = 0; i<str.length(); ++i)
		str[i] =  std::tolower(str[i], loc);

	return str;
}

bool is_pangram(const string &s)
{
	bool res = false;
	string alphabet;
	for (char ch = 'a'; ch <= 'z'; ch++)
		alphabet += ch;

	string str = s;
	
	//remove spaces
	str.erase(remove_if(str.begin(), str.end(), [](char ch) { return std::isspace<char>(ch, std::locale::classic()); }),
		str.end());
	str = to_lower_str(str);
	sort(str.begin(), str.end());
	auto last = unique(str.begin(), str.end());
	str.erase(last, str.end());
	
	if (str == alphabet)
		res = true;
	
	return res;
		
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	
	string str = "We promptly judged antique ivory buckles for the next prize";
	//getline(cin, str);
	if (is_pangram(str))
		cout << "pangram" << endl;
	else
		cout << "not pangram" << endl;
		
	str = "We promptly judged antique ivory buckles for the prize";
	if (is_pangram(str))
		cout << "pangram" << endl;
	else
		cout << "not pangram" << endl;

	return 0;
}

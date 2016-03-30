// ceasar_cipher.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
int ceasar_ab(char ch,int k) {
   int res = ch;
   int lowmin = 'a';
   int uppermin = 'A';
   
   if (isalpha(ch)) {
      if ( isupper(ch))
         res = uppermin + (ch - uppermin + k) % 26;
      if ( islower(ch))
         res = lowmin + ( ch - lowmin + k) % 26;
   }

   return res;
}

string solve(string s,int l,int k) {
   string res;
   for(int i = 0; i < l; i++)
      res += ceasar_ab(s[i],k);
   return res;
}

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;

        cout << solve(s,n,k) << endl;

        //test cases
        //        cout << (char)ceasar_ab('a', 5) << '\n';
        //cout << (char)ceasar_ab('y', 2) << '\n';
        return 0;
}

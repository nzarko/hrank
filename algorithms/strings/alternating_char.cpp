#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int t;
   cin >> t;
   string str;
   uint d;
   for(int a0=1; a0 <= t; a0++) {
      cin >> str;
      d = 0;
      for(size_t i=1; i < str.size(); i++) {
         if ( str[i]==str[i-1])
            d++;
      }
      cout << d << '\n';
   }
   
    return 0;
}

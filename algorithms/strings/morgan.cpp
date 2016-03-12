#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
typedef stack<char> StackedString;

StackedString toStack(string str) {
   StackedString res;
   for(size_t i = 0; i < str.size(); i++)
      res.push(str[i]);
   return res;
}

ostream & operator << ( ostream &os, StackedString ss) {
   while(!ss.empty()) {
      os << ss.top();
      ss.pop();
   }
   os << endl;
   return os;
}

string make_lex_string(string s1,string s2) {
   string res="" ;
   int i=0,j=0;
   while (i<s1.size() && j < s2.size()) {
      if ( s1[i] < s2[j] ) {
         res += s1[i++];        
      }else if (s1[i] > s2[j]) {
         res += s2[j++];
      } else {
         int x = i, y = j;
         char a = s1[i];
         while(x < s1.length() && y < s2.length()) {
            if ( s1[x] != s2[y] )
               break;
            else if(s1[x] > a) {
               res += s1.substr(i,x)+ s2.substr(j,y);
               i = x;
               j = y;
               a = s1[x];
            }
            x++; y++;
         }
         if(x == s1.length()) {
            res += s2[j];
            j++;
         } else if ( y == s2.length()) {
            res+=s1[i];
            i++;
         } else {
            if (s1[x] < s2[y] ) {
               res += s1[i];
               i ++;
            } else {
               res += s2[j];
               j++;
            }
         }
      }
   }

   res += s1.substr(i) + s2.substr(j);
   return res;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int t;
   cin >> t;
   vector<string> result;
   for(int i = 1; i <= t; i++) {
      string a,b;
      cin >> a >> b;    
      result.push_back(make_lex_string(a,b));
   }

   for(size_t i = 0; i < result.size(); i++)
      cout << result[i] << endl;
    return 0;
}

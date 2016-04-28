#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  size_t n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
 
  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  delete[] P;
  
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

string get_next_circular(const string &s,int k) {
   // string result = s;
   // if (k==0) return result;
   // string s_portion = s.substr(0, k);
   // result.erase(0,k);
   // result += s_portion;
   string result;
   if (k==0) return "";
   string s1 = s.substr(0, k);
    string s2 = s.substr(k);
   
   result = s2+s1;
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int N;
   cin >> N;
   string str;
   cin >>str;
   str += str;
   cout << "str = " << str << '\n';
   //vector<string> subs;
   for(size_t i=0; i < N; i++) {
      string sub = str.substr(i,N);
      cout << "sub = " << sub << '\n';
         //      cout << get_next_circular(str,i) << '\n';
      //subs = get_all_substrings(get_next_circular(str,i));
      //cout << subs << endl;
      cout << longestPalindrome(sub).length() << '\n';
      
   }
      
   
    return 0;
}

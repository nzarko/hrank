#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long longestPalindrome(string seq) {
   long longest = 0;
   vector<long> l;
   long i = 0 ;
   long pallen = 0;
   long s = 0;
   long e = 0;
   while ( i < seq.length() ) {
      if ( i > pallen && seq[i-pallen - 1] == seq[i] ) {
         pallen += 2;
         i++;
         continue;
      }
      l.push_back(pallen);
      longest = max(longest,pallen);
      s = l.size() - 2;
      e = s - pallen;
      bool found = false;
      for(long j = s; j > e; j--) {
         long d = j - e - 1;
         if (l[j] == d ) {
            pallen = d;
            found = true;
            break;
         }
         l.push_back(min(d,l[j]));
      }
      if(!found) {
         pallen = 1;
         i++;
      }
   }
   l.push_back(pallen);
   longest = max(longest,pallen);
   return longest;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int N;
   cin >> N;
   string str;
   cin >>str;
   str += str;
   //cout << "str = " << str << '\n';
   //vector<string> subs;
   for(size_t i=0; i < N; i++) {
      string sub = str.substr(i,N);
      // cout << "sub = " << sub << '\n';
         //      cout << get_next_circular(str,i) << '\n';
      //subs = get_all_substrings(get_next_circular(str,i));
      //cout << subs << endl;
      cout << longestPalindrome(sub) << '\n';
      
   }
      
   
    return 0;
}

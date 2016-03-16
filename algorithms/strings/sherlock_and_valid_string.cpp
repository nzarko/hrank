#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

ostream & operator << (ostream & os ,const vector<int> &v) {
    for(size_t i = 0; i < v.size(); i++)
        os << v[i] << " ";
    return os;
}

bool is_valid(string str) {
   vector<int> frequencies(26,0);
   int maxFreq = 0, maxKey = 0;
   for(size_t i=0 ;i < str.length(); i++) {
      frequencies[str[i] - 'a']++;
      if(maxFreq < frequencies[str[i] - 'a'])
         maxFreq = frequencies[str[i] - 'a'];
   }

   cout << "Frequences table: " << frequencies << endl;

   vector<int> mode(maxFreq+1,0);
   maxFreq = 0;
   for(size_t i = 0; i < frequencies.size(); i++) {
      if (frequencies[i] != 0 ) {
         mode[frequencies[i]]++;
         if(maxFreq < mode[frequencies[i]]) {
               maxFreq = mode[frequencies[i]];
               maxKey = frequencies[i];
         }
      }
   }
   //cout << mode << endl;
   cout << "MaxKey : " << maxKey << endl;

   int res = 1;
   int count = 0;
   for(size_t i =0 ; i < 26; ++i) {
      if (frequencies[i]!=0 &&frequencies[i]!=maxKey) {
         if(frequencies[i] < maxKey)
            count ++;
         res -= (frequencies[i] - maxKey);
      }
   }
   cout << "res = " << res << endl;
   if (count == 1)
       return true;
   else if (count > 1)
       return false;

   if (res < 0)
      return false;
   else
      return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin >> s;
    if(is_valid(s))
        cout <<"YES" << '\n';
    else
        cout << "NO" << '\n';
    return 0;
}

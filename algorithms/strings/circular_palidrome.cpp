#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
ostream &operator <<(ostream &os , const vector<string> &v) {
   for(size_t i=0; i < v.size(); i++)
      os << v[i] << '\n';
   return os;
}

string get_next_circular(const string &s,int k) {
   string result = s;
   if (k==0) return result;
   string s_portion = s.substr(0, k);
   result.erase(0,k);
   result += s_portion;
   return result;
}

bool is_palidrome(const string &s) {
   if( equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) )
      return true;
   return false;
}

vector<string> get_all_substrings(const std::string& str)
{
   int len = str.length();
   vector<string> res;
   int k = 2;
   for(;k<len; k++)
      for(int i = 0; i <len-k + 1; i++)
         res.push_back(str.substr(i,k));
    return res;
}

               
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int N;
   cin >> N;
   string str;
   cin >>str;
   vector<string> subs;
   for(int i=0; i < N; i++) {
      //cout << get_next_circular(str,i) << '\n';
      subs = get_all_substrings(get_next_circular(str,i));
      cout << subs << endl;
   }
      
   
    return 0;
}


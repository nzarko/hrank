#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
typedef vector<int> BigNumber;

string toString(int k) {
   ostringstream out;
   while ( k != 0 ) {
      out << k%10;
      k /=10;
   }
   string res = out.str();
   reverse(res.begin(), res.end());
   return res;
}
string toString(BigNumber bn) {
   string res;
   ostringstream os;
   for(int i = 0; i < bn.size(); i++)
      os << bn[i];
   return os.str();
}

ostream &operator << (ostream &os , const vector<int> &v) {
   //ignore leading zeros
   int k = 0;
   while (v[k] == 0 )
      {
         k++;
         continue;
      }
   for(size_t i = k; i < v.size(); i++)
      os << v[i];
   os << endl;
   return os;
}

BigNumber product(string a, string b)
{
   vector<int> result(a.size() + b.size(), 0);
   for( int i = a.size() - 1; i >= 0; i-- )
      {
         for( int j = b.size() - 1; j >= 0; j-- )
            {
               result[ i + j + 1 ] += ( b[ j ] - '0') * ( a[ i ] - '0' ); //single array to store intermediate values
            }
      }
   for( int i = a.size() + b.size() - 1; i >= 0; i-- ){
      if( result[ i ] >= 10 ){
         result[ i - 1 ] +=result[ i ] / 10;
         result[ i ] %= 10;
      }
   }
   /*cout << a << " * " << b << " = ";
   for( int i = 0; i < a.size() + b.size(); i++ ){
      cout << result[ i ];
   }
   cout << endl;*/
   return result;
}

int main(){
    int n;
    cin >> n;
     string factor= "1";
   BigNumber res;
   for(size_t i = 1; i<=n; i++ ) {
      res = product(toString(i), factor);
      factor = toString(res);
   }

   cout << res;
    return 0;
}
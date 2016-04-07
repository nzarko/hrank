#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

ostream &operator<< (ostream &os, vector<long> v) {
   for (int i =0; i < v.size(); i++)
      os << v[i] << " " ;
   os << endl;
   return os;
}

vector<long> find_kaprekar_numbers(long int low, long int limit)
{
    long int i;
    vector<long> res;

    if (low == 1 )
       res.push_back(low);
    
    for(i = low; i <= limit; i++)
    {
        long int m, n;
        long int r, power;
 
        for(m = i, n = i*i, r = 0, power = 1;
            m > 0;
            m = m/10)
        {   
            r = r + power * (n % 10);
            n = n/10;
            power = power * 10;
        }
 
        if(n > 0 &&
            r > 0 &&
            (n + r) == i)
           res.push_back(i);
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   long int l,m;
   cin >>l >> m;
   vector<long> res = find_kaprekar_numbers(l,m);
   if (res.size() == 0 )
      cout << "INVALID RANGE" << '\n';
   else
      cout << res;
    return 0;
}


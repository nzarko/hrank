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
   vector<int> res;
   for(int a0 = 1; a0 <= t; a0++) {
      int n1,n2;
      cin >> n1 >> n2;
      res.push_back(floor(sqrt(n2)) - ceil(sqrt(n1))+1);
   }
   for(size_t i = 0; i < res.size(); i++)
      cout << res[i] << endl;
    return 0;
}

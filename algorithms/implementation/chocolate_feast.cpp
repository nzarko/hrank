/* ************************************** *
 * ALL TESTS PASSED                       *
 * ************************************** */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int fund, int prpu, int wrpu) {
   int choc = 0;
   int rem_w;
   choc = fund / prpu;
   rem_w = choc;

   int p = rem_w / wrpu;
   while ( rem_w >= wrpu) {

      choc += p;
      rem_w = p + rem_w % wrpu;
      p = rem_w / wrpu;
   }
   return choc;
}


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        cout << solve(n,c,m) << endl;
    }
    return 0;
}

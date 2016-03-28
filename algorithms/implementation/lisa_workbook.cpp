#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int n,k;
   cin >> n >> k;
   int page= 0, pr_no=0, res=0;
   for (int chp=1; chp<=n; chp++) {
      page++;
      cin >> pr_no;
      for(int problem=1; problem <= pr_no; problem++) {
         if (problem == page)
            res+=1;
         if(problem % k==0 && problem < pr_no)
            page++;
      }
   }
                                                   
   cout << res << endl;
    return 0;
}

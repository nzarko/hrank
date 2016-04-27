#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   int t,n;

   scanf("%d\n",&t);

   for(int i=0;i<t;i++){
      scanf("%d\n",&n);


      vector<int> a(n);

      for(int j=0;j<n;j++){
         scanf("%d ",&a[j]);
      }
      //sort the array
      vector<int>b = a;

      sort(a.begin(), a.end());
      
      int flag=0;
      int k=0;
      int l;
      while(k<n) {
         if(a[k]==b[k]){
            l=0;
            k++;
            continue;
         }
         int t;
         //cout << "k % n = " << k % n <<'\n';
         t=b[k];
         b[k]=b[(k+1)];
         b[(k+1)]=b[(k+2)];
         b[(k+2)]=t;
         l++;
         if(l==3){
            flag=1;
            break;
         }

      }
      if(flag==1){
         printf("NO\n");
      }else
         {
            printf("YES\n");
         }
   }
   return 0;
}

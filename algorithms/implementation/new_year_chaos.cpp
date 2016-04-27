/* ************************************************** *
 *       All tests passed!!                           *
 * ************************************************** */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int check_eq(int arr[],int x,int n)
{
   for(int i=x;i>=0;i--)
      {
         if(arr[i]==x)
            {
               return i;
            }
      }
   return 0;
}
int main()
{
   int t,n;
   int arr[100000];
   int brr[100000];
   cin>>t;
   arr[0]=0;
   while(t--)
      {

         int bribe=0;
         cin>>n;
         int x;
         for(int i=0;i<=n;i++)
            {
               brr[i]=0;
            }
         for(int i=1;i<=n;i++)
            cin>>arr[i];
         int flag=1;
         int z=0;

         int j=n;
         int i=n;
         for(int i=n;i>0;i--)
            {
               int y=1;
               while(y)
                  {
                     if(arr[j]!=i)
                        {
                           x=check_eq(arr,j,n);
                           int temp=arr[x+1];
                           arr[x+1]=arr[x];
                           arr[x]=temp;
                           bribe+=1;
                           brr[j]+=1;
                           if(brr[j]>2)
                              {
                                 cout<<"Too chaotic"<<endl;
                                 z=1;
                                 i=-1;
                                 break;
                              }
                           if(z==1)
                              break;
                        }
                     if(z==1) break;
                     if(arr[j]==i)
                        {
                           y=0;
                           j-=1;
                        }
                  }
            }

         if(z==0)
            cout<<bribe<<endl;
      }
   return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;
const int MININT = numeric_limits<int>::min();
typedef vector<int> IV;
void solve(IV &pofit, IV &weight) {
}

int main() {
   int N, W; // number of items -- maximum weight of knapsack
   IV profit(N+1,0);
   IV weight(N+1 , 0);

   //READ THE ABOVE ARRAYS.
   //Todo : READ THEM
   vector< vector<int> >opt; //max profit of packing items 1..n with weight limit w
   vector< vector<bool> > sol; //does opt solution to pack items 1..n with weight limit w include item n?

   for(int n = 1; n <= N; n++) {
     for( int w = 1; w <= W; w++) {
       //Don't take item n
       int option1 = opt[n-1][w];
       //take item n
       int option2 = MININT;
       if(weight[n] <= w)
	 option2 = profit[n] +opt[n-1][w - weight[n]];
       
       //select better of two options
       opt[n][w] = max(option1,option2);
       sol[n][w] = (option2 > option1);
     }
   }
   
   //determine which items to take
   bool *take = new bool[N+1];
   for(int n = N, w=W; n>0; n--) {
     if(sol[n][w]) {
       take[n] = true;
       w = w - weight[n];
     } else
       take[n] = false;
   }
   
   //print results
   printf("item \t profit \t weight \t take\t\n");
   for(int n = 1; n<= N; n++) {
     printf("%d \t %d \t %d \t %d\n",n,profit[n],weight[n],take[n]);
   }
   
   return 0;
}

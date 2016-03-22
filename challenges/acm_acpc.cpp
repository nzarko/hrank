#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include "../includes/helper.h"
using namespace std;

struct solution {
   int teams, items;
};

solution solve(vector<string> v,int m) {
   solution res;
   int len = v.size();
   int max = -1;
   int teams = 0;
   for(size_t i = 0;  i < len-1; i++) {
      string b1 = v[i];
     
      for(size_t j = i+1; j < len; j++) {
         string b2 = v[j];
         int kw = 0;
         for(int k = 0; k < m; k ++)
            kw += (b1[k]=='1' || b2[k] == '1') ? 1 : 0;
         
         if( kw > max) {
            max = kw;
            teams = 1;
         } else if (max == kw)
            teams += 1;         
      }
   }
   res.items = max;
   res.teams = teams;
   return res;
}


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }

    cout << topic;
    solution res = solve(topic,m);
    cout << res.items << '\n' << res.teams << endl;
    return 0;
}

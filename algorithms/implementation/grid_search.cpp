#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_pattern_in_grid(const vector<string> &grid, const vector<string> &pattern) {
   bool found = false;
   int edge = pattern.size();
   int i = 0;
   size_t pos ,pos_2;
   int count = 0;
   while (i < grid.size() - edge && found == false) {
      pos = grid[i].find(pattern[0], 0);
      int g_i = i+1;
      int p_i = 1;
      pos_2 = pos;
      while (pos_2 != string::npos && p_i < edge) {
         pos_2 = grid[g_i].find(pattern[p_i],pos);
         g_i ++;
         p_i ++;
         count++;
         //         if(pos_2 == string::npos) break;
         if(pos_2 != pos ) {
            count = 0;
            pos = grid[i].find(pattern[0],pos);
            pos_2 = pos;
         }
      }
      if (count == edge - 1)
         found = true;
      i++;
   }
   return found;
}


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        if ( is_pattern_in_grid(G,P))
           cout << "YES" << '\n';
        else
           cout << "NO" << '\n';
    }
    return 0;
}

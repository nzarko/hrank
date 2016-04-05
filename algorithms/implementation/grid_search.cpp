#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

ostream & operator << (ostream &os, vector<size_t> p) {
    os << "Positions : ";
    for(int i = 0; i < p.size();i++)
        os << p[i] << " " ;
    os << endl;
    return os;
}

bool is_pattern_in_grid(const vector<string> &grid, const vector<string> &pattern) {
    bool found = false;
      int edge = pattern.size();
      int p_len = pattern[0].size();
      int i = 0;
      size_t pos=0;
      int start = 0;
      int count = 0;
      int limit = (grid.size() == edge)?grid.size() : grid.size() - edge +1;
      while (i < limit) {
          count= 0;
         pos = grid[i].find(pattern[0], start);
         if (pos == string::npos) {
             start = 0;
             i++;
         }
         else {
             count ++;
             int g_i=i+1;
             if (g_i == limit)
                 return false;
             int p_i = 1;
             string str;
             while(p_i < edge) {
                 str = grid[g_i].substr(pos,p_len);
                 if(str==pattern[p_i]) {
                     count++;
                 }
                 g_i++;
                 p_i++;
             }
             if (count == edge)
                 return true;
             start++;
         }
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



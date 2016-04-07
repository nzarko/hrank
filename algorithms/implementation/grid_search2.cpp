#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1009;
int grid[N][N];
int pattern[N][N];

int main(){
    int t,R,C,r,c;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        bool result = false;
        
        cin >> R >> C;
        
        for(int G_i = 0;G_i < R;G_i++){
            string G;
           cin >> G;
            for(int j = 0; j < G.size(); j++) {
                grid[G_i][j] = G[j] - '0';
            }
        }
        
        cin >> r >> c;
        
        for(int P_i = 0;P_i < r;P_i++){
            string P;
           cin >> P;
            for(int j = 0; j< P.size(); j++) {
                pattern[P_i][j] = P[j] - '0';
            }
        }
        //TODO : implement it from here!
        for(int i =0; i <R; i++) {
            for (int j = 0; j < C; j++) {
                if (i + r > R || j + c > C) {
                    continue;
                }
                bool check_if_ok = true;
                for(int k = 0; k < r; k++) {
                    for(int z = 0; z < c; z++) {
                        if(grid[i+k][j+z] != pattern[k][z]) {
                            k = R+C;
                            check_if_ok = false;
                            break;
                        }
                    }
                }
                if (check_if_ok) {
                    result = true;
                    i = j = R+C;                    
                }
            }
        }
        if ( result ) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

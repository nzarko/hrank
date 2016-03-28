#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int c = 5*(2*n%3);
        if(c > n )
            cout << -1 << endl;
        else {
            string fives(n-c,'5');
            string threes(c,'3');
            string res = fives+threes;
            cout << res << endl;
        }
    }
    return 0;
}
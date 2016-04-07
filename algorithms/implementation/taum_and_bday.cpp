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
        long long int b;
        long long int w;
        cin >> b >> w;
        long long int x;
        long long int y;
        long long int z;
        cin >> x >> y >> z;
        long long res = 0;
        if(x >y) {
            swap(x,y);
            swap(w,b);
        }
        res = x * b;
        if(z + x < y) {
            res += w*(z + x);
        } else {
            res += y*w;
        }
        cout << res << '\n';
    }
    return 0;
}

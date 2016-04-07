#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t,n,a,b;
    cin >> t;
    for(int a0 = 1; a0 <= t; a0++) {
        cin >> n >> a >> b;
        vector<int> result;
        if ( a > b )
            swap(a,b);
        for ( int i = 1; i <= n; i++ ) {
            result.push_back((i -1)*a + (n - i) * b);         
        }
        sort(result.begin(), result.end());
        cout << result[0] << " ";
        for(int j = 1; j < n; j++ ) {
            if (result[j] != result[j -1])
                cout << result[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

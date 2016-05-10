#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    for(int a0=1; a0 <= t; a0++) {
        string s1,s2;
        cin>>s1 >>s2;      
        size_t pos = s1.find_first_of(s2);
        if(pos != string::npos)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

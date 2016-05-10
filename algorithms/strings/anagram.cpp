#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        string s;
        cin >> s;
        if (s.length() % 2) {
            cout << -1 << '\n';
            continue;
        }
        map<char,int> let;
        int h = s.length() / 2;
        for(int i = 0; i < h; i++) {
            if (let.find(s[i]) != let.end()) 
                let[s[i]]++;
            else 
                let[s[i]] = 1;
        }
        int count = 0;
        for(int j = h; j < s.length(); j++) {
            if( let.find(s[j]) != let.end() && let[s[j]] > 0)
                let[s[j]]--;
            else
                count++;
        }
        cout << count << '\n';
    }
    return 0;
}
 

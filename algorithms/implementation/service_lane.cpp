#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,t;
	cin>>n>>t;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin>>a[i];
	}
	for(int k = 0; k < t; ++k){
		int p,q;
		cin>>p>>q;
		int min = a[p];
		for(int i = p; i <= q; ++i){
			if( a[i] < min){
				min = a[i];
			}
		}
		cout<<min<<endl;
	}
    return 0;
}

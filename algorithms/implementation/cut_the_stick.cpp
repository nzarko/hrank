#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() 
{
	int n;
	cin>>n;
	vector<int> a (n);
	for(int i = 0; i < n; ++i){
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	reverse( a.begin(), a.end());
	while( !a.empty()){
        cout<<a.size()<<endl;
		int cut = a[a.size()-1];
		for(int i = a.size() - 1; i >=0 ; --i){
			a[i] -= cut;	
		}
		while( !a.empty() && a[a.size() - 1] <= 0){
			a.pop_back();
		}
	}
	// your code goes here
	return 0;
}

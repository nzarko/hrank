/**
 * There is no difference whether we try to change the first to 
 * look like the second one, of to change the second one to look 
 * like the first one. The thing is that if one of them has for 
 * example X 'a' letters and the other one has Y 'a' letters, then 
 * no matter what we do we need to do abs(X-Y) deletions in order 
 * to match the number of 'a' s. We have to do the same for all 
 * the 26 letters, in other words the answer is the sum of differences 
 * of each letters quantities in the strings.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	vector<int> freq_s1(27,0),freq_s2(27,0);
	for(int i=0;i<s1.size();++i)
		freq_s1[s1[i]-'a']++;
	for(int j=0;j<s2.size();++j)
		freq_s2[s2[j]-'a']++;
	int res = 0;
	for(int i=0;i<freq_s1.size();++i)
		res += abs(freq_s1[i]-freq_s2[i]);
	cout << res << '\n';
        return 0;
}

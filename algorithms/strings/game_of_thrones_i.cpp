#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* ***********************************************************************************
 * The only thing which we care about is the number of all the letters from a to z.  * 
 * If the string has an even length then we need to have even number of letters of   * 
 * each type so that we can form a palindrome. If the initial string has an odd      *
 * length, then we need to have exactly one letter repeating odd number of times     *
 * and the other letters repeating even number of times.                             *
 * ***********************************************************************************/
int odd_crowd(const vector<int>& vec)
{
	int ans=0;
	for(int i=1;i<=26;++i)
		if(vec[i]%2==1)
			++ans;
	return ans;
}

int main()
{
	string s;
	cin>>s;
	vector<int> letter( 27,0);
	for(int i=0;i<s.size();++i)
		++letter[ s[i]-'a'+1];
	
	int odds= odd_crowd(letter);
	bool ans=true;
	if(s.size()%2==0)
	{
		if(odds>0)
			ans=false;
	}
	else
		if(odds!=1)
			ans=false;
	if(ans)
		cout<<"YES" << '\n';
	else
		cout<<"NO" << '\n';

}
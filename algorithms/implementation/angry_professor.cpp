#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    for(int ii=1;ii<=t;++ii)
    {
        int n,k;
        cin>>n>>k;
        int num=0;
        for(int i=0;i<n;++i)
            {
                int b;
                cin>>b;
                if(b<=0)
                    ++num;
            }
        if(num>=k)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}


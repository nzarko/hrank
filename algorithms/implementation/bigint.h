#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class BigInt
{
 private:
   vector<int> a;
 public:
   BigInt() {
      a.push_back(0);
   }
   
   BigInt(int x) {
      if(x==0)
         a.push_back(0);
      while(x!=0) {
            a.push_back(x%10);
            x=x/10;
      }
   }
   
   void operator += (const BigInt& b) {
      vector<int> x,y,z;
      x=a;
      y=b.a;
      int n=x.size();
      int m=y.size();
      if(n<m)
         for(int i=0;i<m-n;++i)
            x.push_back(0);
      else
         for(int i=0;i<n-m;++i)
            y.push_back(0);
      int h=0;
      for(int i=0;i<x.size();++i) {
            z.push_back(x[i]+y[i]+h);
            h=z[i]/10;
            z[i]%=10;
      }
      if(h==1)
         z.push_back(1);
      while(z[z.size()-1]==0)
         z.pop_back();
      a=z;
   }
   
   void operator -=( const BigInt& b) {
      for(int i=0;i<b.a.size();++i) {
            a[i]-=b.a[i];
            if(a[i]<0) {
                  a[i]+=10;
                  int j=i+1;
                  while(a[j]==0) {
                        a[j]=9;
                        ++j;
                  }
                  --a[j];
            }
      }
      while(a[a.size()-1]==0 && a.size()!=1)
         a.pop_back();
   }
   
   BigInt multByDigit(const BigInt& b,int x) {
      BigInt ans;
      vector<int> res;
      int h=0;
      for(int i=0;i<b.a.size();++i) {
            res.push_back( b.a[i]*x+h);
            h=res[res.size()-1]/10;
            res[res.size()-1]%=10;
      }
      if(h!=0)
         res.push_back(h);
      ans.a=res;
      return ans;
   }
   
   void operator *=( const BigInt& b) {
      BigInt ans;
      for(int i=0;i<b.a.size();++i) {
            vector<int> c;
            for(int j=0;j<i;++j)
               c.push_back(0);
            BigInt d;
            d=d.multByDigit(*this,b.a[i]);
            for(int j=0;j<d.a.size();++j)
               c.push_back(d.a[j]);
            BigInt temp;
            temp.a=c;
            ans+=temp;
      }
      *this=ans;
   }
   
   BigInt half( const BigInt& bb) {
      vector<int> ans;
      BigInt b=bb;
      int i=b.a.size()-1;
      while(i>=0) {
         if(b.a[i]%2==0) {
            if(i!=0)
               ans.push_back(b.a[i]/2);
            --i;
         }
         else {
            if(b.a[i]!=1) {
               ans.push_back(b.a[i]/2);
               b.a[i]=1;
            }
            else {
               int x=b.a[i];
               if(i-1>=0)
                  x=x*10+b.a[i-1];
               if(i!=0)
                  ans.push_back(x/2);
               --i;
               if(i-1>=0)
                  b.a[i]=1;
            }
         }
      }
      BigInt res;
      reverse(ans.begin(),ans.end());
      res.a=ans;
      return res;
   }

   friend istream& operator >> (istream& in, BigInt& x);
   friend ostream& operator<< (ostream& out, const BigInt& x);
   friend BigInt operator+ (const BigInt& a, const BigInt& b);
   friend BigInt operator* ( const BigInt& a, const BigInt& b);
   friend BigInt operator- (const BigInt& a, const BigInt b);
   friend bool operator < (const BigInt& a, const BigInt& b);
   
};

istream& operator >> (istream& in, BigInt& x)
{
   string s;
   x.a.clear();
   in>>s;
   for(int i=s.size()-1;i>=0;--i)
      x.a.push_back(s[i]-'0');
   return in; 
}

ostream& operator<< (ostream& out, const BigInt& x)
{
   for(int i=x.a.size()-1;i>=0;--i)
      out<<x.a[i];
   return out;
}

BigInt operator+ (const BigInt& a, const BigInt& b)
{
   BigInt c;
   c=a;
   c+=b;
   return c;
}

BigInt operator* ( const BigInt& a, const BigInt& b)
{
   BigInt c=a;
   c*=b;
   return c;
}

BigInt operator- (const BigInt& a, const BigInt b)
{
   BigInt c;
   c=a;
   c-=b;
   return c;
}

bool operator < (const BigInt& a, const BigInt& b)
{
   if(a.a.size()<b.a.size())
      return true;
   else {
      if(a.a.size()>b.a.size())
         return false;
      else {
         int i=0;
         while(a.a[i]==b.a[i])
            ++i;
         return a.a[i]<b.a[i];
      }
   }
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_palindrome(string s,int len){
  for(int i=0;i<len/2;i++){
    if(s[i]!=s[len-1-i]){
      return false;
    }
  }
  return true;
}


void remove_at(string &s,int idx){
  for(int i=idx;i<s.size()-1;i++){
    s[i]=s[i+1];
  }
  s[s.size()-1]=' ';
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int t;
  cin>>t;
  for(int a0=0;a0<t;a0++){
    string str;
    cin>>str;
    int len=str.size();
    
    if(is_palindrome(str,len)){
      cout<<-1<<endl;
    }            
    
    for(int i=0;i<len/2;i++){
      if(str[i]!=str[len-1-i]){	
	remove_at(str,i);
	if(is_palindrome(str,len-1)){
	  cout<<i<<endl; //It's palindrome print index.
	  break;
	}else{    //else need to delete len-1-i
	  cout<<len-1-i<<endl;
	  break;
	}
      }
    }
  }             
  return 0;
}

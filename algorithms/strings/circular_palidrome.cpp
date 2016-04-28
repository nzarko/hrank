#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
ostream &operator <<(ostream &os , const vector<string> &v) {
   for(size_t i=0; i < v.size(); i++)
      os << v[i] << '\n';
   return os;
}

string get_next_circular(const string &s,int k) {
   // string result = s;
   // if (k==0) return s;
   // string s_portion = s.substr(0, k);
   // result.erase(0,k);
   // result += s_portion;
   // return result;
   string result;
   if (k==0) return s;
   string s1 = s.substr(0, k);
    string s2 = s.substr(k);
   
   result = s2+s1;
    return result;
}

bool is_palidrome(const string &s) {
   if( equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) )
      return true;
   return false;
}

string findLongestPalindromicString(string text)
{
   int N = text.length();
    if(N == 0)
        return "";
    N = 2*N + 1; //Position count
    int L[N]; //LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1; //centerPosition 
    int R = 2; //centerRightPosition
    int i = 0; //currentRightPosition
    int iMirror; //currentLeftPosition
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;
     
    //Uncomment it to print LPS Length array
    //printf("%d %d ", L[0], L[1]);
    for (i = 2; i < N; i++) 
    {
        //get currentLeftPosition iMirror for currentRightPosition i
        iMirror  = 2*C-i;
        L[i] = 0;
        diff = R - i;
        //If currentRightPosition i is within centerRightPosition R
        if(diff > 0)
            L[i] = min(L[iMirror], diff);
 
        //Attempt to expand palindrome centered at currentRightPosition i
        //Here for odd positions, we compare characters and 
        //if match then increment LPS Length by ONE
        //If even position, we just increment LPS by ONE without 
        //any character comparison
        while ( ((i + L[i]) < N && (i - L[i]) > 0) && 
            ( ((i + L[i] + 1) % 2 == 0) || 
            (text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] )))
        {
            L[i]++;
        }
 
        if(L[i] > maxLPSLength)  // Track maxLPSLength
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }
 
        //If palindrome centered at currentRightPosition i 
        //expand beyond centerRightPosition R,
        //adjust centerPosition C based on expanded palindrome.
        if (i + L[i] > R) 
        {
            C = i;
            R = i + L[i];
        }
        //Uncomment it to print LPS Length array
        //printf("%d ", L[i]);
    }
    //printf("\n");
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength - 1;
    //printf("LPS of string is %s : ", text.c_str());
    string res;
    for(i=start; i<=end; i++) {
       //        printf("%c", text[i]);
       res.push_back(text[i]);
    }
       
    //printf("\n");
    return res;
}

vector<string> get_all_substrings(const std::string& str)
{
   int len = str.length();
   vector<string> res;
   int k = 2;
   for(;k<len; k++)
      for(int i = 0; i <len-k + 1; i++)
         res.push_back(str.substr(i,k));
    return res;
}

               
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int N;
   cin >> N;
   string str;
   cin >>str;
   str += str;
   //vector<string> subs;
   for(int i=0; i < N; i++) {
      //cout << get_next_circular(str,i) << '\n';
      //subs = get_all_substrings(get_next_circular(str,i));
      //cout << subs << endl;
      cout << findLongestPalindromicString(str.substr(i,N)).length() << '\n';
   }
      
   
    return 0;
}


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

ostream & operator << (ostream &os , const vector<string> &v) {
   for(int i = 0; i < v.size(); i++)
      os <<v[i] << '\n';
   os << endl;
   return os;
}

string solve(const string &s) {
   int l = s.length();
   int rows = floor(sqrt(l)), cols = ceil(sqrt(l));
   cout << "Length : " << l << " --> " << rows << " -- " << cols << endl;
   while (rows*cols < l ) {
      if (rows < cols)
         rows++;
      else
         cols++;
   }
   

   vector<string> grid(rows);
   int start = 0;
   for (int i = 0; i< rows; i++) {
      grid[i] = s.substr(start,cols);
      start += cols;
      if (grid[i].length() < cols) {
         for(int j = 0; j < cols - grid[i].length(); j++)
            grid[i].push_back('\0');
      }
   }

   cout << grid << endl;

   string res;
   
   for(int j = 0; j < cols; j++) {
      for(int i = 0; i < rows; i++) {
         if (grid[i][j])
            res.push_back(grid[i][j]);
      }
      res+=" ";
   }
                          
   return res;
}


int main(){
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}


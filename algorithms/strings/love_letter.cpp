#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int t;
   cin >> t;
   for(int a0=1; a0<=t; a0++) {
      string str;
      cin >> str;
      int ops = 0;
      for(int i=0, j = str.length() - 1;
          i< (str.length() / 2) && j >= (str.length() / 2);
          i++, j--)
         ops += abs(str[i] - str[j]);
      cout << ops << '\n';
   }
    return 0;
}

   /*int numberOfTest = int.Parse(Console.ReadLine());

for (int t = 0; t < numberOfTest; t++)
{
var s = Console.ReadLine().ToArray();
var ops = 0;

// Ignore the character in the middle, if any (it will automatically be excluded by the condition in the for-loop)
for (int i = 0, j = s.Length - 1; i < (s.Length / 2) && j >= (s.Length / 2); i++, j--)
ops += Math.Abs(s[j] - s[i]);

Console.WriteLine(ops.ToString());
}
} */

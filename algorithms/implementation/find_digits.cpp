#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<int> digits;
typedef vector<int>::iterator digits_iter;

ostream & operator << (ostream &os , const digits &d) {
   for(size_t i = 0; i < d.size(); i++)
      os << d[i] << " " << endl;
   return os;
}

digits num_to_digits(int num) {
   digits num_digits;
   while ( num != 0) {
      num_digits.push_back(num%10);
      num /= 10;
   }
   reverse(num_digits.begin(), num_digits.end());
   return num_digits;
}

/**
 * Get the one digit dividers of the number
 * Return a vector containing the dividers.
 */
digits num_deviders(long int num) {
   digits res;
   res.push_back(1); //one divides all numbers
   for(int i = 2; i <= 9; i++)
      if(num%i == 0 )
         res.push_back(i);
   return res;
   
}

int main(){
    int t;
     digits dig;
    digits res;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        dig = num_to_digits(n);
        //cout << dig;
        digits n_div = num_deviders(n);
        //cout << n_div;
        int sum = 0;
        for(size_t i=0; i < n_div.size(); i++)
           sum += std::count(dig.begin(), dig.end(), n_div[i]);
        res.push_back(sum);
    }
    
    cout << res;
    return 0;
}
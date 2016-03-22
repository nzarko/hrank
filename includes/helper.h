#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream &operator << (ostream &os , const vector<T> &v) {
   for(size_t i =0; i < v.size(); i++)
      os << v[i] << " " ;
   os << endl;
   return os;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Date {
   int day,month,year;
public:
   enum State {ok = 0, inMonth, inYear, afterYear };
   Date(int d, int m, int y) : day(d), month(m), year(y) {}
   int getDay() const {return day; }
   int getMonth() const { return month; }
   int getYear()  const { return year; }
   friend State getState(const Date &d1, const Date & d2) {
      if ( d1 <= d2)
         return Date::ok;
      else {
         if ( d1.getMonth() == d2.getMonth() && d1.getYear() == d2.getYear() )
            return Date::inMonth;
         if ( d1.getYear() == d2.getYear() )
            return Date::inYear;
         return Date::afterYear;
      }
   }
   friend bool operator <= (const Date &d1, const Date &d2);
};
bool operator <= (const Date &d1, const Date &d2) {
   long int r1 = d1.getDay() + d1.getMonth() * 30 + d1.getYear() * 365;
   long int r2 = d2.getDay() + d2.getMonth() * 30 + d2.getYear() * 365;
   return r1 <= r2;
}
      
   
int main(){
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    int d2;
    int m2;
    int y2;
    cin >> d2 >> m2 >> y2;
    Date date1(d1,m1,y1), date2(d2,m2,y2);
    Date::State state = getState(date1,date2);
    int fine;
    switch(state) {
    case Date::ok:
       fine = 0;
       break;
    case Date::inMonth:
       fine = (date1.getDay() - date2.getDay() )*15;
       break;
    case Date::inYear:
       fine = (date1.getMonth() - date2.getMonth())*500;
       break;
    case Date::afterYear:
       fine =  10000;
       break;
    }
    cout << fine << endl;
    
    return 0;
}

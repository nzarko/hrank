#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const string inttostr(int m) {
    const vector<string> numbers = {
        "invalid", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
        "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", 
        "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", 
        "twenty nine", "thirty"};

    if (m < 1 || m > 29) {
        cout << "Bad number: " << m << endl;
        return "error in in_to_word!";
    }
    return numbers[m];
}

int main() {
    int h;
    cin >> h;
    int m;
    cin >> m;

    string hour = inttostr(h);
    if (m == 0) {
        cout << hour << " o' clock";
    } else if (m == 15) {
        cout << "quarter past " << hour;
    } else if (m == 30) {
        cout << "half past " << hour;
    } else if (m == 1) {
        cout << "one minute past " << hour;
    } else if (m < 30) {
        cout << inttostr(m) << " minutes past " << hour;
    } else {
        string nexth = (h < 12 ? inttostr(h+1) : inttostr(1));
        
        if (m == 45) {
            cout << "quarter to " << nexth;
        } else if (m == 59) {
            cout << "one minute to " << nexth;
        } else {
            cout << inttostr(60-m) << " minutes to " << nexth;
        }
    }
    cout << endl;
    return 0;
}
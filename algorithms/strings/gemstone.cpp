#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int rocks_count;
   cin >> rocks_count;
   
   char letters[26] = {0};
   int gems = 0;

   for(int r_n=0; r_n < rocks_count; r_n++) {
      string rock;
      cin >> rock;
      for(int i=0; i < rock.length(); i++) {
         char ch = rock[i];
         if(letters[ch - 'a'] == r_n) {
            letters[ch - 'a']++;
            if(letters[ch - 'a'] == rocks_count)
               gems++;
         }
      }
   }
   cout << gems << '\n';
    return 0;
}

/* *
int main() {

    int rocks;
    scanf("%d", &rocks);
    char letter[26] = {0};
    int count = 0;
    for (int r = 0; r < rocks; r++) {
        char s[100];
        scanf("%s", s);
        for (int i = 0; i < strlen(s); i++) {
            char c = s[i];
            if (letter[c - 'a'] == r) {
                letter[c - 'a']++;
                if (letter[c - 'a'] == rocks) {
                    count++;
                }                    
            }
        }
    }

    printf("%d", count);

    return 0;
    } */

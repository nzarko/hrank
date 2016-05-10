#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
typedef map<char,int> Dict;
bool validate(Dict dict, int limit){
    if(dict['A'] <= limit && dict['C'] <= limit && dict['G'] <= limit && dict['T'] <= limit){
        return true;
    }else{
       return false;
    }
}

int main() {
    int N, maxIndex = 0, out = 999999;
    Dict dict;
    string str;
    cin >> N >> str;
    int limit = N / 4;
    for (int i = N - 1; i >= 0; i--){
        dict[str[i]]++;
        if(!validate(dict, limit)){
            maxIndex = i + 1;
            dict[str[i]]--;
            break;
        }
    }
    for(int minIndex = -1; minIndex < N - 1 && maxIndex < N && minIndex < maxIndex; minIndex++){
        while(!validate(dict, limit) && maxIndex < N){
            dict[str[maxIndex]]--;
            maxIndex++;
        }
         if(maxIndex > N || !validate(dict, limit)){
            break;
        }
        int sublen = max(0, maxIndex - minIndex - 1);
        if(sublen < out){
            out = sublen;
        }
        dict[str[minIndex + 1]]++;
    }
    cout << out << endl;
    return 0;

}

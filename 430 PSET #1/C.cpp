#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    map<char,int> count;
    count['0'] = 0;
    count['1'] = 0;
    count['2'] = 0;
    for(int i = 0; i < s.size(); i++){
        count[s[i]] += 1;
    }
    int swaps = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            count['0'] -= 1;
        }else{
            swaps += count['0'];
            if(s[i] == '1'){
                count['1'] -= 1;
            }else{
                swaps += count['1'];
            }
        }
    }
    cout << swaps << endl;   
}
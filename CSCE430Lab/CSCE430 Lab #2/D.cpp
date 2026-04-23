#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1;
    string s2;
    cin >> s1 >> s2;
    int num = 1;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] != s2[i]){
            num *= 2;
        }
    }
    cout << num << endl;
}
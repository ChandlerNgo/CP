#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int one = 0;
    int two = 0;
    int three = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            one += 1;
        }
        if(s[i] == '2'){
            two += 1;
        }
        if(s[i] == '3'){
            three += 1;
        }
    }
    if(one == 1 && two == 2 && three == 3){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        int num1 = s[0] - '0';
        int num2 = s[2] - '0';
        if(num1 == num2){
            s[1] = '=';
        }else if(num1 < num2){
            s[1] = '<';
        }else{
            s[1] = '>';
        }
        cout << s << endl;
    }
}
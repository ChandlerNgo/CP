#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int zebra = 'z'-s[0];
    int alpaca = s[0]-'a';
    if(zebra < alpaca){
        cout << "zebra" << endl;
    }else{
        cout << "alpaca" << endl;
    }

}
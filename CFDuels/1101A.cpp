#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        ll l;
        ll r;
        ll cur;
        cin >> l >> r >> cur;
        ll num = cur;
        if(num >= l && num <= r){
            num = ((r/cur)+1)*cur;
        }
        cout << num << endl;
    }
}
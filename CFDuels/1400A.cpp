#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;
    for(int i = 0; i < t; i++){
        ll n;
        cin >> n;
        string bstring;
        cin >> bstring;
        string create = "";

        for(int j = 0; j < bstring.size()-n; j++){
            create += bstring[j+j];
        }
        cout << create << endl;
    }
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int k;
        int x;
        int a;
        cin >> k >> x >> a;
        if((a-x)*k > a){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
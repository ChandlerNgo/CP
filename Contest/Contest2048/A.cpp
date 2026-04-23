#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 33 == 0){
            cout << "YES\n"; 
        }else{
            cout << "NO\n"; 
        }
    }
}
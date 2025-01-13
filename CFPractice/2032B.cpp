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
        int k;
        cin >> n >> k;
        int leftSide = k-1;
        int rightSide = n-k;

        if(leftSide == 0 && rightSide == 0){
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }

        if(leftSide == 0 || rightSide == 0){
            cout << -1 << endl;
            continue;
        }

        if(leftSide % 2 == 1 && rightSide % 2 == 1){
            cout << 3 << endl;
            cout << 1 << " " << k << " " << k+1 << endl;
            continue;
        }else{
            // both even
            cout << 5 << endl;
            cout << 1 << " " << k-1 << " " << k << " " << k+1 << " " << k+2 << endl;
        }

        
    }
}
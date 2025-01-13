#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        int k;
        cin >> n >> k;

        // count up from n-k to n
        for(int j = n-k; j <= n; j++){
            cout << j << " ";
        }
        // count down from n-k-1 to 1 
        for(int j = n-k-1; j >= 1; j--){
            cout << j << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int k;
    cin >> n >> k;
    vector<bool> houses(n+1,false);
    for(int i = 0; i < k; i++){
        int num;
        cin >> num;
        houses[num] = true;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            cout << i << " " << j << endl;
        }
    }
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int k;
    cin >> n >> k;
    if(n == k || k == 0){
        cout << 0 << " " << 0 << endl;
    }else{
        cout << 1 << " " << min(n-k, k+1) << endl;
    }
}
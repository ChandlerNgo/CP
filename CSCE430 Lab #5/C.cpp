#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n < 4){
        cout << 1 << endl;
        return 0;
    }
    cout << n-2 << endl;
}
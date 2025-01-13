#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int m; int a; int b; int c;
        cin >> m >> a >> b >> c;
        int total = 0;
        total += min(m,a);
        total += min(m,b);
        total += min((m*2)-total,c);
        cout << total << endl;
    }
}
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        int b;
        cin >> a >> b;

        for(int j = 0; j < b; j++){
            cout << j << " ";
        }

        for(int j = b+1; j < a; j++){
            cout << j << " ";
        }

        if(b != a){
            cout << b;
        }
        cout << "\n";
    }
    cout << flush;
}
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    cin >> n;
    int l = 0;
    int r = n.size()-1;
    bool ending = true;
    while(l < r){
        if(n[r] == '0' && ending){
            r -= 1;
            continue;
        }else{
            ending = false;
            if(n[l] != n[r]){
                cout << "NO" << endl;
                return 0;
            }
            l += 1;
            r -= 1;
        }
    }
    cout << "YES" << endl;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a;
        int b;
        cin >> a >> b;
        if(a >= b){
            cout << a << endl;
        }else{
            // binary search
            int l = 1;
            int r = a;
            while(l <= r){
                int m = (l + r)/2;
                if(a-m >= b-(2*m)){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
            cout << max(a-l,0) << endl;
        }
    }
}
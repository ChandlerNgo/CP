#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int j = 0; j < t; j++){
        int w;
        int h;
        int n;
        cin >> w >> h >> n;
        int a = 0;
        while(w % 2 == 0){
            w = w / 2;
            a *= 2;
        }
        int b = 1;
        while(h % 2 == 0){
            h = h / 2;
            b *= 2;
        }
        
        if((a+b) >= n){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
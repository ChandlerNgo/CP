#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long a;
        long long b;
        cin >> a >> b;
        if(a < b){
            swap(a,b);
        }
        // a > b
        long long moves = 0;
        double val = log2(a/b);
        while(a != b){
            if(b * 8 <= a){
                moves += 1;
                b *= 8;
            }else if(b * 4 <= a){
                moves += 1;
                b *= 4;
            }else if(b * 2 <= a){
                moves += 1;
                b *= 2;
            }else{
                moves = -1;
                break;
            }
        }
        cout << moves << "\n";
        
    }
}
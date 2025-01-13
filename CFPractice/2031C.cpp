#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int num;
        cin >> num;
        if(num % 2 == 0){
            // alternate sets of 2
            for(int i = 1; i <= num; i++){
                cout << (i - (i%2 == 0)) << " ";
            }
            cout << endl;
        }else{
            // odd
            // only odds > 25
            
            if(num >= 27){
                cout << "1 13 13 12 12 11 11 10 10 9 9 8 8 6 7 7 1 6 5 5 4 4 2 3 3 1 2 ";
                for(int i = 28; i <= num; i++){
                    if(i % 2 == 1){
                        cout << i-1 << " ";
                    }else{
                        cout << i << " ";
                    }
                }
                cout << endl;
            }else{
                cout << -1 << endl;
            }
        }
    }
}
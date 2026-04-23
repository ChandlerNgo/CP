#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ones = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                ones += 1;
            }
        }

        cout << (n-ones)*(ones+1) + (ones)*(ones-1) << "\n";
    }
    cout << flush;
}
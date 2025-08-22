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
        string s1;
        cin >> s >> s1;
        int first = 0;
        int second = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                first += (s[i] == '1');
                second -= (s1[i] == '0');
            }else{
                first -= (s1[i] == '0');
                second += (s[i] == '1');
            }
        }
        if(first > 0 || second > 0){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
}
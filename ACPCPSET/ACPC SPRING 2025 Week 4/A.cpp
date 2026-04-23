#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string c = "codeforces";
    string s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        int num = 0;
        for(int j = 0; j < 10; j++){
            if(s[j] != c[j]){
                num += 1;
            }
        }
        cout << num << endl;
    }
}